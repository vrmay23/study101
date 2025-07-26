/*
 * ==========================================================================
 *
 *    Filename:     2_posix_log_creation.c
 *
 *    Description:  create log file - ALWAYS CLEAN AT STARTUP (O_TRUNC)
 *    Version:      1.0
 *    Created:      07/06/2025 10:49:23 AM
 *    Revision:     none
 *    Compiler:     gcc
 *
 *   Author:        vinicius may 
 *   Organization:  QsimX
 *
 * ==========================================================================
 */


/*
 * man 2 open
 * open()	int open(const char *pathname, int flags, mode_t mode)
 *
 * man 2 write
 * write()	ssize_t write(int fd, const void *buf, size_t count);
 *
 * man 2 close
 * close()	int close(int fd);
 *
 * man 2 read
 * read() ssize_t read(int fd, void buf[.count], size_t count);
 * 
 * man 3 time
 * man 3 ctime
 * man 3 strftime
*/

#include <stdio.h>         /* standard input output library                */
#include <unistd.h>        /* include system func (fork, exec, pipe, etc.) */
#include <fcntl.h>         /* manipulate file descriptor (fd)              */
#include <string.h>
#include <time.h>          

#define FILE_NAME           "my_log.txt"              
#define LOG_HEADER          "============ LOGGER ============\n\n"
#define LENGHT_HEADER       strlen(LOG_HEADER)

#define MAX_LINES             5
#define LINE_BUFFER_SIZE     64


int main() {

  int i  = 0;
  int fd = open(FILE_NAME, O_CREAT | O_WRONLY | O_TRUNC, 0644);
  
  if (fd < 0)
  { 
    perror("Error opening file!");
    return 1;
  }

  if (write(fd, LOG_HEADER, LENGHT_HEADER) < 0)
  {
    perror("Error on writing header to the file!");
    return 1;
  }

  char line_log[LINE_BUFFER_SIZE];
  time_t rawtime;          // To store the raw time value
  struct tm *info;         // To store the broken-down time components
  char   time_str[20];     // To store the formatted time string 
                           // (e.g., "YYYY-MM-DD HH:MM:SS")
  
  for (i=0; i<MAX_LINES; i++)
  {
    time(&rawtime);             // Get current calendar time
    info = localtime(&rawtime); // Convert to local time structure
    
    /*
       * 2. Format the time string
       * Example format: YYYY-MM-DD HH:MM:SS
       * strftime returns the number of characters placed into the array, 
       * not including the null terminator.
       */

     if (strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", info) == 0) 
       {
        perror("Error formatting time string");
        close(fd);
        return 1;
      }

    int write_result = snprintf(line_log,          \
                                LINE_BUFFER_SIZE,  \
                                "%s [%d - LOG]\n", \
                                time_str,          \
                                i);

    if (write_result < 0 || write_result >= LINE_BUFFER_SIZE)
    {
      perror("Error formatting string or buffer is too small!");
      close(fd);
      return 1;
    }

   write(fd, line_log, strlen(line_log));
  }

  write(fd, "\n", strlen("\n"));
  close(fd);

  return 0;
}

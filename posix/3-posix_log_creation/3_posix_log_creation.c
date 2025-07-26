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

#include <stdio.h>         /* standard input output library                */
#include <unistd.h>        /* include system func (fork, exec, pipe, etc.) */
#include <fcntl.h>         /* manipulate file descriptor (fd)              */
#include <string.h>

#define FILE_NAME       "my_log.txt"              
#define LOG_HEADER      "============ LOGGER ============\n\n"
#define LENGHT_HEADER   strlen(LOG_HEADER)
#define MAX_LINES        5
#define LINE_BUFFER     30
  

int main() {

  int i  = 0;
  int fd = open(FILE_NAME, O_CREAT | O_WRONLY | O_TRUNC, 0644);
  
  if (fd < 0)
  { 
    perror("Error opening file!");
    return 1;
  }

  write(fd, LOG_HEADER, LENGHT_HEADER);

  char line_log[LINE_BUFFER];
  for (i=0; i<MAX_LINES; i++)
  {
    int write_result = snprintf(line_log, LINE_BUFFER, "[%d - LOG]\n", i);
    if (write_result < 0 || write_result >= LINE_BUFFER)
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

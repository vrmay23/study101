/*
 * ===========================================================================
 *
 *   Filename:     1_log.c
 *
 *   Description:  Demonstrates log techs and ifdef
 *                 there is one 'logical' error. 
 *                 tip: 200/40 =5 (and not 2) MUHaHAHAH HAHHAAHahaha
 *
 *   Version:      1.0
 *   Created:      08/02/2025 09:00:00 AM
 *   Author:       vrmay23 (c)
 *   Organization: QsimX 
 *
 * ===========================================================================
 */

#include <stdio.h>      /* Basic i/o function                               */
#include <string.h>     /* String manipulation                              */

#include <stdint.h>     /* uint8_t                                          */
#include <fcntl.h>      /* POSIX flags and constants for file control flow  */
#include <unistd.h>     /* POSIX calls, such as read(), close(), etc.       */
#include <sys/stat.h>   /* Provides the struct 'stat' and stat() function,
                           which returns information about files            */
/* DEFINES =================================================================*/

#define MAX_LOG_SIZE       1024
#define MAX_ITERATION      200

#define LOG_FILENAME       "logic_output.txt"
#define LOG_ROTATED_NAME   "logic_output.1.txt"

/* FUNCTION SIGNATURES =====================================================*/

void write_log(const char *str);

/* MAIN ====================================================================*/

int main(void)
{

  uint8_t i = 0;

  for (i=0; i<MAX_ITERATION; i++)
  {
    write_log("This is a test log entry!\n");
  }

  return 0;

}

/* AUX FUNCTION  ===========================================================
*
* Write a string to the log file.
* If file exceeds MAX_LOG_SIZE, the file is rotated (new file)
*
*/

void write_log(const char *str)
{

/*  Demonstrates use of #ifdef to enable or disable log rotation. */

#ifdef MAX_LOG_SIZE
  struct stat st;
  int fd;

  /* check current file size */ 
  
  if ( (stat(LOG_FILENAME, &st) == 0) && (st.st_size >= MAX_LOG_SIZE) )
  {
     unlink(LOG_ROTATED_NAME);                    /* remove old rotated log */
     rename(LOG_FILENAME, LOG_ROTATED_NAME);      /* rename current logname */
  }
#endif 

  /* open file and write new entry */

  fd = open(LOG_FILENAME, O_WRONLY | O_CREAT | O_APPEND, 0644);
  if (fd >=0)
  {
    write(fd, str, strlen(str));
    close(fd);
  }

}
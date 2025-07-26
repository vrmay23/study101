/*
 * ===========================================================================
 *
 *   Filename:     calc_1.c
 *
 *   Description:  introdution to basic math operations
 *
 *
 *   Version:      1.0
 *   Created:      07/21/2025 07:40:05 PM
 *   Revision:     none
 *   Compiler:     gcc
 *
 *   Author:  vrmay23 (c) 
 *   Organization:  QsimX 
 *
 * ===========================================================================
 */

/* ---- Includes -----------------------------------------------------------*/

/* own libraries */

/* standard libraries */

#include <stdio.h>     /* STANDARD streaming (printf, perror, etc.          */
#include <string.h>    /* Help to handle strings                            */

/* external libraries */

#include <fcntl.h>     /* POSIX lib for flags (open, O_WRONLY, etc.         */
#include <unistd.h>    /* POSIX lib for basic syscall (write, close, etc.   */

/* --- defines -------------------------------------------------------------*/

/* --- constants -----------------------------------------------------------*/
const char *msg =
    "\\a - Bell            \n"
    "\\b - Backspace       \n"
    "\\f - Form feed       \n"
    "\\n - New line        \n"
    "\\r - Carriage return \n"
    "\\t - Horizontal tab  \n"
    "\\v - Vertical tab    \n"
    "\\\\ - Backslash      \n"
    "\\' - Single quote    \n"
    "\\\" - Double quote   \n"
    "\\? - Question mark   \n"
    "\\ooo - Octal         \n"
    "\\xhh - Hexadecimal   \n"
    "\u03A9 - omega        \n";

/* --- functions signature -------------------------------------------------*/

/* --- functions -----------------------------------------------------------*/

/* main function */

int main(int argc, char *argv[])
{
  (void)argc;                            /* 'disabling' the warning */
  (void)argv;

  int fd = open("/dev/tty", O_WRONLY);   /* being reduntant - to be explicit*/
  
  if (fd < 0)
  {
    perror("fail to open");              /* if can not open*/
    return 1;
  }

  write(fd, msg, strlen(msg));
  close(fd);

  return 0;
}


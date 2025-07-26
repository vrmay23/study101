/*
 * ==========================================================================
 *
 *    Filename:     1_posix_intro.c
 *
 *    Description:  introduction
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

#define FILE_NAME "test.txt"              

const char *g_text = "This is another way to handle the POSIX function 'open'\n"
                     "As you can see, there is no need to count manually the \n"
                     "lenght of the whole content. We just need to use strlen\n"
                     "to do if for us!\n";

#define LENGHT strlen(g_text)

int main() {

  int fd = open(FILE_NAME, O_CREAT | O_WRONLY, 0644);
  
  if (fd < 0) return 1;
  write(fd, g_text, LENGHT);
  close(fd);

  return 0;
}

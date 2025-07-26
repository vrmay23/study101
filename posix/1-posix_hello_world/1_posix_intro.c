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

#define FILE_NAME "test.txt"
#define TEXT      "This is my first POSIX program"
#define LENGHT    30

int main() {

  int fd = open(FILE_NAME, O_CREAT | O_WRONLY, 0644);
  
  if (fd < 0) return 1;
  write(fd, TEXT, LENGHT);
  close(fd);

  return 0;
}

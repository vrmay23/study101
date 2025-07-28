/*
 * ===========================================================================
 *
 *   Filename:     2_char.c
 *
 *   Description:  introduction to var declaration and types;
 *                 char type and fixing the 'return issue'
 *
 *   Version:      1.0
 *   Created:      07/22/2025 14:06:02 PM
 *   Author:       vrmay23 (c)
 *   Organization: QsimX 
 *
 * ===========================================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include <fcntl.h>
#include <unistd.h>

/* --- constants -----------------------------------------------------------*/
const char *msg = "\n";

/* --- function signatures -------------------------------------------------*/
int print_header(void);
void print_example(void);

/* --- main function -------------------------------------------------------*/
int main(int argc, char *argv[])
{
  (void)argc;
  (void)argv;

  int ret = print_header();
  if (ret != 0)
    return 1;

  (void)print_example();

  return 0;
}

/* --- aux functions -------------------------------------------------------*/

int print_header(void)
{
  int fd = open("/dev/tty", O_WRONLY);
  if (fd < 0)
  {
    perror("Fail to open fd");
    return 1;
  }

  write(fd, msg, strlen(msg));
  close(fd);
  return 0;
}

void print_example(void)
{
  char n1 = 10, n2 = 20, n3 = 26, r = n1+n2+n3;
  char character = 'V';

  printf("Result: %d + %d + %d = %d\n", n1, n2, n3, r);
  printf("\nChar   (ascii): %d", r);
  printf("\nChar   (ascii): %x", character);
  printf("\nChar   (value): %c", character); 
  printf("\nChar   (hex):   %c", character);
  printf("\n");
}


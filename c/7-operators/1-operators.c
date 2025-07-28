/*
 * ===========================================================================
 *
 *   Filename:     1_relational_conditional.c
 *
 *   Description:  Examples using relational and conditional operators
 *
 *   Version:      1.0
 *   Created:      07/28/2025 20:32:00 PM
 *   Author:       vrmay23 (c)
 *   Organization: QsimX 
 *
 * ===========================================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>

/* --- constants -----------------------------------------------------------*/
const char *msg = "\nRelational and Conditional Operators\n\n";

/* --- function signatures -------------------------------------------------*/
int print_header(void);
void print_example(void);

/* --- main function -------------------------------------------------------*/
int main(int argc, char *argv[])
{
  (void)argc;
  (void)argv;

  if (print_header() != 0)
    return 1;

  print_example();

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
  int a = 10, b = 20;
  
  printf("\n\n");
  printf("A: %d, B: %d", a,b);
  printf("\n\n");
  printf("A. Equal (a == b)\n");
  printf("Expected: 0 (false)\n");
  printf("Result: %d\n\n", a == b);

  printf("B. Not Equal (a != b)\n");
  printf("Expected: 1 (true)\n");
  printf("Result: %d\n\n", a != b);

  printf("C. Less Than (a < b)\n");
  printf("Expected: 1 (true)\n");
  printf("Result: %d\n\n", a < b);

  printf("D. Greater Than (a > b)\n");
  printf("Expected: 0 (false)\n");
  printf("Result: %d\n\n", a > b);

  printf("E. Less Than or Equal (a <= b)\n");
  printf("Expected: 1 (true)\n");
  printf("Result: %d\n\n", a <= b);

  printf("F. Greater Than or Equal (a >= b)\n");
  printf("Expected: 0 (false)\n");
  printf("Result: %d\n\n", a >= b);

  printf("G. Logical AND (a < b && b == 20)\n");
  printf("Expected: 1 (true)\n");
  printf("Result: %d\n\n", (a < b) && (b == 20));

  printf("H. Logical OR (a == 10 || b == 30)\n");
  printf("Expected: 1 (true)\n");
  printf("Result: %d\n\n", (a == 10) || (b == 30));

  printf("I. Logical NOT (!(a > b))\n");
  printf("Expected: 1 (true)\n");
  printf("Result: %d\n\n", !(a > b));
}


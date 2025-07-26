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
    "\n"
    "====================================\n"
    "==       basic math operations    ==\n"
    "==                                ==\n"
    "==   Addition       (+)           ==\n"
    "==   Subtraction    (-)           ==\n"
    "==   Multiplication (*)           ==\n"
    "==   Division       (\\)           ==\n"
    "==                                ==\n"
    "====================================\n"
    "\n"
    "\a";



/* --- functions signature -------------------------------------------------*/
int print_header(void);
int print_example(void);

/* --- functions -----------------------------------------------------------*/

/* main function */

int main(int argc, char *argv[])
{
  (void)argc;                            /* 'disabling' the warning */
  (void)argv;

  print_header();
  print_example();

  return 0;
}

/*  ---- aux functions -----------------------------------------------------*/

/*
 * Just print the 'header' of this code.
 * Printing out the basic for math operation
 *
 * * * * * * * * * * * * * * * * * * * * * * */
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

/* 
 * Print out the examples about the priority
 * in terms of math operation
 *
 * * * * * * * * * * * * * * * * * * * * * */
int print_example(void)
{
  printf("A. Adding 5+3.\n");
  printf("Expected: 8 because 5 plus 3 equals 8.\n");
  printf("Result: %d\n\n", 5 + 3);

  printf("B. Subtracting 10-4.\n");
  printf("Expected: 6 because 10 minus 4 equals 6.\n");
  printf("Result: %d\n\n", 10 - 4);

  printf("C. Multiplying 6*7.\n");
  printf("Expected: 42 because 6 times 7 equals 42.\n");
  printf("Result: %d\n\n", 6 * 7);

  printf("D. Dividing 20/4.\n");
  printf("Expected: 5 because 20 divided by 4 equals 5.\n");
  printf("Result: %d\n\n", 20 / 4);

  printf("E. 8+2*3.\n");
  printf("Expected: 14 because multiplication comes before addition\n");
  printf("          (8+(2*3)).\n");
  printf("Result: %d\n\n", 8 + 2 * 3);

  printf("F. (8+2)*3.\n");
  printf("Expected: 30 because parentheses change the order\n");
  printf("          ((8+2)*3).\n");
  printf("Result: %d\n\n", (8 + 2) * 3);

  printf("G. 20-4/2.\n");
  printf("Expected: 18 because division comes before subtraction\n");
  printf("          (20-(4/2)).\n");
  printf("Result: %d\n\n", 20 - 4 / 2);

  printf("H. (20-4)/2.\n");
  printf("Expected: 8 because parentheses change the order\n");
  printf("          ((20-4)/2).\n");
  printf("Result: %d\n\n", (20 - 4) / 2);

  printf("I. 10*2+5.\n");
  printf("Expected: 25 because multiplication comes before addition\n");
  printf("          ((10*2)+5).\n");
  printf("Result: %d\n\n", 10 * 2 + 5);

  printf("J. 10*(2+5).\n");
  printf("Expected: 70 because parentheses force addition first\n");
  printf("          (10*(2+5)).\n");
  printf("Result: %d\n\n", 10 * (2 + 5));

  printf("K. 20/2/2.\n");
  printf("Expected: 5 because division associates left-to-right:\n");
  printf("          (20/2)=10 then (10/2)=5.\n");
  printf("Result: %d\n\n", 20 / 2 / 2);

  printf("L. 100-50-25.\n");
  printf("Expected: 25 because subtraction associates left-to-right:\n");
  printf("          (100-50)=50 then (50-25)=25.\n");
  printf("Result: %d\n\n", 100 - 50 - 25);

  printf("M. Integer division 7/2.\n");
  printf("Expected: 3 because integer division truncates the decimal\n");
  printf("          part (7/2=3.5 => 3).\n");
  printf("Result: %d\n\n", 7 / 2);

  printf("N. Adding negative numbers: -5+3.\n");
  printf("Expected: -2 because adding 3 to -5 equals -2.\n");
  printf("Result: %d\n\n", -5 + 3);

  printf("O. Negative multiplication: -4*3.\n");
  printf("Expected: -12 because negative times positive equals\n");
  printf("          negative.\n");
  printf("Result: %d\n\n", -4 * 3);

  printf("P. Zero in multiplication: 0*100.\n");
  printf("Expected: 0 because anything times zero is zero.\n");
  printf("Result: %d\n\n", 0 * 100);

  printf("Q. Zero in addition: 0+7.\n");
  printf("Expected: 7 because adding zero does not change the\n");
  printf("          number.\n");
  printf("Result: %d\n\n", 0 + 7);

  printf("R. Zero in subtraction: 0-7.\n");
  printf("Expected: -7 because 0 minus 7 equals -7.\n");
  printf("Result: %d\n\n", 0 - 7);

  printf("S. Zero divided by number: 0/5.\n");
  printf("Expected: 0 because zero divided by anything (except zero)\n");
  printf("          is zero.\n");
  printf("Result: %d\n\n", 0 / 5);

  printf("T. Dividing by zero: 5/0.\n");
  printf("Expected: ERROR because division by zero is undefined and\n");
  printf("          causes a runtime error.\n");
  // printf("Result: %d\n\n", 5 / 0); // Uncommenting crashes the program!

  printf("All examples complete. Review the output to understand\n");
  printf("addition, subtraction, multiplication, division,\n");
  printf("precedence, associativity, and integer division behavior.\n");

  return 0;
}

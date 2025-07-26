/*
 * ===========================================================================
 *
 *   Filename:     1_var.c
 *
 *   Description:  introdution to var declaration and types;
 *                 it will fail due missing 'stdint.h'.
 *
 *   Version:      1.0
 *   Created:      07/22/2025 07:22:12 PM
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
    "==       basic variable types     ==\n"
    "==                                ==\n"
    "==   int           (integer)      ==\n"
    "==   float         (decimal)      ==\n"
    "==   double        (double float) ==\n"
    "==   char          (character)    ==\n"
    "==   short         (short int)    ==\n"
    "==   long          (long int)     ==\n"
    "==   unsigned      (no sign)      ==\n"
    "==   void          (no value)     ==\n"
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
 * Print out examples of how to declare variables
 * and their corresponding types (including stdint)
 *
 * * * * * * * * * * * * * * * * * * * * * * * * */
int print_var_examples(void)
{
  printf("A. Integer variable.\n");
  printf("Declaration: int x = 10;\n");
  int x = 10;
  printf("Value: %d\n\n", x);

  printf("B. Float variable.\n");
  printf("Declaration: float pi = 3.14f;\n");
  float pi = 3.14f;
  printf("Value: %f\n\n", pi);

  printf("C. Double variable.\n");
  printf("Declaration: double e = 2.71828;\n");
  double e = 2.71828;
  printf("Value: %lf\n\n", e);

  printf("D. Char variable.\n");
  printf("Declaration: char c = 'A';\n");
  char c = 'A';
  printf("Value: %c\n\n", c);

  printf("E. Short variable.\n");
  printf("Declaration: short s = 100;\n");
  short s = 100;
  printf("Value: %d\n\n", s);

  printf("F. Long variable.\n");
  printf("Declaration: long l = 100000L;\n");
  long l = 100000L;
  printf("Value: %ld\n\n", l);

  printf("G. Unsigned int variable.\n");
  printf("Declaration: unsigned int u = 42;\n");
  unsigned int u = 42;
  printf("Value: %u\n\n", u);

  printf("H. Void pointer (generic pointer).\n");
  printf("Declaration: void *ptr = NULL;\n");
  void *ptr = NULL;
  printf("Value: %p\n\n", ptr);

  printf("I. uint8_t variable.\n");
  printf("Declaration: uint8_t a = 255;\n");
  uint8_t a = 255;
  printf("Value: %u\n\n", a);

  printf("J. uint16_t variable.\n");
  printf("Declaration: uint16_t b = 65535;\n");
  uint16_t b = 65535;
  printf("Value: %u\n\n", b);

  printf("K. uint32_t variable.\n");
  printf("Declaration: uint32_t c32 = 4294967295U;\n");
  uint32_t c32 = 4294967295U;
  printf("Value: %u\n\n", c32);

  printf("L. uint64_t variable.\n");
  printf("Declaration: uint64_t d = 18446744073709551615ULL;\n");
  uint64_t d = 18446744073709551615ULL;
  printf("Value: %llu\n\n", d);

  printf("M. int8_t variable.\n");
  printf("Declaration: int8_t e8 = -128;\n");
  int8_t e8 = -128;
  printf("Value: %d\n\n", e8);

  printf("N. int16_t variable.\n");
  printf("Declaration: int16_t e16 = -32768;\n");
  int16_t e16 = -32768;
  printf("Value: %d\n\n", e16);

  printf("O. int32_t variable.\n");
  printf("Declaration: int32_t e32 = -2147483648;\n");
  int32_t e32 = -2147483648;
  printf("Value: %d\n\n", e32);

  printf("P. int64_t variable.\n");
  printf("Declaration: int64_t e64 = -9223372036854775807LL;\n");
  int64_t e64 = -9223372036854775807LL;
  printf("Value: %lld\n\n", e64);

  printf("All examples complete. Review the output to\n");
  printf("understand declaration and usage of variable\n");
  printf("types: int, float, double, char, short, long,\n");
  printf("unsigned, void pointer and all stdint.h types.\n");

  return 0;
}


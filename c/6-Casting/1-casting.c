/*
 * ===========================================================================
 *
 *   Filename:     4-casting
 *
 *   Description:  introduction to casting (including lm)
 *
 *   Version:      1.0
 *   Created:      07/28/2025 20:02:44 PM
 *   Author:       vrmay23 (c)
 *   Organization: QsimX 
 *
 * ===========================================================================
 */

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include <fcntl.h>
#include <unistd.h>

/* --- function signatures -------------------------------------------------*/
void print_example(void);

/* --- main function -------------------------------------------------------*/
int main(int argc, char *argv[])
{
  (void)argc;
  (void)argv;

  print_example();

  return 0;
}

/* --- aux functions -------------------------------------------------------*/
void print_example(void)
{
  int v;                        /* user input */
  int ang = 45;                 /* fixed angle */
  int g = 10;                   /* gravity */
  double pi = 3.14159265;       /* pi constant */

  printf("Initial velocity (m/s): ");
  scanf("%d", &v);

  double wrong = (v * v * sin(2 * ang * pi / 180)) / g;

  double right = ((double)v * (double)v * 
                 sin(2.0 * (double)ang * pi / 180.0)) / (double)g;

  printf("\n[!] Result without casting: %.2f m\n", wrong);
  printf("[✓] Result with casting:    %.2f m\n", right);
}


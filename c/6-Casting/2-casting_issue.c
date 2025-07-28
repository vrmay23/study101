/*
 * ===========================================================================
 *
 *   Filename:     6-casting
 *
 *   Description:  introduction to casting and show resolution issue2
 *
 *   Version:      1.0
 *   Created:      07/28/2025 20:13:15 PM
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
  int weight;
  int tall_cm;

  printf("How tall are you (cm)? ");
  scanf("%d", &tall_cm);

  printf("What is your weight (kg)? ");
  scanf("%d", &weight);

  /* casting correto */
  float tall_m = (float)tall_cm / 100.0f;

  /* erro de casting: divisão ocorre entre inteiros */
  float imc_wrong = (float)(weight / (tall_cm * tall_cm));

  /* casting correto: altura já em metros como float */
  float imc_right = weight / (tall_m * tall_m);

  printf("\n[!] IMC sem casting: %.2f\n", imc_wrong);
  printf("[✓] IMC com casting:  %.2f\n", imc_right);
}


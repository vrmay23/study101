/*
 * ===========================================================================
 *
 *   Filename:     increase_decrease_overflow.c
 *
 *   Description:  Demonstrates x++, ++x, x--, --x and uint8_t overflow
 *
 *   Version:      1.0
 *   Created:      08/02/2025 10:30:00 AM
 *   Author:       vrmay23 (c)
 *   Organization: QsimX 
 *
 * ===========================================================================
 */

#include <stdio.h>      /* Basic I/O functions                              */
#include <stdint.h>     /* uint8_t, uint16_t                                */

/* DEFINES =================================================================*/

#define MAX_ITERATIONS  1000  /* For overflow demo */

/* FUNCTION SIGNATURES =====================================================*/

void demo_post_increment(void);
void demo_pre_increment(void);
void demo_post_decrement(void);
void demo_pre_decrement(void);
void demo_uint8_overflow(uint32_t max_iterations);

/* MAIN ====================================================================*/

int main(void)
{
  demo_post_increment();
  demo_pre_increment();
  demo_post_decrement();
  demo_pre_decrement();
  demo_uint8_overflow(MAX_ITERATIONS);

  return 0;
}

/* AUX FUNCTION ============================================================
 *
 * Post-increment: x++
 * Uses current value of x, then increments x after.
 */

void demo_post_increment(void)
{
  uint8_t x = 5;
  uint8_t y;

  printf("\n--- Post-Increment (x++) ---\n");
  printf("Before: x = %d\n", x);

  y = x++;
  printf("After:  x = %d (incremented)\n", x);
  printf("Result: y = %d (original x)\n", y);
}

/* =========================================================================
 *
 * Pre-increment: ++x
 * Increments x first, then uses the updated value.
 */

void demo_pre_increment(void)
{
  uint8_t x = 5;
  uint8_t y;

  printf("\n--- Pre-Increment (++x) ---\n");
  printf("Before: x = %d\n", x);

  y = ++x;
  printf("After:  x = %d (incremented)\n", x);
  printf("Result: y = %d (updated x)\n", y);
}

/* =========================================================================
 *
 * Post-decrement: x--
 * Uses current value of x, then decrements x after.
 */

void demo_post_decrement(void)
{
  uint8_t x = 5;
  uint8_t y;

  printf("\n--- Post-Decrement (x--) ---\n");
  printf("Before: x = %d\n", x);

  y = x--;
  printf("After:  x = %d (decremented)\n", x);
  printf("Result: y = %d (original x)\n", y);
}

/* =========================================================================
 *
 * Pre-decrement: --x
 * Decrements x first, then uses the new value.
 */

void demo_pre_decrement(void)
{
  uint8_t x = 5;
  uint8_t y;

  printf("\n--- Pre-Decrement (--x) ---\n");
  printf("Before: x = %d\n", x);

  y = --x;
  printf("After:  x = %d (decremented)\n", x);
  printf("Result: y = %d (updated x)\n", y);
}

/* =========================================================================
 *
 * Overflow demo:
 * Increments a uint8_t x up to max_iterations.
 * Each time x wraps from 255 to 0, increments y.
 */

void demo_uint8_overflow(uint32_t max_iterations)
{
  uint8_t x = 0;
  uint16_t y = 0;
  uint8_t prev = 0;

  printf("\n--- Overflow Counter (uint8_t) ---\n");
  printf("Incrementing x from 0 up to %u times...\n", max_iterations);

  for (uint32_t i = 0; i < max_iterations; i++)
  {
    prev = x;
    x++;

    if (x < prev)
    {
      y++;  /* Overflow occurred */
      printf("Overflow #%u detected at iteration %u\n", y, i + 1);
    }
  }

  printf("Final value of x = %u\n", x);
  printf("Total overflows counted in y = %u\n", y);
}

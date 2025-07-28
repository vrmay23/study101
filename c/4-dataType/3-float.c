/*
 * ===========================================================================
 *
 *   Filename:     3_char.c
 *
 *   Description:  introduction to float numbers
 *
 *   Version:      1.0
 *   Created:      07/28/2025 19:22:34 PM
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
const char *msg = "==== FLOAT NUMMBERS ====\n";

/* --- function signatures -------------------------------------------------*/
int print_header(void);
float print_example(float r, float v);

/* --- main function -------------------------------------------------------*/
int main(int argc, char *argv[])
{
  (void)argc;
  (void)argv;

  float current = 0,
        resistor = 2.2E3,
        voltage  = 3.300;

  int ret = print_header();
  
  if (ret != 0)
    return 1;
   
  current = print_example(resistor, voltage);
  printf("\n i = V/R =  %.5f", current);
  printf("\n \n");
  printf("========================");
  printf("\n");

  return 0;
}

/* --- aux functions -------------------------------------------------------*/

int print_header()
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

float print_example(float r, float v)
{
  float c = 0.0;
  
  return c= v/r;
}


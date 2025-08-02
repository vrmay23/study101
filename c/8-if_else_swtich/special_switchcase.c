/*
 * ===========================================================================
 *
 *   Filename:     1_log.c
 *
 *   Description:  Demonstrates log techs and ifdef
 *                 there is one 'logical' error. 
 *                 tip: 200/40 =5 (and not 2) MUHaHAHAH HAHHAAHahaha
 *
 *   Version:      1.0
 *   Created:      08/02/2025 09:00:00 AM
 *   Author:       vrmay23 (c)
 *   Organization: QsimX 
 *
 * ===========================================================================
 */

#include <stdio.h>      /* Basic i/o function                               */

/* DEFINES =================================================================*/

/* FUNCTION SIGNATURES =====================================================*/

/* MAIN ====================================================================*/

int main(void)
{
  char choice = '0';

  printf("================================================\n");
  printf("======     Y/y --> yes                 =========\n");
  printf("======     N/n --> not                 =========\n");
  printf("======  Make your choice!              =========\n"); 
  printf("================================================\n");
  printf("Type 'y' or 'n': \t");
  scanf(" %c", &choice);
  
  switch (choice)
  {
  case 'y':
  case 'Y':
    printf("You have chosen 'YES'\n");
    break;
  
  case 'n':
  case 'N':
    printf("You have chosen 'NOT'\n");
    break; 

  default:
    printf("Wrong input!\n");
    break;
  }

  return 0;
}

/* AUX FUNCTION  ===========================================================*/


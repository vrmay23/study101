/*
 * ===========================================================================
 *
 *   Filename:     helloworld_posix_2.c
 *
 *   Description:  Introducing 'dprintf'
 *
 *
 *   Version:      1.0
 *   Created:      07/21/2025 06:22:25 PM
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

#include <stdlib.h>
#include <stdio.h>                     /* STANDARD stream functions   */

/* external libraries */

#include <fcntl.h>                     /* POSIX lib for flags         */
#include <unistd.h>                    /* POSIX lib for basic syscall */


/* --- functions signature -------------------------------------------------*/


/* --- functions -----------------------------------------------------------*/

/* main function */

int main(int argc, char *argv[])
{
  printf("Hello, world! \n");
  
  return EXIT_SUCCESS;
}


/*
 * ===========================================================================
 *
 *   Filename:     1_scanf_buffer
 *
 *   Description:  introduction to keyboard inputs and buffer issue (enter)
 *
 *   Version:      1.0
 *   Created:      07/28/2025 19:58:06 PM
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
const char *msg = "===========================\n"
                  "====  keyboard inputs  ====\n"
                  "===========================\n"
                  "\n";

/* --- function signatures -------------------------------------------------*/
int print_header(void);
void print_example();

/* --- main function -------------------------------------------------------*/
int main(int argc, char *argv[])
{
  (void)argc;
  (void)argv;

  int ret = print_header();
  
  if (ret != 0)
    return 1;
   
  print_example();

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

void print_example(void)
{
 char key, key2;

 printf("Please, enter with one single key from your keyboard: \t");
 scanf("%c", &key);
 printf("The key was: %c", key);
 printf("\n \n");
 printf("Please, now enter a new key from your keyboard: \t");
 scanf("%c", &key2);
 printf("The other key was: %c", key2);
 printf("\n \n");

 }


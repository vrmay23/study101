/*
 * ===========================================================================
 *
 *   Filename:     8_login_check.c
 *
 *   Description:  User inputs password, if correct: success; else: error.
 *
 *   Version:      1.0
 *   Created:      07/28/2025 21:45:00 PM
 *   Author:       vrmay23 (c)
 *   Organization: QsimX 
 *
 * ===========================================================================
 */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

/* --- constants -----------------------------------------------------------*/
const char *msg = "\nPassword Check Test\n\n";
const char *valid_password = "qsimx123";

/* --- function signatures -------------------------------------------------*/
int print_header(void);
void check_password(const char *input);

/* --- main function -------------------------------------------------------*/
int main(int argc, char *argv[])
{
  (void)argc;
  (void)argv;

  char input[32];

  if (print_header() != 0)
    return 1;

  printf("Enter password: ");
  scanf("%31s", input);

  check_password(input);

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

void check_password(const char *input)
{
  if (strcmp(input, valid_password) == 0)
  {
    printf("  Access granted.\n");
  }
  else
  {
    printf("  Incorrect password.\n");
  }
}


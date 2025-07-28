/*
 * ===========================================================================
 *
 *   Filename:     9_grade_check.c
 *
 *   Description:  Classifies a score using if, else if, and else
 *
 *   Version:      1.0
 *   Created:      07/28/2025 21:55:00 PM
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
const char *msg = "\nGrade Classification\n\n";

/* --- function signatures -------------------------------------------------*/
int print_header(void);
void classify_score(int score);

/* --- main function -------------------------------------------------------*/
int main(int argc, char *argv[])
{
  (void)argc;
  (void)argv;

  int score = 0;

  if (print_header() != 0)
    return 1;

  printf("Enter your score (0-100): ");
  scanf("%d", &score);

  classify_score(score);

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

void classify_score(int score)
{
  if (score >= 90)
  {
    printf("  Resultado: Excelente!\n");
  }
  else if (score >= 70)
  {
    printf("  Resultado: Aprovado.\n");
  }
  else if (score >= 50)
  {
    printf("  Resultado: Recuperação.\n");
  }
  else
  {
    printf("  Resultado: Reprovado.\n");
  }
}


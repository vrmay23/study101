/*
 * ===========================================================================
 *
 *   Filename:     13_conditional_structures.c
 *
 *   Description:  Demonstrates if, else, ternary, switch-case,
 *                 and conditional compilation with POSIX rotating log
 *
 *   Version:      1.3
 *   Created:      08/02/2025 10:30:00 AM
 *   Author:       vrmay23 (c)
 *   Organization: QsimX
 *
 * ===========================================================================
 */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

/*
 * ---------------------------------------------------------------------------
 * Compile-time feature flags
 * ---------------------------------------------------------------------------
 */
#define FEATURE_ENABLED
#define ENABLE_LOG_FILE
/* #define DEBUG_MODE */

/*
 * ---------------------------------------------------------------------------
 * Global constants
 * ---------------------------------------------------------------------------
 */
#define LOG_FILENAME       "logic_output.txt"
#define LOG_ROTATED_NAME   "logic_output.1.txt"
#define MAX_LOG_SIZE       1024  /* Max 1 KB before rotation */

const char *msg = "\nConditional Structures in Action (POSIX)\n\n";

/*
 * ---------------------------------------------------------------------------
 * Function prototypes
 * ---------------------------------------------------------------------------
 */
int print_header(void);
void test_if_else(int number);
void test_if_elseif_else(int value);
void test_ternary(int age);
void test_switchcase(char grade);
void test_conditional_compilation(void);
void write_log(const char *str);

/*
 * ---------------------------------------------------------------------------
 * Main function
 * ---------------------------------------------------------------------------
 */
int main(int argc, char *argv[])
{
  (void)argc;
  (void)argv;

  int n = 0, val = 0, age = 0;
  char g = ' ';

  if (print_header() != 0)
    return 1;

  printf("Enter an integer (for if/else): ");
  scanf("%d", &n);
  test_if_else(n);

  printf("\nEnter another integer (for if/else-if/else): ");
  scanf("%d", &val);
  test_if_elseif_else(val);

  printf("\nEnter your age (for ternary): ");
  scanf("%d", &age);
  test_ternary(age);

  printf("\nEnter your grade (A/B/C/D/F): ");
  scanf(" %c", &g);
  test_switchcase(g);

  test_conditional_compilation();

  return 0;
}

/*
 * ---------------------------------------------------------------------------
 * Print message to /dev/tty using POSIX write
 * ---------------------------------------------------------------------------
 */
int print_header(void)
{
  int fd = open("/dev/tty", O_WRONLY);
  if (fd < 0)
  {
    perror("Failed to open /dev/tty");
    return 1;
  }

  write(fd, msg, strlen(msg));
  close(fd);
  return 0;
}

/*
 * ---------------------------------------------------------------------------
 * IF / ELSE: Check if number is even or odd
 * ---------------------------------------------------------------------------
 */
void test_if_else(int number)
{
  printf("\n--- IF / ELSE Example ---\n");

  if (number % 2 == 0)
  {
    printf("Number %d is even\n", number);
    write_log("Number is even\n");
  }
  else
  {
    printf("Number %d is odd\n", number);
    write_log("Number is odd\n");
  }
}

/*
 * ---------------------------------------------------------------------------
 * IF / ELSE IF / ELSE: Categorize value
 * ---------------------------------------------------------------------------
 */
void test_if_elseif_else(int value)
{
  printf("\n--- IF / ELSE IF / ELSE Example ---\n");

  if (value < 0)
  {
    printf("Value %d is negative\n", value);
    write_log("Value is negative\n");
  }
  else if (value == 0)
  {
    printf("Value is zero\n");
    write_log("Value is zero\n");
  }
  else if (value <= 10)
  {
    printf("Value %d is between 1 and 10\n", value);
    write_log("Value is between 1 and 10\n");
  }
  else
  {
    printf("Value %d is greater than 10\n", value);
    write_log("Value is greater than 10\n");
  }
}

/*
 * ---------------------------------------------------------------------------
 * TERNARY OPERATOR: Classify age
 * ---------------------------------------------------------------------------
 */
void test_ternary(int age)
{
  printf("\n--- TERNARY OPERATOR Example ---\n");

  const char *status = (age >= 18) ? "Adult" : "Minor";
  printf("Age = %d → Status: %s\n", age, status);

  char buffer[64];
  snprintf(buffer, sizeof(buffer), "Age status: %s\n", status);
  write_log(buffer);
}

/*
 * ---------------------------------------------------------------------------
 * SWITCH / CASE: Match grade to description
 * ---------------------------------------------------------------------------
 */
void test_switchcase(char grade)
{
  printf("\n--- SWITCH / CASE Example ---\n");

  switch (grade)
  {
    case 'A':
      printf("Grade A → Excellent\n");
      write_log("Grade: Excellent\n");
      break;
    case 'B':
      printf("Grade B → Good\n");
      write_log("Grade: Good\n");
      break;
    case 'C':
      printf("Grade C → Average\n");
      write_log("Grade: Average\n");
      break;
    case 'D':
      printf("Grade D → Below Average\n");
      write_log("Grade: Below Average\n");
      break;
    case 'F':
      printf("Grade F → Fail\n");
      write_log("Grade: Fail\n");
      break;
    default:
      printf("Invalid grade '%c'\n", grade);
      write_log("Grade: Invalid\n");
      break;
  }
}

/*
 * ---------------------------------------------------------------------------
 * CONDITIONAL COMPILATION: Show macro-controlled output
 * ---------------------------------------------------------------------------
 */
void test_conditional_compilation(void)
{
  printf("\n--- CONDITIONAL COMPILATION Example ---\n");

#ifdef FEATURE_ENABLED
  printf("FEATURE_ENABLED is defined → Feature is ACTIVE\n");
  write_log("Feature is active\n");
#else
  printf("FEATURE_ENABLED is NOT defined → Feature is DISABLED\n");
  write_log("Feature is disabled\n");
#endif

#ifndef DEBUG_MODE
  printf("DEBUG_MODE is NOT defined → Release mode\n");
  write_log("Build mode: Release\n");
#else
  printf("DEBUG_MODE is defined → Debug mode\n");
  write_log("Build mode: Debug\n");
#endif

#ifdef ENABLE_LOG_FILE
  printf("ENABLE_LOG_FILE is defined → Logging is ENABLED\n");
  write_log("Logging: enabled\n");
#else
  printf("ENABLE_LOG_FILE is NOT defined → Logging is DISABLED\n");
#endif
}

/*
 * ---------------------------------------------------------------------------
 * POSIX LOG ROTATION:
 * If the log file exceeds MAX_LOG_SIZE, rotate it to *.1.txt
 * ---------------------------------------------------------------------------
 */
void write_log(const char *str)
{
#ifdef ENABLE_LOG_FILE
  struct stat st;
  int fd;

  if (stat(LOG_FILENAME, &st) == 0 && st.st_size >= MAX_LOG_SIZE)
  {
    unlink(LOG_ROTATED_NAME);               /* Remove old rotated log */
    rename(LOG_FILENAME, LOG_ROTATED_NAME); /* Rotate current log */
  }

  fd = open(LOG_FILENAME, O_WRONLY | O_CREAT | O_APPEND, 0644);
  if (fd >= 0)
  {
    write(fd, str, strlen(str));
    close(fd);
  }
#endif
}

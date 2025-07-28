/*
 * ===========================================================================
 *
 *   Filename:     12_logic_ops_full.c
 *
 *   Description:  Demonstrates relational, conditional, unary and ternary ops
 *
 *   Version:      1.0
 *   Created:      07/28/2025 23:00:00 PM
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
const char *msg = "\nAll Logic Operators in Action\n\n";

/* --- function signatures -------------------------------------------------*/
int print_header(void);
void test_relational(int x, int y, int z);
void test_conditional(int x, int y, int z);
void test_unary(int x);
void test_ternary(int score);

/* --- main function -------------------------------------------------------*/
int main(int argc, char *argv[])
{
  (void)argc;
  (void)argv;

  int a = 0, b = 0, c = 0, grade = 0;

  if (print_header() != 0)
    return 1;

  printf("Enter three integers (x, y, z): ");
  scanf("%d %d %d", &a, &b, &c);

  test_relational(a, b, c);
  test_conditional(a, b, c);
  test_unary(a);

  printf("\nEnter your score (0-100): ");
  scanf("%d", &grade);
  test_ternary(grade);

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

/*
 * Relational operators: ==, !=, <, >, <=, >=
 */
void test_relational(int x, int y, int z)
{
  printf("\n--- Relational Operators ---\n");

  if (x == y) printf("x == y → true\n");
  if (x != y) printf("x != y → true\n");
  if (x > z)  printf("x > z → true\n");
  if (y < z)  printf("y < z → true\n");
  if (x >= 0) printf("x >= 0 → true\n");
  if (z <= 100) printf("z <= 100 → true\n");
}

/*
 * Conditional (logical) operators: &&, ||, !
 */
void test_conditional(int x, int y, int z)
{
  printf("\n--- Conditional Operators ---\n");

  if (x > 0 && y > 0)
    printf("(x > 0 && y > 0) → both positive\n");

  if (x < 0 || z < 0)
    printf("(x < 0 || z < 0) → at least one negative\n");

  if (!(x == y))
    printf("!(x == y) → x is not equal to y\n");

  if ((x + y) > z && z != 0)
    printf("(x+y > z && z != 0) → combined true\n");

  if (x == y || z == 999)
    printf("(x == y || z == 999) → one is true\n");
}

/*
 * Unary operators: +, -, ++, --, !
 */
void test_unary(int x)
{
  printf("\n--- Unary Operators ---\n");

  int a = +x;      // explicit positive
  int b = -x;      // negation
  int c = x;       
  int d = x;

  printf("Value: x = %d\n", x);
  printf("Unary plus (+x): %d\n", a);
  printf("Unary minus (-x): %d\n", b);
  printf("Pre-increment (++x): %d\n", ++c);  // increment then use
  printf("Post-decrement (x--): %d (after = %d)\n", d--, d);  // use then decrement

  if (!0)
    printf("Logical NOT (!0) → true\n");
}

/*
 * Ternary operator: (cond) ? value_if_true : value_if_false
 */
void test_ternary(int score)
{
  printf("\n--- Ternary Operator ---\n");

  const char *result = (score >= 90) ? "Excellent" :
                       (score >= 70) ? "Approved"  :
                       (score >= 50) ? "Recovery"  : "Failed";

  printf("Score = %d → Result: %s\n", score, result);
}


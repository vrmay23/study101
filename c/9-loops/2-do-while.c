
#include <stdio.h>
#include <stdint.h>

#define INF_LOOP   1
#define MULT_TABLE 2

int menu(void);
void clear(void);
void infinity_loop (void);
void print_multiplication_table(uint8_t n);
void print_multiplication_table_menu (void);

int main(void){
  int ret = menu();

  if (ret == INF_LOOP) infinity_loop();
  else if (ret == MULT_TABLE) print_multiplication_table_menu();
  else 
  {
    printf("Wrong input. Please, try again!");
    clear();
    ret = menu();
  }

  return 0;
}

int menu(void)
{
  int ret = 0;
  
  do{
     printf("=========================================\n");
     printf("============  Make your choise ==========\n");
     printf("                                         \n");
     printf("        1 - InfinityLoop()               \n");
     printf("        2 - MultiplicTable()             \n");
     printf("                                         \n");
     printf("=========================================\n");
     printf("\n");
     printf("CHOICE: \t");
     scanf(" %d", &ret);
  
  } while(ret != INF_LOOP && ret != MULT_TABLE);

  return ret;
}

void infinity_loop()
{
  while(1)                                                  /* infinity loop*/
  {
    int i = 0;
    while (i < 10)
    {
       printf("Hello, world!\n");
       ++i;
    }
    printf("\n================== Finish! ===============\n");
  }
}

void print_multiplication_table_menu (void){
    printf("Please, inform one integer number: \t");
    int n;
    scanf("%d", &n);
    
    print_multiplication_table(n);
}

void print_multiplication_table(uint8_t n)
{
    char i   = 0;
    char res = 0;

    while(i<=10)
    {
      res = n*i;
      printf("%d * %d = %d\n", n, i, res);
      i++;
    }
}

void clear()
{
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");

}
#include <stdio.h>
#include <stdlib.h>

int main() {
  int num = 4;
  int num_tmp = num;
  int values[num];

  printf("Enter %d integers: \n", num);

  for(int i = 0; i < num; ++i) {
     scanf("%d", &values[i]);
  }

  printf("Displaying Variable: \n");

char name_values[] = {'a', 'b', 'c', 'd'};
  for(int i = 0; i < num; ++i) {
     printf("Variable is %c and value %d\n", name_values[i], values[i]);
  }

  printf("Displaying Change Variable: \n");

   for (int count = num - 1; count >= 0; count--)  {
     int antivar = num - num_tmp; //считаем в обратную сторону для массива с именами переменных
     int n = abs(antivar);
     printf("Variable change is %c and value %d\n", name_values[n], values[count]);
     num--;
  }


  return 0;
}

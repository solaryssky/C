#include <stdio.h>
#include <stdlib.h>

int main() {
  // размер массива должен быть константой
  // лучше использовать более понятные имена
  const int size = 4;
  int values[size];

  printf("Enter %d integers: \n", size);

  for(int i = 0; i < size; ++i) {
     scanf("%d", &values[i]);
  }

  printf("Displaying Variable: \n");

  // с буквами можно чуть проще, так как их ascii коды идут по очереди 
  for(int i = 0; i < size; ++i) {
     printf("Variable is %c and value %d\n", 'a' + i, values[i]);
  }

  printf("Displaying Change Variable: \n");

  // переменные лучше объявлять как можно ближе к месту первого использования
  int size_tmp = size;

  // лучше в циклах использовать индексы i,j,k - это короче и любой программист поймет
  for (int i = size - 1; i >= 0; --i)  {
     int antivar = size_tmp - size; //считаем в обратную сторону для массива с именами переменных
     int n = abs(antivar);

     // тут для примера тоже с кодами символов поэксперементировала
     printf("Variable change is %c and value %d\n", 'd' - (size - size_tmp), values[i]);
     size_tmp--;
  }


  return 0;
}

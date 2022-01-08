#include <stdio.h>
#include <stdlib.h>
#define N 365

// Описание структуры:
typedef struct MyMoney{
   double money;//сумма
   double rate;//процент
   int times;//срок дней
}Money;

// Функция для вычисления итоговой суммы по вкладу:
double getMoney(Money obj){

   // Переменная для записи результата:
   double s = obj.money;
   s = (obj.money*obj.rate*obj.times/N)/100;
   return s;
}
// Функция для отображения значений 
// экземпляра структуры и сумм по вкладу
void show(Money obj){
   printf("Начальная сумма: %.2f\n",obj.money);
   printf("Процентная ставка: %.2f\n",obj.rate);
   printf("Время вклада(дней): %d\n",obj.times);
   printf("Сумма начисленных процентов: %.2f\n", getMoney(obj));
   printf("Итоговая сумма: %.2f\n", getMoney(obj)+obj.money);

double arr_tmp[N];
int d = obj.times;

//массив процентов по дням, начиная с максимальных процентов в обратном порядке
for(int k=1; k<=obj.times; k++){
    arr_tmp[k] = getMoney(obj)/k;
    printf("Процент за %d день вклада: %.2f\n", d--, arr_tmp[k]);
   }
}

int main(void){

double dengi,procent,srok;
char dosroch[0];    

//инициализация структуры:
   printf("Введите сумму:\n");
   scanf("%lf",&dengi); 
   printf("Введите ставку процента:\n");
   scanf("%lf",&procent);
   printf("Введите срок вклада(дней):\n");
   scanf("%lf",&srok);
   printf("Досрочное закрытие(y/n):\n");
   scanf("%s",dosroch);
   
   //если досрочное закрытие - снижаем ставку на 2%
   if(dosroch[0] == 'y'){
      procent = procent - 2;
      printf("%.2f\n", procent); 
   }
   
   Money objA={dengi,procent,srok};
   
   //выполняем функцию по возврату рассчетов
   show(objA);
   printf("\n");
   return 0;
}

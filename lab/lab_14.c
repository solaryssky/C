#include <stdio.h>
#include <stdlib.h>
 
int main(void) {
    //установили курс
    float dollar = 73.77;
    float euro = 83.14;
    float funt = 98.41;
 
    printf("Пересчет валют: \n");
    printf("Доллар к рублю: %.2f\n", dollar);
    printf("Евро к рублю: %.2f\n", euro);
    printf("Фунт стерлинга к рублю: %.2f\n", funt);

    printf("\nВведите число для выполнения операции: \n");
    printf("Перевести RUB->USD введите: 1\n");
    printf("Перевод RUB->EUR введите: 2\n");
    printf("Перевод RUB->GBP введите: 3\n");
 
    int number = 0;
    float summ = 0.0, result = 0.0;
 
    scanf("%d", &number);
    printf("Введите сумму: \n");
    scanf("%f", &summ);
    switch (number) {
        case 1:
            result = summ / dollar;
            printf("USD: %.2f\n", result);
            break;
 
        case 2:
            result = summ / euro;
            printf("EUR: %.2f\n", result);
            break;
 
        case 3:
            result = summ / funt;
            printf("GBP: %.2f\n", result);
            break;
        default:
            printf("Вы ввели не корректное число!");
            break;
    }
 
    return 0;
}

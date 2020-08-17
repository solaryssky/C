#include<stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
	double x, grav;
	printf("Enter your weight\n");

	scanf("%lf", &x);

	if(x < 0) {
        	printf("Error negative value!\n");
		// exit(0); - системный вызов, сразу прекращает работу всей программы
		return 1;
      	} else {
		// правильно, но нечитабельно - присваивание теряется среди другого кода
		// printf("Gravity will be for weight %.4f is %.4f H\n", x, grav = x * 9.8);
		
		// лучше:
		grav = x * 9.8;
		printf("Gravity will be for weight %.4f is %.4f H\n", x, grav);
		
		// еще один вариант (меньше кода и переменная grav не нужна вообще)
		// printf("Gravity will be for weight %.4f is %.4f H\n", x, x * 9.8);
	}

  	return 0;
}

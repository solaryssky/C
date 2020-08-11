#include<stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
	double x, grav;
	printf("Enter your weight\n");

	scanf("%lf", &x);

	if(x < 0)
     {
        printf("Error negative value!\n");
				exit(0);
      }
			else{
				printf("Gravity will be for weight %.4f is %.4f H\n", x, grav = x * 9.8);
			}

  return 0;



}

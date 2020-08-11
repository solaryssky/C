#include<stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
	double x;
	printf("Enter digit\n");

	scanf("%lf", &x);

	if(x < 0)
     {
        printf("Negative value\n");
				exit(0);
      }
			else{
				printf("The square root of %.4f is %.4f\n", x, sqrt(x));
			}

  return 0;



}

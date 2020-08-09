#include<stdio.h>

int main(){
	int a = 1111, b = 355;
	const int  a_const = 111;
        int c = a;

        a = b;

        b = c;

	printf("Hello %d %d %d \n", a, b, c);


	return 0;



}

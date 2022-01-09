#include <stdio.h>

float f(float x){
            return x*x*x+x*x+x+1;
        }

  float d2d(float a, float b, float eps){
        float c;
      
        
        while(b -a > eps){
            c = (a+b)/2;
            if( f(a)*f(c) < 0) {
               b = c; 
            }
            else{
                a = c;
            }
        }
        return (a+b)/2;
  }

int main(void)
{
    //a начало интервала
    float a = -2, b = 1, eps = 0.001;
        
        
        printf("%6.3f", d2d(a, b, eps));

    return 0;
}


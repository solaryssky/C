#include <stdio.h>
#include <string.h>
#define N 256
int main ()
{
    char s[] = "Rust is cooler than C!";
    
    //256 символов ASCII
    int cnt[N] = {0};
     //условие пока указатель указывает не на нулевой символ завершающий строку
    for(char * c = s; *c; cnt[(unsigned char)*c++]++);

    for(int i = 0; i < N; ++i)
     if (cnt[i])
      if(((char)i != 'A' || (char)i != 'E' || (char)i != 'I' || (char)i != 'O' || (char)i != 'U' || (char)i != 'Y')){
            printf("%c -- %d\n", (char)i, cnt[i]);
        }
}

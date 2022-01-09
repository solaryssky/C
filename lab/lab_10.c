#include <stdio.h>
#include <stdlib.h>

int main(){
    //создаем пустую струкруту с алиасом WORKER
    typedef struct{
        char* fio;
        char* staff;
        int year;

    }WORKER;

    int itter=3, x, age, number, current = 2021;
    
	//определяем размер типа структуры через указатель *base и динамически выделяем память через malloc
    WORKER* base = malloc(itter * sizeof *base);
    
    for (x = 0; x < itter; x++){      
		//определяем размер для массива fio
		base[x].fio = (char*)malloc(sizeof(char*));
		printf("Enter FIO\n");
		scanf("%s",base[x].fio);
		
		//определяем размер для массива staff
        base[x].staff = (char*)malloc(sizeof(char*));
		printf("Enter position\n");
		scanf("%s",base[x].staff);
		
		printf("Enter year\n");
        scanf("%d",&base[x].year);
        
    }  
    printf("Enter need age\n");
    scanf("%d", &age);

    //в цикле выводим значения наших массивов структур
	for (x = 0; x < itter; x++)
	
	   if(age < current-base[x].year){
    printf("fio:%s,staff:%s,year:%d%d\n",base[x].fio,base[x].staff,base[x].year, current-base[x].year);
	   }

    return 0;
}

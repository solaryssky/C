#include <stdio.h>

int main()
{
    char fname[100], fkey[255], ch;
	int arr[1] = {0};
	//f_in - указатель на входной файл 
	//f_tmp - указатель на временный файл
	//fk - указатель на файл ключа
	FILE *f_in, *f_tmp, *fk;
	
	printf("Key file name:\n");
	scanf("%s",fkey);
	
	printf("Input file name:\n");
	scanf("%s",fname);
	
	//читаем ключ из файла
	fk = fopen(fkey, "r");
	for (int i = 0; i < 1; i++) {
        fscanf(fk, "%d", &arr[i]);
    }
	//закрыли дескриптор
	fclose(fk);
	//printf("%d",  arr[0]);
	
    f_in = fopen(fname, "r");
    //если fopen не открыл файл и вернул NULL - то выходим с кодом 0
	if(f_in == NULL){
        return 0;
	}
	
	//временный файл открыли на запись
    f_tmp = fopen("temp.txt", "w");
    if(f_tmp == NULL){
        return 0;
	}
    ch = fgetc(f_in);
	
	//читаем файл пока не достигнем конца EOF и     
	while(ch != EOF){
	//читаем посимвольно и к ASCII-коду символа прибавляем значение из файла-ключа, сдвигая тем самым код символа
        ch = ch+arr[0];
    //пишем во временный файл  		
        fputc(ch, f_tmp);
        ch = fgetc(f_in);
    }
    
	//закрыли дескрипторы
	fclose(f_in);
    fclose(f_tmp);
	
    f_in = fopen(fname, "w");
    if(f_in == NULL){
        return 0;
	}
	
	//временный файл открыли на чтение
    f_tmp = fopen("temp.txt", "r");
    if(f_tmp == NULL){ 
	return 0; 
	}
    ch = fgetc(f_tmp);
    
	//записываем результат обратно в входной файл
	while(ch != EOF){
        ch = fputc(ch, f_in);
        ch = fgetc(f_tmp);
    }
	
    fclose(f_in);
    fclose(f_tmp);
	
    printf("\nDone! File %s encrypt!\n", fname);
    return 0;
}

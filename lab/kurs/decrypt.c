#include <stdio.h>

int main()
{
    char fname[20], ch, fkey[255];
	int arr[1] = {0};
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
	
	
    f_in = fopen(fname, "w");
    if(f_in == NULL){
        return 0;
}
    f_tmp = fopen("temp.txt", "r");
    if(f_tmp == NULL){
        return 0;
}
    ch = fgetc(f_tmp);
    while(ch != EOF){
        ch = ch-arr[0];
        fputc(ch, f_in);
        ch = fgetc(f_tmp);
    }
    fclose(f_in);
    fclose(f_tmp);
    printf("\nDone %s file decrypted!\n", fname);
    return 0;
}

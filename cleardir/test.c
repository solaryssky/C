#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


void listdir(const char *name, int indent, int td)
{
    DIR *dir;
    struct dirent *entry;
    struct stat buff;


    if (!(dir = opendir(name))){
      perror(name);
      return;
    }
    chdir(name);

    while((entry = readdir(dir)) != NULL){
		
		char path[1024];
		int len = snprintf(path, sizeof(path)-1, "%s/%s", name, entry->d_name); // get depth
		
        if(entry->d_type == DT_DIR){
			

            if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0){
                continue;
              }
			

              stat(entry->d_name, &buff);
			  
			  
			  //struct timespec st_atim;        /* Time of last access.  */
              //struct timespec st_mtim;        /* Time of last modification.  */
              //struct timespec st_ctim;        /* Time of last status change.  */


                time_t times = buff.st_mtim.tv_sec; //buff.st_ctim.tv_sec;
                time_t seconds;
				seconds = time(NULL); //current unixtime
		   long diff_sec = seconds - 86400*td;//1 day second * day	
			
			if(buff.st_mtim.tv_sec < diff_sec){
                //fprintf(stdout, "%s [%s] (%d)\n", name, entry->d_name, indent+1);
			     // Append fullPath to entry->d_name here
                   					  

				 printf("%s/%s/ %ld %s %ld %ld\n", name, entry->d_name, buff.st_mtim.tv_sec, ctime(&times), seconds, diff_sec);
				 listdir(path, indent + 1, td);
				}
				
				//printf("%s %s\n", entry->d_name, ctime(&times)); //



        }
    }
    closedir(dir);
    chdir("..");
}

int main(int argc, char *argv[]){
	
	if(argc != 3)
    {
        fprintf(stderr, "usage: %s [int time in day, example: 30] [path, example: /var/opt]\n", argv[0]);
        return 1;
    }
	
    char *a = argv[1];
    int td = atoi(a);
	
	char *tpath = strdup(argv[2]);
	
    listdir(tpath, 0, td);
    
    return 0;
}

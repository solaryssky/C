#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>
#include <string.h>

int main(int argc, char *argv[])
{   
 
 if(argc < 2) {
    printf("Not set arguments. Example: used -[u|t|a] <mount point>\n");
    exit(EXIT_SUCCESS);
    }
	
    char *keys = argv[1];
    char *pathes = argv[2];
		
	if (argv[2] == NULL){
		pathes = "/";
		}	
	
	
    //printf("Path %s\n", pathes);
    
    const unsigned int GB = (1024 * 1024) * 1024;
    struct statvfs buffer;
	
	
    int ret = statvfs(pathes, &buffer);

    if (!ret) {
        const double total = (double)(buffer.f_blocks * buffer.f_frsize) / GB;
        const double available = (double)(buffer.f_bfree * buffer.f_frsize) / GB;
        const double used = total - available;
        const double usedPercentage = (double)(used / total) * (double)100;
        
		if (strcmp("-t", keys) == 0) {
		printf("Total: %f --> %.0f\n", total, total);
		}
		else if (strcmp("-a", keys) == 0) {
        printf("Available: %f --> %.0f\n", available, available);
		}
		else if (strcmp("-u", keys) == 0) {
        //printf("Used: %f --> %.1f\n", used, used);
		printf("%.0f\n", used);
		}
		else if (strcmp("-p", keys) == 0) {
        printf("Used Percentage: %f --> %.0f\n", usedPercentage, usedPercentage);
		}
    }
    return ret;
}

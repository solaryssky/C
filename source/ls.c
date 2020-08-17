#include <stdio.h>
#include <dirent.h>
#include <string.h>

#define GREEN "\x1b[32m"
#define BLUE "\x1b[34m"
#define WHITE "\x1b[37m"

void Usage() {
    fprintf(stderr, "\nUsage: exec [OPTION]... [DIR]...\n");
    fprintf(stderr, "List DIR's (directory) contents\n");
    fprintf(stderr, "\nOptions\n-R\tlist subdirectories recursively\n");
    return;
}

void RecDir(char * path, int flag) {
    DIR * dp = opendir(path);
    if(!dp) {
        perror(path);
        return;
    }
    struct dirent * ep;
    char newdir[512];
    printf(BLUE "\n%s :\n" WHITE, path);
    while((ep = readdir(dp)))
        if(strncmp(ep->d_name, ".", 1))
            printf(GREEN "\t%s\n" WHITE, ep->d_name);
    closedir(dp);
    dp = opendir(path);
    while((ep = readdir(dp))) if(strncmp(ep->d_name, ".", 1)) {
        if(flag && ep->d_type == 4) {
            sprintf(newdir, "%s/%s", path, ep->d_name);
            RecDir(newdir, 1);
        }
    }
    closedir(dp);
}

int main(int argc, char ** argv) {
    switch(argc) {
    case 2:
        if(strcmp(argv[1], "-R") == 0) Usage();
        else RecDir(argv[1], 0);
        break;
    case 3:
        if(strcmp(argv[1], "-R") == 0) RecDir(argv[2], 1);
        else Usage();
        break;
    default: Usage();
    }
    return 0;
}

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void listdir(const char *name, int indent)
{
    DIR *dir;
    struct dirent *entry;
    struct stat buff;


    if (!(dir = opendir(name))){
        return;
      }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            //char path[1024];

            //если значение элемента d_name структуры не верхний уровень, то продолжаем цикл
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0){
                continue;
              }
              //
              stat(entry->d_name, &buff);

              time_t times = buff.st_ctim.tv_sec;

              printf("%s %s", entry->d_name, ctime(&times)); //

              listdir(entry->d_name, indent + 1);


            //snprintf(path, sizeof(path), "%s/%s", name, entry->d_name);
            //printf("%*s[%s]\n", indent, "", entry->d_name);
            //listdir(path, indent + 2);


        }
    }
    closedir(dir);
}

int main(void) {
    listdir(".", 0);
    return 0;
}

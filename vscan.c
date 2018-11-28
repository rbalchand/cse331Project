#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
/* "readdir" etc. are defined here. */
#include <dirent.h>
int scanVirus(char filename[], char sequence[])
{
    size_t bytes_read;
    FILE *fp = fopen(filename,"rb");
    
    int size_sequence = 0;
    if(fp == NULL){
        return 1;
    }
    else{
        size_sequence = strlen(sequence);
        unsigned char buffer[100];
        bytes_read = fread(buffer,size_sequence,1,fp);
        printf("%s\n", buffer);
        unsigned char buffer1[100];  
        fseek(fp,1,SEEK_SET);
        bytes_read = fread(buffer1,size_sequence,1,fp);
        printf("%s\n", buffer1);
        return 0; 
    }
    fclose(fp);
    return 0;
    
}
void listdir(const char *name,char sequence[])
{
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(name)))
        return;

    while ((entry = readdir(dir)) != NULL) {
            char path[1024];
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
            snprintf(path, sizeof(path), "%s/%s", name, entry->d_name);
            printf("%s\n", entry->d_name,sequence);
            listdir(path);
    }
    closedir(dir);
}

int main (int argc, char* argv[])
{
    listdir(argv[1],);
    return 0;
}

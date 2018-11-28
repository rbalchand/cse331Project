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
    FILE *fp = fopen(filename,"r");
    
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

void scanDir(char *basePath)
{
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);

    // Unable to open directory stream
    if (!dir)
        return;

    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            
            //Here is the comparing algorithm we should put for the file
            printf("%s\n", dp->d_name);
            scanVirus(dp->d_name, "ok");
            // Construct new path from our base path
            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);

            scanDir(path);
        }
    }

    closedir(dir);
}

 int main (int argc, char* argv[])
{
    scanDir(argv[1]);
    return 0;
}

#ifndef LIB
#define LIB

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>

char * parseCommandLine(FILE* fp, size_t baseLength);
char * printFolderContents(const char * folderString);

//BOOLEAN FUNCTIONS
//0 is true
//1 is false
int isValidPath(const char * filePath);
int isValidFolder(const char * folderPath);

#endif

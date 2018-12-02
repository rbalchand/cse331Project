#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>


//Dynamically allocate data for a string input to the command line
char * parseCommandLine(FILE* fp, size_t baseLength){
  char * finalString;
  int c;
  finalString = realloc(NULL, sizeof(char)* baseLength);
  int length = 0;
  if(!finalString){
    return finalString;
  }
  while( ((c = fgetc(fp)) != EOF) && c != '\n'){
    finalString[length++] = c;
    if(baseLength == length){
      finalString = realloc(finalString, sizeof(char)* (baseLength += 16));
      if(!finalString){
	return finalString;
      }
    }
  }
  finalString[length++] = '\0';
  return realloc(finalString, sizeof(char) * length);
}

char * printFolderContents(const char * folderString){
  char * ans = "";
  //printf("Sizeof Initial array: %d", ansLength);
  //prints and returns the string
  struct dirent *d;
  DIR *dir = opendir(folderString);
  if(dir == NULL){
    printf("\nError: could not open directory\n");
    
  }else{

    while((d = readdir(dir)) != NULL){
      char * fileName = d->d_name;
      printf("%s\n", fileName);
      const char ch = '.';
      char * fullPath = malloc(strlen(folderString) + strlen(fileName) + 2);
      strcpy(fullPath, folderString);
      strcat(fullPath, "\\");
      strcat(fullPath, fileName);
      const char * fileNameConst = (const char *)fullPath;
      if(strchr(fileNameConst, ch) == NULL){
	printf("Scanning subfolder %s...\n", fileNameConst);
	//found another folder
	char * temp = printFolderContents(fileNameConst);
      }
      free(fullPath);
      //printf("%s \n", fileName);
      //strcat(ans, d->d_name);
      //strcat(ans, "\n");
    }
  }
  closedir(dir);
  return ans;

}



//BOOLEAN FUNCTIONS
//functions return 1 if false, and then returns 0 for true

int isValidPath(const char * filePath){
  const char * constFilePath = (const char *)(filePath);
  struct stat structStat;
  if((stat(constFilePath, &structStat)) < 0){
    return 1;
  }else{
    return 0;
  }
}


int isValidFolder(const char * folderPath){
  const char * constFolderPath = (const char *)(folderPath);
  struct stat structStat;
  if((stat(constFolderPath, &structStat)) < 0){
    return 1;
  }else{
    return 0;
  } 
}



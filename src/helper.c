#include <stdio.h>
#include <stdlib.h>


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

  



//RONALD BALCHAND
//CSE 331
//CLASS PROJECT
//Project 2: Antivirus for Linux
//MAIN FILE
#include <stdio.h>
#include <stdlib.h>
#include "helper.h"
#include <string.h>


int main(int argc, char** argv){
  //first read from input
  char * inputString;
  printf("Please enter the path of the directory you wish to scan: \n");
  inputString = parseCommandLine(stdin, 10);
  int folderOrFile = -1;//first boolean to test whether the entered string is a file or folder
  int validPath = -1; //boolean to test whether entered "folder or file" is valid
  const char ch = '.';
  const char * inputConst = (const char *)inputString;
  if(strchr(inputConst, ch) != NULL){
    //file with extension
    folderOrFile = 1;
  }else{
    //folder
    folderOrFile = 2;
  }
  printf("inputString scanned: folder or file flag value: %d\n", folderOrFile);
  if(folderOrFile == 1){
    validPath = isValidPath(inputConst); 
  }else{
    validPath = isValidFolder(inputConst);
  }


  if(validPath == 1){//testing return value of the path searching folder
    printf("Your entry was not valid\n");
  }else{
    
    //if its a folder search through all files in folder
    if(folderOrFile == 2){
      printf("You entered a valid Folder name\n");
      printf("Scanning Folder...\n");
      char * fileList = printFolderContents(inputConst);
      printf("%s\n", fileList);
      //free(fileList);
    }
    //if its a  file scan the file
    
  }
  printf("You entered: %s\n", inputConst);
  free(inputString);
  return 0;
  
}



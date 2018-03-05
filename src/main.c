//RONALD BALCHAND
//CSE 331
//CLASS PROJECT
//Project 2: Antivirus for Linux
//MAIN FILE
#include <stdio.h>
#include <stdlib.h>
#include "helper.h"

int main(int argc, char** argv){
  //first read from input
  char * inputString;
  printf("Please enter the path of the directory you wish to scan: \n");
  inputString = parseCommandLine(stdin, 10);
  printf("You entered: %s\n", inputString);
  free(inputString);
  return 0;
  
}



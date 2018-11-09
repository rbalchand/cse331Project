#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main (int argc, char* argv[]) {
	FILE *fp;

	/* Open file for both reading and writing */
	fp = fopen(argv[1], "r");
    char *buffer = (char*)malloc(sizeof(char)*512);
    /* Seek to the beginning of the file */
    fseek(fp, 0, SEEK_SET);

    /* Read and display data */
	int x=0;
	while(fread(&buffer, 1, 128, fp+x*128)==128)
	{
    	printf("%X\n",(unsigned int) buffer);
   		x+=1;
		printf("%d\n",x);
		if(x>4){
			break;
		}
		rewind(fp);
	}
    fclose(fp);
   
    return(0);
}

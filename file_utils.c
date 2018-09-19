#include "file_utils.h"
#include <sys/stat.h>

/****************************************************************
 *This is the function C file for running the reverse file method
 *@Version Sept./2018
 *@Author: Runquan Ye
 ****************************************************************/

/****************************************************************
 *This method is going to read the file's content into buffer
 ****************************************************************/
int read_file(char* filename, char** buffer){
	
		
	struct stat st;
	stat(filename,&st);
	int size = st.st_size;
	
	FILE *file1 = fopen(filename,"r");
	//fseek(file1, 0, SEEK_END); 
	//long size = ftell(file1); 
	//fseek(file1, 0, SEEK_SET); 
	
    
    	//fread(*buffer,sizeof(char), size, file1); 
    	fread(*buffer, size, 1, file1); 
	return 0;

}



/****************************************************************
 *This method is going to write into the next file
 ****************************************************************/
int write_file(char* filename, char *buffer, int size){
	FILE *file2 = fopen(filename,"r");
	fwrite(buffer, size, 1, file2); 

}

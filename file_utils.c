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
	
	//get the file's size	
	struct stat st;
	stat(filename,&st);
	int size = st.st_size;
	
	//open the file
	FILE *file1 = fopen(filename,"r");
	
	//read the file content and store it into the buffer
    	fread(*buffer, size, 1, file1); 
	
	return 0;

}



/****************************************************************
 *This method is going to write into the next file
 ****************************************************************/
int write_file(char* filename, char *buffer, int size){
	//open or create the output file
	FILE *file2 = fopen(filename,"w");
	
	//write the buffer context into the output file
	fwrite(buffer, size, 1, file2); 
	
	return 0;
}

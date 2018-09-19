#include "file_utils.h"
#include "file_utils.c"

/******************************************************************************
 *This is the main file for running the reverse file method for this assignment
 *@Version Sept./2018
 *@Author: Runquan Ye
 *****************************************************************************/



int main(int argc, char** argv){
	int i;
	char ch, ch1;
	FILE *file1, *file2;
	//char* buffer, buffer2;
	long size;

	file1 = fopen(argv[1], "r");
	
	if(file1 == NULL){
		printf("The file cannot be read.\n");
		return 1;
	}else{
		fseek(file1, 0, SEEK_END); 
		size = ftell(file1); 
	    	fseek(file1, 0, SEEK_SET);  
	    
	    
	    	char* buffer = (char*) malloc(size * sizeof(char));

	    	char* buffer2 = (char*) malloc(size * sizeof(char));

	    	fread(buffer, sizeof(char), size, file1); 
		//read_file(argv[1], &buffer);
	    
	    	for(int i = 0; i < size; ++i){
	    	
			buffer2[i] = buffer[size-i];
	    	}
	}

	file2 = fopen(argv[2], "w");
	
	if(file2 == NULL){
		printf("The result cannot be write.\n");
		return 3;
	}else{
		//write_file(argv[2], buffer, size);
		fwrite(buffer2, sizeof(char), size, file2); 
	}
	free(buffer2);
	free(buffer);
	
	fclose(file1);
	fclose(file2);
    
	return 0;
	
}


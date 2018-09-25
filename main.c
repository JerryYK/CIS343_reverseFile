#include "file_utils.h"

/******************************************************************************
 *This is the main file for running the reverse file method for this assignment
 *@Version Sept./2018
 *@Author: Runquan Ye
 *****************************************************************************/



int main(int argc, char** argv){
	FILE *file1;
       	FILE *file2;
	struct stat st;
	stat(argv[1],&st);
	int size = st.st_size;
	char* buffer;
	char* outputBuffer;

	//open input file as file1
	file1 = fopen(argv[1], "r");
	
	//error exception handler for file1
	if(file1 == NULL){
		printf("The file cannot be read.\n");
		return 1;
	}

	//malloc the heap memory for storing the reading result of the input file
	buffer = (char*) malloc(size * sizeof(char));

	//malloc the heap memory for storing the result after filping the buffer char
	outputBuffer = (char*) malloc(size * sizeof(char));

	read_file(argv[1], &buffer);
	
	//fliping the char in the buffer 
	for(int i = 0; i < size; ++i){
		outputBuffer[i] = buffer[size - i - 1];
	}
	
	//open the output file
	//if the output file doesn't exist, it will be created
	file2 = fopen(argv[2], "w");
	
	//error exception handler for file2
	if(file2 == NULL){
		printf("The result cannot be write.\n");
		return 2;
	}else{
		write_file(argv[2],outputBuffer, size);
	}

	//free the heap memory for the outputBuffer
	free(outputBuffer);

	//free the heap memory for the buffer
	free(buffer);

	//close the input file1	
	fclose(file1);

	//close the output file2
	fclose(file2);
    
	return 0;
	
}

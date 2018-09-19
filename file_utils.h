#ifndef H_FILE_UTILS
#define H_FILE_UTILS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>


/****************************************************************
 *This is the function h file for function c file
 *@Version Sept./2018
 *@Author: Runquan Ye
 ****************************************************************/



/****************************************************************
 *This method is going to read the file's content into buffer
 ****************************************************************/
int read_file(char* filename, char** buffer);



/****************************************************************
 *This method is going to write into the next file
 ****************************************************************/
int write_file(char* filename, char *buffeer, int size);

#endif

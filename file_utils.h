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

struct stat st;
stat(filename, &st);
int size = st.st_size;

int read_file(char* filename, char** buffer);
int write_file(char* filename, char *buffeer, int size);

#endif

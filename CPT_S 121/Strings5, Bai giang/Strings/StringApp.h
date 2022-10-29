#ifndef STRINGS_APP_H
#define STRINGS_APP_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h> // atoi ()

// struct
typedef struct student
{
	char last[30];
	char first[30];
	int id;
} Student;

char* my_strcpy(char dest[], const char src[]);
char* my_strcpy_ptr(char *dest, const char *src);

#endif
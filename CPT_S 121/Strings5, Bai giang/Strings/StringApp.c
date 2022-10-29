#include "StringApp.h"

char* my_strcpy(char dest[], const char src[])
{
	int index = 0;
	for (; src[index] != '\0'; ++index)
	{
		dest[index] = src[index];
	}

	// copy null character into the dest
	dest[index] = '\0';

	return dest; // dest is an address; of first character
}

char* my_strcpy_ptr(char* dest, const char* src)
{
	int index = 0;

	for (; *(src + index) != '\0'; ++index)
	{
		*(dest + index) = *(src + index);
	}
	*(dest + index) = '\0';

	// *(dest + index) == dest[index]

	return dest;
}
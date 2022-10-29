
/*

  This is the header file that stores standard library includes, #defined and function prototypes

*/


#ifndef HEADER_H //guard code

#define HEADER_H


#define _CRT_SECURE_NO_WARNINGS //ignore the error about scanf()

#include<stdio.h> //necessary to use printf() and scanf()




//Function prototype





//All the function prototypes for task 1



/*
  Function:    char* string_reverse ()

  Date Created: Mar 25, 2021

  Date Last Modifiled: Mar 25, 2021

  Description:  This function reverses the string by using array notation

  Input parameters:   a string

  Returns:   The pointer to the string

  Preconditions:    The string

  Postconditions:   The string has been reversed and the pointer has been returned
*/
char* string_reverse(char str[]);





/*
  Function:   char* string_reverse_ptr ()

  Date Created: Mar 25, 2021

  Date Last Modifiled: Mar 25, 2021

  Description:  This function reverses the string by using pointer notation

  Input parameters:  The pointer to the string

  Returns:    The pointer to the string

  Preconditions:   The pointer to the string

  Postconditions:   The string has been reversed and the pointer has been returned
*/
char* string_reverse_ptr(char* str);





//All the function prototypes for task 2


/*
  Function:   char* my_strcpy ()

  Date Created: Mar 25, 2021

  Date Last Modifiled: Mar 25, 2021

  Description:  This function copies all characters in the array pointed to by source into the array pointed to by destination

  Input parameters:  The pointer to the source array and the pointer to the destination array

  Returns:   The pointer to the destination array

  Preconditions:   The pointer to the source array and the pointer to the destination array

  Postconditions:   destination has been returned
*/
char* my_strcpy(char* destinaiton, const char* source);






/*
  Function:  char* my_strcat ()

  Date Created: Mar 25, 2021

  Date Last Modifiled: Mar 25, 2021

  Description:  This function appends a copy of the string pointed to by source (including the null character) to the end of the string pointed to by destination

  Input parameters:  The pointer to the source array and the pointer to the destination array

  Returns:   The string pointed to by destination

  Preconditions:   The pointer to the source array and the pointer to the destination array

  Postconditions:   The string pointed to by destination is returned
*/
char* my_strcat(char* destination, const char* source);







/*
  Function:   int my_strcmp ()

  Date Created: Mar 25, 2021

  Date Last Modifiled: Mar 25, 2021

  Description:  This function compares the string pointed to by s1 to the string pointed to by s2

  Input parameters:    The two string pointed to by s1 ans s2

  Returns:     If the string pointed to by s1 comes before the string pointed to by s2 in dictionary ordering, then -1 is returned.
               If the string pointed to by s1 is the same as the string pointed to by s2, then 0 is returned (the compare function is case sensitive). Otherwise 1 is returned.

  Preconditions:    The two string pointed to by s1 ans s2

  Postconditions:  0, 1, or -1 has been returned
*/
int my_strcmp(const char* s1, const char* s2);








/*
  Function:   int my_strlen ()

  Date Created: Mar 25, 2021

  Date Last Modifiled: Mar 25, 2021

  Description:  This function computes the length of the string pointed to by s

  Input parameters:  The string pointed to by s

  Returns:  The length of the string

  Preconditions:   The string pointed to by s

  Postconditions:  The length of the string has been returned
*/
int my_strlen(const char* s);


#endif

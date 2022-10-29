
/*

  This is the header file that stores standard library includes, #defined and function prototypes

*/


#ifndef HEADER_H //guard code

#define HEADER_H


#define _CRT_SECURE_NO_WARNINGS //ignore the error about scanf()

#include<stdio.h> //necessary to use printf() and scanf()

#include<stdlib.h>  //necessary to use rand() and srand()

#include<time.h>    //necessary to use time()




//Function prototype





//All the function prototypes for task 1



/*
  Function:

  Date Created: Mar 15, 2021

  Date Last Modifiled: Mar 15, 2021

  Description:

  Input parameters:

  Returns:

  Preconditions:

  Postconditions:
*/
void display_array(int integers[], int size);






//All the function prototypes for task 3



/*
  Function:

  Date Created: Mar 15, 2021

  Date Last Modifiled: Mar 15, 2021

  Description:

  Input parameters:

  Returns:

  Preconditions:

  Postconditions:
*/
void display_characters(char c[], int size);




/*
  Function:

  Date Created: Mar 15, 2021

  Date Last Modifiled: Mar 15, 2021

  Description:

  Input parameters:

  Returns:

  Preconditions:

  Postconditions:
*/
int is_win(char guess[], int size);






#endif

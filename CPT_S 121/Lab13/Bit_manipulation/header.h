
/*

  This is the header file that stores standard library includes, #defined and function prototypes

*/


#ifndef HEADER_H //guard code

#define HEADER_H


#define _CRT_SECURE_NO_WARNINGS //ignore the error about scanf()

#include<stdio.h> //necessary to use printf() and scanf()

#include<math.h>  //necessary to use pow()




//Function prototype





//All the function prototypes for task 1



/*
  Function:   void print_binary_form ()

  Date Created:     April 22, 2021

  Date Last Modifiled:    April 22, 2021

  Description:  This function prints an unsigned integer number in bits format

  Input parameters:    An unsigned integer

  Returns:    None 

  Preconditions:    The unsigned integer

  Postconditions:    The number has been displayed in bits format to the screen
*/
void print_binary_form(unsigned int n);



/*
  Function:   void print_binary_form_after_rightshift_4bits ()

  Date Created:     April 22, 2021

  Date Last Modifiled:    April 22, 2021

  Description:     This function prints an unsigned integer number in bits format after right shifting by 4 bits

  Input parameters:    An unsigned integer

  Returns:     None
    
  Preconditions:    The unsigned integer

  Postconditions:    The number has been displayed in bits format to the screen
*/
void print_binary_form_after_rightshift_4bits(unsigned int n);





//All the function prototypes for task 2


/*
  Function:   int power2 ()
   
  Date Created:     April 22, 2021

  Date Last Modifiled:    April 22, 2021

  Description:     This function uses the left shift operator to calculate a number * 2^pow

  Input parameters:    An unsigned integer number and the integer value of a pow

  Returns:    The result of the number * 2^pow

  Preconditions:    The unsigned integer number and the integer value of the pow

  Postconditions:   The result has been returned
*/
int power2(int number, int pow);







//All the function prototypes for task 3



/*
  Function:    unsigned int packCharacters ()

  Date Created:     April 22, 2021

  Date Last Modifiled:    April 22, 2021

  Description:     This function packs four characters into an unsigned integer number

  Input parameters:    Four characters

  Returns:    The unsigned integer number packed into

  Preconditions:     The four characters

  Postconditions:     The unsigned integer number has been packed into and returned
*/
unsigned int packCharacters(char c1, char c2, char c3, char c4);






#endif

/*

    This file is to establish the definitions for all programmer-defined functions, aside from main ()

*/


#include "header.h"



//All the defined functions for task 1


void print_binary_form(unsigned int n)
{
    int k = 0;
    for(k = 0; k >= 0; k+=4)    
    {
        if (pow(2, k) > n)
        {
            break;
        }
    }

    int l = k - 1;

    unsigned i;
    for (i = 1 << l; i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");

}




void print_binary_form_after_rightshift_4bits(unsigned int n)
{
    int k = 0;
    for (k = 0; k >= 0; k += 4)
    {
        if (pow(2, k) > n)
        {
            break;
        }
    }

    int l = k + 3;

    unsigned i;
    for (i = 1 << l; i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");

}



//All the defined functions for task 2

int power2(int number, int pow)
{
    /*Left shifting an unsigned integer by 1 bit is equivalent to multiplying the value 2
       Therefore, number * (2^pow) = number << pow
    */

    return (number << pow);
}



//All the defined functions for task 3

unsigned int packCharacters(char c1, char c2, char c3, char c4)
{
    //Assign the first character to the unsigned variable
    unsigned int i = c1;


    //Shift the unsigned variable left by 8 bit positions and combine the unsigned variable with the second character using the bitwise inclusive OR operator
    i = (i << 8) | c2;

    //Shift the unsigned variable left by 8 bit positions and combine the unsigned variable with the 3rd character using the bitwise inclusive OR operator
    i = (i << 8) | c3;

    //Shift the unsigned variable left by 8 bit positions and combine the unsigned variable with the 4th character using the bitwise inclusive OR operator
    i = (i << 8) | c4;

    return i;
}
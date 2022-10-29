
/*

    This file is to establish the definitions for all programmer-defined functions, aside from main ()

*/


#include "header.h"



//All the defined functions 
void display_array(int integers[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("arr[%d]: %d\n", i, integers[i]);
    }

}



void display_characters(char c[], int size)
{
    int i = 0;
    for (i; i < size; i++)
    {
        printf("%c", c[i]);
    }
}



int is_win(char guess[], int size)
{
    int flag = 1;

    for (int i = 0; i < size; i++)
    {
        if (guess[i] == '*')
        {
            flag = 0; break;
        }
    }


    return flag;   // 0 is not won yet, 1 is win
}
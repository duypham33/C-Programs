
/*

  This is the header file that stores standard library includes, #defined and function prototypes

*/


#ifndef HEADER_H //guard code

#define HEADER_H


#define _CRT_SECURE_NO_WARNINGS //ignore the error about scanf()

#include<stdio.h>   //necessary to use printf() and scanf()

#include<string.h>  //necessary to use to use strlen()

#include<stdlib.h>  //necessary to use rand() and srand()




#define NUM_DISKS 3








//Function prototype





//All the function prototypes for task 3



/*
  Function:   char* reverse_string ()

  Date Created:       April 15, 2021

  Date Last Modifiled:      April 15, 2021

  Description:  This function reverses a string by using recursion

  Input parameters:   A pointer to a string, a starting index and an ending index

  Returns:   The pointer to the reversed string

  Preconditions:   A pointer to a string, a starting index and an ending index

  Postconditions:   The pointer to the reversed string has been returned
*/
char* reverse_string(char* str, int start, int end);







//All the function prototypes for task 4


/*
  Function:    void move_disks ()

  Date Created:       April 15, 2021

  Date Last Modifiled:      April 15, 2021

  Description:  This function shows all of the moves with the minumun number of turns needed to move the disks to another post by using recursion

  Input parameters:   The number of disks, the initial, destination, and indirect indexes for posts

  Returns:   None

  Preconditions:    The number of disks, the initial, destination, and indirect indexes for posts

  Postconditions:   None
*/
void move_disks(int n, int initial_index, int dest_index, int indirect_index);





/*
  Function:   int min_num_moves ()

  Date Created:       April 15, 2021

  Date Last Modifiled:      April 15, 2021

  Description:  This function calculates the minimum number of turns to move the disks to another post by using recursion

  Input parameters:   The number of disks

  Returns:    The minimum number of moves

  Preconditions:     The number of disks

  Postconditions:   The minimum number of moves has been returned
*/
int min_num_moves(int n);





#endif
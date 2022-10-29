
/*

    This file is to establish the definitions for all programmer-defined functions, aside from main ()

*/


#include "header.h"



//All the defined functions for task 3
char* reverse_string(char* str, int start, int end)
{
    char temp;

    //Base case
    if (start >= end)
        return;
    else
    {
        temp = *(str + start);
        *(str + start) = *(str + end);
        *(str + end) = temp;

        //Recursion
        reverse_string(str, ++start, --end);
    }


    return str;
}





//All the defined functions for task 4

void move_disks(int n, int initial_index, int dest_index, int indirect_index)
{
   
    //Base case
    if (n == 1)
    {
        printf("\nMove disk(d%d) from post%d to post%d\n", n, initial_index, dest_index);


        return;
    }


    else
    {
        move_disks(n - 1, initial_index, indirect_index, dest_index);

        printf("\nMove disk(d%d) from post%d to post%d\n", n, initial_index, dest_index);

        move_disks(n - 1, indirect_index, dest_index, initial_index);
    }
   
}





int min_num_moves(int n)
{
    int num_moves = 0;

    //Base case
    if (n == 1)
    {
        num_moves = 1;
    }

    else
    {
        //First, move the first n-1 disks from the initial post to the indirect post
        num_moves += min_num_moves(n - 1);

        //Then, move the largest disk from the initial post to the destination post
        num_moves += 1;

        //Fimally, move previous n-1 disks from the indirect post to the destination post
        num_moves += min_num_moves(n - 1);
    }


    return num_moves;

}
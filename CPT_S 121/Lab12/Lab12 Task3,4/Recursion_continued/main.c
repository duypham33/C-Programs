
/*
      * Programmer: Duy Pham

      * Class: CptS 121, Spring 2021; Section 01; Lab Section 14

      * Programming Assignment:     Lab 12: Recursion (Task 3 and Task 4)

      * Date: April 15, 2021

      * Description: This program performs two different tasks:
                  - Task 3: A function recursively reverses a string.

                  - Task 4: A program simulates a game of Tower of Hanoi. The idea behind the game is to find an efficient method for moving disks between three posts.
                          Each disk has a different diameter, but all of them can be placed on the available posts. 
                          The goal of the game is to move all of the disks from one post to another according the following rules:
                            1. Only one disk may be transferred at a time

                            2. Only the top disk on any post may be accessed at a given time

                            3. No disk may be placed on top of a smaller disk at any point
                     At the start of the game, all of the disks must originally be placed such that the largest disk is on the bottom of the stack of one post, 
                      and the smallest is on the top of the stack on the same post. The disks should form a cone shape. Initially start with three disks in your game.
*/



#include "header.h"


int main(void)
{

    //Task 3
    printf("3) ");   //Start task 3


    char str[100];


    printf("Enter the string: ");
    gets(str);

    int start = 0;
    int end = strlen(str) - 1;

    reverse_string(str, start, end);


    printf("The reversed string is: %s\n", str);

    getch();



    //Task 4
    printf("\n\n4) ");   //Start task 4


    printf("\t\t\t\tWELCOME TO TOWER OF HANOI\n");

    int i;   //The index

    printf("\n\tWe have three posts and %d disks with different diameters (", NUM_DISKS);

    for (i = 1; i < NUM_DISKS; i++)
    {
        printf("d%d < ", i);
    }

    printf("d%d)\n", NUM_DISKS); 

    printf("\tPlease hit the ENTER to randomly determine which one is the initial post for placing disks!");
    getch();
    system("cls");   //Clear the screen



    srand((unsigned int)time(NULL));

    int initial_index = rand() % 3 + 1;   //Randomly determine which one is the initial post for placing disks


    int dest_index = 0;

    do         ////Randomly determine which one is the destination post
    {
        dest_index = rand() % 3 + 1;
    } while (dest_index == initial_index);


    int indirect_index = 6 - initial_index - dest_index;

    printf("  Begin! All of the disks were originally placed on the post %d!\n\n", initial_index);

    printf("Please hit ENTER to know the minimum number of steps needed to move the disks to another post!");
    getch();

    printf("\n");
    printf("\nThere are at least %d turns to move all of the disks to another post!\n\n", min_num_moves(NUM_DISKS));
    printf("Please hit ENTER to view how steps are!"); getch();


    printf("\n");
    move_disks(NUM_DISKS, initial_index, dest_index, indirect_index);



    return 0;     //The program was successful



}
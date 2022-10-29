
/*
      * Programmer: Duy Pham

      * Class: CptS 121, Spring 2021; Section 01; Lab Section 14

      * Programming Assignment:     Lab 12: Recursion (Task 1 and Task 2)

      * Date: April 15, 2021

      * Description: This program performs two different tasks:
                  - Task 1: A function accepts an 8 by 8 array of characters that represents a maze. Each position can contain either an X or a blank.
                            Starting at position (0, 1), list any path through the maze to get to location (7, 7). Only horizontal and vertical moves are allowed.
                            Only horizontal and vertical moves are allowed. If no path exists, write a message indicating there is no path.
                            Moves can be made only to locations that contain a blank. If an X is encountered, that path is blocked and another must be chosen.

                  - Task 2: A function returns the sum of the digits of an integer value. You must use recursion. Example sum (765) = 18, sum (16978) = 31, etc.

*/



#include "header.h"


int main(void)
{

    //Task 1
    printf("1) ");    //Start task 1


    char maze[NUM_ROWS][NUM_COLS] = { {' ', ' ', ' ', 'X', 'X', ' ', ' ', 'X'},
                                      {' ', 'X', ' ', ' ', 'X', ' ', 'X', ' '},
                                      {'X', ' ', ' ', 'X', ' ', ' ', 'X', ' '},
                                      {' ', ' ', 'X', ' ', 'X', ' ', ' ', 'X'},
                                      {' ', 'X', ' ', ' ', ' ', 'X', 'X', ' '},
                                      {' ', ' ', ' ', 'X', ' ', ' ', ' ', ' '},
                                      {'X', 'X', 'X', ' ', 'X', ' ', 'X', 'X'},
                                      {' ', 'X', ' ', ' ', 'X', ' ', ' ', ' '}
    };


    printf("The initial maze:\n");

    print_maze(maze);   getch();

    solve_Maze(maze);

    printf("\n\n");




    //Task 2
    printf("2) ");   //Start task 2

    int a = 0;
    printf("Enter an integer value:  ");
    scanf("%d", &a);

    printf("The sum of digits of %d is: %d\n", a, calculate_sum_digits(a));









    return 0;     //The program was successful
}
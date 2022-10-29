
/*

  This is the header file that stores standard library includes, #defined and function prototypes

*/


#ifndef HEADER_H //guard code

#define HEADER_H


#define _CRT_SECURE_NO_WARNINGS //ignore the error about scanf()

#include<stdio.h> //necessary to use printf() and scanf()

#include<math.h>  //necessary to use abs()


#define NUM_ROWS 8     //The number of rows of the maze

#define NUM_COLS 8     //The number of columns of the maze

#define TRUE 1

#define FALSE 0







//Function prototype





//All the function prototypes for task 1



/*
  Function:   int is_safe ()

  Date Created:       April 15, 2021

  Date Last Modifiled:      April 15, 2021

  Description:  This function determines whether a position(x,y) inside maze and blocked or not

  Input parameters:   The array of characters for maze, coordinates x and y

  Returns:  TRUE (1) or FALSE (0)

  Preconditions:  The array of characters for maze, coordinates x and y

  Postconditions:  1 or 0 has been returned
*/
int is_safe(char maze[NUM_ROWS][NUM_COLS], int x, int y);




/*
  Function:    int find_path()

  Date Created:       April 15, 2021

  Date Last Modifiled:      April 15, 2021

  Description:  This function checks if there exists a path from (x,y) to (7,7)

  Input parameters:  The array of characters for maze, coordinates x and y, and an int maze_to_check[NUM_ROWS][NUM_COLS]

  Returns:   TRUE (1) or FALSE (0)

  Preconditions:  The array of characters for maze, coordinates x and y, and an int maze_to_check[NUM_ROWS][NUM_COLS]

  Postconditions:  1 or 0 has been returned
*/
int find_path(char maze[NUM_ROWS][NUM_COLS], int x, int y, int maze_to_check[NUM_ROWS][NUM_COLS]);




/*
  Function:   void draw_path()

  Date Created:       April 15, 2021

  Date Last Modifiled:      April 15, 2021

  Description:  This function draws the path found by add a * into a non-blocked position if its corresponding position in the maze_to_check is 1

  Input parameters:    The array of characters for maze, and an int maze_to_check[NUM_ROWS][NUM_COLS]

  Returns:   None

  Preconditions:   The array of characters for maze, and an int maze_to_check[NUM_ROWS][NUM_COLS]

  Postconditions:  Characters in the maze have been updated 
*/
void draw_path(char maze[][NUM_COLS], int maze_to_check[][NUM_COLS]);





/*
  Function:   void print_maze()

  Date Created:       April 15, 2021

  Date Last Modifiled:      April 15, 2021

  Description:  This function prints out all of characters in the maze to the screen

  Input parameters:   The array of characters for maze

  Returns:   None

  Preconditions:   The array of characters for maze

  Postconditions:    All of characters in the maze have been displayed to the screen
*/
void print_maze(char maze[][NUM_COLS]);







/*
  Function:   int solve_Maze()

  Date Created:       April 15, 2021

  Date Last Modifiled:      April 15, 2021

  Description:     This function determines there exits any path or not. If yes, draws and prints the resulting maze 

  Input parameters:   The array of characters for maze

  Returns:    TRUE (1) or FALSE (0)

  Preconditions:    The array of characters for maze
   
  Postconditions:   1 or 0 has been returned
*/
int solve_Maze(char maze[NUM_ROWS][NUM_COLS]);








//All the function prototypes for task 2



/*
  Function:    int calculate_sum_digits ()

  Date Created:       April 15, 2021

  Date Last Modifiled:      April 15, 2021

  Description:  This function calculates the sum of digits of an integer number by using recursion

  Input parameters:   An integer value

  Returns:    The sum of digits

  Preconditions:    The integer value

  Postconditions:    The sum of digits has been returned
*/
int calculate_sum_digits(int n);









#endif

/*

    This file is to establish the definitions for all programmer-defined functions, aside from main ()

*/


#include "header.h"



//All the defined functions for task 1



int is_safe(char maze[NUM_ROWS][NUM_COLS], int x, int y)
{
    // if (x, y outside maze) return false
    if (x >= 0 && x < NUM_ROWS && y >= 0 && y < NUM_COLS && maze[x][y] == ' ')
        return TRUE;

    else
    {
        return FALSE;
    }
}



int find_path(char maze[NUM_ROWS][NUM_COLS], int x, int y, int maze_to_check[NUM_ROWS][NUM_COLS])
{
    // if (x, y is goal) return true
    if (x == NUM_ROWS - 1 && y == NUM_COLS - 1 && maze[x][y] == ' ')
    {
        maze_to_check[x][y] = 1;
        return TRUE;
    }


    /*
        We create an int maze_to_check[NUM_ROWS][NUM_COLS]
        If a position contains 0, which means the path cannot go through it. If it contains 1, then the path can go through
    */



    // Check if maze[x][y] is valid
    if (is_safe(maze, x, y) == TRUE)
    {
        // Check if the current block is already part of solution path.   
        if (maze_to_check[x][y] == 1)
            return FALSE;


        maze_to_check[x][y] = 1;


        if (find_path(maze, x + 1, y, maze_to_check) == TRUE)
            return TRUE;


        if (find_path(maze, x, y + 1, maze_to_check) == TRUE)
            return TRUE;


        if (find_path(maze, x - 1, y, maze_to_check) == TRUE)
            return TRUE;


        if (find_path(maze, x, y - 1, maze_to_check) == TRUE)
            return TRUE;

        //Else
        maze_to_check[x][y] = 0;
        return FALSE;
    }

    else
    {
        return FALSE;
    }
}




void draw_path(char maze[][NUM_COLS], int maze_to_check[][NUM_COLS])
{
    int i, j;   //The index

    for (i = 0; i < NUM_ROWS; i++)
    {
        for (j = 0; j < NUM_COLS; j++)
        {
            if (maze_to_check[i][j] == 1)
            {
                maze[i][j] = '*';
            }
        }
    }
}



void print_maze(char maze[][NUM_COLS])
{
    int i, j;   //The index

    for (i = 0; i < NUM_ROWS; i++)
    {
        printf("\t");

        for (j = 0; j < NUM_COLS; j++)
        {
            printf(" %c ", maze[i][j]);
        }

        printf("\n");
    }

}





int solve_Maze(char maze[NUM_ROWS][NUM_COLS])
{
    /*
        We create an int maze_to_check[NUM_ROWS][NUM_COLS]
        If a position contains 0, which means the path cannot go through it. If it contains 1, then the path can go through
    */

    int maze_to_check[NUM_ROWS][NUM_COLS] = { 0 };     //Initialize all items as 0



    if (find_path(maze, 0, 1, maze_to_check) == FALSE)
    {
        printf("There is no path to leave the maze!\n");
        return FALSE;
    }



    printf("\nHere is a map of the path out of the maze:\n");
    draw_path(maze, maze_to_check);
    print_maze(maze);
    return TRUE;
}






//All the defined functions for task 2

int calculate_sum_digits(int n)
{
    int sum_digits = 0;

    n = abs(n);

    if (n < 10)        //base case
    {
        sum_digits = n;
    }


    else
    {
        sum_digits = (n % 10) + calculate_sum_digits(n / 10);
    }

    return sum_digits;

}




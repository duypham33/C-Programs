

/*

  This is the header file that stores standard library includes, #defined and function prototypes

*/


#ifndef HEADER_H //guard code

#define HEADER_H


#define _CRT_SECURE_NO_WARNINGS //ignore the error about scanf()


#include<stdio.h>    //necessary to use printf() and scanf()

#include<stdlib.h>  //necessary to use rand() and srand()

#include<time.h>    //necessary to use time()



#define n 3     //Select the size of nxn Cells



typedef struct coordinate
{

    int row;

    int column;

} Coordinate;



typedef struct cell
{

    int occupied; // 1 if an X or O is in this cell; 0 otherwise

    char symbol; // X for one player, O for the other player

    Coordinate location; // A struct defined above, which represents the position of the cell within the game board

} Cell;



typedef struct board
{

    Cell game_board[n][n];

} Board;


typedef struct game_info

{
    int wins;

    int losses;

    int total_games_played;

} Game_info;







//Function prototype



//All the function prototypes for task 1



/*
  Function:

  Date Created: March 29, 2021

  Date Last Modifiled: March 29, 2021

  Description:   This functions

  Input parameters:

  Returns:

  Preconditions:

  Postconditions:
*/
void upper_first_letter(int index);





//All the function prototypes for task 2

/*
  Function:

  Date Created: March 29, 2021

  Date Last Modifiled: March 29, 2021

  Description:   This functions

  Input parameters:

  Returns:

  Preconditions:

  Postconditions:
*/
void init_board(Board* board_ptr);


int select_first_player();


void choose_cell(int reprs_num, Board* board_ptr);

int does_align_in_row_k(Board* board_ptr, int k);

int does_align_in_column_k(Board* board_ptr, int k);

int does_align_diagonally(Board* board_ptr, char* win_symbol);

int is_win_horizontally(Board* board_ptr, char* win_symbol);

int is_win_vertically(Board* board_ptr, char* win_symbol);

int is_scratch(Board* board_ptr);


void display_board(Board* board_ptr);


void display_winner(char win_symbol, Game_info player[]);



void display_game_info(Game_info player[]);





#endif


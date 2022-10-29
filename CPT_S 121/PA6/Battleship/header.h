

/*

  This is the header file that stores standard library includes, #defined and function prototypes

*/


#ifndef HEADER_H //guard code

#define HEADER_H


#define _CRT_SECURE_NO_WARNINGS //ignore the error about scanf()


#include<stdio.h>    //necessary to use printf() and scanf()

#include<stdlib.h>  //necessary to use rand() and srand()

#include<time.h>    //necessary to use time()

#include<string.h>  //necessary to use strcpy()


#define MAX_ROWS 10

#define MAX_COLS 10

#define NUM_DIR 2

#define NUM_SHIPS 5





typedef struct coordinate
{

    int row;

    int column;

} Coordinate;



typedef struct cell
{

    int occupied; // 0 if an - is in this cell; 1 if 'c', 'b', 'r', 's', or 'd' is in this cell, 2 if an '*' or 'm' is in this cell

    char symbol;  // '-', 'c', 'b', 'r', 's', 'd', '*', or 'm'

    Coordinate location; // A struct defined above, which represents the position of the cell within the game board

} Cell;



typedef struct board
{

    Cell game_board[MAX_ROWS][MAX_COLS];

} Board;







typedef enum direction
{
    Vertical, Horizontal
} Direction;


typedef enum ship_t
{
    Carrier = 1, Battleship, Cruiser, Submarine, Destroyer

} Ship_t;


typedef struct ship
{
    Ship_t sh_type;
    int length;
    char symbol;
    Direction dir;
    Coordinate start_position;
    int num_hits;

} Ship;



typedef struct fleet
{
    Ship sh[NUM_SHIPS];    //There are five ships in a fleet

} Fleet;




typedef enum result
{
    Won, Lost
} Result;


typedef struct stats
{
    int num_hits;
    int num_misses;
    int total_shots;
    double hits_misses_ratio;
    Result res;

} Stats;







//All the function prototypes 



/*
  Function:      void welcome_screen( )

  Date Created: April 7, 2021

  Date Last Modifiled: April 7, 2021

  Description:  This function displays an initial program welcome message along with the rules of Battleship

  Input parameters:  None

  Returns:     None

  Preconditions:   None

  Postconditions:   The rules has been displayed to the screen
  */
void welcome_screen();




/*
  Function:    void init_game_board ()

  Date Created: April 7, 2021

  Date Last Modifiled: April 7, 2021

  Description:   This function initializes the game board before starting game

  Input parameters:    The board pointer

  Returns:    None

  Preconditions:   The board pointer

  Postconditions:  All the variables of Board have been initialized
  */
void init_game_board(Board* board_ptr);



/*
  Function:    int select_who_starts_first()

  Date Created: April 7, 2021

  Date Last Modifiled: April 7, 2021

  Description:  This function determines if Player1 or Player2 goes first in the game randomly

  Input parameters:  None

  Returns:   The number represnting for the player  (0 for player1, 1 for player2)

  Preconditions:  None

  Postconditions:    The number represnting for the player has been returned
  */
int select_who_starts_first();



/*
  Function:  void init_stats()

  Date Created: April 7, 2021

  Date Last Modifiled: April 7, 2021

  Description:   This function initializes the Stats before starting game

  Input parameters:    The stat pointer

  Returns:    None

  Preconditions:   The stat pointer

  Postconditions:  All the variables of Stats have been initialized
  */
void init_stats(Stats* sta_ptr);



/*
  Function:   void init_ships()

  Date Created: April 7, 2021

  Date Last Modifiled: April 7, 2021

   Description:   This function initializes the Fleets before starting game

  Input parameters:    The fleet pointer

  Returns:    None

  Preconditions:   The fleet pointer

  Postconditions:  All the variables of Fleets have been initialized
  */
void init_ships(Fleet* fl_ptr);





/*
  Function:   Direction generate_direction()

  Date Created: April 7, 2021

  Date Last Modifiled: April 7, 2021

  Description:  This function generates direction randomly

  Input parameters:   None

  Returns:   The direction 

  Preconditions:  None

  Postconditions:  The direction has been returned
  */
Direction generate_direction();




/*
  Function:  void generate_start_pt()

  Date Created: April 7, 2021

  Date Last Modifiled: April 7, 2021

  Description:  This function generates the starting point(cell) to place a ship randomly

  Input parameters:  The target row pointer, the target column pointer, the direction, and the ship length

  Returns:  None

  Preconditions:   The target row pointer, the target column pointer, the direction, and the ship length

  Postconditions:  The target row and column has been generated randomly
  */
void generate_start_pt(int* row_start_ptr, int* col_start_ptr, Direction dir, int ship_length);




/*
  Function:   void randomly_place_ships_on_board ()

  Date Created: April 7, 2021

  Date Last Modifiled: April 7, 2021

  Description:  This function randomly places the 5 types of ships on a board

  Input parameters:   The fleet pointer and the board pointer

  Returns:   None

  Preconditions:     The fleet pointer and the board pointer

  Postconditions:    Five ships have been generated
  */
void randomly_place_ships_on_board(Fleet* fl_ptr, Board* board_ptr);




/*
  Function:   void manually_place_ships_on_board ()

  Date Created: April 7, 2021

  Date Last Modifiled: April 7, 2021

  Description:  This function  allows the user to place each of the 5 types of ships on his/her game board.

  Input parameters:   The ship pointer and the board pointer

  Returns:  None

  Preconditions:   The ship pointer and the board pointer

  Postconditions:    The ship has been generated
  */
void manually_place_ships_on_board(Ship* sh, Board* board_ptr);




/*
  Function:   void prompt_target_position ()

  Date Created: April 7, 2021

  Date Last Modifiled: April 7, 2021

  Description:  This function prompts the player1 for coordinates of target cell

  Input parameters:  The target row pointer, the target column pointer, the number representing for the players, and the board pointer

  Returns:       None

  Preconditions:   The target row pointer, the target column pointer, the number representing for the players, and the board pointer

  Postconditions:   None
  */
void prompt_target_position(int* target_row_ptr, int* target_col_ptr, int reprs_num, Board board[]);





/*
  Function:   void randomly_choose_target_position ()

  Date Created: April 7, 2021

  Date Last Modifiled: April 7, 2021

  Description:  This function randomly chooses coordinates of target cell

  Input parameters:  The target row pointer, the target column pointer, the number representing for the players, and the board pointer

  Returns:  None

  Preconditions:  The target row pointer, the target column pointer, the number representing for the players, and the board pointer

  Postconditions:  None
  */
void randomly_choose_target_position(int* target_row_ptr, int* target_col_ptr, int reprs_num, Board board[]);



/*
  Function:   void check_shot_and_update_board ()

  Date Created: April 7, 2021

  Date Last Modifiled: April 7, 2021

  Description:  This function determines if the shot taken was a hit or a miss, and also updates the board every time a shot is taken. '*' indicates a hit and 'm' indicates a miss.

  Input parameters:  The target row, the target column, the number representing for the players, and for ship, and the arrays of Board, Stats, Fleets

  Returns:  None

  Preconditions:  The target row, the target column, the number representing for the players, and for ship, and the arrays of Board, Stats, Fleets

  Postconditions:    The reprs_ship_num has been determined
  */
void check_shot_and_update_board(int target_row, int target_col, Board board[], Stats sta[], Fleet fl[], int reprs_num, int* reprs_ship_ptr);




/*
  Function:   int is_winner ()

  Date Created: April 7, 2021

  Date Last Modifiled: April 7, 2021

  Description:  This function determines if a winner exists

  Input parameters:    The stats pointer

  Returns:   0 (false), 1 (true)

  Preconditions:    The stats pointer

  Postconditions:   0 or 1 has been returned
  */
int is_winner(Stats sta[]);




/*
  Function:     void display_board ()

  Date Created: April 7, 2021

  Date Last Modifiled: April 7, 2021

  Description:  This function displays boards to the screen

  Input parameters:   The board pointer

  Returns:      None

  Preconditions:  The board pointer

  Postconditions:    The two boards have been displayed to the screen
  */
void display_board(Board board[]);




/*
  Function:    int check_if_sunk_ship ()

  Date Created: April 7, 2021

  Date Last Modifiled: April 7, 2021

  Description:  This function determines if a ship was sunk

  Input parameters:    The ship pointer

  Returns:      0 (false), 1 (true)

  Preconditions:   The ship pointer

  Postconditions:     0 or 1 has been returned
  */
int check_if_sunk_ship(Ship sh);




/*
  Function:    void output_current_move ()

  Date Created: April 7, 2021

  Date Last Modifiled: April 7, 2021

  Description:  This function writes the position of the shot taken by the current player to the log file. It also writes whether or not it was a hit, miss, and if the ship was sunk.

  Input parameters:  The output file, the target row, and column, the number representing for the players, and for ship, and the arrays of Board, and Fleets

  Returns:   None

  Preconditions:   The output file, the target row, and column, the number representing for the players, and for ship, and the arrays of Board, and Fleets

  Postconditions:   The data have been written to the output file
  */
void output_current_move(FILE* outfile, int target_row, int target_col, Board board[], Fleet fl[], int reprs_num, int reprs_ship_num);




/*
  Function:     void update_hits_misses_ratio ()

  Date Created: April 7, 2021

  Date Last Modifiled: April 7, 2021

  Description:  This function calculates the hits to misses ratio directly

  Input parameters:   The stats pointer

  Returns:    None

  Preconditions:   The stats pointer

  Postconditions:   The ratios have been directly determined
  */
void update_hits_misses_ratio(Stats sta[]);




/*
  Function:   void output_stats ()

  Date Created: April 7, 2021

  Date Last Modifiled: April 7, 2021

  Description:  This function writes the statistics collected on each player to the output file.

  Input parameters:  The output file, and the stats array

  Returns:     None

  Preconditions:    The output file, and the stats array

  Postconditions:    The statistics have been written to the output file
  */
void output_stats(FILE* outfile, Stats sta[]);






#endif

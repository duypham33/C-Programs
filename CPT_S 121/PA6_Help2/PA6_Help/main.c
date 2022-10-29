// This code will help you get started with PA 6

// History: 3/31 - Defined an enum representing Direction.
//                 Implemented generate_dir () and
//                 generate_start_pt () so that you could
//                 get started with randomly placing
//                 ships on your board.
//          3/29 - Declared a p1_board. Implemented
//                 a function to initialize and display
//                 a board. These are called init_board ()
//                 and print_board (), respectively.

#include "PA6Help.h"

int main(void)
{
	char p1_board[MAX_ROWS][MAX_COLS] = { {'~'}, {'~'} };
	Direction dir = VERTICAL;
	int row_start = 0, col_start = 0;

	srand((unsigned int)time(NULL));

	init_board(p1_board, MAX_ROWS, MAX_COLS);
	print_board(p1_board, MAX_ROWS, MAX_COLS);

	dir = generate_dir();
	// determine the start point for submarine, i.e. length 3
	generate_start_pt(&row_start, &col_start, dir, 3);
	// now place the ship on the board from the given
	// starting point and direction

	return 0;
}
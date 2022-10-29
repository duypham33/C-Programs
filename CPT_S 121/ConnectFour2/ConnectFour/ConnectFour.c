#include "ConnectFour.h"

void set_token(Token* token_ptr, char new_color)
{
	//(*token_ptr).color = new_color;
	token_ptr->color = new_color;
}

void init_board(Board* board_ptr)
{
	int row_index = 0, col_index = 0;

	for (; row_index < MAX_ROWS; ++row_index)
	{
		for (col_index = 0; col_index < MAX_COLS; 
			++col_index)
		{
			board_ptr->game_board[row_index][col_index].occupied = FALSE;
			board_ptr->game_board[row_index][col_index].piece.color = '\0';
			board_ptr->game_board[row_index][col_index].location.row = row_index;
			board_ptr->game_board[row_index][col_index].location.col = col_index;
		}
	}
}

/*

	This file is to establish the definitions for all programmer-defined functions, aside from main ()

*/


#include "header.h"


//All the defined functions for task 1

void upper_first_letter(int index)
{
	switch (index)
	{
	case 0: printf("The "); break;

	case 1: printf("A "); break;

	case 2: printf("One "); break;

	case 3: printf("Some "); break;

	case 4: printf("Any "); break;

	}


}




//All the defined functions for task 2

void init_board(Board* board_ptr)
{
	int row_index = 0, col_index = 0;

	for (; row_index < n; ++row_index)
	{
		for (col_index = 0; col_index < n; ++col_index)
		{
			board_ptr->game_board[row_index][col_index].occupied = 0;
			board_ptr->game_board[row_index][col_index].symbol = ' ';
			board_ptr->game_board[row_index][col_index].location.row = row_index;
			board_ptr->game_board[row_index][col_index].location.column = col_index;
		}
	}
}




int select_first_player()
{
	int reprs_num;           //representative number for the player (0 for player with symbol O, 1 for the player with symbol X)

	printf("Please press the key ENTER to randomly choose who goes first! ");
	getch();

	reprs_num = rand() % 2;

	if (reprs_num == 0)
	{
		printf("\nThe player with symbol O will start the game!\n");
	}

	else if (reprs_num == 1)
	{
		printf("\nThe player with symbol X will start the game!\n");
	}

	return reprs_num;

}



void choose_cell(int reprs_num, Board* board_ptr)
{
	char c = NULL;

	//0 for symbol O, 1 for symbol X
	if (reprs_num == 0) { c = 'O'; }
	else if (reprs_num == 1) { c = 'X'; }

	int row, col;

	do
	{
		printf("Please choose a position (row and column) in which to draw your symbol (%c): ", c);

		scanf("%d%d", &row, &col);

		if (board_ptr->game_board[row][col].occupied == 1)
		{
			printf("\nThis position has already been chosen! Please try again!\n\n");
		}
	} while (board_ptr->game_board[row][col].occupied == 1);

	board_ptr->game_board[row][col].occupied = 1;
	board_ptr->game_board[row][col].symbol = c;


}




int does_align_in_row_k(Board* board_ptr, int k)
{
	int col_index;
	int flag = 1;    //0 is flase, 1 is true

	for (col_index = 0; col_index < n - 1; col_index++)
	{
		if (board_ptr->game_board[k][col_index].symbol != board_ptr->game_board[k][col_index + 1].symbol)
		{
			flag = 0; break;
		}

	}

	if (board_ptr->game_board[k][0].occupied == 0)    //When all the symbols are the same, we finally need to check if they are occupied
	{
		flag = 0;
	}


	return flag;

}


int does_align_in_column_k(Board* board_ptr, int k)
{
	int row_index;
	int flag = 1;    //0 is flase, 1 is true

	for (row_index = 0; row_index < n - 1; row_index++)
	{
		if (board_ptr->game_board[row_index][k].symbol != board_ptr->game_board[row_index + 1][k].symbol)
		{
			flag = 0; break;
		}

	}

	if (board_ptr->game_board[0][k].occupied == 0)    //When all the symbols are the same, we finally need to check if they are occupied
	{
		flag = 0;
	}

	return flag;

}



int does_align_diagonally(Board* board_ptr, char* win_symbol)
{

	//First, we work on the first diagonal line that passes through board[i][i], for all i from 0 to n-1

	int flag1 = 1;   //1 is true, 0 is false
	int i;

	for (i = 0; i < n - 1; i++)
	{
		if (board_ptr->game_board[i][i].symbol != board_ptr->game_board[i + 1][i + 1].symbol)
		{
			flag1 = 0; break;
		}
	}

	if (board_ptr->game_board[0][0].occupied == 0)    //When all the symbols are the same, we finally need to check if they are occupied
	{
		flag1 = 0;
	}



	//Second, we work on the second diagonal line that passes through board[i][n-1-i], for all i from 0 to n-1

	int flag2 = 1;   //1 is true, 0 is false

	for (i = 0; i < n - 1; i++)
	{
		if (board_ptr->game_board[i][n - 1 - i].symbol != board_ptr->game_board[i + 1][n - 2 - i].symbol)
		{
			flag2 = 0; break;
		}
	}

	if (board_ptr->game_board[0][n - 1].occupied == 0)    //When all the symbols are the same, we finally need to check if they are occupied
	{
		flag2 = 0;
	}



	//Combine the two cases
	int flag;       //1 is true, 0 is false

	if (flag1 == 0 && flag2 == 0)
	{
		flag = 0;
	}

	else if (flag1 == 1)
	{
		flag = 1;
		*win_symbol = board_ptr->game_board[0][0].symbol;
	}

	else if (flag2 == 1)
	{
		flag = 1;
		*win_symbol = board_ptr->game_board[0][n - 1].symbol;
	}

	return flag;

}


int is_win_horizontally(Board* board_ptr, char* win_symbol)
{
	int flag;   //1 is true, 0 is false
	int row;
	for (row = 0; row < n; row++)
	{
		if (does_align_in_row_k(board_ptr, row) == 1)
		{
			flag = 1;
			*win_symbol = board_ptr->game_board[row][0].symbol;
			break;
		}

		flag = 0;
	}

	return flag;

}


int is_win_vertically(Board* board_ptr, char* win_symbol)
{
	int col;

	for (col = 0; col < n; col++)
	{
		if (does_align_in_column_k(board_ptr, col) == 1)
		{
			return 1;   //1 is true
			*win_symbol = board_ptr->game_board[0][col].symbol;
			break;
		}
		else
			return 0;  //0 is false
	}

}






int is_scratch(Board* board_ptr)
{
	int flag = 1;     //1 is true, 0 is false

	int row_index = 0, col_index = 0;

	for (; row_index < n; ++row_index)
	{
		for (col_index = 0; col_index < n; ++col_index)
		{
			if (board_ptr->game_board[row_index][col_index].occupied == 0)
			{
				flag = 0; break;
			}

		}

		if (flag == 0) { break; }
	}

	return flag;
}


void display_board(Board* board_ptr)
{

	int row_index = 0, col_index = 0;


	for (; row_index < n; ++row_index)
	{
		printf("\n\t\t       ");

		for (col_index = 0; col_index < n; ++col_index)
		{

			printf("%c  ", board_ptr->game_board[row_index][col_index].symbol);

		}

		printf("\n");
	}

	printf("\n");
}



void display_winner(char win_symbol, Game_info player[])
{
	if (win_symbol == 'O')
	{
		printf("\n\tThe player with symbol O won!\n");
		player[0].wins++;
		player[1].losses++;
	}

	else if (win_symbol == 'X')
	{
		printf("\n\tThe player with symbol X won!\n");
		player[1].wins++;
		player[0].losses++;
	}

}

void display_game_info(Game_info player[])
{
	printf("\t\t The Game Information\n");

	printf("\t   The wins\tThe losses\t the total games\n");
	printf("Player(O)      %d\t     %d\t   \t\t%d\n", player[0].wins, player[0].losses, player[0].total_games_played);
	printf("Player(X)      %d\t     %d\t   \t\t%d\n", player[1].wins, player[1].losses, player[1].total_games_played);


}
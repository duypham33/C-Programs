#include "PA6Help.h"

void init_board(char board[][MAX_COLS], int num_rows,
	int num_cols)
{
	int row_index = 0, col_index = 0;

	for (; row_index < num_rows; ++row_index)
	{
		for (col_index = 0; col_index < num_cols; ++col_index)
		{
			board[row_index][col_index] = '~';
		}
	}
}

void print_board(char board[][MAX_COLS], int num_rows,
	int num_cols)
{
	int row_index = 0, col_index = 0;

	printf("%5d%4d%4d%4d%4d%4d%4d%4d%4d%4d\n",
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
	for (; row_index < num_rows; ++row_index)
	{
		printf("%-2d", row_index);
		for (col_index = 0; col_index < num_cols; 
			++col_index)
		{
			printf("|%2c ", board[row_index][col_index]);
		}
		putchar('\n');
	}
}

Direction generate_dir(void)
{
	return (Direction)(rand() % NUM_DIR);
}

void generate_start_pt(int* row_start_ptr, 
	int* col_start_ptr,
	Direction dir, int ship_length)
{
	if (dir == HORIZONTAL)
	{
		*row_start_ptr = rand() % MAX_ROWS;
		*col_start_ptr = rand() % (MAX_COLS - ship_length + 1);
	}
	else if (dir == VERTICAL)
	{
		*row_start_ptr = rand() % (MAX_ROWS - ship_length + 1);
		*col_start_ptr = rand() % MAX_COLS;
	}
}
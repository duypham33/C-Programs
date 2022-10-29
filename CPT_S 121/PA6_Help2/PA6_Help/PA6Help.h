#ifndef PA6HELP_H
#define PA6HELP_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10

#define NUM_DIR 2

typedef enum direction
{
	VERTICAL, HORIZONTAL
} Direction;

typedef struct stats
{
	int num_hits;
	int num_misses;
	int total_shots;
	double hits_misses_ratio;
} Stats;

void init_board(char board[][MAX_COLS], int num_rows,
	int num_cols);
void print_board(char board[][MAX_COLS], int num_rows,
	int num_cols);

Direction generate_dir(void);
void generate_start_pt(int* row_start_ptr, int* col_start_ptr,
	Direction dir, int ship_length);

#endif
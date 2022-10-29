#ifndef CONNECT_FOUR_H
#define CONNECT_FOUR_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 6
#define MAX_COLS 7

typedef enum boolean
{
	FALSE, TRUE
} Boolean;

typedef struct token
{
	char color;
} Token;

typedef struct position
{
	int row;
	int col;
} Position;

typedef struct cell
{
	Position location;
	Boolean occupied;
	Token piece;
} Cell;

typedef struct board
{
	Cell game_board[MAX_ROWS][MAX_COLS];
} Board;

void set_token(Token* token_ptr, char new_color);
void init_board(Board* board_ptr);

#endif
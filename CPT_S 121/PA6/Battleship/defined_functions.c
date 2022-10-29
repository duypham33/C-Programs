
/*

	This file is to establish the definitions for all programmer-defined functions, aside from main ()

*/


#include "header.h"


//All the defined functions 

void welcome_screen()
{
	printf("\t\t***** Welcome to Battleship! *****\n\n");
	printf("\t\tRules of the Game:\n");
	printf("\t\t1. This is a two player game.\n");
	printf("\t\t2. Player1 is you and Player2 is the computer.\n");
	printf("\t\t3. Firstly, you will choose either manually place each of the 5 ships in your fleet\n\t\t    or to have them randomly placed on the board.\n");
	printf("\t\t4. During the game, in turn, you will select one position to target (specifying where to \"shoot\") on the enemy's board.\n");
	printf("\t\t5. The Player to sink his/her enemy's fleet first wins.\n");

}



void init_game_board(Board* board_ptr)
{
	int row_index = 0, col_index = 0;

	for (; row_index < MAX_ROWS; ++row_index)
	{
		for (col_index = 0; col_index < MAX_COLS; ++col_index)
		{
			board_ptr->game_board[row_index][col_index].occupied = 0;
			board_ptr->game_board[row_index][col_index].symbol = '-';
			board_ptr->game_board[row_index][col_index].location.row = row_index;
			board_ptr->game_board[row_index][col_index].location.column = col_index;
		}
	}

}




int select_who_starts_first()
{

	int reprs_num;           //representative number for the player (0 for player 1, 1 for the player 2)

	printf("Please press the key ENTER to randomly choose who goes first! ");
	getch();

	reprs_num = rand() % 2;


	if (reprs_num == 0)
	{
		printf("\nYou (player1) will start first!\n");
	}

	else if (reprs_num == 1)
	{
		printf("\nThe player 2 will start first!\n");
	}


	return reprs_num;


}


void init_stats(Stats* sta_ptr)
{
	sta_ptr->num_hits = 0;
	sta_ptr->num_misses = 0;
	sta_ptr->hits_misses_ratio = 0.0;
	sta_ptr->total_shots = 0;
	sta_ptr->res = Lost;
}






void init_ships(Fleet* fl_ptr)
{
	fl_ptr->sh[0].sh_type = Carrier;      fl_ptr->sh[0].symbol = 'c';  fl_ptr->sh[0].num_hits = 0; fl_ptr->sh[0].length = 5;      //Carrier has 5 cells

	fl_ptr->sh[1].sh_type = Battleship;   fl_ptr->sh[1].symbol = 'b';  fl_ptr->sh[1].num_hits = 0; fl_ptr->sh[1].length = 4;      //Battleship has 4 cells

	fl_ptr->sh[2].sh_type = Cruiser;      fl_ptr->sh[2].symbol = 'r';  fl_ptr->sh[2].num_hits = 0; fl_ptr->sh[2].length = 3;      //Cruiser has 3 cells

	fl_ptr->sh[3].sh_type = Submarine;    fl_ptr->sh[3].symbol = 's';  fl_ptr->sh[3].num_hits = 0; fl_ptr->sh[3].length = 3;      //Submarine has 3 cells

	fl_ptr->sh[4].sh_type = Destroyer;    fl_ptr->sh[4].symbol = 'd';  fl_ptr->sh[4].num_hits = 0; fl_ptr->sh[4].length = 2;      //Destroyer has 2 cells

}



Direction generate_direction()
{
	return (Direction)(rand() % NUM_DIR);
}



void generate_start_pt(int* row_start_ptr, int* col_start_ptr, Direction dir, int ship_length)
{
	if (dir == Horizontal)
	{
		*row_start_ptr = rand() % MAX_ROWS;
		*col_start_ptr = rand() % (MAX_COLS - ship_length + 1);
	}
	else if (dir == Vertical)
	{
		*row_start_ptr = rand() % (MAX_ROWS - ship_length + 1);
		*col_start_ptr = rand() % MAX_COLS;
	}
}



void randomly_place_ships_on_board(Fleet* fl_ptr, Board* board_ptr)
{
	int i, j;   //index
	int row = 0, col = 0;
	int length = 0;



	for (i = 0; i < NUM_SHIPS; ++i)
	{
		length = fl_ptr->sh[i].length;


		     // Use goto statement
  Re_do: do
		{
	        fl_ptr->sh[i].dir = generate_direction();

			generate_start_pt(&fl_ptr->sh[i].start_position.row, &fl_ptr->sh[i].start_position.column, fl_ptr->sh[i].dir, length);

			row = fl_ptr->sh[i].start_position.row;   col = fl_ptr->sh[i].start_position.column;

		} while (board_ptr->game_board[row][col].occupied == 1);      //Check whether the starting cell is occupied or not
		

		//Then, check whether the next cells are occupied or not

		if(fl_ptr->sh[i].dir == Vertical)
		{
			for (j = 0; j < length; j++)
			{
				if (board_ptr->game_board[row + j][col].occupied == 1)  
				{
					goto Re_do;     //if occupied, return back the step of generating the starting position by using goto statement
				}
			}
		}
		
		else if (fl_ptr->sh[i].dir == Horizontal)
		{
			for (j = 0; j < length; j++)
			{
				if (board_ptr->game_board[row][col + j].occupied == 1)
				{
					goto Re_do;   //if occupied, return back the step of generating the starting position by using goto statement
				}
			}
		}


		//Here, we have chosen proper positions. Then, place the ship into the positions

		if (fl_ptr->sh[i].dir == Vertical)
		{
			for (j = 0; j < length; j++)
			{
				board_ptr->game_board[row + j][col].occupied = 1;
				board_ptr->game_board[row + j][col].symbol = fl_ptr->sh[i].symbol;
			}
		}

		else if (fl_ptr->sh[i].dir == Horizontal)
		{
			for (j = 0; j < length; j++)
			{
				board_ptr->game_board[row][col + j].occupied = 1;
				board_ptr->game_board[row][col + j].symbol = fl_ptr->sh[i].symbol;
			}
		}

	}


}



void manually_place_ships_on_board(Ship* sh, Board* board_ptr)
{
	char sh_t[20] ="";
	switch ((int)sh->sh_type)
	{
	case 1:  strcpy(sh_t, "Carrier"); break;
	case 2:  strcpy(sh_t, "Battleship"); break;
	case 3:  strcpy(sh_t, "Cruiser"); break;
	case 4:  strcpy(sh_t, "Submarine"); break;
	case 5:  strcpy(sh_t, "Destroyer"); break;
	}

	int i;  //index
	int length = sh->length;

	int row[5] = { 0 };
	int col[5] = { 0 };

	int flag;
	
	do
	{
		flag = 1;

		printf("\nPlease enter the %d cells to place the %s across: ", length, sh_t);

		for (i = 0; i < length; ++i)
		{
			scanf("%d%d", &row[i], &col[i]);
		}

		for (i = 0; i < length; ++i)
		{
			if (board_ptr->game_board[row[i]][col[i]].occupied == 1)
			{
				printf("The position is on top of a ship that has already been placed! Please try again!\n\n");
				flag = 0; break;
			}

			else if (row[i] < 0 || row[i] > 9 || col[i] < 0 || col[i] > 9)
			{
				printf("The position is outside the boundaries of the board! Please try again!\n\n");
				flag = 0; break;		
			}
		}

	} while (flag == 0);


	//Here, we have chosen proper positions. Then, place the ship into the positions
	   
	for (i = 0; i < length; ++i)
	{
		board_ptr->game_board[row[i]][col[i]].occupied = 1;

		board_ptr->game_board[row[i]][col[i]].symbol = sh->symbol;
	}



}



void prompt_target_position(int* target_row_ptr, int* target_col_ptr, int reprs_num, Board board[])
{
	int reprs_enemy_num = 1 - reprs_num;      // 1 - 0 = 1,  or  1 - 1 = 0
	int flag;

	do
	{
		flag = 1;

		printf("\nEnter a target: ");
		scanf("%d%d", &(*target_row_ptr), &(*target_col_ptr));

		if (board[reprs_enemy_num].game_board[*target_row_ptr][*target_col_ptr].occupied == 2)
		{
			printf("\nThe target position has already been chosen! Please try again!\n\n");
			flag = 0;
		}

	} while (flag == 0);


}



void randomly_choose_target_position(int* target_row_ptr, int* target_col_ptr, int reprs_num, Board board[])
{
	int reprs_enemy_num = 1 - reprs_num;      // 1 - 0 = 1,  or  1 - 1 = 0
	int flag;

	do
	{
		flag = 1;

		*target_row_ptr = rand() % MAX_ROWS;
		*target_col_ptr = rand() % MAX_COLS;

		if (board[reprs_enemy_num].game_board[*target_row_ptr][*target_col_ptr].occupied == 2)
		{
			flag = 0;
		}

	} while (flag == 0);


	printf("\nPlayer2 selects: %d %d\n", *target_row_ptr, *target_col_ptr);


}





void check_shot_and_update_board(int target_row, int target_col, Board board[], Stats sta[], Fleet fl[], int reprs_num, int* reprs_ship_ptr)
{
	int reprs_enemy_num = 1 - reprs_num;      // 1 - 0 = 1,  or  1 - 1 = 0

	char symbol = board[reprs_enemy_num].game_board[target_row][target_col].symbol;
	
  *reprs_ship_ptr = -1; //It is in {0, 1, 2, 3, 4} to represent the ship type accordingly, so we initialize as -1 (out of [0,4]), which means not determined yet


		if (board[reprs_enemy_num].game_board[target_row][target_col].occupied == 1)
		{
			printf("(%d , %d) is a hit!\n", target_row, target_col);
			printf("\a\n");    //Sound when hitting

			++sta[reprs_num].num_hits;
			++sta[reprs_num].total_shots;

			//If the position specified happens to hit a ship, then a '*' should replace the '-'
			board[reprs_enemy_num].game_board[target_row][target_col].symbol = '*';  
			board[reprs_enemy_num].game_board[target_row][target_col].occupied = 2;

			//Now, we determine which ship type was hit in this turn 
			switch (symbol)
			{
			case 'c':  *reprs_ship_ptr = 0; break;
			case 'b':  *reprs_ship_ptr = 1; break;
			case 'r':  *reprs_ship_ptr = 2; break;
			case 's':  *reprs_ship_ptr = 3; break;
			case 'd':  *reprs_ship_ptr = 4; break;
			}

			++fl[reprs_enemy_num].sh[*reprs_ship_ptr].num_hits;  //increment the number of times the ship was hit 

		}



		else if (board[reprs_enemy_num].game_board[target_row][target_col].occupied == 0)
		{
			printf("(%d , %d) is a miss!\n", target_row, target_col);

			++sta[reprs_num].num_misses;
			++sta[reprs_num].total_shots;

			//If the positioned specified misses any one of the ships in the fleet, then a 'm' should replace the '-'
			board[reprs_enemy_num].game_board[target_row][target_col].symbol = 'm';
			board[reprs_enemy_num].game_board[target_row][target_col].occupied = 2;
		}
	

}



int is_winner(Stats sta[])
{
	int i;          //index
	int flag = 0;   // 0 is flase 

	int row, col;

	for (i = 0; i < 2; ++i)
	{
		if (sta[i].num_hits == 17)    // 2+3+3+4+5 = 17 celss
		{
			flag = 1;   // 1 is true
			
			sta[i].res = Won;

			break;
		}

	}

	sta[1 - i].res = Lost;

	return flag;
}



void display_board(Board board[])
{
	int row_index = 0, col_index = 0;


	  //Player1's board
	printf(" Player1\'s Board:\n\n");
	
		printf("%5d%4d%4d%4d%4d%4d%4d%4d%4d%4d\n",
			0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
		for (; row_index < MAX_ROWS; ++row_index)
		{
			printf("%-2d", row_index);
			for (col_index = 0; col_index < MAX_COLS; ++col_index)
			{
				printf(" %2c ", board[0].game_board[row_index][col_index].symbol);
			}
			putchar('\n');
		}


	
		//Player2's board
		printf(" \nPlayer2\'s Board:\n\n");

		printf("%5d%4d%4d%4d%4d%4d%4d%4d%4d%4d\n",
			0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
		for (row_index=0; row_index < MAX_ROWS; ++row_index)
		{
			printf("%-2d", row_index);
			for (col_index = 0; col_index < MAX_COLS; ++col_index)
			{
				if (board[1].game_board[row_index][col_index].occupied == 2)
				{
					printf(" %2c ", board[1].game_board[row_index][col_index].symbol);
				}
				
				else
				{
					printf(" %2c ", '-');
				}
			}
			putchar('\n');
		}


}



int check_if_sunk_ship(Ship sh)
{
	int flag = 0;  // 0 is false

	if (sh.num_hits == sh.length)   //The number of time of being hit = the length, so it was sunk 
	{
		flag = 1;  // 1 is true
	}

	return flag;
}




void output_current_move(FILE* outfile, int target_row, int target_col, Board board[], Fleet fl[], int reprs_num, int reprs_ship_num)
{
	int reprs_enemy_num = 1 - reprs_num;      // 1 - 0 = 1,  or  1 - 1 = 0

	char sh_t[20] = "";

	if (board[reprs_enemy_num].game_board[target_row][target_col].symbol == '*')   //It is a hit
	{
		fprintf(outfile, "Player %d shoots:\n\t(%d , %d) was a hit!\n", reprs_num + 1, target_row, target_col);

		if (  check_if_sunk_ship( fl[reprs_enemy_num].sh[reprs_ship_num] ) == 1 )  //This ship was sunk after this shot
		{
	       //First, we determine the type of this ship
			switch (reprs_ship_num)
			{
			case 0:  strcpy(sh_t, "Carrier"); break;
			case 1:  strcpy(sh_t, "Battleship"); break;
			case 2:  strcpy(sh_t, "Cruiser"); break;
			case 3:  strcpy(sh_t, "Submarine"); break;
			case 4:  strcpy(sh_t, "Destroyer"); break;
			}

			//Display to the output file
			fprintf(outfile, "  The ship %s in the fleet %d was sunk!\n", sh_t, reprs_enemy_num + 1);
		}
	}


	else if (board[reprs_enemy_num].game_board[target_row][target_col].symbol == 'm')   //It is a miss
	{
		fprintf(outfile, "Player %d shoots:\n\t(%d , %d) was a miss!\n", reprs_num + 1, target_row, target_col);
	}


}


void update_hits_misses_ratio(Stats sta[])
{
	int i;  //index

	for (i = 0; i < 2; i++)
	{
		sta[i].hits_misses_ratio = ((double)sta[i].num_hits / (double)sta[i].num_misses) * 100;  //perform as a percentage
	}

}





void output_stats(FILE* outfile, Stats sta[])
{
	char res0[10], res1[10];

	if ((int)sta[0].res == 0)
	{
		strcpy(res0, "Won");  strcpy(res1, "Lost");
	}

	else
	{
		strcpy(res0, "Lost");  strcpy(res1, "Won");
	}

	fprintf(outfile, "\t*********************************************************************************************************\n");
	fprintf(outfile, "\t\t\t\t\t                         Game Statistics\n");

	fprintf(outfile, "\t                                  Player 1\t        Player 2\n");
	fprintf(outfile, "  Total number of shots:                 %d\t                %d\n", sta[0].total_shots, sta[1].total_shots);
	fprintf(outfile, "  Total number of hits:                  %d\t                %d\n", sta[0].num_hits, sta[1].num_hits);
	fprintf(outfile, "  Total number of misses:                %d\t                %d\n", sta[0].num_misses, sta[1].num_misses);
	fprintf(outfile, "  Hits to misses ratio:                %.2lf%%\t          %.2lf%%\n", sta[0].hits_misses_ratio, sta[1].hits_misses_ratio);
	fprintf(outfile, "  Final result:\t                        %s\t               %s\n", res0, res1);

}
// This is the start of the game Connect 4.

// History: 3/31 - Completed defining a struct for a Cell.
//                 Introduced an enum type for Boolean.
//                 Defined a struct for a Board object.
//                 Implemented init_board ().
//          3/29 - Started defining the structs
//                 required for our game of Connect 4.
//                 We defined a struct for a Token.
//                 We implemented a function called
//                 set_token ().
//                 We partially defined a struct for a
//                 Cell. We'll continue with this example
//                 on 3/31.

#include "ConnectFour.h"

int main(void)
{
	Board board1 = { {{{0,0}, FALSE, {'\0'}}} };

	init_board(&board1);

	/*Token p1_token = { '\0' };
	Cell c1 = { {0, 0} };

	set_token(&p1_token, 'R');
	printf("token color: %c\n", p1_token.color);

	c1.location.row = 1;
	c1.location.col = 1;*/

	return 0;
}
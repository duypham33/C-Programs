
/*
      * Programmer: Duy Pham

      * Class: CptS 121, Spring 2021; Section 01; Lab Section 14

      * Programming Assignment:      PA 6: Basic Game of Battleship

      * Date: April 7, 2021

      * Description: This program simulates the game of Battleship:
                       - This is a two player game. The Player to sink his/her enemy's fleet first wins.
                       - Two 10x10 boards exist within the game.
                       - Both players' fleets consist of 5 ships that are hidden from the enemy. 
                       -Each ship may be differentiated by its "size" (besides the Cruiser and Submarine) or number of cells it expands on the game board. 
                          The Carrier has 5 cells, Battleship has 4 cells, Cruiser has 3 cells, Submarine has 3 cells, and the Destroyer has 2 cells.
*/


#include "header.h"


int main(void)
{

    FILE* outfile;
    outfile = fopen("battleship.log", "w");

    Board board[2];        // board[0] for player 1, board[1] for player 2
    Fleet fl[2];           // fl[0] for player 1, fl[1] for player 2

    Stats sta[2] = { {0, 0, 0, 0.0, Lost } };      // sta[0] for player 1, sta[1] for player 2

    int reprs_num;      // This value will change alternately as 0 and 1, to keep track of every catogories realated to player 1 and 2 accordingly

    int opt = 0;        //option(1, or 2) to either manually place each of the 5 ships in his/her fleet or to have them randomly placed on the board

    int i;   //index for loops used

    int target_row, target_col;     //The row index and column index of the target position to shoot

    int reprs_ship_num;   //represents the ship type ( 0-Carrier, 1-Battleship, 2-Cruiser, 3-Submarine, and 4-Destroyer)

    int num_games = 0;    //The number of games taken

    int win_status;

    char ans;     // 'y' for yes, 'n' for no


    srand((unsigned int)time(NULL));


    do      //The loop for the whole of one game
    {
        //Print the game rules to the screen
        welcome_screen();
        printf("\nPlease hit the ENTER to start the game!\n");
        getch();
        system("cls");   //Clear the screen


        num_games++;    //increment the number of games taken
        fprintf(outfile, "\n\n       **********Data and Statistics of Game %d**********\n\n", num_games);


        //Initialize the two game boards of the two players before the game
        init_game_board(&board[0]); init_game_board(&board[1]);

        //Initialize the two stats of the two players before the game
        init_stats(&sta[0]); init_stats(&sta[1]);

        //Initialize the two fleets of the two players before the game
        init_ships(&fl[0]);  init_ships(&fl[1]);



        //Ask either manually place each of the 5 ships in his/her fleet or to have them randomly placed on the board
        printf("Please select from the following menu:\n1. Enter positions of ships manually.\n2. Allow the program to randomly select positions of ships.\n");
        printf("Your option (1 or 2): ");
        scanf("%d", &opt);


        if (opt == 1)       //Manually place ships
        {
            for (i = 0; i < NUM_SHIPS; i++)
            {
                manually_place_ships_on_board(&fl[0].sh[i], &board[0]);
            }

        }

        else if (opt == 2)    //Randomly place ships
        {
            randomly_place_ships_on_board(&fl[0], &board[0]);
        }


        printf("\n");
        randomly_place_ships_on_board(&fl[1], &board[1]);              //Randomly place Player2's ships
        printf("Player2 (Computer's) board has been generated!\n");

        printf("Please hit the ENTER to continue!");  getch();  system("cls");     //Clear the screen



        //Randomly select Player1 or Player2 to go first.
        reprs_num = select_who_starts_first();


        do          //The loop for each turn of each player
        {

            display_board(board);      //Display the two game boards to the screen

            if (reprs_num == 0)      //Player1's turn
            {
                prompt_target_position(&target_row, &target_col, reprs_num, board);     //Prompt the player 1 for coordinates of target cell
                system("cls");    //Clear the screen

                check_shot_and_update_board(target_row, target_col, board, sta, fl, reprs_num, &reprs_ship_num);   //Check whether the shot was a hit or miss 
            }

            else     //Player2's turn
            {
                randomly_choose_target_position(&target_row, &target_col, reprs_num, board);     //Randomly choose coordinates of target cell

                check_shot_and_update_board(target_row, target_col, board, sta, fl, reprs_num, &reprs_ship_num);   //Check whether the shot was a hit or miss

                printf("Hit ENTER to continue!"); getch(); system("cls");     //Clear the screen
            }


            output_current_move(outfile, target_row, target_col, board, fl, reprs_num, reprs_ship_num);    //Write data of each turn to the output file


            reprs_num = 1 - reprs_num;       // 1 - 0 = 1,  or  1 - 1 = 0,  to move on the other player's turn

        } while (is_winner(sta) == 0);       //The loop will continue if there has not been any player winning yet


        win_status = is_winner(sta);        //To directly compute variables of Stats 

        update_hits_misses_ratio(sta);      //Compute hits to misses ratio directly



        display_board(board);       //Display the final board before ending 
        printf("\n*******************************************************************************\n");

        //Determine and print the winner to the screen
        if (sta[0].res == Won)
        {
            printf("\t\tYou (Player1) won! Congratulations!\n\n");

        }

        else
        {
            printf("\t\tPlayer2 Won! You lost!\n\n");
        }


        //Print the statistics to the output file
        output_stats(outfile, sta);



        //Ask the user if he/she wants to play the game again
        printf("\n**************************************************************************************************\n");
        printf("\t\t\tWould you like to play again (y/n)? ");
        scanf(" %c", &ans);

        system("cls");    //clear the screen

        if (ans == 'n')   //If no, print the goodbye message and quit the program
        {
            printf("Thank you for joining us! See you next time!\n");
        }



    } while (ans == 'y');     //If yes, turn back the menu to continue playing the game






    fclose(outfile);   //close the file



    return 0;    //The program was successful
}
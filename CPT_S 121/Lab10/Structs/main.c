
/*
      * Programmer: Duy Pham

      * Class: CptS 121, Spring 2021; Section 01; Lab Section 14

      * Programming Assignment:      Lab 10: Structs

      * Date: March 29, 2021

      * Description: This program performs two different tasks:
                      - Task 1: A program that uses random number generation to create sentences
                      - Task 2: A two-player interactive game to play Tic Tac Toe. The game board for Tic Tac Toe will be represented by a 2-Dimensional array of structs.
*/


#include "header.h"


int main(void)
{
    //Task 1
    printf("1) ");   //start task 1


    char* article[] = { "the", "a", "one", "some", "any" };
    char* noun[] = { "boy", "girl", "dog", "town", "car" };
    char* verb[] = { "drove", "jumped", "ran", "walked", "skipped" };
    char* preposition[] = { "to", "from", "over", "under", "on" };


    srand((unsigned int)time(NULL));


    int i = 0;
    int j = 1;      //to count the number of sentence
    int holder[6];  //to save random numbers generated

    printf("\tThe 20 sentences generated!\n\n");

    do
    {
        for (i = 0; i < 6; i++)
        {
            holder[i] = rand() % 5;

        }

        i = 0;   //reset i = 0
        printf("The sentence %d: ", j);

        if (j == 20) { upper_first_letter(holder[i]); }              //Because the final should start with a capital letter
        else { printf("%s ", article[holder[i]]); }

        printf("%s ", noun[holder[i++]]);
        printf("%s ", verb[holder[i++]]);
        printf("%s ", preposition[holder[i++]]);
        printf("%s ", article[holder[i++]]);
        printf("%s", noun[holder[i++]]);

        if (j == 20) { printf("!\n"); }                     //Because the final should end with an exclamation mark (!)
        else { printf("\n"); }


        j++;  //increment the number of sentence

    } while (j < 21);





    //Task 2
    printf("\n2) ");    //start task 2


    Board board1 = { { { 0, '\0', {0,0} } } };

    Game_info player[2] = { {0, 0, 0}, {0, 0, 0} };     //player[0] is with symbol O, player[1] is with symbol X


    int k = 0;


    int reprs_num;           //representative number for the player (0 for player with symbol O, 1 for the player with symbol X)

    char win_symbol = NULL;

    int num_game = 0;   //The number of game played
    char ans;   //'y' is yes, 'n' is no

    do
    {
        num_game++;

        init_board(&board1);    //reset the game board before a new game

        printf("\t\tTHE GAME (TURN %d) STARTS\n\n", num_game);

        reprs_num = select_first_player();


        do
        {
            //Prompt the player for a position (row and column) in which to draw his/her symbol
            choose_cell(reprs_num, &board1);

            display_board(&board1);

            //Change representative number for the player 

            if (reprs_num == 0)
            {
                reprs_num = 1;
            }

            else if (reprs_num == 1)
            {
                reprs_num = 0;
            }

        } while (is_win_horizontally(&board1, &win_symbol) == 0 && is_win_vertically(&board1, &win_symbol) == 0 && does_align_diagonally(&board1, &win_symbol) == 0
            && is_scratch(&board1) == 0);


        if (is_win_horizontally(&board1, &win_symbol) == 1)
        {
            k = is_win_horizontally(&board1, &win_symbol);
        }

        else if (is_win_vertically(&board1, &win_symbol) == 1)
        {
            k = is_win_vertically(&board1, &win_symbol);
        }

        else if (does_align_diagonally(&board1, &win_symbol) == 1)
        {
            k = does_align_diagonally(&board1, &win_symbol);
        }

        else
        {
            printf("\"Scratch\" game occurs and no player wins!\n");
        }


        printf("\nPlease press the key ENTER to view the game board! ");
        getch();

        printf("\n\t\t   THE GAME BOARD\n");
        display_board(&board1);

        display_winner(win_symbol, player);

        player[0].total_games_played++;
        player[1].total_games_played++;

        printf("\n*********************************************************\n");

        display_game_info(player);

        printf("\n*********************************************************\n");
        printf("Would you like to play again! ");
        scanf(" %c", &ans);    //'y' is yes, 'n' is no

        system("cls");  //clean the screen

        if (ans == 'n')
        {
            printf("Thank you for joining us! Goodbye!\n");
        }

    } while (ans == 'y');






    return 0;
}
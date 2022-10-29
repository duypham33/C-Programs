
/*
      * Programmer: Duy Pham

      * Class: CptS 121, Spring 2021; Section 01; Lab Section 14

      * Programming Assignment: PA 5 The Game of Yahtzee 

      * Date: March 24, 2021

      * Description: This program implements a game of Yahtzee according to the rules:
                          -Points are obtained by rolling five 6-sided die across thirteen rounds.
                          During each round, each player may roll the dice up to three times to make one of the possible scoring combinations.
                          Once a combination has been achieved by the player, it may not be used again in future rounds, 
                          except for the Yahtzee combination may be used as many times as the player makes the combination.
                          
                          
                          - The scorecard used for Yahtzee is composed of two sections. A upper section and a lower section.
                           A total of thirteen boxes or thirteen scoring combinations are divided amongst the sections.
                           The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box.                                                  
                           If the sum of the upper scores is greater than or equal to 63, then 35 more points are added to the players overall score as a bonus.
                           The lower section contains a number of poker like combinations.
                                         1. Sum of 1's        7. Three-of-a-kind
                                         2. Sum of 2's        8. Four-of-a-kind
                                         3. Sum of 3's        9. Full house
                                         4. Sum of 4's        10. Small straight
                                         5. Sum of 5's        11. Large straight
                                         6. Sum of 6's        12. Yahtzee
                                                     13. Chance
*/


#include "header.h"


int main(void)
{

    int num_rounds = 1;      //The number of rounds  (1-13)
    int num_rolls;           //The number of rolls that the player take in each round  (1-3)

    int i;    // i will change alternately as 1 and 2, to keep track of every catogories realated to player 1 and 2

    int die[NUM];     //The dice values of the five dice
    
    char save_opt;             //to ask the player if wants to use the roll for a combination  ('y' yes / 'n' no)
    char die_opt = NULL;       //to ask the player if wants to keep or not each die   ('k' keep / 'n' not)
    
    int comb_num;        //The number for a combination kind, for example 10 is for Small straight

    int comb_status[3][14] = { {0,1,2}, {0} };      /*comb_status[i][j] is status of the combnation j that player i choose, for example comb_status[1][9] is for Full house of player 1
                                                   when status = 1, that combination may not used in the future rounds  */

    int total_upper_score[3] = { 0, 0, 0 };     //total_upper_score[1] is the total upper score of the player 1, smilar to total_upper_score[2]
    int total_score[3] = { 0, 0, 0 };           //total_score[1] is the total score of the player 1, smilar to total_score[2]

    int comb_score[3][14] = { {0,1,2}, {0} };   //For example comb_score[1][7] is the Three-of-a-kind score of the player 1

    int bonus[2] = { 0,0 };                    // bonus[0] is the upper bonus of player 1, and bonus[1] is the upper bonus of player 2



    srand((unsigned int)time(NULL));





    printf("\t\t  WELCOME TO THE GAME OF YAHTZEE\n\n");

    int menu_option = 0;

    do
    {
        print_menu();              //Print a game menu for Yahtzee

        menu_option = get_menu_option();
        system("cls");           //Clear the screen after choosing a menu option




        switch (menu_option)
        {
        case 1: print_rules();           //option 1 is entered, then print the game rules
                break;

        case 2: break;
            
        case 3: printf("Good bye! Hope you will join us soon!\n");          //option 3 is entered, then print a goodbye message and quit the program
            break;

        default: printf("Your menu option is invalid!\n\n");          //option != 1,2, and 3, which is invalid
        }



        //Option 2 is entered, then the game start

        if (menu_option == 2)
        {
            printf("\n********************************************************************************************\n");
            printf("\t\t\tS T A R T  T H E  G A M E\n");

            do       //The loop for the whole game with 13 rounds
            {
                i = 1;      //Keep track of everything about the player 1, when a new round starts

                printf("\nR O U N D %d\n", num_rounds);

                do       //The loop for each round
                {
                    num_rolls = 1;      //Start the first roll in each round

                    printf("\nPLAYER %d\n", i);
                    printf("Please press the key ENTER to roll the dice!\n");    //Ask the player to hit the key ENTER to roll the dice
                    getch();

                    printf("The dice values of player %d in turn %d round %d:\n", i, num_rolls, num_rounds);
                    roll_dice(die, NUM);
                    display_dice(die, NUM);

                    do     //The loop for asking and choosing whether or not keep the dice
                    {
                        printf("\nDo you want to use this roll for one of the game combinations (y/n): ");
                        scanf(" %c", &save_opt);     // 'y' yes / 'n' no

                        if (save_opt == 'n')
                        {
                            ++num_rolls;      //increment the number of rolls, when doing re-roll 
                            printf("Please choose dice you want to re-roll:\n");
                            re_roll(die, NUM, die_opt);         // 'k' keep / 'n' not
                            system("cls");       //clear the screen before a new turn being displayed

                            printf("\nTurn %d\n", num_rolls);
                            display_dice(die, NUM);
                        }

                        else { break; }       //when save_opt == 'y', then choose one combination
                    } while (num_rolls < 3);


                    do     //The loop for choosing the game combination for the round
                    {
                        comb_num = choose_combination();      //Enter a number (1-13)
                        if (comb_status[i][comb_num] == 1)
                        {
                            printf("This combination has already used!\n");
                        }
                    } while (comb_status[i][comb_num] == 1);

                    display_comb(die, NUM, comb_num, comb_status, i, &total_score[i], &total_upper_score[i], comb_score);   //diplay the combination score that player just chose

                    i++;    //increment i to keep track of player 2

                } while (i < 3);   // i = only 1 or 2, to keep track for 2 players


                ++num_rounds;   //increment the number of rounds




            } while (num_rounds < 14);    //There are 13 rounds in total

            printf("\n\t\tPlease press the key Enter to view the game result!\n");    //Ask the user to hit key Enter to view the game result
            getch();
            system("cls");     //clear the screen before viewing the game result

            printf("\n*******************************************************************************************\n");



            //If the total score in the upper section is greater than or equal to 63 for a player, then add 35 points to the total score
            if (total_upper_score[1] > 62)
            {
                bonus[0] = 35;
            }

            if (total_upper_score[2] > 62)
            {
                bonus[1] = 35;
            }

            total_score[1] += bonus[0];
            total_score[2] += bonus[1];



            print_result_sheet(comb_score, total_upper_score, total_score, bonus);    //Print the game result


            //Print the winner

            printf("\n*******************************************************************************************\n");
            if (total_score[1] > total_score[2])
            {
                printf("\t\t\tTHE PLAYER 1 WIN!\n");
                printf("\n*******************************************************************************************\n");
            }

            else
            {
                printf("\t\t\tTHE PLAYER 2 WIN!\n");
                printf("\n*******************************************************************************************\n");
            }




            printf("\n\t\tPlease press the key ENTER to return the Game Menu!");   //Ask the user to hit key ENTER to return the game menu
            getch();
            system("cls");    //clear the screen before returning back the game menu



        }


    } while (menu_option != 3);    //Only the opition 3 will quit the game


    

   


    return 0;    //The program was successful

}
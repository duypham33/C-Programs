
/*
      * Programmer: Duy Pham

      * Class: CptS 121, Spring 2021; Section 01; Lab Section 14

      * Programming Assignment:   PA 7 Poker (5-Card Draw)

      * Date:     April 21, 2021

      * Description: This program implements a game of Poker (5-Card Draw) according to the rules:
                          - Play against a dealer(computer)
                           There are 5 cards on each hand. Players can select to draw up to three cards to replace old ones in each round
                           Once all of the players get their best hands, they will show their final set of cards

                          - The results are determined based on 6 following game combinaitons with priority order:
                                         1. Four of a kind:  Any four cards of the same rank. If both players have four of a kind, then compare the value strength of four kinds

                                         2. Flush:   Any five cards of the same suit which are not consecutive. 
                                                    The highest card of the five makes out the rank of the flush (like (*)) 

                                         3. Straight:  Any five consecutive cards of different suits. If both players have the value of straights, go to (*)      

                                         4. Three of a kind: Any three cards of the same rank. If both players get this type, then compare the value strength of three of a kind.       

                                         5. Two pairs: The highest pair of the two make out the rank of the two pairs. 

                                         6. One pair:  If both players have one pair, then compare the value strength of pairs. 
                                                                                                         
                                        (*) High card: Any hand that does not make up any of the above mentioned hands, then compare the highest cards.

*/


#include "header.h"


int main(void)
{



    /* initialize suit array */
    const char* suit[NUM_SUITS] = { "Hearts", "Diamonds", "Clubs", "Spades" };

    /* initialize face array */
    const char* face[NUM_FACES] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
        "Nine", "Ten", "Jack", "Queen", "King" };


    Hand Phand, Dhand;     //Phand is for the player(user), Dhand is for the dealer(computer)

    srand((unsigned)time(NULL)); /* seed random-number generator */

    int menu_opt = 0;   //The menu option (1,2,3 is valid)

    do    //The loop for all the game(Can return menu to play again)
    {
        /* initalize deck array */
        int deck[NUM_SUITS][NUM_FACES] = { 0 };

        int num_turns = 0;       //The number of the turns in each game
        int card_post = 1;       //The position of the first card on the deck at the time
        char save_opt = NULL;    // 'y' is yes, 'n' is no (to ask the user whether want to save the hand)
        int is_saved = 0;        //1 if the user saved the hand, 0 is otherwise
        int dealer_saved = 0;    //1 if the dealer saved the hand, 0 is otherwise

        int num_replaces = 0;    //The number of replaced cards (<=3) of the dealer


        int Prepr_comb_num = 0;  //The number representing for the player's combination type saved
        int Drepr_comb_num = 0;  //The number representing for the dealer's combination type saved


         /* initalize combination in each hand */
        init_comb(&Phand);
        init_comb(&Dhand);





        menu_opt = get_menu_option();   //Get the menu option from the user


        //Option 2 is entered, then the game start
        if (menu_opt == 2)
        {
            system("cls");   //Clear the screen
            printf("\t\t   START GAME\n");

            shuffle(deck);   //Shuffle the deck randomly
            printf("The deck was shuffled! Please hit ENTER to deal deck!");   getch();  system("cls");   //Clear the screen                   
            printf("\n\n");

            deal(deck, &Phand, &Dhand);   //Deal the deck
            card_post += 10;      //The card position on the deck = 11, after dealing 10 cards for the two players

            
            display_hands(num_turns, Phand, face, suit);   //Display the hands to the screen

            do    //The loop for all the turns in each game
            {
                if (card_post >= 49)
                {
                    printf("\nPlease note that the deck has only %d cards left!\n\n", 52 - card_post);
                }


                if (is_saved == 0)   //The user have not saved the hand yet
                {
                    printf("Do you want to save your current hand as the final one (y/n)?: ");  //Ask the user whether want to save the hand or not
                    scanf(" %c", &save_opt);

                    if (save_opt == 'n')  //If the answer is 'no'
                    {
                        //Ask the user whether keep or not each card respectively
                        printf("\nPlease choose cards you want to replace:\n");

                        //Replace cards 
                        replace_cards(&Phand, deck, &card_post);
                    }

                    else  //The answer is 'yes'
                    {
                        printf("Your hand was saved!\n\n");
                        is_saved = 1;   //saved
                    }
                }




                //Dealer's turn (Automatically replace cards based on the quality of the current hand with intelligence)

                if (dealer_saved == 0)    //The dealer have not saved the hand yet
                {

                    num_replaces = replace_dealer_cards(&Dhand, deck, &card_post);   //The number of cards should be replaced in this turn

                    if (num_replaces > 0)
                    {
                        printf("\nThe dealer did draw cards in this turn!\n");
                    }

                    else   //num_replaces == 0, which means saving the hand
                    {
                        printf("\nThe dealer decided to save current hand as the final one!\n");

                        dealer_saved = 1;  //saved
                    }
                }


                if (is_saved == 0 || dealer_saved == 0)   //If there is still at least one player continuing the turns
                {
                    getch();    system("cls");   //Clear the screen

                    num_turns++;
                    
                    display_hands(num_turns, Phand, face, suit);   //Display the hand after replacing cards to the screen
                }


                getch();

                if (is_saved == 1)
                {
                    system("cls");   //Clear the screen
                }

            } while ((is_saved == 0 || dealer_saved == 0) && card_post < 53);


            if (card_post == 53)   
            {
                printf("There is no card left!\n\n");
            }



            //Display the game result to the screen 
            printf("\n\t\t\t\t\t\t\t      THE GAME RESULT\n\n");

            printf("\t  User's hand:     ");
            display_final_hand(Phand, face, suit);
            display_final_comb(&Phand, &Prepr_comb_num);


            printf("\t  Dealer's hand:   ");
            display_final_hand(Dhand, face, suit);
            display_final_comb(&Dhand, &Drepr_comb_num);



            if (Prepr_comb_num < Drepr_comb_num)
            {
                printf("\t\t\t\t  Congratulations! You won the game!\n");
            }

            else if (Prepr_comb_num > Drepr_comb_num)
            {
                printf("\t\t\t\t  Sorry, you lost! The dealer won the game!\n");
            }



            //If both of them got the same game combinations
            else if (Prepr_comb_num == Drepr_comb_num)
            {
                determine_winner_with_same_comb(Prepr_comb_num, Phand, Dhand);
            }



            printf("   **********************************************************************************************************\n\n");
            printf("  Please hit the ENTER to return the game menu!");
            getch();
            system("cls");    //Clear the screen
        }

    } while (menu_opt != 3);    //Only the opition 3 will quit the game





    return 0;    //The program was successful

}
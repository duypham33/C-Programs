
/*

    This file is to establish the definitions for all programmer-defined functions, aside from main ()

*/


#include "header.h"


//Function definitions




//Functions for game menu

void print_menu()
{
    printf("\t\t\tG A M E  M E N U\n");
    printf("\t\t     1. Print game rules\n");
    printf("\t\t     2. Start a game of Poker (5-Card Draw)\n");
    printf("\t\t     3. Exit\n");
}



void print_rules()
{
    printf("\n\t\t\t\t\tG A M E  R U L E S\n");
    printf("\t\t-Play against a dealer(computer). There are 5 cards on each hands\n");
    printf("\t\t-Players can select to draw up to three cards to replace old ones in each round\n");
    printf("\t\t-Once all of the players get their best hands, they will show their final set of cards\n\n");
    printf("\t\t-The results are determined based on 6 following game combinaitons with priority order:\n");
    printf("\t\t   1. Four of a kind:  Any four cards of the same rank. If both players have four of a kind, then compare the value strength of four kinds\n\n");
    printf("\t\t   2. Flush:   Any five cards of the same suit which are not consecutive.\n");
    printf("\t\t               The highest card of the five makes out the rank of the flush (like (*))\n\n");
    printf("\t\t   3. Straight:  Any five consecutive cards of different suits. If both players have the value of straights, go to (*)\n\n");
    printf("\t\t   4. Three of a kind: Any three cards of the same rank. If both players get this type, then compare the value strength of three of a kind\n\n");
    printf("\t\t   5. Two pairs: The highest pair of the two make out the rank of the two pair. If they euqals, then compare the lowest pairs.\n\n");
    printf("\t\t   6. One pair:  If both players have one pair, then compare the value strength of pairs.\n\n");
    printf("\t\t   (*) High card: Any hand that does not make up any of the above mentioned hands, then compare the highest cards\n");
    printf("\t**********************************************************************************************\n\n");
}



int get_menu_option()
{
    int menu_option = 0;


    print_menu();

    printf("\nPlease choose your menu option: ");
    scanf("%d", &menu_option);

    switch (menu_option)
    {
    case 1: system("cls");
        print_rules();           //option 1 is entered, then print the game rules
        printf("\n\nPlease hit ENTER to return The Game Menu!"); getch();  system("cls");
        break;

    case 3: printf("Good bye! Hope you will join us soon!\n");          //option 3 is entered, then print a goodbye message and quit the program
        break;

    default: printf("Your menu option is invalid!\n\n");          //option != 1,2, and 3, which is invalid
    }


    return menu_option;
}








 //Functions for shuffling and dealing deck randomly


void shuffle(int wDeck[][NUM_FACES])     //shuffle cards in deck
{
    int row = 0;       // row number 
    int column = 0;    // column number 
    int card = 0;      // card counter 

    /* for each of the 52 cards, choose slot of deck randomly */
    for (card = 1; card <= 52; card++)
    {
        /* choose new random location until unoccupied slot found */
        do
        {
            row = rand() % NUM_SUITS;
            column = rand() % NUM_FACES;
        } while (wDeck[row][column] != 0);

        /* place card number in chosen slot of deck */
        wDeck[row][column] = card;
    }
}



// Phand is hand of the player(user), Dhand is hand of the dealer(computer) 

void deal(int wDeck[][NUM_FACES], Hand* Phand_ptr, Hand* Dhand_ptr)    
{
    int row = 0;      // row number 
    int column = 0;   // column number 
    int card = 0;     // card counter 

    int i = 0, j = 0;  //to count cards dealt

    /* deal each of the 52 cards */
    for (card = 1; card <= 10; card++)
    {
        /* loop through rows of wDeck */
        for (row = 0; row < NUM_SUITS; row++)
        {
            /* loop through columns of wDeck for current row */
            for (column = 0; column < NUM_FACES; column++)
            {
                /* if slot contains current card, display card */
                if (wDeck[row][column] == card)
                {
                    if (card % 2 == 1)   //Odd is for user's hand because of dealing cards alternately between two players
                    {
                        Phand_ptr->car[i].suit_index = row;
                        Phand_ptr->car[i].face_index = column;
                        i++;
                    }

                    else if (card % 2 == 0)  //Even if for the dealer because of dealing cards alternately between two players
                    {
                        Dhand_ptr->car[j].suit_index = row;
                        Dhand_ptr->car[j].face_index = column;
                        j++;
                    }
                }
            }
        }
    }
}



 //Display the two sets of cards of both players to the screen (User's hand is visible, but the dealer's hand is dealt "face down" as []
void display_hands(int num_turns, Hand Phand, const char* wFace[], const char* wSuit[])
{
    int row, col;
    int i;    //The index

    printf("\n Turn %d:\n", num_turns);

    printf("\t  User's hand:   ");
    for (i = 0; i < NUM_CARDS; i++)
    {
        row = Phand.car[i].suit_index; 
        col = Phand.car[i].face_index;
        printf("%5s of %-8s    ", wFace[col], wSuit[row]);
    }
    printf("\n\n");


    printf("\t  Dealer's hand:   ");
    
    printf("[]    []    []    []    []");
    printf("\n\n");

}






void replace_cards(Hand* Phand_ptr, int wDeck[][NUM_FACES], int* card_post_ptr)
{
    char opt;    //'k' for keep, 'n' for not
    int i;
    int row, col;
    int reset = *card_post_ptr;
    int num_replace;    //To count the number of replaced cards (<=3)

    do
    {
        *card_post_ptr = reset;   //Reset the value of the card position when the process is invalid. We are re-doing again.
        num_replace = 0;

        for (i = 0; i < NUM_CARDS; i++)
        {
            printf("Card%d 'k'(keep) / 'n'(not): ", i + 1);
            scanf(" %c", &opt);
            if (opt == 'n')
            {
                if (*card_post_ptr == 53)
                {
                    printf("There is no card left! Please try again with less discards!\n\n");
                }


                else
                {

                    for (row = 0; row < NUM_SUITS; row++)
                    {
                        for (col = 0; col < NUM_FACES; col++)
                        {
                            if (wDeck[row][col] == *card_post_ptr)
                            {
                                Phand_ptr->car[i].suit_index = row;
                                Phand_ptr->car[i].face_index = col;
                            }
                        }
                    }

                    ++* card_post_ptr;
                    num_replace++;

                    if (num_replace > 3)
                    {
                        printf("You may not replace more than three cards! Please try again!\n\n");
                        break;  //break the loop
                    }

                }
            }
        }

    } while (num_replace > 3 || *card_post_ptr >= 53);


}





//Functions for determing game combinations

int is_one_pair(Hand wHand)
{
    int i, j;   //The index
    int count = 0;

    for (i = 0; i < NUM_CARDS - 1; i++)
    {
        for (j = i + 1; j < NUM_CARDS; j++)
        {
            if (wHand.car[i].face_index == wHand.car[j].face_index)
            {
                count++;
                break;
            }
        }
    }

    if (count == 1)
        return 1;   //True

    else
        return 0;  //False
}



int is_two_pairs(Hand wHand)
{

    int i, j;   //The index
    int count = 0;
    int face1, face2 = 0;


    for (i = 0; i < NUM_CARDS - 1; i++)
    {
        for (j = i + 1; j < NUM_CARDS; j++)
        {
            if (wHand.car[i].face_index == wHand.car[j].face_index)
            {
                count++;
                if (count == 1) { face1 = wHand.car[j].face_index; }

                else if (count == 2) { face2 = wHand.car[j].face_index; }

                break;
            }
        }
    }


    if (count == 2 && (face1 - face2) != 0)   //To check if two pairs are different. If not, it is a three of a kind 
        return 1;   //True

    else
        return 0;  //False

}





int number_of_k_in_hand(Hand wHand, int k)
{
    int count = 0;
    for (int i = 0; i < NUM_CARDS; i++)
    {
        if (wHand.car[i].face_index == k)
        {
            count++;
        }
    }

    return count;
}





int is_three_of_a_kind(Hand wHand)
{
    int i, j;
    int flag = 0;   //0 is false, 1 is true

    for (i = 0; i < NUM_CARDS - 1; i++)
    {
        for (j = i + 1; j < NUM_CARDS; j++)
        {
            if (wHand.car[i].face_index == wHand.car[j].face_index)
            {
                if (number_of_k_in_hand(wHand, wHand.car[i].face_index) == 3)
                {
                    flag = 1;
                    break;
                }
            }
        }

        if (flag == 1) { break; }
    }


    return flag;

}





int is_four_of_a_kind(Hand wHand)
{
    int i, j;
    int flag = 0;   //0 is false, 1 is true

    for (i = 0; i < NUM_CARDS - 1; i++)
    {
        for (j = i + 1; j < NUM_CARDS; j++)
        {
            if (wHand.car[i].face_index == wHand.car[j].face_index)
            {
                if (number_of_k_in_hand(wHand, wHand.car[i].face_index) == 4)
                {
                    flag = 1;
                    break;
                }
            }
        }

        if (flag == 1) { break; }
    }


    return flag;

}







int number_of_suit_type_in_hand(Hand wHand, int suit_t)
{
    int count = 0;
    int i;  //The index

    for (i = 0; i < NUM_CARDS; ++i)
    {
        if (wHand.car[i].suit_index == suit_t)
        {
            count++;
        }
    }

    return count;

}


int is_flush(Hand wHand)
{
    int flag = 0;   //0 is false, 1 is true

    int suit_t = wHand.car[0].suit_index;

    if (number_of_suit_type_in_hand(wHand, suit_t) == 5)
    {
        flag = 1;
    }

    return flag;
}






/*
   We will determine whether a hand is straight by three following functions:
    1) int is_k_in_hand(Hand wHand, int k) is to determine whether a face value is in that hand. If yes, return 1; no, return 0

    2) Then we create an int array:  int a[13];   with a[i] = is_k_in_hand(Hand wHand, int i)

       We will create a function called  int is_straight_from_position_k (Hand wHand, int k), in order to determine whether a[k], a[k+1], a[k+2], a[k+3], a[k+4] all equal 1 (k in [0,9])

   3) Finally, function int is_straight(Hand wHand) is to determine whether that hand is straight or not
               by determining whether there exists one value equal 1 from is_straight_from_position_k (Hand wHand, int k) (k from 0 to 9)
*/



int is_k_in_hand(Hand wHand, int k)
{
    int i;  //The index
    int flag = 0;   //0 is false, 1 is true

    for (i = 0; i < NUM_CARDS; ++i)
    {
        if (wHand.car[i].face_index == k)
        {
            flag = 1;
            break;  //break the loop
        }
    }

    return flag;
}



int is_straight_from_position_k(Hand wHand, int k)
{
    int a[NUM_FACES];
    int i;   //The index
    int flag = 0;   //0 is false, 1 is true

    for (i = 0; i < NUM_FACES; i++)
    {
        a[i] = is_k_in_hand(wHand, i);
    }


    if (k == 9)    //A straight of Ten, Jack, Queen, King, and Ace
    {
        if (a[9] == 1 && a[10] == 1 && a[11] == 1 && a[12] == 1 && a[0] == 1)
        {
            flag = 1;
        }
    }

    else if (k >= 0 && k <= 8)
    {
        if (a[k] == 1 && a[k + 1] == 1 && a[k + 2] == 1 && a[k + 3] == 1 && a[k + 4] == 1)
        {
            flag = 1;
        }
    }

    return flag;
}



int is_straight(Hand wHand)
{
    int i;            //The index
    int flag = 0;     //0 is false, 1 is true

    for (i = 0; i <= 9; i++)
    {
        if (is_straight_from_position_k(wHand, i) == 1)
        {
            flag = 1;
            break;   //break the loop
        }
    }

    return flag;
}





//Functions for simulating the dealer with basic intelligence



int is_nearly_flush(Hand wHand)
{
    int i;          //The index
    int flag = 0;    //0 is false, 1 is true

    for (i = 0; i < NUM_CARDS; ++i)
    {
        if (number_of_suit_type_in_hand(wHand, wHand.car[i].suit_index) >= 3)
        {
            flag = 1;
        }
    }

    return flag;
}








int replace_dealer_cards(Hand* wDhand_ptr, int wDeck[][NUM_FACES], int* card_post_ptr)
{
    int num_replaces = 0;    //The number of replaced cards (<=3)
    int i;   //The index for loops

    int row, col;   //The indexes for suits and faces



    /*
        First priority: Try to get Four of a kind
    */

    if (is_four_of_a_kind(*wDhand_ptr) == 1)    //If the hand is four of a kind, should save, no need to replace any card
    {
        num_replaces = 0;
    }




    else if (is_three_of_a_kind(*wDhand_ptr) == 1)   //If it is three of a kind, should replace the two others to try to have four of a kind
    {

        for (i = 0; i < NUM_CARDS; ++i)
        {
            if (*card_post_ptr == 53) { break; }

            else
            {
                if (number_of_k_in_hand(*wDhand_ptr, wDhand_ptr->car[i].face_index) < 3)    //This card should be replaced
                {
                    for (row = 0; row < NUM_SUITS; row++)
                    {
                        for (col = 0; col < NUM_FACES; col++)
                        {
                            if (wDeck[row][col] == *card_post_ptr)
                            {
                                wDhand_ptr->car[i].suit_index = row;
                                wDhand_ptr->car[i].face_index = col;
                            }
                        }
                    }

                    ++* card_post_ptr;
                    ++num_replaces;
                }
            }
        }

    }






    /*
        Second priority: Try to get a flush
    */


    else if (is_flush(*wDhand_ptr) == 1)    //If it is flush, should save
    {
        num_replaces = 0;
    }



    else if (is_nearly_flush(*wDhand_ptr) == 1) //If it is nearly flush, should keep as many cards with same suit as possible, and replace the others to try to get flush
    {
        for (i = 0; i < NUM_CARDS; ++i)
        {
            if (*card_post_ptr == 53) { break; }

            else
            {
                if (number_of_suit_type_in_hand(*wDhand_ptr, wDhand_ptr->car[i].suit_index) < 3)    //This card should be replaced
                {
                    for (row = 0; row < NUM_SUITS; row++)
                    {
                        for (col = 0; col < NUM_FACES; col++)
                        {
                            if (wDeck[row][col] == *card_post_ptr)
                            {
                                wDhand_ptr->car[i].suit_index = row;
                                wDhand_ptr->car[i].face_index = col;
                            }
                        }
                    }

                    ++* card_post_ptr;
                    num_replaces++;
                }
            }
        }
    }










    /*
        Third priority: Try to get a straight
    */

    else if (is_straight(*wDhand_ptr) == 1)    //If it is straight, should save
    {
        num_replaces = 0;
    }






    /*
        4th priority: Try to get Three of a kind
    */


    else if (is_two_pairs(*wDhand_ptr) == 1)      //If it is a two-pair, should replace the other one to try to have a three of a kind
    {
        //Replace the other one

        for (i = 0; i < NUM_CARDS; ++i)
        {
            if (*card_post_ptr == 53) { break; }

            else
            {
                if (number_of_k_in_hand(*wDhand_ptr, wDhand_ptr->car[i].face_index) == 1)    //This card should be replaced
                {
                    for (row = 0; row < NUM_SUITS; row++)
                    {
                        for (col = 0; col < NUM_FACES; col++)
                        {
                            if (wDeck[row][col] == *card_post_ptr)
                            {
                                wDhand_ptr->car[i].suit_index = row;
                                wDhand_ptr->car[i].face_index = col;
                            }
                        }
                    }

                    ++num_replaces;
                    ++* card_post_ptr;
                }
            }
        }
    }




    else     //This case may be one pair or not in any combination. This case will have at least three distinct face values. So replace all of them.
    {

        for (i = 0; i < NUM_CARDS; ++i)
        {
            if (*card_post_ptr == 53 || num_replaces == 3) { break; }

            else
            {
                if (number_of_k_in_hand(*wDhand_ptr, wDhand_ptr->car[i].face_index) == 1)    //This card should be replaced
                {
                    for (row = 0; row < NUM_SUITS; row++)
                    {
                        for (col = 0; col < NUM_FACES; col++)
                        {
                            if (wDeck[row][col] == *card_post_ptr)
                            {
                                wDhand_ptr->car[i].suit_index = row;
                                wDhand_ptr->car[i].face_index = col;
                            }
                        }
                    }

                    ++* card_post_ptr;
                    num_replaces++;
                }
            }
        }
    }





    return num_replaces;

}









//Functions for the game result

void display_final_hand(Hand wHand, const char* wFace[], const char* wSuit[])
{
    int row, col;
    int i;    //The index


    for (i = 0; i < NUM_CARDS; i++)
    {
        row = wHand.car[i].suit_index;
        col = wHand.car[i].face_index;
        printf("%5s of %-8s    ", wFace[col], wSuit[row]);
    }
    printf("\n");

}




void init_comb(Hand* wHand_ptr)
{
    int i;   //The index for loop

    for (i = 0; i < NUM_COMBINATIONS; ++i)
    {
        wHand_ptr->comb[i] = 0;    //0 if the hand is not in the corresponding combination, 1 is otherwise
    }

}



void display_final_comb(Hand* wHand_ptr, int* repr_comb_num)
{
    if (is_four_of_a_kind(*wHand_ptr) == 1)
    {
        wHand_ptr->comb[0] = 1;
        *repr_comb_num = 0;      //0 is for four of a kind

        printf("\t\t\t\t\t\t\t    (FOUR OF A KIND)\n\n");
    }


    else if (is_flush(*wHand_ptr) == 1)
    {
        wHand_ptr->comb[1] = 1;
        *repr_comb_num = 1;      //1 is for flush

        printf("\t\t\t\t\t\t\t      (FLUSH)\n\n");
    }

    else if (is_straight(*wHand_ptr) == 1)
    {
        wHand_ptr->comb[2] = 1;
        *repr_comb_num = 2;      //2 is for straight

        printf("\t\t\t\t\t\t\t      (STRAIGHT)\n\n");
    }

    else if (is_three_of_a_kind(*wHand_ptr) == 1)
    {
        wHand_ptr->comb[3] = 1;
        *repr_comb_num = 3;      //3 is for three of a kind

        printf("\t\t\t\t\t\t\t    (THREE OF A KIND)\n\n");
    }

    else if (is_two_pairs(*wHand_ptr) == 1)
    {
        wHand_ptr->comb[4] = 1;
        *repr_comb_num = 4;      //4 is for two pairs

        printf("\t\t\t\t\t\t\t     (TWO PAIRS)\n\n");
    }


    else if (is_one_pair(*wHand_ptr) == 1)
    {
        wHand_ptr->comb[5] = 1;
        *repr_comb_num = 5;      //5 is for one pair

        printf("\t\t\t\t\t\t\t     (ONE PAIR)\n\n");
    }


    else
    {
        *repr_comb_num = 6;      //6 is out of combinations, it is a type of high card

        printf("\t\t\t\t\t\t  (NO COMBINATION MADE, IT WILL BE A TYPE OF HIGH CARD)\n\n");
    }

}


int index_highest_card_in_hand(Hand wHand)
{
    int i, j;   //The index for loop
    int max_value = wHand.car[0].face_index;

    int suit = 0;
    int car_index = 0;

    //Note: Ace is the highest face value
    if (max_value != 0)   //if is not an Ace
    {
        for (i = 1; i < NUM_CARDS; ++i)
        {
            if (max_value < wHand.car[i].face_index || wHand.car[i].face_index == 0)
            {
                max_value = wHand.car[i].face_index;
                car_index = i;

                if (max_value == 0)
                {
                    break;
                }
            }
        }
    }


    //If the hand have more than one face value of max, we compare the suit Hearts > Diamonds > Clubs > Spades
    if (number_of_k_in_hand(wHand, max_value) > 1)
    {
        for (i = 0; i < NUM_CARDS - 1; ++i)
        {
            if (wHand.car[i].face_index == max_value)
            {
                car_index = i;
                suit = wHand.car[i].suit_index;

                for (j = i + 1; j < NUM_CARDS; ++j)
                {
                    if (wHand.car[j].face_index == max_value && wHand.car[j].suit_index < suit)
                    {
                        suit = wHand.car[j].suit_index;
                        car_index = j;
                    }
                }

                break;   //Break the loop since car_index has been found
            }
        }
    }


    return car_index;
}







int determine_who_has_higher_card(Hand wPhand, Hand wDhand, int Pindex, int Dindex)
{
    /*
       Assume that we need to compare card[Pindex] of the Player and card[Dindex] of the dealer.
       This function comparse them and determines who has the higher card. It returns 1 if it is the player, 2 if it is the dealer.

       This function is useful to determine who is the winner if both of them got the same game combinations.
    */




    int flag = -1;   //1 if it is the player, 2 if it is the dealer


    if (wPhand.car[Pindex].face_index == 0) { wPhand.car[Pindex].face_index = 13; }   //Ace. It helps compare more easily
    if (wDhand.car[Dindex].face_index == 0) { wDhand.car[Dindex].face_index = 13; }   //Ace. It helps compare more easily


    if (wPhand.car[Pindex].face_index < wDhand.car[Dindex].face_index)
    {
        flag = 2;
    }

    else if (wPhand.car[Pindex].face_index > wDhand.car[Dindex].face_index)
    {
        flag = 1;
    }


    //If the face values are the same, we compare the suit Hearts > Diamonds > Clubs > Spades
    else if (wPhand.car[Pindex].face_index == wDhand.car[Dindex].face_index)
    {
        if (wPhand.car[Pindex].suit_index < wDhand.car[Dindex].suit_index) { flag = 1; }

        else { flag = 2; }
    }


    return flag;    //1 if it is the player, 2 if it is the dealer
}









int determine_who_has_higher_pair(Hand wPhand, Hand wDhand, int Ppair_value, int Dpair_value)
{
    /*
       Assume that the player has a value of a pair (called Ppair_value) and the dealer also has a value of a pair (called Dpair_value)
       This function comparse them and determines who has the higher pair. It returns 1 if it is the player, 2 if it is the dealer.

       This function is useful to determine who is the winner if both of them got the Two pairs or One pair.
    */


    int flag = -1;   //1 if it is the player, 2 if it is the dealer

    int i, j;   //The indexes for loops
    int suit1 = 0, suit2 = 0;
    int index1 = 0, index2 = 0;


    /*
       Firstly, We find the higher card between the two cards of the pair in Player's hand
    */
    for (i = 0; i < NUM_CARDS - 1; ++i)
    {

        if (wPhand.car[i].face_index == Ppair_value)
        {
            suit1 = wPhand.car[i].suit_index;
            index1 = i;

            for (j = i + 1; j < NUM_CARDS; ++j)
            {
                if (wPhand.car[j].face_index == Ppair_value && wPhand.car[j].suit_index < suit1)   //Hearts > Diamonds > Clubs > Spades
                {
                    index1 = j;
                    break;   //Break the loop
                }
            }

            break;  //Break the loop since the index1 has been found

        }
    }



    /*
         Similarly, we find the higher card between the two cards of the pair in Dealer's hand
     */
    for (i = 0; i < NUM_CARDS - 1; ++i)
    {

        if (wDhand.car[i].face_index == Dpair_value)
        {
            suit2 = wDhand.car[i].suit_index;
            index2 = i;

            for (j = i + 1; j < NUM_CARDS; ++j)
            {
                if (wDhand.car[j].face_index == Dpair_value && wDhand.car[j].suit_index < suit2)   //Hearts > Diamonds > Clubs > Spades
                {
                    index2 = j;
                    break;
                }
            }

            break;  //Break the loop since the index2 has been found
        }
    }




    /*
       Now, we compare them thanks to determine_who_has_higher_card()
    */
    int k = determine_who_has_higher_card(wPhand, wDhand, index1, index2);



    return k;    //1 if it is the player, 2 if it is the dealer
}










void determine_winner_with_same_comb(int repr_comb_num, Hand wPhand, Hand wDhand)
{
    int i, j;     //The indexes for loops
    int a1 = 0, a2 = 0;

    int k = 0;   //Need k = determine_win_with_highest_card(wPhand, wDhand)


    //Four of a kind: If both players have four of a kind, then compare the value strength of four kinds
    if (repr_comb_num == 0)
    {
        for (i = 0; i < NUM_CARDS; ++i)
        {
            if (number_of_k_in_hand(wPhand, wPhand.car[i].face_index) == 4)
            {
                a1 = wPhand.car[i].face_index;
                break;  //Break the loop
            }
        }

        for (i = 0; i < NUM_CARDS; ++i)
        {
            if (number_of_k_in_hand(wDhand, wDhand.car[i].face_index) == 4)
            {
                a2 = wDhand.car[i].face_index;
                break;  //Break the loop
            }
        }

        if (a1 == 0) { a1 = 13; }   //Ace. It helps compare more easily
        if (a2 == 0) { a2 = 13; }   //Ace. It helps compare more easily

        printf("\t\t\t\t%s won the game with the higher four of a kind!\n", a1 < a2 ? "Sorry, you lost! The dealer" : "Congratulations! You");
    }




    //Flush: Go to the case of Highest card
    if (repr_comb_num == 1)
    {
        k = determine_who_has_higher_card(wPhand, wDhand, index_highest_card_in_hand(wPhand), index_highest_card_in_hand(wDhand));    //1 if player wins, 2 if dealer wins

        printf("\t\t\t\t%s won the game with the higher highest card in flushes!\n", k == 2 ? "Sorry, you lost! The dealer" : "Congratulations! You");
    }




    //Straight: Go to the case of Highest card (Because the highest cards in straights may determine which one is higher) 
    if (repr_comb_num == 2)
    {
        k = determine_who_has_higher_card(wPhand, wDhand, index_highest_card_in_hand(wPhand), index_highest_card_in_hand(wDhand));    //1 if player wins, 2 if dealer wins

        printf("\t\t\t\t%s won the game with the higher straight!\n", k == 2 ? "Sorry, you lost! The dealer" : "Congratulations! You");
    }





    //Three of a kind: If both players get this type, then compare the value strength of three of a kind
    if (repr_comb_num == 3)
    {
        for (i = 0; i < NUM_CARDS; ++i)
        {
            if (number_of_k_in_hand(wPhand, wPhand.car[i].face_index) == 3)
            {
                a1 = wPhand.car[i].face_index;
                break;  //Break the loop
            }
        }

        for (i = 0; i < NUM_CARDS; ++i)
        {
            if (number_of_k_in_hand(wDhand, wDhand.car[i].face_index) == 3)
            {
                a2 = wDhand.car[i].face_index;
                break;  //Break the loop
            }
        }

        if (a1 == 0) { a1 = 13; }   //Ace. It helps compare more easily
        if (a2 == 0) { a2 = 13; }   //Ace. It helps compare more easily

        printf("\t\t\t\t%s won the game with the higher three of a kind!\n", a1 < a2 ? "Sorry, you lost! The dealer" : "Congratulations! You");
    }




    //Two pairs: The highest pair of the two make out the rank of the two pairs. 
    if (repr_comb_num == 4)
    {
        int Phighpair_val = 0, Dhighpair_val = 0;


        /*
           Firstly, we find the value of highest pair in player's hand
        */
        for (i = 0; i < NUM_CARDS - 1; ++i)
        {
            if (number_of_k_in_hand(wPhand, wPhand.car[i].face_index) == 2)
            {
                Phighpair_val = wPhand.car[i].face_index;

                if (Phighpair_val == 0)    //The Ace is definitely the highest
                {
                    break;
                }

                else
                {
                    for (j = i + 1; j < NUM_CARDS; ++j)
                    {
                        if ((number_of_k_in_hand(wPhand, wPhand.car[j].face_index) == 2 && wPhand.car[j].face_index > Phighpair_val) || wPhand.car[j].face_index == 0)
                        {
                            Phighpair_val = wPhand.car[j].face_index;
                            break;
                        }
                    }
                }

                break;   //Break the loop since the Phighpair_val has been found
            }
        }




        /*
           Similarly, we find the value of highest pair in dealer's hand
        */
        for (i = 0; i < NUM_CARDS - 1; ++i)
        {
            if (number_of_k_in_hand(wDhand, wDhand.car[i].face_index) == 2)
            {
                Dhighpair_val = wDhand.car[i].face_index;

                if (Dhighpair_val == 0)   //The Ace is definitely the highest
                {
                    break;
                }

                else
                {
                    for (j = i + 1; j < NUM_CARDS; ++j)
                    {
                        if ((number_of_k_in_hand(wDhand, wDhand.car[j].face_index) == 2 && wDhand.car[j].face_index > Dhighpair_val) || wDhand.car[j].face_index == 0)
                        {
                            Dhighpair_val = wDhand.car[j].face_index;
                            break;
                        }
                    }
                }

                break;   //Break the loop since the Dhighpair_val has been found
            }
        }



        /*
           Finally, we compare these two highest pairs
        */
        k = determine_who_has_higher_pair(wPhand, wDhand, Phighpair_val, Dhighpair_val);    //1 if player wins, 2 if dealer wins

        printf("\t\t\t\t%s won the game with the higher highest pair!\n", k == 2 ? "Sorry, you lost! The dealer" : "Congratulations! You");
    }






    //One pair: If both players have one pair, then compare the value strength of pairs
    if (repr_comb_num == 5)
    {
        int Ppair_val = 0, Dpair_val = 0;


        //First, we find the pair value of the player's hand
        for (i = 0; i < NUM_CARDS; ++i)
        {
            if (number_of_k_in_hand(wPhand, wPhand.car[i].face_index) == 2)
            {
                Ppair_val = wPhand.car[i].face_index;
                break;
            }
        }


        //Similarly, we find the pair value of the dealer's hand
        for (i = 0; i < NUM_CARDS; ++i)
        {
            if (number_of_k_in_hand(wDhand, wDhand.car[i].face_index) == 2)
            {
                Dpair_val = wDhand.car[i].face_index;
                break;
            }
        }


        /*
           Finally, we compare these two pairs
        */
        k = determine_who_has_higher_pair(wPhand, wDhand, Ppair_val, Dpair_val);    //1 if player wins, 2 if dealer wins

        printf("\t\t\t\t%s won the game with the higher pair!\n", k == 2 ? "Sorry, you lost! The dealer" : "Congratulations! You");

    }




    //Final case (High card): Both players do not have any game combinations, then compare the highest cards.
    if (repr_comb_num == 6)
    {
        k = determine_who_has_higher_card(wPhand, wDhand, index_highest_card_in_hand(wPhand), index_highest_card_in_hand(wDhand));   //1 if player wins, 2 if dealer wins

        printf("\t\t\t\t%s won the game with the higher highest card!\n", k == 2 ? "Sorry, you lost! The dealer" : "Congratulations! You");
    }


}





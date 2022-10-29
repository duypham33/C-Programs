

/*

  This is the header file that stores standard library includes, #defined and function prototypes

*/


#ifndef HEADER_H //guard code

#define HEADER_H


#define _CRT_SECURE_NO_WARNINGS //ignore the error about scanf()


#include<stdio.h>    //necessary to use printf() and scanf()

#include<stdlib.h>  //necessary to use rand() and srand()

#include<time.h>    //necessary to use time()




#define NUM_SUITS 4

#define NUM_FACES 13

#define NUM_CARDS 5

#define NUM_COMBINATIONS 6




typedef struct card
{
	int face_index;    //the index of where to find the face value of the card in the array of strings

	int suit_index;    //the index of where to find the suit of the card in the other array of strings

} Card;



typedef struct hand
{
	Card car[NUM_CARDS];          //There are five cards each hand

	//The index of where to find the combinaiton of the hand (0-Four of a kind, 1-Flush, 2-Straight, 3-Three of a kind, 4-Two pairs, and 5-One pair
	int comb[NUM_COMBINATIONS];

} Hand;










//Function prototype


/*
  Function:      void print_menu()

  Date Created: April 21, 2021

  Date Last Modifiled: April 21, 2021

  Description:  This function prints the game menu to the screen

  Input parameters:  None

  Returns:     None

  Preconditions:   None

  Postconditions:   The menu has been displayed to the screen
  */
void print_menu();



/*
  Function:   void print_rules()

  Date Created: April 21, 2021

  Date Last Modifiled: April 21, 2021

  Description:  This function prints the game rules to the screen

  Input parameters:   None

  Returns:   None

  Preconditions:   None

  Postconditions:   The rules has been displayed to the screen
  */
void print_rules();



/*
  Function:   int get_menu_option()

  Date Created: April 21, 2021

  Date Last Modifiled: April 21, 2021

  Description:  This function prompts the user for menu option

  Input parameters:  None

  Returns:  The menu option (integer)

  Preconditions:  None

  Postconditions:  The menu option has been returned
  */
int get_menu_option();





/*
  Function:   void shuffle()

  Date Created: April 21, 2021

  Date Last Modifiled: April 21, 2021

  Description:  This function shuffle the deck randomly

  Input parameters:  The integer array of the deck

  Returns:   None

  Preconditions:  The integer array of the deck

  Postconditions:   The deck has been shuffled randomly
  */
void shuffle(int wDeck[][NUM_FACES]);    




/*
  Function:

  Date Created: April 21, 2021

  Date Last Modifiled: April 21, 2021

  Description:  This function

  Input parameters:

  Returns:

  Preconditions:

  Postconditions:
  */
void deal(int wDeck[][NUM_FACES], Hand* Phand_ptr, Hand* Dhand_ptr);




/*
  Function:  void display_hands()

  Date Created: April 21, 2021

  Date Last Modifiled: April 21, 2021

  Description:  This function displays the hands after replacing the cards to the screen

  Input parameters:   The number of turns, a hand, array of face and suit 

  Returns:   None

  Preconditions:   The number of turns, a hand, array of face and suit 

  Postconditions:  The hands have been displayed
  */
void display_hands(int num_turns, Hand Phand, const char* wFace[], const char* wSuit[]);






/*
  Function:   void replace_cards ()

  Date Created: April 21, 2021

  Date Last Modifiled: April 21, 2021

  Description:  This function replaces the cards of the user

  Input parameters:  The pointer of player's hand, the array of deck, and the pointer of card position

  Returns:  None

  Preconditions:   The pointer of player's hand, the array of deck, and the pointer of card position

  Postconditions:   The chosen cards have been replaced
  */
void replace_cards(Hand* Phand_ptr, int wDeck[][NUM_FACES], int* card_post_ptr);



/*
  Function:    int is_one_pair()

  Date Created: April 21, 2021

  Date Last Modifiled: April 21, 2021

  Description:  This function determines whether the hand is one pair

  Input parameters:   A hand

  Returns:  1 is true, 0 is false

  Preconditions:   The hand

  Postconditions: 1 or 0 has been returned
  */
int is_one_pair(Hand wHand);



/*
  Function:   int is_two_pairs()

  Date Created: April 21, 2021

  Date Last Modifiled: April 21, 2021

  Description:  This function determines whether the hand is two pairs

  Input parameters:  A hand

  Returns:   1 is true, 0 is false

  Preconditions:   The hand
   
  Postconditions:  1 or 0 has been returned
  */
int is_two_pairs(Hand wHand);



/*
  Function:    int number_of_k_in_hand()

  Date Created: April 21, 2021

  Date Last Modifiled: April 21, 2021

  Description:  This function calculates the number of a face value in a hand

  Input parameters:  The hand, and the face value

  Returns:   The number of times it appears

  Preconditions:   The hand, and the face value

  Postconditions:   The number of times it appears has been returned
  */
int number_of_k_in_hand(Hand wHand, int k);



/*
  Function:   int is_three_of_a_kind ()

  Date Created: April 21, 2021

  Date Last Modifiled: April 21, 2021

  Description:  This function determines whether the hand is three of a kind

  Input parameters:  The hand

  Returns:    1 is true, 0 is false

  Preconditions:   The hand

  Postconditions:   1 or 0 has been returned
  */
int is_three_of_a_kind(Hand wHand);




/*
  Function:

  Date Created: April 21, 2021

  Date Last Modifiled: April 21, 2021

  Description:  This function determines whether the hand is four of a kind

  Input parameters:  The hand

  Returns:    1 is true, 0 is false

  Preconditions:   The hand

  Postconditions:   1 or 0 has been returned
  */
int is_four_of_a_kind(Hand wHand);




/*
  Function:

  Date Created: April 21, 2021

  Date Last Modifiled: April 21, 2021

  Description:  This function calculates the number of a suit in hand

  Input parameters:  The hand, and the suit

  Returns:    The number of the suit

  Preconditions:   The hand, and the suit

  Postconditions:  The number has been returned
  */
int number_of_suit_type_in_hand(Hand wHand, int suit_t);



/*
  Function:   int is_flush ()

  Date Created: April 21, 2021

  Date Last Modifiled: April 21, 2021

  Description:  This function determines whether the hand is flush

  Input parameters:  The hand

  Returns:    1 is true, 0 is false

  Preconditions:   The hand

  Postconditions:   1 or 0 has been returned
  */
int is_flush(Hand wHand);





/*
  Function:

  Date Created: April 21, 2021

  Date Last Modifiled: April 21, 2021

  Description:  This function determines whether a face value (k) is in a hand or not

  Input parameters:  The hand and the face value

  Returns:    1 is true, 0 is false

  Preconditions:   The hand and the face value

  Postconditions:   1 or 0 has been returned
  */
int is_k_in_hand(Hand wHand, int k);




/*
  Function:   int is_straight_from_position_k

  Date Created: April 21, 2021

  Date Last Modifiled: April 21, 2021

  Description:  This function determines the hand is straight from a face value(k) or not

  Input parameters:   The hand and the face value

  Returns:   1 is true, 0 is false

  Preconditions:   The hand and the face value

  Postconditions:  1 or 0 has been returned
  */
int is_straight_from_position_k(Hand wHand, int k);




/*
  Function:   int is_straight()

  Date Created: April 21, 2021

  Date Last Modifiled: April 21, 2021

  Description:  This function determines whether the hand is straight

  Input parameters:  The hand

  Returns:    1 is true, 0 is false

  Preconditions:   The hand

  Postconditions:   1 or 0 has been returned
  */
int is_straight(Hand wHand);




/*
  Function:   int is_nearly_flush ()

  Date Created: April 21, 2021

  Date Last Modifiled: April 21, 2021

  Description:  This function determines whether the current hand has more than two cards with the same suit or not

  Input parameters:   The hand

  Returns:   1 is true, 0 is false

  Preconditions:   The hand

  Postconditions:   1 or 0 has been returned
  */
int is_nearly_flush(Hand wHand);




/*
  Function:   int replace_dealer_cards ()

  Date Created: April 21, 2021

  Date Last Modifiled: April 21, 2021

  Description:  This function replace the dealer's cards with intelligence

  Input parameters:  The pointer of dealer's hand, the array of deck, and the pointer of the card position

  Returns:   The number of cards should be replaced

  Preconditions:   The pointer of dealer's hand, the array of deck, and the pointer of the card position

  Postconditions:   The number of cards replaced has been returned
  */
int replace_dealer_cards(Hand* wDhand_ptr, int wDeck[][NUM_FACES], int* card_post_ptr);




/*
  Function:    void display_final_hand()

  Date Created: April 21, 2021

  Date Last Modifiled: April 21, 2021

  Description:  This function displays the final hands after saving

  Input parameters:  The hand, tha array of face and suit

  Returns:  None

  Preconditions:   The hand, tha array of face and suit

  Postconditions:  The hands have been returned
  */
void display_final_hand(Hand wHand, const char* wFace[], const char* wSuit[]);




/*
  Function:   void init_comb()

  Date Created: April 21, 2021

  Date Last Modifiled: April 21, 2021

  Description:  This function initilaizes the array of game combinaitons (all = 0)

  Input parameters: The pointer of the hand

  Returns:  None

  Preconditions:   The pointer of the hand

  Postconditions:  All the values of the array have been 0
  */
void init_comb(Hand* wHand_ptr);




/*
  Function:   void display_final_comb()
   
  Date Created: April 21, 2021

  Date Last Modifiled: April 21, 2021

  Description:  This function displays the game combination the player got

  Input parameters:   The pointer of the hand, and the number representing for the player's combination type saved

  Returns:  None

  Preconditions:   The pointer of the hand, and the number representing for the player's combination type saved

  Postconditions:  The combination has been displayed
  */
void display_final_comb(Hand* wHand_ptr, int* repr_comb_num);



/*
  Function:    int index_highest_card_in_hand()

  Date Created: April 21, 2021

  Date Last Modifiled: April 21, 2021

  Description:  This function determines the index of the highest card in a hand

  Input parameters:  The hand

  Returns:   The index of the highest card

  Preconditions:    The hand

  Postconditions:  The index has been returned
  */
int index_highest_card_in_hand(Hand wHand);




/*
  Function:   int determine_who_has_higher_card()

  Date Created: April 21, 2021

  Date Last Modifiled: April 21, 2021

  Description:  This function compares two cards of two players and determines who has the higher card

  Input parameters:   The two hand, the two indexes of two cards 

  Returns:   1 if it is the user, 2 if it is the dealer

  Preconditions:    The two hand, the two indexes of two cards 

  Postconditions:   1 or 2 has been returned
  */
int determine_who_has_higher_card(Hand wPhand, Hand wDhand, int Pindex, int Dindex);






/*
  Function:   int determine_who_has_higher_pair()

  Date Created: April 21, 2021

  Date Last Modifiled: April 21, 2021

  Description:  This function compares two pairs of two players and determines who has the higher pair

  Input parameters:   The two hand, the two face values of two pairs 

  Returns:   1 if it is the user, 2 if it is the dealer

  Preconditions:    The two hand, the two face values of two pairs 

  Postconditions:   1 or 2 has been returned
  */
int determine_who_has_higher_pair(Hand wPhand, Hand wDhand, int Ppair_value, int Dpair_value);






/*
  Function:   void determine_winner_with_same_comb ()

  Date Created: April 21, 2021

  Date Last Modifiled: April 21, 2021

  Description:  This function determines who is the winner in case they got the same game combinaiton

  Input parameters:  The number representing for the player's combination type saved, and the two hands

  Returns:   None

  Preconditions:    The number representing for the player's combination type saved, and the two hands

  Postconditions:   The winner has been determined
  */
void determine_winner_with_same_comb(int repr_comb_num, Hand wPhand, Hand wDhand);







#endif
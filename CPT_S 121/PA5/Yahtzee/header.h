

/*

  This is the header file that stores standard library includes, #defined and function prototypes

*/


#ifndef HEADER_H //guard code

#define HEADER_H


#define _CRT_SECURE_NO_WARNINGS //ignore the error about scanf()


#include<stdio.h>    //necessary to use printf() and scanf()

#include<stdlib.h>  //necessary to use rand() and srand()

#include<time.h>    //necessary to use time()

#define NUM 5      // 5 is the number of dice


//Function prototype


/*
  Function:     void print_menu()

  Date Created: March 24, 2021

  Date Last Modifiled: March 24, 2021

  Description:  This function prints out the game menu to the screen

  Input parameters:  None

  Returns:     None

  Preconditions:   None

  Postconditions:   The menu has been displayed to the screen
  */
void print_menu();



/*
  Function:    void print_rules()

  Date Created: March 24, 2021

  Date Last Modifiled: March 24, 2021

  Description:  This function prints out the game rules to the screen

  Input parameters:   None

  Returns:    None

  Preconditions:    None

  Postconditions:    The game rules have been displayed to the screen
  */
void print_rules();





/*
  Function:   int get_menu_option()

  Date Created: March 24, 2021

  Date Last Modifiled: March 24, 2021

  Description:  This function prompts the user for menu option

  Input parameters:  None

  Returns:  The menu option

  Preconditions:  None

  Postconditions:  The menu option has been got
  */
int get_menu_option();




/*
  Function:    void roll_dice ()

  Date Created: March 24, 2021

  Date Last Modifiled: March 24, 2021

  Description:  This function gets a random value (1-6) for 5 dice

  Input parameters:   The dice values, and the number of dice

  Returns:      None

  Preconditions:   The dice values, and the number of dice

  Postconditions:   The dice values have been generated
  */
void roll_dice(int die[], int num_dice);




/*
  Function:     void display_dice ()

  Date Created: March 24, 2021

  Date Last Modifiled: March 24, 2021

  Description:  This function displays the dice values to the screen 

  Input parameters:    The dice values, and the number of dice

  Returns:   None

  Preconditions:     The dice values, and the number of dice
   
  Postconditions:   The dice values have been displayed to the screen
  */
void display_dice(int die[], int num_dice);




/*
  Function:     void re_roll ()

  Date Created: March 24, 2021

  Date Last Modifiled: March 24, 2021

  Description:  This function asks the user whether keep or not the dice, and then re-generates dice chosen

  Input parameters:   The dice values, the number of dice, and the the option for each die

  Returns:     None

  Preconditions:   The dice values, the number of dice, and the the option for each die

  Postconditions:   The  chosen dice values have been generated again
  */
void re_roll(int die[], int num_dice, char die_opt);




/*
  Function:     int choose_combination ()

  Date Created: March 24, 2021

  Date Last Modifiled: March 24, 2021

  Description:  This function prompts the player for whether or not want to use the roll for a game combination (yes or no)

  Input parameters:  None

  Returns:   A number (1-13)

  Preconditions:  None

  Postconditions:   The number option for a combination kind has been returned
  */
int choose_combination();



/*
  Function:    int compute_upper_types ()

  Date Created: March 24, 2021

  Date Last Modifiled: March 24, 2021

  Description:  This function computes scores for one upper combination

  Input parameters:    The dice values, the number of dice, and the type of upper combination (1-6)

  Returns:   The upper score

  Preconditions:   The dice values, the number of dice, and the type of upper combination (1-6)

  Postconditions:   The upper score has been returned
  */
int compute_upper_types(int die[], int num_dice, int t);



/*
  Function:   int compute_three_of_a_kind ()

  Date Created: March 24, 2021

  Date Last Modifiled: March 24, 2021

  Description:  This function computes scores for three-of-a-kind

  Input parameters:   The dice values, and the number of dice

  Returns:  The score 

  Preconditions:  The dice values, and the number of dice

  Postconditions:    The score has been returned
  */
int compute_three_of_a_kind(int die[], int num_dice);




/*
  Function:   int compute_four_of_a_kind ()

  Date Created: March 24, 2021

  Date Last Modifiled: March 24, 2021

  Description:  This function computes scores for four-of-a-kind

  Input parameters:   The dice values

  Returns:   The score

  Preconditions:   The dice values

  Postconditions:   The score has been returned
  */
int compute_four_of_a_kind(int die[]);



/*
  Function:   int is_k_in_array ()

  Date Created: March 24, 2021

  Date Last Modifiled: March 24, 2021

  Description:  This function checks whether a value k appears in an array or not 

  Input parameters:   The array, the size of the array, and the value k

  Returns:   0 is for false, 1 is for true

  Preconditions:   The array, the size of the array, and the value k

  Postconditions:  0 or 1 has been returned
  */
int is_k_in_array(int arr[], int size, int k);



/*
  Function:    int number_of_k_in_array ()

  Date Created: March 24, 2021

  Date Last Modifiled: March 24, 2021

  Description:  This function calculates how many times the value k appears in one array

  Input parameters:   The array, the size of the array, and the value k

  Returns: The number of k in the array

  Preconditions:  The array, the size of the array, and the value k

  Postconditions:  The number of k has been returned
  */
int number_of_k_in_array(int arr[], int size, int k);




/*
  Function:    int compute_full_house ()

  Date Created: March 24, 2021

  Date Last Modifiled: March 24, 2021

  Description:  This function calculates the score for Full house
   
  Input parameters:   The dice values

  Returns:   The score

  Preconditions:    The dice values

  Postconditions:   The score has been returned
  */
int compute_full_house(int die[]);



/*
  Function:      int compute_small_straight ()

  Date Created: March 24, 2021

  Date Last Modifiled: March 24, 2021

  Description:  This function calculates the score for Small straight 

  Input parameters:  The dice values

  Returns:  The score

  Preconditions:   The dice values

  Postconditions:   The score has been returned
  */
int compute_small_straight(int die[]);



/*
  Function:     int compute_large_straight ()

  Date Created: March 24, 2021

  Date Last Modifiled: March 24, 2021

  Description:  This function calculates the score for Large straight 

  Input parameters: The dice values

  Returns:  The score

  Preconditions:   The dice values

  Postconditions:  The score has been returned
  */
int compute_large_straight(int die[]);




/*
  Function:   compute_Yahtzee()

  Date Created: March 24, 2021

  Date Last Modifiled: March 24, 2021

  Description:  This function calculates the score for for Yahtzee

  Input parameters:   The dice values

  Returns:   The score

  Preconditions:    The dice values

  Postconditions:   The score has been returned
  */
int compute_Yahtzee(int die[]);



/*
  Function:

  Date Created: March 24, 2021

  Date Last Modifiled: March 24, 2021

  Description:  This function calculates the score for Chance

  Input parameters:   The dice values

  Returns:           The score

  Preconditions:    The dice values

  Postconditions:   The score has been returned
  */
int compute_chance(int die[], int num_dice);




/*
  Function:   void display_comb ()

  Date Created: March 24, 2021

  Date Last Modifiled: March 24, 2021

  Description:  This function displays the combination score that player can get after chossing

  Input parameters:  The dice values, the number of dice, the number for type of combination, the status of that combination of the player, the index i for player, the total score, the upper score, and the combination scores

  Returns: None

  Preconditions: The dice values, the number of dice, the number for type of combination, the status of that combination of the player, the index i for player, the total score, the upper score, and the combination scores

  Postconditions: The combination score, the total score, and the upper score have been calculated
  */
void display_comb(int die[], int num_dice, int num, int comb_status[][14], int i, int* total_score, int* upper_score, int comb_score[][14]);






/*
  Function:    void print_result_sheet ()

  Date Created: March 24, 2021

  Date Last Modifiled: March 24, 2021

  Description:  This function prints the game result to the screen

  Input parameters:  The combinaiton scores, the total upper score, the total score, and the bonus of the upper section

  Returns:   None

  Preconditions:   The combinaiton scores, the total upper score, the total score, and the bonus of the upper section

  Postconditions:  The game result has been printed
  */
void print_result_sheet(int comb_score[][14], int total_upper_score[], int total_score[], int bonus[]);



#endif

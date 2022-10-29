

/*

  This is the header file that stores standard library includes, #defined and function prototypes

*/


#ifndef HEADER_H //guard code

#define HEADER_H


#define _CRT_SECURE_NO_WARNINGS //ignore the error about scanf()


#include<stdio.h>    //necessary to use printf() and scanf()

#include<stdlib.h>  //necessary to use rand() and srand()

#include<time.h>    //necessary to use time()




//Function prototype


/*
  Function:   void print_game_rules ()

  Date Created: March 9, 2021

  Date Last Modifiled: March 9, 2021

  Description:  This function prints out the rules of the game of "craps"

  Input parameters:  None

  Returns:  None

  Preconditions:   None

  Postconditions:   prints out the rules
  */
void print_game_rules(void);




/*
  Function:      double get_bank_balance ()

  Date Created: March 9, 2021

  Date Last Modifiled: March 9, 2021

  Description:  This function prompts the player for an initial bank balance from which wagering will be added or subtracted

  Input parameters:   None

  Returns:  The initial bank balance

  Preconditions:    None

  Postconditions:   The balance has been returned
  */
double get_bank_balance(void);




/*
  Function:     double get_wager_amount ()

  Date Created: March 9, 2021

  Date Last Modifiled: March 9, 2021

  Description:  This function prompts the player for a wager on a particular roll

  Input parameters:   None

  Returns:    The wager

  Preconditions:   None

  Postconditions:   The wager has been returned
  */
double get_wager_amount(void);




/*
  Function:       int check_wager_amount ()

  Date Created: March 9, 2021

  Date Last Modifiled: March 9, 2021

  Description:  This function checks to see if the wager is within the limits of the player's available balance

  Input parameters:  The wager amount and the bank balance

  Returns:   If the wager exceeds the player's allowable balance, then 0 is returned; otherwise 1 is returned

  Preconditions:   The wager amount and the bank balance

  Postconditions:   0 or 1 has been returned
  */
int check_wager_amount(double wager, double balance);




/*
  Function:       int roll_die ()

  Date Created: March 9, 2021

  Date Last Modifiled: March 9, 2021

  Description:  This function randomly generates a value between 1 and 6 for one die

  Input parameters:    None

  Returns:         The value of the die

  Preconditions:      None

  Postconditions:   The value of the die has been returned
  */
int roll_die(void);





/*
  Function:        int calculate_sum_dice ()

  Date Created: March 9, 2021

  Date Last Modifiled: March 9, 2021

  Description:  This function sums together the values of the two dice

  Input parameters:   The values of the two dice

  Returns:    The sum

  Preconditions:   The values of the two dice

  Postconditions:   The sum has been returned
  */
int calculate_sum_dice(int die1_value, int die2_value);





/*
  Function:        int is_win_loss_or_point ()

  Date Created: March 9, 2021

  Date Last Modifiled: March 9, 2021

  Description:  This function determines the result of the first dice roll

  Input parameters:  The sum of the values of the two dice after the first throw

  Returns:  If the sum is 7 or 11, 1 is returned. If the sum is 2, 3, or 12, 0 is returned. If the sum is 4, 5, 6, 8, 9, or 10, then -1 is returned.

  Preconditions:   The sum

  Postconditions:   0, 1, or -1 has been returned
  */
int is_win_loss_or_point(int sum_dice);





/*
  Function:       int is_point_loss_or_neither ()

  Date Created: March 9, 2021

  Date Last Modifiled: March 9, 2021

  Description:  This function determines the result of any successive roll after the first roll

  Input parameters:   The sum of the values of the two dice after the previous roll, and the point value

  Returns:   If the sum of the roll is the point_value, then 1 is returned. If the sum of the roll is a 7, then 0 is returned. Otherwise, -1 is returned

  Preconditions:    The sum and the point value

  Postconditions:    0, 1, or -1 has been returned
  */
int is_point_loss_or_neither(int sum_dice, int point_value);





/*
  Function:   double adjust_bank_balance ()

  Date Created: March 9, 2021

  Date Last Modifiled: March 9, 2021

  Description:  This function adjusts the bank balance 

  Input parameters:  The bank balance, the wager amount and the status of add or subtract (0,1,or-1)

  Returns:    The bank balance

  Preconditions:   The bank balance, the wager amount and the status of add or subtract (0,1,or-1)

  Postconditions:   The bank balance has been returned
  */
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract);





/*
  Function:      void chatter_messages ()

  Date Created: March 9, 2021

  Date Last Modifiled: March 9, 2021

  Description:  This function prints an appropriate message dependent on the number of rolls taken so far by the player, the current balance, and whether or not the player just won his roll

  Input parameters:  The number of rolls, the win_loss_neither, the initial bank balance, and the current bank balance

  Returns:    None

  Preconditions:    The number of rolls, the win_loss_neither, the initial bank balance, and the current bank balance

  Postconditions:    An messasge has been displayed
  */
void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance);




#endif
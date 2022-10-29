
/*

    This file is to establish the definitions for all programmer-defined functions, aside from main ()

*/


#include "header.h"


   //Function definitions

void print_game_rules(void)
{
    printf("\t\t\tCRAPS\n");
    printf("\t   *RULES:\n");
    printf("\t\t-Roll two dice, you will win if the sum of the spots on the two upward faces is 7 or 11 on the first throw\n");
    printf("\t\t-If the sum is 2, 3, or 12 (called \"craps\"), you will lose\n");
    printf("\t\t-If the sum is 4, 5, 6, 8, 9, or 10, then the sum will become your point\n");
    printf("\t\t-You must continue rolling the dice until making your point. You will lose by rolling a 7 before making the point.\n");
    printf("_______________________________________________________________________________________________________________________________________\n\n");
}


double get_bank_balance(void)
{
    printf("To begin, please enter your initial bank balance from which wagering will be added or subtracted during the game: $");
    
    double balance = 0.0;
    scanf("%lf", &balance);

    return balance;
}


double get_wager_amount(void)
{
    printf("Please enter your wager amount on this roll: $");

    double wager = 0.0;
    scanf("%lf", &wager);

    return wager;
}


int check_wager_amount(double wager, double balance)
{
    if (wager <= balance)
        return 1;

    else
        return 0;
}


int roll_die(void)
{

    return (rand() % 6 + 1);
}


int calculate_sum_dice(int die1_value, int die2_value)
{
    int sum_dice = die1_value + die2_value;
    return sum_dice;
}


int is_win_loss_or_point(int sum_dice)
{
    if (sum_dice == 11 || sum_dice == 7)    //The player wins    
    {
        printf("Congratulations! You won the roll, take your award amount!\n");
        return 1;
    }

    else if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12)    //The player loses
    {
        printf("Sorry, you lost! You will lose your wager amount!\n");
        return 0;
    }
        
   

    else            //The sum becomes the player's "point"
    {
        printf("Now your sum (%d) becomes your point. Let's continue rolling!\n", sum_dice);
        return -1;
    }
}


int is_point_loss_or_neither(int sum_dice, int point_value)
{
    if (sum_dice == point_value)   //winning point
    {
        printf("Congratulations! You won the roll, take your award amount!\n");
        return 1;
    }

    else if (sum_dice == 7)       //losing point
    {
        printf("Sorry, you lost! You will lose your wager amount!\n");
        return 0;
    }

    else
        return - 1;   

}



double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract)
{
    if( add_or_subtract == 1 )      //the player wins the game
    { 
        bank_balance += wager_amount;
    }

    else if (add_or_subtract == 0)  //the player loses the game
    {
        bank_balance -= wager_amount;
    }

    return bank_balance;
}





void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance)
{
    if (win_loss_neither == 0)
    {
        if (current_bank_balance == 0) { printf("Sorry, you busted!\n"); }
        else if ( current_bank_balance <= (0.3 * initial_bank_balance) )   //when the current balance is just lower than 30 percent of the initial balance 
        {
            printf("Oh, you're going for broke, huh?\n");
        }
    }

    else if (win_loss_neither == -1)
    {
         if ( number_rolls > 1 && (number_rolls%2) == 1 )
         { printf("Aw cmon, take a chance!\n"); }
    }

    else if (win_loss_neither == 1 && current_bank_balance >= initial_bank_balance)
    {
        printf("You're up big, now's the time to cash in your chips!\n");
    }

}






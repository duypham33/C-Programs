
/*
      * Programmer: Duy Pham

      * Class: CptS 121, Spring 2021; Section 01; Lab Section 14

      * Programming Assignment: PA4  A Game of Chance "Craps"

      * Date: March 9, 2021

      * Description: This program implements a craps game according to the rules:
                           - Roll two dice 
                           - If the sum is 7 or 11 on the first throw, the player wins
                           - If the sum is 2, 3, or 12 on the first throw, the player loses
                           - If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's "point."
                           - Then, continue rolling the dice until making the point. The player loses by rolling a 7 before making the point.
*/


#include "header.h"


int main(void)
{

    //Print the rules of the game
    print_game_rules();

    //Prompt the player for the initial bank balance 
    double balance = 0.0;
    balance = get_bank_balance();
    double initial_bank_balance = balance;

    
    double wager = 0.0;    //The wager amount that the player places for one round

    
    srand((unsigned int)time(NULL));

    int die1_value = 0, die2_value = 0;  //The two dice values

    int number_rolls = 1;                //The number of rolls in one round
    
    int number_rounds = 0;               //The number of rounds that the player would take

    int sum = 0;                         //The sum of the spots on the two upward faces
    
    int win_loss_neither = 0;            //To check win, lose or make point on the first throw
    
    int point_value = 0;                 //The point value when the sum becomes point
    
    int point_loss_or_neither = 0;       //To check the point win, lose or neither

    int add_or_subtract = 0;             //To check win or lose for computing the bank balance
    
    char option = '\0';                  //Yes or No for the question asking for playing a new round
    
    

    do
    {
        number_rounds++;   //count the number of rounds

        //Prompt the player for a wager on the round
        wager = get_wager_amount();


        //Check to see if the wager is within the limits of the player's available balance.
        int check_wager = check_wager_amount(wager, balance);

        while (check_wager == 0)
        {
            printf("\nYour wager exceeds your allowable balance!\n");
            wager = get_bank_balance();
            check_wager = check_wager_amount(wager, balance);
        }


        //Initialize back some variables for the new round

        number_rolls = 1; 

        option = '\0';




        //The results of the two dice
        die1_value = roll_die(); die2_value = roll_die();
        printf("\nThe values of two dice (throw %d): %d and %d\n", number_rolls, die1_value, die2_value);

        //Sum the two dice values
        sum = calculate_sum_dice(die1_value, die2_value);
        printf("The sum of the spots on the two upward faces: %d\n", sum);

        //Check the result after the first throw
        win_loss_neither = is_win_loss_or_point(sum);


        //In case the sum becomes the point and the player must continue rolling until making the point
        if (win_loss_neither == -1)
        {
            point_value = sum;  //The sume becomes the the player's point

            do
            {
                number_rolls++;   //count the number of rolls on the round

                //The results of the two dice
                die1_value = roll_die(); die2_value = roll_die();
                printf("\nThe values of two dice (throw %d): %d and %d\n", number_rolls, die1_value, die2_value);

                //Sum the two dice values
                sum = calculate_sum_dice(die1_value, die2_value);
                printf("The sum of the spots on the two upward faces: %d\n", sum);

                //Check the result after the throw
                point_loss_or_neither = is_point_loss_or_neither(sum, point_value);

                //Print message
                chatter_messages(number_rolls, point_loss_or_neither, initial_bank_balance, balance);

            } while (point_loss_or_neither == -1);


            //The status of the final result on the round
            add_or_subtract = point_loss_or_neither;
        }

        else { add_or_subtract = win_loss_neither; }     //The status of the final result on the round  

        //Adjust the bank balance based on the result of the game round
        balance = adjust_bank_balance(balance, wager, add_or_subtract);
        printf("\nYour current bank balance is $%.2lf after round %d\n", balance, number_rounds);


        if (balance == 0) 
        { 
            printf("Sorry, you busted! Good luck for the next time! Thank you!\n"); 
            break;
        }    //When the player busted, cannot continue playing


        else     //Ask whether want to play a new round nor not
        {
            printf("Do you want to play a new round? ");
            scanf(" %c", &option);    // 'y' for 'yes'; 'n' for 'no'
        }

    } while (option == 'y');




    if (option == 'n')       
    {
        printf("\nThank you for joining us! See you again!\n");
    }





    return 0;  //The program was successful

}
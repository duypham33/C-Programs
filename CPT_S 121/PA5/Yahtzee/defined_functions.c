
/*

    This file is to establish the definitions for all programmer-defined functions, aside from main ()

*/


#include "header.h"


//Function definitions
void print_menu()
{
    printf("\t\t\tG A M E  M E N U\n");
    printf("\t\t     1. Print game rules\n");  
    printf("\t\t     2. Start a game of Yahtzee\n");
    printf("\t\t     3. Exit\n");
}


void print_rules()
{
    printf("\n\t\t\t\t\tG A M E  R U L E S\n");
    printf("\t\t-Two players will compete against each other to score the higher point\n");
    printf("\t\t-Points are obtained by rolling five 6-sided die across thirteen rounds\n");
    printf("\t\t-During each round, each player may roll the dice up to three times to make one of the possible scoring combinations\n");
    printf("\t\t-Once a combination has been achieved by the player, it may not be used again in future rounds,\n");
    printf("\t\t  except for the Yahtzee combination may be used as many times as the player makes the combination\n");
    printf("\t\t-The scorecard used for Yahtzee is composed of two sections\n");
    printf("\t\t-The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box\n");
    printf("\t\t-If the sum of the upper scores is greater than or equal to 63, then 35 more points are added to the players overall score as a bonus\n");
    printf("\t\t-The lower section contains a number of poker like combinations\n");
    printf("\t**********************************************************************************************\n\n");
}


int get_menu_option()
{
    int option = 0;
    printf("\nPlease choose your menu option: ");
    scanf("%d", &option);
    return option;
}


void roll_dice(int die[], int num_dice)
{
    int i;
    for (i = 0; i < num_dice; i++)
    {
        die[i] = rand() % 6 + 1;

    }
    
}

void display_dice(int die[], int num_dice)
{
    int i;
    for (i = 0; i < num_dice; i++)
    {
        printf("   die %d: %d ", i + 1, die[i]);
    }
}


void re_roll(int die[], int num_dice, char die_opt)
{
    int i;
    for (i = 0; i < num_dice; i++)
    {
        printf("die %d 'k'(keep) / 'n'(not): ", i+1);
        scanf(" %c", &die_opt);
        if (die_opt == 'n')
        {
            die[i] = rand() % 6 + 1;
        }
    }

}



int choose_combination()
{   
    int num;
    printf("\n\n1. Sum of 1's        7. Three-of-a-kind\n2. Sum of 2's        8. Four-of-a-kind\n");
    printf("3. Sum of 3's        9. Full house\n4. Sum of 4's        10. Small straight\n5. Sum of 5's        11. Large straight\n");
    printf("6. Sum of 6's        12. Yahtzee\n\t    13. Chance\n");
    printf("Please choose your combination for this round by entering a number (1-13): ");
    scanf("%d", &num);    ////Enter a number (1-13)
    return num;
}




int compute_upper_types(int die[], int num_dice, int t)
{
    int sum = 0; int i;
    for (i = 0; i < num_dice; i++)
    {
        if (die[i] == t)
        {
            sum += t;
        }
    }

    return sum;
}



int compute_three_of_a_kind(int die[], int num_dice)
{
    int i, j, l;
    int flag = 0;   //0 is false, 1 is true
    int result = 0;

    for (i = 0; i < num_dice-2; i++)
    {
        for (j = i + 1; j < num_dice - 1; j++)
        {
            if (die[i] == die[j])
            {
                for (l = j + 1; l < num_dice; l++)
                {
                    if (die[l] == die[i])
                    {
                        flag = 1;
                    }
                }
            }
        }
    }
    if (flag == 1) 
    {
        for (i = 0; i < num_dice; i++)
        {
            result += die[i];          //The three-of-a-kind is sum of all face values on the 5 dice
        }
    }
    
    return result;
}



int compute_four_of_a_kind(int die[])
{
    int i; 
    int k = 0;  //the number of equal values
    int result = 0;

    if (die[0] == die[1]) 
    {
        k = 2;
        for (i = 2; i < NUM; i++)
        {    
            if (die[i] == die[0]) { k++; }
        }
    }
    
    else
    {
        if (die[2] == die[3] && die[3] == die[4])
        {
            int s = die[2];

            if (die[0] == s || die[1] == s) { k = 4; }
        }
    }

    if (k >= 4)
    {
        for (i = 0; i < NUM; i++)
        {
            result += die[i];             //The four-of-a-kind is sum of all face values on the 5 dice
        }
    }

    return result;
}


int is_k_in_array(int arr[], int size, int k)
{
    int flag = 0;   //0 is false, 1 is true
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == k)
        {
            flag = 1; break;
        }
    }

    return flag;
}

int number_of_k_in_array(int arr[], int size, int k)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == k)
        {
            count++;
        }
    }
    return count;
}


int compute_full_house(int die[])
{
    int a[7];         //the sequence a[i] for checking if the number i is in the die[5] ,  i(1-6)
    int b[7];         //the sequence b[i] for computing how many times the number i appears in the die[5] ,  i(1-6)
    int result = 0;

    int i; int sum = 0; int flag = 0;
    for (i = 1; i < 7; i++)
    {
        a[i] = is_k_in_array(die, NUM, i); sum += a[i];
        b[i] = number_of_k_in_array(die, NUM, i);
        if (b[i] == 3) { flag = 1; }   //There is a number (1-6) that appears exactly three times
    }


    if (sum == 2 && flag == 1)    //This is Full house     
    {
        result = 25;        //The full house point is 25
    }


    return result;
}







int compute_small_straight(int die[])
{
    int i; 
    int flag[7];        //the sequence flag[i] for checking if the number i is in the die[5] ,  i(1-6)
    int main_flag = 0;  //0 is not a Small Straight, 1 is a Small Straight
    int result = 0;

    /*
      There are three possible types of Small Straight (1,2,3,4) ; (2,3,4,5) ; (3,4,5,6)
    */
    for (i = 1; i < 7; i++)
    {
        flag[i] = is_k_in_array(die, NUM, i);
    }

    if (flag[1] == 1 && flag[2] == 1 && flag[3] == 1 && flag[4] == 1)
    {
        main_flag = 1;
    }

    else if (flag[2] == 1 && flag[3] == 1 && flag[4] == 1 && flag[5] == 1)
    {
        main_flag = 1;
    }

    else if (flag[3] == 1 && flag[4] == 1 && flag[5] == 1 && flag[6] == 1)
    {
        main_flag = 1;
    }

    if (main_flag == 1) { result = 30; }       //Small straight point is 30

    return result;
}



int compute_large_straight(int die[])
{
    int i; 
    int flag[7];        //the sequence flag[i] for checking if the number i is in the die[5] ,  i(1-6)
    int main_flag = 0;  //0 is not a Large Straight, 1 is a Large Straight
    int result = 0;

    /*
      There are two possible types of Large Straight (1,2,3,4,5) ; (2,3,4,5,6) 
    */
    for (i = 1; i < 7; i++)
    {
        flag[i] = is_k_in_array(die, NUM, i);
    }

    if (flag[1] == 1 && flag[2] == 1 && flag[3] == 1 && flag[4] == 1 && flag[5] == 1)
    {
        main_flag = 1;
    }

    else if (flag[2] == 1 && flag[3] == 1 && flag[4] == 1 && flag[5] == 1 && flag[6] == 1)
    {
        main_flag = 1;
    }

    if (main_flag == 1) { result = 40; }       //Large straight point is 40

    return result;

}



int compute_Yahtzee(int die[])
{
    int i, j;
    int flag = 1;   //1 is true, 0 is false
    int result = 0;

    for (i = 0; i < NUM-1; i++)
    {
        for (j = i + 1; j < NUM; j++)
        {
            if (die[j] != die[i])
            {
                flag = 0; break;
            }
        }
    }

    if (flag == 1)
    {
        result = 50;    //Yahtzee point is 50
    }

    return result;
}


int compute_chance(int die[], int num_dice)
{
    int result = 0;
    int i;
    for (i = 0; i < num_dice; i++)
    {
        result += die[i];         //The chance point is sum of all face values on the 5 dice
    }

    return result;
}


void display_comb(int die[], int num_dice, int num, int comb_status[][14], int i, int *total_score, int *upper_score, int comb_score[][14])
{
    int score = 0;

    
    if (num > 0 && num < 7)   //Upper Section
    {   
        score = compute_upper_types(die, num_dice, num);
        printf("Player %d marked Sum of %d\'s: %d point(s)\n\n", i, num, score);
        comb_status[i][num] = 1;
        *total_score += score;
        *upper_score += score;
        comb_score[i][num] = score;
    }
    
    else    //Lower Section
    {
        switch (num)
        {
        case 7:    //Three-of-a-kind
            score = compute_three_of_a_kind(die, num_dice);
            printf("Player %d marked Three-of-a-kind: %d point(s)\n\n",i, score);
            *total_score += score;
            comb_status[i][num] = 1;
            comb_score[i][num] = score;
            break;

        case 8:   //Four-of-a-kind
            score = compute_four_of_a_kind(die);
            printf("Player %d marked Four-of-a-kind: %d point(s)\n\n", i, score);
            comb_status[i][num] = 1;
            *total_score += score;
            comb_score[i][num] = score;
            break;

        case 9:   //Full house
            score = compute_full_house(die);
            printf("Player %d marked Full house: %d point(s)\n\n", i, score);
            comb_status[i][num] = 1;
            *total_score += score;
            comb_score[i][num] = score;
            break;

        case 10:  //Small straight
            score = compute_small_straight(die);
            printf("Player %d marked Small straight: %d point(s)\n\n", i, score);
            comb_status[i][num] = 1;
            *total_score += score;
            comb_score[i][num] = score;
            break;

        case 11:  //Large straight
            score = compute_large_straight(die);
            printf("Player %d marked Large straight: %d point(s)\n\n", i, score);
            comb_status[i][num] = 1;
            *total_score += score;
            comb_score[i][num] = score;
            break;

        case 12:  //Yahtzee
            score = compute_Yahtzee(die);
            printf("Player %d marked Yahtzee: %d point(s)\n\n", i, score);    
            *total_score += score;
            comb_score[i][num] += score;    //Because Yahtzee combination may be used manytimes
            break;            

        case 13:  //Chance
            score = compute_chance(die, num_dice);
            printf("Player %d marked Chance: %d point(s)\n\n", i, score);
            comb_status[i][num] = 1;
            *total_score += score;
            comb_score[i][num] = score;
            break;

        }            

    }



}




void print_result_sheet(int comb_score[][14], int total_upper_score[], int total_score[], int bonus[])
{
   

    printf("\t\t\t\tRESULT SHEET\n");
    printf("\t\t      Player 1\t\t\tPlayer 2\n");
    printf("\tUpper Section\n");
    printf("\t  Aces:\t\t %d\t\t\t%d\n", comb_score[1][1], comb_score[2][1]);
    printf("\t  Twos:\t\t %d\t\t\t%d\n", comb_score[1][2], comb_score[2][2]);
    printf("\t  Threes:\t %d\t\t\t%d\n", comb_score[1][3], comb_score[2][3]);
    printf("\t  Fours:\t %d\t\t\t%d\n", comb_score[1][4], comb_score[2][4]);
    printf("\t  Fives:\t %d\t\t\t%d\n", comb_score[1][5], comb_score[2][5]);
    printf("\t  Sixs:\t\t %d\t\t\t%d\n", comb_score[1][6], comb_score[2][6]);
    printf("   Total upper score:    %d\t\t\t%d\n", total_upper_score[1], total_upper_score[2]);
    printf("\t  Bonus:\t %d\t\t\t%d\n\n", bonus[0], bonus[1]);

    printf("\tLower Section\n");
    printf("\tThree-of-a-kind: %d\t\t\t%d\n", comb_score[1][7], comb_score[2][7]);
    printf("\tFour-of-a-kind:\t %d\t\t\t%d\n", comb_score[1][8], comb_score[2][8]);
    printf("\tFull house:\t %d\t\t\t%d\n", comb_score[1][9], comb_score[2][9]);
    printf("\tSmall straight:\t %d\t\t\t%d\n", comb_score[1][10], comb_score[2][10]);
    printf("\tLarge straight:\t %d\t\t\t%d\n", comb_score[1][11], comb_score[2][11]);
    printf("\t  Yahtzee:\t %d\t\t\t%d\n", comb_score[1][12], comb_score[2][12]);
    printf("\t  Chance:\t %d\t\t\t%d\n\n", comb_score[1][13], comb_score[2][13]);

    printf("\tGrand Total:\t %d\t\t\t%d", total_score[1], total_score[2]);
}

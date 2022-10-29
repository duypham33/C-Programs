
/*

    This file is to establish the definitions for all programmer-defined functions, aside from main ()

*/


#include "header.h"



// All defined-functions for task 1

void get_gender(FILE* infile, char gender[10])
{
    //function definition

    fscanf(infile,"%s", gender);

}


double get_weight_in_pounds(FILE* infile)
{

    double weight_in_pounds = 0.0;
    fscanf(infile, "%lf", &weight_in_pounds);
    return weight_in_pounds;

}


double get_height_in_inches(FILE* infile)
{

    double height_in_inches = 0.0;
    fscanf(infile, "%lf", &height_in_inches);
    return height_in_inches;

}


int get_age_in_years(FILE* infile)
{

    int age_in_years = 0;
    fscanf(infile, "%d", &age_in_years);
    return age_in_years;
}


double compute_BMR(char gender[10], double weight_in_pounds, double height_in_inches, int age_in_years)
{
    //function definition


    double BMR = 0.0;  //the Basal Metabolic Rate

    if (strcmp(gender, "women") == 0) { BMR = 655 + (4.35 * weight_in_pounds) + (4.7 * height_in_inches) - (4.7 * age_in_years); }

    else if (strcmp(gender, "men") == 0) { BMR = 66 + (6.23 * weight_in_pounds) + (12.7 * height_in_inches) - (6.8 * age_in_years); }

    return BMR;

}


double compute_daily_calorie_intake(double BMR, char activity_level)
{
    //function definition

    double Calories = 0.0;   //daily calorie intake

    if(activity_level=='s') //sedentary
    { Calories = BMR * 1.2; }

    else if(activity_level=='l') // low activity
    { Calories = BMR * 1.375; }

    else if (activity_level=='m') // moderate activity
    { Calories = BMR * 1.55; }

    else if (activity_level == 'h') // high activity
    { Calories = BMR * 1.725; }

    else if (activity_level == 'e') // extra activity
    { Calories = BMR * 1.9; }

    return Calories;
}


void display_calories(double BMR, double Calories)
{

    printf("\nThe person's BMR: %lf\n", BMR);
    printf("The total daily calorie intake that the person need: %lf\n", Calories);

}





// All defined-functions for task 2


char answer_questions(char award[50])
{
    //function definition

    char answer;
    //Prompt the user for yes-no questions to add the bonus
    printf("Does the baseball player gain the %s?: ", award);

    //Get the response 
    scanf(" %c", &answer);   //the answer is y (yes) or n (no)
    
    return answer;

}


int add_bonus(char answer, int bonus)
{
    int add = 0;  //I use "adding value" to replace the repetition function that we have not learned
    if (answer == 'y') { add += bonus; }  //if the answer is "yes", add that bonus to the total
    return add;
}


void display_total_bonus(int total_bonus)
{
    printf("\nThe total bonus that the baseball player receives at the end of the season: $%d\n", total_bonus);

}





// All defined-functions for task 3

double read_number(FILE* infile)
{
    double num = 0.0;
    fscanf(infile, "%lf", &num);

    return num;
}


double compute_average(double num1, double num2, double num3, double num4, double num5)
{
    double average = 0.0;
    average = (num1 + num2 + num3 + num4 + num5) / 5;
    return average;
}



double highest_value(double num1, double num2, double num3, double num4, double num5)
{
    double max = 0.0;
    max = num1;

    if (max <= num2) { max = num2; }  //to find max{num1,num2}
    if (max <= num3) { max = num3; }  //to find max{num1,num2,num3}
    if (max <= num4) { max = num4; }  //to find max{num1,num2,num3,num4}
    if (max <= num5) { max = num5; }  //to find max{num1,num2,num3,num4,num5}

    return max;
}


double lowest_value(double num1, double num2, double num3, double num4, double num5)
{
    double min = 0.0;
    min = num1;

    if (min >= num2) { min = num2; }  //to find min{num1,num2}
    if (min >= num3) { min = num3; }  //to find min{num1,num2,num3}
    if (min >= num4) { min = num4; }  //to find min{num1,num2,num3,num4}
    if (min >= num5) { min = num5; }  //to find min{num1,num2,num3,num4,num5}

    return min;

}


double compute_result(int opt, double num1, double num2, double num3, double num4, double num5)
{
    double result = 0.0;

    switch (opt)
    {
    case 1:    result = compute_average(num1, num2, num3, num4, num5); break;
    case 2:    result = highest_value(num1, num2, num3, num4, num5); break;
    case 3:    result = lowest_value(num1, num2, num3, num4, num5); break;
    default:   //Anything but 1, 2, 3
        printf("Unrecognized option!\n"); break;
    }

    return result;
}


void display_result(double result)
{
    printf("\nThe result of selected operation on the five numbers: %lf\n", result);

}




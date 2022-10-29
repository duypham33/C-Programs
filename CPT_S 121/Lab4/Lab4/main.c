
/*
      * Programmer: Duy Pham

      * Class: CptS 121, Spring 2021; Section 01; Lab Section 14

      * Programming Assignment: Lab 4


      * Date: February 18, 2021

      * Description: This program computes (performs):
          -   a person's total daily calorie need , to maintain current body weight, based on gender, age, weight, and height, and activity level
          -   determine a professional baseball player's bonus at the end of a season
          -   one of the operations on five numbers read from the file

*/


  #include "header.h"


int main(void)
{

    // Task 1 (Calorie Calculator program)
    printf("1) ");  //start task 1

    char gender[10]; double weight_in_pounds = 0.0, height_in_inches = 0.0; int age_in_years = 0;
    FILE* infile_1 = NULL;  

    infile_1 = fopen("data1.txt", "r");  //input file opened with read permisions “r”


    //Read the gender, weight, height and age from the input file
    get_gender(infile_1, gender);
    weight_in_pounds = get_weight_in_pounds(infile_1);
    height_in_inches = get_height_in_inches(infile_1);
    age_in_years = get_age_in_years(infile_1);


    //Display the gender, weight, height and age to the screen
    printf("The personal information of the person\n");
    printf("Gender: %s\n", gender);
    printf("Weight: %lf (in pounds)\n", weight_in_pounds);
    printf("Height: %lf (in inches)\n", height_in_inches);
    printf("Age: %d (in years)\n\n", age_in_years);


    //Compute the BMR
    double BMR = 0.0;
    BMR = compute_BMR(gender, weight_in_pounds, height_in_inches, age_in_years);



    //Prompt the user for activity level through the keyboard
    char activity_level = NULL;
    printf("Please enter the person's activity level (s,l,m,h,e)\nwith the standing ('s'= sedentary, 'l'= low activity, 'm'= moderate activity, 'h'= high activity, 'e'= extra activity): ");
    scanf(" %c", &activity_level);
    

    //Compute the total daily calorie intake 
    double Calories = 0.0;
    Calories = compute_daily_calorie_intake(BMR, activity_level);


    //Display the BMR and Calories to the screen
    display_calories(BMR, Calories);


    fclose(infile_1);





    // Task 2  (Program to determine a professional baseball player's bonus at the end of a season)
    printf("\n\n2) ");   //start task 2


    char award1[50] = "All-Star Game appearance($25,000)";     char ans1 = NULL; 
    char award2[50] = "Regular season MVP($75,000)";           char ans2 = NULL;
    char award3[50] = "World Series MVP($100,000)";            char ans3 = NULL;
    char award4[50] = "Gold Glove award($50,000)";             char ans4 = NULL;
    char award5[50] = "Silver Slugger award($35,000)";         char ans5 = NULL;
    char award6[50] = "Home run champ($25,000)";               char ans6 = NULL;
    char award7[50] = "Batting average champ($25,000)";        char ans7 = NULL;


    //Prompt the user for yes-no questions to add the bonus
    printf("Please answer seven yes-no questions about the bonus!\n");
    ans1 = answer_questions(award1);
    ans2 = answer_questions(award2);
    ans3 = answer_questions(award3);
    ans4 = answer_questions(award4);
    ans5 = answer_questions(award5);
    ans6 = answer_questions(award6);
    ans7 = answer_questions(award7);


    //Add the bonus to the total 
    int bonus1 = 25000, bonus2 = 75000, bonus3 = 100000, bonus4 = 50000, bonus5 = 35000, bonus6 = 25000, bonus7 = 25000;

    int add1=0, add2=0, add3=0, add4=0, add5=0, add6=0, add7= 0;  //I use "adding values" to replace the repetition function that we have not learned  


    add1 = add_bonus(ans1, bonus1);
    add2 = add_bonus(ans2, bonus2);
    add3 = add_bonus(ans3, bonus3);
    add4 = add_bonus(ans4, bonus4);
    add5 = add_bonus(ans5, bonus5);
    add6 = add_bonus(ans6, bonus6);
    add7 = add_bonus(ans7, bonus7);


    //Compute the total bonus by summing all the "adding values"
    int total_bonus = 0;
    total_bonus = add1 + add2 + add3 + add4 + add5 + add6 + add7;


    //Display the result to the screen
    display_total_bonus(total_bonus);






    //Task 3 (Program reads five numbers and performs operations)
    printf("\n3) ");   //start task 3

    FILE* infile_3 = NULL;
    infile_3 = fopen("data3.txt", "r");  //input file opened with read permisions “r”

    //Read the five numbers from the file
    double num1 = 0.0, num2 = 0.0, num3 = 0.0, num4 = 0.0, num5 = 0.0;
    num1 = read_number(infile_3);
    num2 = read_number(infile_3);
    num3 = read_number(infile_3);
    num4 = read_number(infile_3);
    num5 = read_number(infile_3);
    printf("The five numbers in the input file:\n %lf, %lf, %lf, %lf, %lf\n", num1, num2, num3, num4, num5);


    //Display the menu with operations
    printf("\n\t\t\tMENU WITH OPTIONS OF OPERATIONS\n");
    printf("\t\t\t\t1. Average\n");
    printf("\t\t\t\t2. High Value\n");
    printf("\t\t\t\t3. Low Value\n");


    //Get the selected option from the user through the keyboard
    int opt = 0;
    printf("\nPlease enter your option (1, 2,or 3): ");
    scanf("%d", &opt);  //enter opt = 1, 2, or 3


    //Compute the result of the selected operations
    double result = 0.0;
    result = compute_result(opt, num1, num2, num3, num4, num5);

    //Display the result to the screen
    display_result(result);


    fclose(infile_3);  //close the file



    return 0;  //the program was successful


 }



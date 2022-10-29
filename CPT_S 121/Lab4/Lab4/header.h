

/*

  This is the header file that stores standard library includes, #defined and function prototypes

*/



#ifndef HEADER_H //guard code

#define HEADER_H

#define _CRT_SECURE_NO_WARNINGS //ignore the error about scanf()

#include<stdio.h> //necessary to use printf() and scanf()





//Function prototype



  // All function prototypes for task 1

/*
  Function:  

  Date Created: Feb 18, 2021

  Date Last Modifiled: Feb 18, 2021

  Description:  This function prompts 

  Input parameters: 

  Returns:  

  Preconditions:  

  Postconditions:  
*/
void get_gender(FILE* infile, char gender[10]);






/*
  Function:

  Date Created: Feb 18, 2021

  Date Last Modifiled: Feb 18, 2021

  Description:  This function prompts

  Input parameters:

  Returns:

  Preconditions:

  Postconditions:
*/
double get_weight_in_pounds(FILE* infile);


/*
  Function:

  Date Created: Feb 18, 2021

  Date Last Modifiled: Feb 18, 2021

  Description:  This function prompts

  Input parameters:

  Returns:

  Preconditions:

  Postconditions:
*/
double get_height_in_inches(FILE* infile);




/*
  Function:

  Date Created: Feb 18, 2021

  Date Last Modifiled: Feb 18, 2021

  Description:  This function prompts

  Input parameters:

  Returns:

  Preconditions:

  Postconditions:
*/
int get_age_in_years(FILE* infile);





/*
  Function:

  Date Created: Feb 18, 2021

  Date Last Modifiled: Feb 18, 2021

  Description:  This function prompts

  Input parameters:

  Returns:

  Preconditions:

  Postconditions:
*/
double compute_BMR(char gender[10], double weight_in_pounds, double height_in_inches, int age_in_years);




/*
  Function:

  Date Created: Feb 18, 2021

  Date Last Modifiled: Feb 18, 2021

  Description:  This function prompts

  Input parameters:

  Returns:

  Preconditions:

  Postconditions:
*/
double compute_daily_calorie_intake(double BMR, char activity_level);




/*
  Function:

  Date Created: Feb 18, 2021

  Date Last Modifiled: Feb 18, 2021

  Description:  This function prompts

  Input parameters:

  Returns:

  Preconditions:

  Postconditions:
*/
void display_calories(double BMR, double Calories);







// All function prototypes for task 2


/*
  Function:

  Date Created: Feb 18, 2021

  Date Last Modifiled: Feb 18, 2021

  Description:  This function prompts

  Input parameters:

  Returns:

  Preconditions:

  Postconditions:
*/
char answer_questions(char award[50]);






/*
  Function:

  Date Created: Feb 18, 2021

  Date Last Modifiled: Feb 18, 2021

  Description:  This function prompts

  Input parameters:

  Returns:

  Preconditions:

  Postconditions:
*/
int add_bonus(char answer, int bonus);





/*
  Function:

  Date Created: Feb 18, 2021

  Date Last Modifiled: Feb 18, 2021

  Description:  This function prompts

  Input parameters:

  Returns:

  Preconditions:

  Postconditions:
*/
void display_total_bonus(int total_bonus);






// All function prototypes for task 3


/*
  Function:

  Date Created: Feb 18, 2021

  Date Last Modifiled: Feb 18, 2021

  Description:  This function prompts

  Input parameters:

  Returns:

  Preconditions:

  Postconditions:
*/
double read_number(FILE* infile);



/*
  Function:

  Date Created: Feb 18, 2021

  Date Last Modifiled: Feb 18, 2021

  Description:  This function prompts

  Input parameters:

  Returns:

  Preconditions:

  Postconditions:
*/
double compute_average(double num1, double num2, double num3, double num4, double num5);



/*
  Function:

  Date Created: Feb 18, 2021

  Date Last Modifiled: Feb 18, 2021

  Description:  This function prompts

  Input parameters:

  Returns:

  Preconditions:

  Postconditions:
*/
double highest_value(double num1, double num2, double num3, double num4, double num5);




/*
  Function:

  Date Created: Feb 18, 2021

  Date Last Modifiled: Feb 18, 2021

  Description:  This function prompts

  Input parameters:

  Returns:

  Preconditions:

  Postconditions:
*/
double lowest_value(double num1, double num2, double num3, double num4, double num5);



/*
  Function:

  Date Created: Feb 18, 2021

  Date Last Modifiled: Feb 18, 2021

  Description:  This function prompts

  Input parameters:

  Returns:

  Preconditions:

  Postconditions:
*/
double compute_result(int opt, double num1, double num2, double num3, double num4, double num5);




/*
  Function:

  Date Created: Feb 18, 2021

  Date Last Modifiled: Feb 18, 2021

  Description:  This function prompts

  Input parameters:

  Returns:

  Preconditions:

  Postconditions:
*/
void display_result(double result);



#endif 

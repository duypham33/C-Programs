
/*
      * Programmer: Duy Pham

      * Class: CptS 121, Spring 2021; Section 01; Lab Section 14

      * Programming Assignment: Lab 3 Task 1

      * Date: February 10, 2021

      * Description: This program prompts the user for weight in pounds and height in feet, then convert the height into inches and calculate the BMI by the formula:
                                            BMI = ((weight in pounds) / (height in inches)^2 ) * 703

*/


#define _CRT_SECURE_NO_WARNINGS //ignore the error about scanf()

#include<stdio.h> //necessary to use printf() and scanf()


// function prototypes


/*
  Function:   get_weight ()

  Date Created: Feb 10, 2021

  Date Last Modifiled: Feb 10, 2021

  Description:  This function  prompts the user for weight in pounds, and returns the weight

  Input parameters: None

  Returns:  The weight

  Preconditions:  None

  Postconditions:  The weight has been got and returned
*/
double get_weight(void);






/*
  Function:   get_height ()

  Date Created: Feb 10, 2021

  Date Last Modifiled: Feb 10, 2021

 Description:  This function  prompts the user for height in feet, and returns the height

 Input parameters: None

 Returns:  The height

 Preconditions:  None

 Postconditions:  The height has been got and returned
*/

double get_height(void);





/*
Function:   convert_feet_to_inches ()

Date Created: Feb 10, 2021

Date Last Modifiled: Feb 10, 2021

Description:  This function converts the height of the user from feet to inches, and returns the height in inches

Input parameters:  The height in feet

Returns:  The height in inches

Preconditions:   The height in feet

Postconditions:    The height in inches has been converted
*/

double convert_feet_to_inches(double height_in_feet);





/*
Function:   calculate_BIM ()

Date Created: Feb 10, 2021

Date Last Modifiled: Feb 10, 2021

Description:  This function evaluates the BMI based on weight in pounds and height in inches, and returns the BMI

Input parameters: The weight in pounds and the height in feet

Returns:   The BMI

Preconditions:  The weight in pounds and the height in feet

Postconditions:  BMI has been calculated
*/

double calculate_BMI(double weight_in_pounds, double height_in_feet);





/*
Function:  display_BMI

Date Created: Feb 10, 2021

Date Last Modifiled: Feb 10, 2021

Description:  This function display the resultant BMI value to the tenths place

Input parameters:   The BMI

Returns:  None

Preconditions: The BMI

Postconditions:  The result has been displayed on the screen
*/

void display_BMI(double BMI);




int main(void)
{
    double weight_in_pounds = 0.0, height_in_feet = 0.0;

    // Prompt the user for weight in pounds and height in feet

    weight_in_pounds = get_weight();
    height_in_feet = get_height();


    // Convert the height to inches
    double height_in_inches = 0.0;
    height_in_inches = convert_feet_to_inches(height_in_feet);


    // Compute the BMI 
    double BMI = 0.0;
    BMI = calculate_BMI(weight_in_pounds, height_in_feet);


    // Display the BMI value to the screen
    display_BMI(BMI);


    return 0; //the program was successful
}



double get_weight(void)  //function header
{
    // function definition

    // Prompt the user for weight in pounds
    printf("Enter the weight (in pounds): ");

    // Get the weight from the user through the keyboard
    double weight_in_pounds = 0.0;
    scanf("%lf", &weight_in_pounds);

    return weight_in_pounds;
}


double get_height(void)  //function header
{
    // function definition

    // Prompt the user for height in feet
    printf("Enter the height (in feet): ");

    // Get the height from the user through the keyboard
    double height_in_feet = 0.0;
    scanf("%lf", &height_in_feet);

    return height_in_feet;
}


double convert_feet_to_inches(double height_in_feet)   //function header
{
    // function definition

    double height_in_inches = 0.0;
    height_in_inches = height_in_feet * 12; //since 1 foot = 12 inches
    return height_in_inches;

}


double calculate_BMI(double weight_in_pounds, double height_in_feet)    //function header
{
    // function definition

    double BMI = 0.0; double height_in_inches = 0.0;

    height_in_inches = convert_feet_to_inches(height_in_feet);

    BMI = (weight_in_pounds / ((height_in_inches) * (height_in_inches))) * 703;   // Compute the BMI by the formula

    return BMI;
}



void display_BMI(double BMI)   //funciton header
{
    // function definition

 // Display the BMI value to the screen

    printf("The BMI value = ( (weight in pounds) / (height in inches)^2 ) * 703 = %lf\n", BMI);


}
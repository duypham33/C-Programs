
/*

  This is the header file that stores standard library includes, #defined and function prototypes

*/


#ifndef HEADER_H //guard code

#define HEADER_H


#define _CRT_SECURE_NO_WARNINGS //ignore the error about scanf()

#include<stdio.h>    //necessary to use printf() and scanf()

#include<string.h>   //necessary to use strcpy() and strtok()

#include <stdlib.h>  //necessary to use atoi()




typedef struct profile
{
	char name[100];           // customer's name - last, first
	char plan;                // plan 'A' or 'B'
	int talk_minutes;         // number of minutes used for talking
	int data_MB;              // amount of data used in MB
	double charges;           // total charges for this customer

} Profile;








//Function prototype





//All the function prototypes 



/*
  Function:      char convert_string_to_char()

  Date Created:     May 4, 2021

  Date Last Modifiled:      May 4, 2021

  Description:  This function converts a string with length of 1 to a char variable (necessary to read the plan of a customer from the input file)

  Input parameters:   A string with length of 1

  Returns:     A character

  Preconditions:   The string with length of 1

  Postconditions:    The character has been returned
*/
char convert_string_to_char(char s[]);




/*
  Function:        void compute_total_charge ()

  Date Created:     May 4, 2021

  Date Last Modifiled:      May 4, 2021

  Description:  This function computes the total charge of a customer

  Input parameters:   The pointer to the cusotmer's profile 

  Returns:     None

  Preconditions:   The pointer to the cusotmer's profile 

  Postconditions:   The total charge has been return indirectly
*/
void compute_total_charge(Profile* customer_ptr);




/*
  Function:     void swap_customers_profiles()

  Date Created:     May 4, 2021

  Date Last Modifiled:      May 4, 2021

  Description:  This function swaps two profiles of two customeers

  Input parameters:   The two pointers to the two cusotmers' profiles 

  Returns:   None

  Preconditions:  The two pointers to the two cusotmers' profiles

  Postconditions:   None
*/
void swap_customers_profiles(Profile* cus1_ptr, Profile* cus2_ptr);




/*
  Function:    void sort_profiles()

  Date Created:     May 4, 2021

  Date Last Modifiled:      May 4, 2021

  Description:  This function sorts customer plans based on their names (in reverse dictionary ordering ‘z’ – ‘a’)

  Input parameters:    The array of customers' profiles, and the number of customers

  Returns:   None

  Preconditions:     The array of customers' profiles, and the number of customers

  Postconditions:    None
*/
void sort_profiles(Profile customers[], int num_customers);




/*
  Function:   double max_charge()

  Date Created:     May 4, 2021

  Date Last Modifiled:      May 4, 2021

  Description:  This function finds maximum charge of from all the profiles

  Input parameters:    The array of customers' profiles, and the number of customers

  Returns:    The max charge

  Preconditions:    The array of customers' profiles, and the number of customers

  Postconditions:    The max charge has been returned
*/
double max_charge(Profile customers[], int num_customers);




/*
  Function:    double min_charge()

  Date Created:     May 4, 2021

  Date Last Modifiled:      May 4, 2021

  Description:  This function finds minimum charge of from all the profiles

  Input parameters:    The array of customers' profiles, and the number of customers

  Returns:    The min charge

  Preconditions:    The array of customers' profiles, and the number of customers

  Postconditions:    The min charge has been returned
*/
double min_charge(Profile customers[], int num_customers);







#endif

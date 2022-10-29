

/*

  This is the header file that stores standard library includes, #defined and function prototypes

*/


#ifndef HEADER_H //guard code

#define HEADER_H


#define _CRT_SECURE_NO_WARNINGS //ignore the error about scanf()


#include<stdio.h>    //necessary to use printf() and scanf()

#include<stdlib.h>   //necessary to use rand() and srand()

#include<time.h>     //necessary to use time()

#include <string.h>  //necessary to use strcmp()


//Global variable for the point
extern int POINT;   // extern tells the compiler that global variables exist somewhere else



//Function prototypes


/*
  Function:     void print_menu()

  Date Created:    April 26th, 2022

  Date Last Modifiled:    April 26th, 2022

  Description:  This function displays the main menu to the screen

  Input parameters:  None

  Returns:     None 

  Preconditions:   None

  Postconditions:   The main menu has been displayed to the screen.
*/
void print_menu();



/*
  Function:     int get_user_option()

  Date Created:    April 26th, 2022

  Date Last Modifiled:    April 26th, 2022

  Description:  This function prompts the user for the menu option.

  Input parameters:  None

  Returns:     The menu option

  Preconditions:   None

  Postconditions:   The valid option has been returned.
*/
int get_user_option();



/*
  Function:     void display_tutorial()

  Date Created:    April 26th, 2022

  Date Last Modifiled:    April 26th, 2022

  Description:  This function displays the tutorial of the program

  Input parameters:  None

  Returns:     None

  Preconditions:   None

  Postconditions:   The tutorial has been displayed to the screen.
*/
void display_tutorial();





/*
  Function:     char* get_initials()

  Date Created:    April 26th, 2022

  Date Last Modifiled:    April 26th, 2022

  Description:  This function gets the user's initials

  Input parameters:  The pointer to the string initials

  Returns:     The pointer to the string initials

  Preconditions:   None

  Postconditions:   The pointer to the string initials has been returned.
*/
char* get_initials(char* initials);





/*
  Function:      int select_difficulty()

  Date Created:    April 26th, 2022

  Date Last Modifiled:    April 26th, 2022

  Description:  This function prompts the user for the level of difficulty.

  Input parameters:  None

  Returns:     The level of difficulty

  Preconditions:   None

  Postconditions:   The level of difficulty has been returned.
*/
int select_difficulty();




/*
  Function:       void print_operator()

  Date Created:    April 26th, 2022

  Date Last Modifiled:    April 26th, 2022

  Description:  This function prints out the operator to the screen based on the operator type.

  Input parameters:  The operator type

  Returns:     None

  Preconditions:   None

  Postconditions:   The operator has been printed out the screen.
*/
void print_operator(int operator_type);




/*
  Function:     int perform_operation()

  Date Created:    April 26th, 2022

  Date Last Modifiled:    April 26th, 2022

  Description:  This function performs the operation on the two integers based on the operator type.

  Input parameters:  The two integer operands and the operator type

  Returns:     The result of the operation

  Preconditions:   None

  Postconditions:   The result of the operation has been returned.
*/
int perform_operation(int op1, int op2, int operator_type);




/*
  Function:    int generate_number()

  Date Created:    April 26th, 2022

  Date Last Modifiled:    April 26th, 2022

  Description:  This function randomly generates an integer between a lower bound and upper bound 

  Input parameters:  The integer lower bound and upper bound

  Returns:     The generated number 

  Preconditions:   None

  Postconditions:   The generated number has been returned.
*/
int generate_number(int lower_bound, int upper_bound);



/*
  Function:    int easy()

  Date Created:    April 26th, 2022

  Date Last Modifiled:    April 26th, 2022

  Description:  This function generates a question of easy level

  Input parameters:  The hard level

  Returns:     The result of the question

  Preconditions:   None

  Postconditions:   The result of the question has been returned.
*/
int easy(int hard_level);



/*
  Function:    int fair()

  Date Created:    April 26th, 2022

  Date Last Modifiled:    April 26th, 2022

  Description:  This function generates a question of fair level

  Input parameters:  The hard level

  Returns:     The result of the question

  Preconditions:   None

  Postconditions:   The result of the question has been returned.
*/
int fair(int hard_level);



/*
  Function:    void intermediate()

  Date Created:    April 26th, 2022

  Date Last Modifiled:    April 26th, 2022

  Description:  This function generates a question of intermediate level

  Input parameters:  The hard level, and the pointers to quotient and remainder

  Returns:     None

  Preconditions:   None

  Postconditions:   The results of the question has indirectly been returned.
*/
void intermediate(int* quotient, int* remainder, int hard_level);




/*
  Function:    int generate_denominator

  Date Created:    April 26th, 2022

  Date Last Modifiled:    April 26th, 2022

  Description:  This function generates a denominator of an integer number 

  Input parameters:  The integer number, and the lower bound and upper bound

  Returns:     The generated denominator

  Preconditions:   None

  Postconditions:   The generated denominator has been returned.
*/
int generate_denominator(int num, int lower_bound, int upper_bound);



/*
  Function:      int generate_number2()

  Date Created:    April 26th, 2022

  Date Last Modifiled:    April 26th, 2022

  Description:  This function generates an integer number between lower bound and upper bound, and different from -2, -1, 0, 1, 2

  Input parameters:  The lower bound and upper bound

  Returns:     The generated number

  Preconditions:   None

  Postconditions:   The generated number has been returned.
*/
int generate_number2(int lower_bound, int upper_bound);



/*
  Function:    int hard()

  Date Created:    April 26th, 2022

  Date Last Modifiled:    April 26th, 2022

  Description:  This function generates a question of hard level

  Input parameters:  The hard level

  Returns:     The result of the question

  Preconditions:   None

  Postconditions:   The result of the question has been returned.
*/
int hard(int hard_level);



/*
  Function:    int impossible()

  Date Created:    April 26th, 2022

  Date Last Modifiled:    April 26th, 2022

  Description:  This function generates a question of impossible level

  Input parameters:  None

  Returns:     The result of the question

  Preconditions:   None

  Postconditions:   The result of the question has been returned.
*/
int impossible();




/*
  Function:      void generate_message()

  Date Created:    April 26th, 2022

  Date Last Modifiled:    April 26th, 2022

  Description:  This function generates the message based on the correction.

  Input parameters:  The flag correct or not, and the level of the question

  Returns:     None

  Preconditions:   None

  Postconditions:   The message has been generated.
*/
void generate_message(int incorrect_correct, int level);



/*
  Function:     void run()

  Date Created:    April 26th, 2022

  Date Last Modifiled:    April 26th, 2022

  Description:  This function runs the whole the sequence of ten problems.

  Input parameters:  The level of the sequence

  Returns:     None

  Preconditions:   None

  Postconditions:   None
*/
void run(int level);





/*
  Function:    int search_lastest_record()

  Date Created:    April 26th, 2022

  Date Last Modifiled:    April 26th, 2022

  Description:  This function seaches latest record in the file through the user's initials

  Input parameters:  The input file, and pointer to the initials

  Returns:     Found (1 is found, 0 is not found)

  Preconditions:   The input file was openned with read permission.

  Postconditions:   
*/
int search_lastest_record(FILE* infile, char* initials);



#endif

/*

  This is the header file that stores standard library includes, #defined and function prototypes

*/


#ifndef HEADER_H //guard code

#define HEADER_H


#define _CRT_SECURE_NO_WARNINGS //ignore the error about scanf()

#include<stdio.h>    //necessary to use printf() and scanf()

#include<string.h>   //necessary to use strlen()


#define NUM 5    //The number of the array in task 2


typedef struct occurrences    //Struct for task 6

{

    int num_occurrences;

    double frequency;

} Occurrences;



//Define the number of rows and columns of the array in task 7
#define NUM_ROWS 4
                       //We can change the numbers as we want
#define NUM_COLS 5









//Function prototype





//The function prototype for task 1



/*
  Function:     char* my_str_n_cat ()

  Date Created:      April 28, 2021

  Date Last Modifiled:        April 28, 2021

  Description:   This functions copies one string into another 

  Input parameters:  Pointer to destination, pointer to source, and an unsigned integer number

  Returns:    Pointer to destination 

  Preconditions:   Pointer to destination, pointer to source, and an unsigned integer number

  Postconditions:   None
*/
char* my_str_n_cat(char* destination, const char* source, unsigned int n);






//The function prototype for task 2



/*
  Function:     int binary_search()

  Date Created:      April 28, 2021

  Date Last Modifiled:        April 28, 2021

  Description:   This functions finds the index of a target value in an int array

  Input parameters:    Sorted integer array, the size and the target value

  Returns:     Index of target value (-1 if not found)

  Preconditions:    Sorted integer array, the size and the target value

  Postconditions:    None
*/
int binary_search(int values[], int target, int num_values);





//The function prototype for task 3



/*
  Function:      void bubble_sort ()

  Date Created:      April 28, 2021

  Date Last Modifiled:        April 28, 2021

  Description:   This functions sorts an array of strings based on ASCII values

  Input parameters:    Array of pointers to strings, size of array

  Returns:    None

  Preconditions:     Array of pointers to strings, size of array

  Postconditions:    None
*/
void bubble_sort(char* str[], int size);





//The function prototype for task 4



/*
  Function:    int is_palindrome ()

  Date Created:      April 28, 2021

  Date Last Modifiled:        April 28, 2021

  Description:   This functions recursively determines if a strin is a palindrome

  Input parameters:   The pointer to the string, and the length 

  Returns:    1 if palindrome, 0 otherwise

  Preconditions:     The pointer to the string, and the length 

  Postconditions:    None
*/
int is_palindrome(char* str, int length);




//The function prototypes for task 5



/*
  Function:    int is_prime ()

  Date Created:      April 28, 2021

  Date Last Modifiled:        April 28, 2021

  Description:   This functions determines whether an unsigned integer number is prime or not

  Input parameters:    The unsigned integer number

  Returns:   1 is true, 0 is false

  Preconditions:    The unsigned integer number

  Postconditions:    None
*/
int is_prime(unsigned int n);





/*
  Function:      int sum_primes ()

  Date Created:      April 28, 2021

  Date Last Modifiled:        April 28, 2021

  Description:   This functions recursively calculates the sum of primes to a number

  Input parameters:       The unsigned integer number

  Returns:    The sum of the primes up to n 

  Preconditions:        The unsigned integer number

  Postconditions:   The sum has been returned
*/
int sum_primes(unsigned int n);




//The function prototypes for task 6



/*
  Function:    void init_occ_array()

  Date Created:      April 28, 2021

  Date Last Modifiled:        April 28, 2021

  Description:   This functions initializes array of structs

  Input parameters:    Occurrences array and the size  

  Returns:     None
   
  Preconditions:     Occurrences array and the size  

  Postconditions:     None
*/
void init_occ_array(Occurrences occ[], int size);





/*
  Function:     void maximum_occurrences ()

  Date Created:      April 28, 2021

  Date Last Modifiled:        April 28, 2021

  Description:   This functions determines the frequency of characters in a string

  Input parameters:    String, array of struct Occurrences, pointer to int, pointer to char

  Returns:      None

  Preconditions:    String, array of struct Occurrences, pointer to int, pointer to char

  Postconditions:    None
*/
void maximum_occurrences(char* string, Occurrences occ[], int* max_occ, char* char_occ_max);










//The function prototypes for task 7



/*
  Function:    int is_consective ()

  Date Created:      April 28, 2021

  Date Last Modifiled:        April 28, 2021

  Description:   This functions determines if the value at a index is consective or not

  Input parameters:   The array, the number of rows and columns, and the index

  Returns:    1 is true, 0 is false

  Preconditions:   The array, the number of rows and columns, and the index

  Postconditions:  1 or 0 has been returned
*/
int is_consective(int arr[][NUM_COLS], int num_rows, int num_cols, int index);



/*
  Function:   int num_consective_integers ()

  Date Created:      April 28, 2021

  Date Last Modifiled:        April 28, 2021

  Description:   This functions calculates the length of the sequence at the index in which the corresponding value is consective

  Input parameters:    The array, the number of rows and columns, and the index

  Returns:  The length

  Preconditions:    The array, the number of rows and columns, and the index

  Postconditions:   The length has been returned
*/
int num_consective_integers(int arr[][NUM_COLS], int num_rows, int num_cols, int index);




/*
  Function:   int target_index_max_consective_integers()

  Date Created:      April 28, 2021

  Date Last Modifiled:        April 28, 2021

  Description:   This functions determines the target index of the value with maximum consecutive sequence and the length of tht sequence

  Input parameters:    The array, the number of rows and columns, and the pointer to the maximum consecutive sequence of the same integer

  Returns:      The target index 

  Preconditions:   The array, the number of rows and columns, and the pointer to the maximum consecutive sequence of the same integer

  Postconditions:   The target index has been returned
*/
int target_index_max_consective_integers(int arr[][NUM_COLS], int num_rows, int num_cols, int* max_ptr);




/*
  Function:   void max_consecutive_integers ()

  Date Created:      April 28, 2021

  Date Last Modifiled:        April 28, 2021

  Description:   This functions finds the maximum consecutive sequence of one integer int the two-dimensional array

  Input parameters:  The array, the number of rows and columns, the double pointer to the address max consective and the pointer to the maximum consecutive sequence 

  Returns:  None 

  Preconditions:   The array, the number of rows and columns, the double pointer to the address max consective and the pointer to the maximum consecutive sequence 

  Postconditions:  None
*/
void max_consecutive_integers(int arr[][NUM_COLS], int num_rows, int num_cols, int** address_max_consec_ptr, int* num_consec_values_ptr);













#endif
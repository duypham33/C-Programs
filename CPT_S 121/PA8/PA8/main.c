
/*
      * Programmer: Duy Pham

      * Class: CptS 121, Spring 2021; Section 01; Lab Section 14

      * Programming Assignment:     BONUS Programming Assignment 8: C Interview Questions

      * Date:    April 28, 2021

      * Description: This program performs seven different tasks:
                      - Task 1: Write a function called my_str_n_cat()
                      - Task 2: Write a C function called binary_search()
                      - Task 3: Write a function called bubble_sort() that accepts an array of pointers to strings 
                                and the number of strings as arguments, and returns nothing. The function sorts the strings
                      - Task 4: Write a recursive function called is_palindrome() that accepts a pointer to a string 
                                and its length, and recursively determines if the string is a palindrome. 
                                A palindrome is a sequence of symbols that may be interpreted the same forward and backward
                      - Task 5: Write a recursive function called sum_primes() that accepts an unsigned integer, n, as an argument, 
                                and returns the sum of all primes from 2 to n
                      - Task 6: Write a function called maximum_occurences() that accepts a pointer to a string 
                               (consisting of alphanumeric and whitespace characters only), a pointer to an array of struct occurrences,  
                                a pointer to an integer, and a pointer to a character as arguments.
                      - Task 7: Write a function called max_consecutive_integers() that accepts a two-dimensional array of signed integers,
                                the number of rows, the number of columns as input parameters, 
                                and two pointers as output parameters (one of these pointers is actually a pointer to a pointer, i.e. two stars!).
                                The function finds the maximum consecutive sequence of one integer. 
                                The first pointer stores the address the start of the maximum consecutive sequence of the same integer.
                                The second indirectly stores the number the same consecutive integers in a row. These sequences may wrap from one row to the next.
*/



#include "header.h"


int main(void)
{
    //Task 1
    printf("1) ");     //Start task 1

    char dept[30] = "Cpts ";
    char cour_num[30] = "121 Spring!";

    my_str_n_cat(dept, cour_num, 3);
    printf("The course: ");
    puts(dept);



    //Task 2
    getch();
    printf("\n\n2) ");     //Start task 2

    int sorted_arr[5] = { 3, 7, 17, 27, 30 };

    int i = 0;   //The index for loops
    printf("The sorted array: ");
    for (i = 0; i < NUM; i++)
    {
        printf("%3d  ", sorted_arr[i]);
    }

    printf("\n");

    printf("The index of the value 27 in the array is: %d\n", binary_search(sorted_arr, 27, 5));


    //Task 3
    getch();
    printf("\n3) ");     //Start task 3

    char* str[5] = { "Cat", "Dog", "Chicken", "Monkey", "Fish" };

    printf("The array of strings before softing: ");
    for (i = 0; i < 5; i++)
    {
        printf("%s  ", str[i]);
    }


    bubble_sort(str, 5);

    printf("\n\nThe array of strings after softing:  ");
    
    for (i = 0; i < 5; ++i)
    {
        printf("%s  ", str[i]);
    }



    //Task 4
    getch();
    printf("\n\n4) ");     //Start task 4

    char* string = "race car";
   
    printf("Our string: "); puts(string);

        if (is_palindrome(string, strlen(string)) == 1)
        {
            printf("The string is a palindrome!\n");
        }

        else
        {
            printf("The string is not a palindrome!\n");
        }






        //Task 5
        getch();
        printf("\n5) ");     //Start task 5

        unsigned int n = 0;
        printf("Please enter an unsigned integer value n: ");
        scanf("%d", &n);

        printf("The sum of all primes from 2 to %d: %d\n", n, sum_primes(n));




        //Task 6
        getch();
        printf("\n6) ");     //Start task 6


        string = "Taraba ablub4979 tubo599";
        printf("The string (consisting of alphanumeric and whitespace characters only): ");
        puts(string);

        Occurrences occ[123] = { {0, 0.0} };

        init_occ_array(occ, 123);

        int max_occ = 0;
        char ch_occ_max = NULL;
 
        
        maximum_occurrences(string, occ, &max_occ, &ch_occ_max);


        


        //Task 7
        getch();
        printf("\n7) ");     //Start task 7

        int arr[NUM_ROWS][NUM_COLS] = { 0 };

        
        //Prompt the user for values of the array
        printf("Please enter values of the array:\n");

        for (i = 0; i < NUM_ROWS; ++i)
        {
            for (int j = 0; j < NUM_COLS; ++j)
            {
                printf("arr[%d][%d]: ", i, j);
                scanf("%d", &arr[i][j]);
            }
        }


        //Display the array to the screen
        printf("\n\n");
        for (i = 0; i < NUM_ROWS; ++i)
        {
            for (int j = 0; j < NUM_COLS; ++j)
            {
                printf("  %3d (%d)   ", arr[i][j], &arr[i][j]);
            }

            printf("\n");
        }


        int maxinum_consec_values = 0;
        int* address_max_consec_ptr = 0;

        max_consecutive_integers(arr, NUM_ROWS, NUM_COLS, &address_max_consec_ptr, &maxinum_consec_values);





    return 0;      //The program was successfull
}
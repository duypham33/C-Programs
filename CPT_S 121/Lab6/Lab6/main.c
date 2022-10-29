
/*
      * Programmer: Duy Pham

      * Class: CptS 121, Spring 2021; Section 01; Lab Section 14

      * Programming Assignment:     Wonderful World of Iterative Statements in C Continued

      * Date: March 5, 2021

      * Description: This program performs three different tasks:
                      - Task 1: Determines if the sum of the integers and its the individual digits are prime numbers
                      - Task 2: Determines the factorial of n, represented n!
                      - Task 3: Determines the Fibonacci number for the nth term                   

*/



#include "header.h"


int main(void)
{

    //Task 1 (Determines if the sum of the integers and its the individual digits are prime numbers)
    printf("1) ");   //start task 1


    FILE* infile = NULL;

    infile = fopen("data1.txt", "r");   //input file opened with read permisions "r"



    //Read all the integers from the file and sum them 
    int value = 0;  int sum = 0;

    printf("Integer values in the file: \n");

    while (!feof(infile))
    {
        fscanf(infile, "%d", &value);
        printf("\t%d\n", value);
        sum += value;
      
    }

    printf("The sum of the integers: %d\n", sum);




    //Determines if the sum of the integers is prime
    if ( is_prime(sum) == 0 )
    {
        printf("The sum of the integers is a prime number!\n");
    }
    else { printf("The sum of the integers is not a prime number!\n"); }




    //Calculate the sum of digits, in the sum of the integers
    int sum_digits = 0;
    sum_digits = calculate_sum_digits(sum);

    printf("\nThe sum of the individual digits, in the sum of the integers: %d\n", sum_digits);




    //Determine if the sum of the individual digits, in the sum of the integers, is prime
    if (is_prime(sum_digits) == 0)
    {
        printf("The sum of the individual digits, in the sum of the integers is a prime number!\n");
    }
    else { printf("The sum of the individual digits, in the sum of the integers is not a prime number!\n"); }


    fclose(infile);






    //Task 2 (Determines the factorial of n, represented n!)
    printf("\n2) ");    //start task 2


    //Prompt the user for the non-negative integer number
    printf("Please enter your integer number: ");
    int n = 0;
    scanf("%d", &n);

    while (n < 0)
    {
        printf("\nYour entered number is negative!\nPlease enter another integer number (non-negative): ");
        scanf("%d", &n);
    }


    //Calculate the factorial of the number
    int factorial = 0;
    factorial = calculate_factorial(n);

    printf("\nThe factorial of n: %d! = %d\n", n, factorial);





    //Task 3 (Determines the Fibonacci number for the nth term)
    printf("\n3) ");  //start task 3


    //Prompt the user for the non-negative integer number
    printf("Please enter your integer number: ");
       n = 0;
    scanf("%d", &n);

    while (n < 0)
    {
        printf("\nYour entered number is negative!\nPlease enter another integer number (non-negative): ");
        scanf("%d", &n);
    }



    //Determines the Fibonacci number for the nth term
    int Fibonacci = 0;
    Fibonacci = calculate_Fibonacci(n);

    printf("\nThe Fibonacci number for the nth term: Fib (%d) = %d\n", n, Fibonacci);




    return 0;   //The program was successfull


}
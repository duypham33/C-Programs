
/*
      * Programmer: Duy Pham

      * Class: CptS 121, Spring 2021; Section 01; Lab Section 14

      * Programming Assignment:     Lab 13: Bit Manipulation

      * Date:     April 22, 2021

      * Description: This program performs three different tasks:
                      - Task 1: A program that right shifts an integer variable 4 bits. 
                               The program should print the integer in bits before and after the shift operation.

                      - Task 2: Write a function power2() that takes two integer arguments number and pow and calculates number * 2^pow.
                                Use the shift operator to calculate the result. Print the values as integers and as bits.

                      - Task 3: Write a program that inputs four characters from the keyboard and passes them to function packCharacters().
                                To pack four characters into an unsigned integer variable, assign the first character to the unsigned variable
                                , shift the unsigned variable left by 8 bit positions and combine the unsigned variable with the second character using the bitwise inclusive OR operator.
                                Continue to shift by 8 and OR until all characters have been packed into the 4 byte unsigned integer variable.
                                The program should output the characters in their bit format before and after they are packed into the unsigned integer
                                to prove that the characters are in fact packed correctly in the unsigned variable
                      
*/



#include "header.h"


int main(void)
{

    //Task 1
    printf("1) ");     //Start task 1

    unsigned int n;

    //Prompt the user for an unsigned integer number
    printf("Please enter an unsigned integer value: ");
    scanf("%d", &n);


    printf("\nThe integer number in bits binary form: ");
    print_binary_form(n);

    n = n >> 4;
    printf("\nThe integer number in bits binary form after right shifting by 4 bits: ");
    print_binary_form_after_rightshift_4bits(n);




    //Task 2
    printf("\n\n2) ");    //Start task 2
    
    int number = 0;
    //Prompt the user for an unsigned integer number
    printf("Please enter an integer value: ");
    scanf("%d", &number);

    printf("\nThe integer number in bits binary form: ");
    print_binary_form(number);

    int pow = 0;
    printf("\nPlease enter an integer value of a pow: ");
    scanf("%d", &pow);


    int result = power2(number, pow);
    printf("\nThe value of the number * 2^pow as integers: %d\n", result);
    printf("The value of the number * 2^pow as bits: ");
    print_binary_form(result);






    //Task 3
    printf("\n\n3) ");    //Start task 3

    char c1 = NULL, c2 = NULL, c3 = NULL, c4 = NULL;

    //Prompt the user for four characters through the key board
    printf("Please enter four characters: ");
    scanf(" %c %c %c %c", &c1, &c2, &c3, &c4);


    printf("\nThe four characters performed in their bit format respectively: ");
    print_binary_form(c1);   printf("  ");
    print_binary_form(c2);   printf("  ");
    print_binary_form(c3);   printf("  ");
    print_binary_form(c4);   printf("\n\n");


    unsigned int i = packCharacters(c1, c2, c3, c4);
    printf("The unsigned integer packed from these four characters is: %d  in decimal    and   ", i);
    print_binary_form(i); 
    printf("  in bits\n\n");



    return 0;      //The program was successful
}
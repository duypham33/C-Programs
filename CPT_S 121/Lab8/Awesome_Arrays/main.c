
/*
      * Programmer: Duy Pham

      * Class: CptS 121, Spring 2021; Section 01; Lab Section 14

      * Programming Assignment:     Lab 8: Awesome Arrays

      * Date: March 15, 2021

      * Description: This program performs three different tasks:
                      - Task 1: Populates an array with integer values read from a file
                      - Task 2: Populates an array with 20 random integers between 1 - 100. Then use a second array of size 101 to 
                                keep track of the number of times each integer was generated.
                      - Task 3: Programming a game of hangman
                      
*/



#include "header.h"


int main(void)
{

    //Task 1  (The program which populates an array with integer values read from a file)
    printf("1) ");   //start task 1

    FILE* infile = NULL;
    infile = fopen("data.txt", "r");        //input file opened with read permisions “r”

    int size = 0;  int integer_values[50];

    int input_status;

    //Read the values from the input file
    input_status = fscanf(infile, "%d", &integer_values[0]);
    
    while (input_status != EOF)
    {    
        ++size;
        input_status = fscanf(infile, "%d", &integer_values[size]); 

    }


    //Display the array to the screen
    if (size == 0)
    {
        printf("The input file is empty!\n");
    }

    else
    {
        printf("The array populated with integer values read from the input file:\n");
        display_array(integer_values, size);
    }


    fclose(infile);




    //Task 2
    printf("\n2) ");   //start task 2


    //Populates an array with 20 random integers between 1 - 100. And  Use a second array of size 101 to keep track of the number of times each integer was generated
    int arr[20]; int i, j;
    int b[101];    //The second array of size 101


    //Initialize each item in the second array to 0
    for (i = 0; i < 101; i++)
    {
        b[i] = 0;
    }



    srand((unsigned int)time(NULL));

    printf("All the random integer values in the first array:\n");
   
    for (i = 0; i < 20; i++)
    {
        arr[i] = rand() % 100 + 1;

        //Display the array to the screen
        printf("arr[%d]: %d\n", i, arr[i]);

        /*
        For each item in the first array, use it as the index into the second array 
        and increment the contents found in the second array at the corresponding index
        */


        j = arr[i];
        ++b[j];

    }


    //Display the second array to the screen
    printf("\nAll the non-zero values in the second array:\n");

    for (i = 0; i < 101; i++)
    {
        if (b[i] != 0)
        {
            printf("b[%d] = %d, means the value %d was generated %d (once/twice/times) in the first array!\n", i, b[i], i, b[i]);
        }

    }

    
    
    

    //Task 3 (a game of hangman)
    printf("\n3) ");    //start task 3

    char key_word[20] = { 'n', 'h', 'u', 'n', 'g' };    //Create the key word
    size = 0;
    char guess[20];

    while ( key_word[size] != NULL )
    {
        guess[size] = '*';
        ++size;
    }

    int total_guesses = size * 1.5;   //Let total of guesses equals (1.5 * the number of letters) 

    printf("Welcome to the game of hangman!\nThis is your key word: ");
    display_characters(guess, size);
    printf("  (%d letters)\n", size);
    printf("You have %d tries in total!\n", total_guesses);


    int try = 1; char letter; int flag; int num_correct; int win_status;

    do
    {
        printf("\nPlease enter your letter in try %d: ", try);
        scanf(" %c", &letter);

        flag = 0;  // 0 is false, 1 is true
        num_correct = 0;

        for (i = 0; i < size; i++)
        {
            if (letter == key_word[i])
            {
                flag = 1; 
                guess[i] = letter; 
                num_correct++;
            }
        }

        if (flag == 1)   //Correct guess
        {
            printf("Great job! We have %d letter %c!\n", num_correct, letter);
            printf("\t\t");
            display_characters(guess, size);
            printf("\n");
        }

        else
        {
            printf("Sorry! Your guess is incorrect!\n");
        }


        win_status = is_win(guess, size);

        try++;

    } while (try <= total_guesses && win_status == 0);

    
        if (win_status == 1)
        {
            printf("\nCongratulations! You won the game!\n*****************************************************************");
        }


        else
        {
            printf("\nSorry! You lose, good luck for the next time! Thank you!\n*******************************************************************");
        }





    return 0;
}
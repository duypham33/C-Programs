
/*
      * Programmer: Jenny Cheng

      * Class: CptS 121, Spring 2022

      * Programming Assignment:      Bonus Assignment: Educational Math Program

      * Date: April 26th, 2022

      * Description: This program constructs a basic math program which targets elementary school children.
                     Allows the user to enter his/her initials. 
                     Generates five different levels of Mathematics problems. 
                     The player can earn points for correct answers and loses points for incorrect answers.
                     The number of points depends on the difficulty of the problem.
                     Within each level, problems should become a little more difficult as the user enters correct answers.
                     Once the user quits the program, output the user's initials and total score to a file.
                     The player can load your latest record from prior progress through your initials.

*/

#include "header.h"

//Initializes global varibles 
int POINT = 0;


int main(void)
{
    srand((unsigned int)time(NULL));
    
    
    FILE* file = NULL;    //The file to write new record of the new player, and also be used to load progress of previous players 
      
    
    int opt = 0;    // Variable for menu option from the user
    char initials[10] = "";
    int got_initials = 0;   //Flag for whether the player enters his/her initials yet
    int level = 0;

    
    do
    {
        //Display the main menu
        print_menu();

        // Prompt the user for menu option
        opt = get_user_option();
        system("cls");   // Clear the screen


        if (opt == 1)   // Display the tutorial
        {
            display_tutorial();
        }

        else if (opt == 2)   // Get user's initials
        {
            get_initials(initials);
            printf(" Welcome %s\n", initials);

            got_initials = 1;   //Got initials
        }

        else if (opt == 3)   // Load previous progress
        {
            if (got_initials == 0)    //Prompt the player the initials before output to the file
            {
                printf(" We need your initials to load your progress!\n");
                get_initials(initials);
                got_initials = 1;   //Got initials
            }

            file = fopen("records.txt", "r");   //input file opened with read permisions “r”
            if (search_lastest_record(file, initials) == 1)
                printf(" Your latest point is %d\n\n", POINT);
            else
                printf(" There is no record matching with your initials! Your point is still %d!\n\n", POINT);

            fclose(file);   //Close the file
        }

        else if (opt == 4)   // Difficulty selection
        {
            level = select_difficulty();
            run(level);
        }
        
        else if(opt == 5)   // Start a new sequence of problems
        {
            if (level < 5)
                level++;  //Go to the next level 

            run(level);
        }

       
        if (opt != 6)
        {
            printf(" Please, hit the ENTER button to return the main menu!");
            getch();
            system("cls");   // Clear the screen
        }
        

    } while (opt != 6);   // option 6 (Quit)


    //Output the user's initials and total score to a file
    if (got_initials == 0)    //Prompt the player the initials before output to the file
    {
        get_initials(initials);
        got_initials = 1;   //Got initials
    }
        
    file = fopen("records.txt", "a");  //output file opened with append permisions “a”
    fprintf(file, "%s %d\n", initials, POINT);
    fclose(file);   //Close the file


    printf("INITIALS:  %s\nPOINT:  %d\n", initials, POINT);
    printf("Thank you for joining us! \n\n");


    return 0;    //The program was successful
}
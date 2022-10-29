
/*
      * Programmer: Duy Pham

      * Class: CptS 121, Spring 2021; Section 01; Lab Section 14

      * Programming Assignment:     Lab 7: Pointers and Output Parameters

      * Date: March 10, 2021

      * Description: This program performs two different tasks:
                  - Task 1: Computes the total charges and average cost per hour of each customer using InternetLite.
                            Charges customers a flat rate of $7.99 for up to 10 hours of connection time. Additional hours or partial hours are charged at $1.99 each.
                  
                  - Task 2: Calculate the revenues by the function of time: R(t) = 203.265 X (1.071)^t, where R is in millions of dollars and t is the years since 1984.
                            And determine when revenues will likely exceed $1 trillion. 
                            Then print a table of estimated revenues for all the year from 1984 through the year when revenues should exceed $1 trillion.
       

*/



#include "header.h"


int main(void)
{
    //Task 1

    FILE* infile = NULL, * outfile = NULL;

    infile = fopen("data1.txt", "r");       //input file opened with read permisions “r”
    outfile = fopen("outfile.txt", "w");    //output file opened with write permisions “w”


    //Read line 1 (current month and year as two integers) from the input file
    int month = 0, year = 0;
    fscanf(infile, "%d%d", &month, &year);

    //Print month and year to the screen and also the output file
    printf("\t\t\tCurrent Month: %d\tYear: %d\n\n", month, year);

    fprintf(outfile, "\t\t\t\tCurrent Month: %d\tYear: %d\n\n", month, year);



    //Print out the table of contents
    printf("  Order\tCustomer number\t\tNumber of hours used\tTotal charge\tAverage cost per hour\n");

    fprintf(outfile, "  Order\tCustomer number\t\tNumber of hours used\tTotal charge\tAverage cost per hour\n");


    //Compute and print out the total charge and average cost per hour of each customer
    int customer_id = 0; double number_hours = 0.0, total_charge = 0.0, average_cost = 0.0;
    int count = 0;   

    while (!feof(infile))
    {
        count++;

        fscanf(infile, "%d%lf", &customer_id, &number_hours);   //Read customer number (a 5-digit number) and number of hours used from the input file

        charges(number_hours, &total_charge, &average_cost);    //Calculate the total charge and the average cost per hour

        total_charge = round_money(total_charge);               //Round the total charge to two decimal places

        average_cost = round_money(average_cost);               //Round the average cost per hour to two decimal places

        //Print them to the screen and also the output file
        printf("    %d\t%10d\t\t%10.2lf\t%15.2lf\t%20.2lf\n", count, customer_id, number_hours, total_charge, average_cost);

        fprintf(outfile, "    %d\t%10d\t\t%15.2lf\t%20.2lf\t%15.2lf\n", count, customer_id, number_hours, total_charge, average_cost);


    }


    fclose(infile);
    fclose(outfile);




    //Task 2
    printf("\n_______________________________________________________________________________________________\n");    //Start task 2

    outfile = fopen("estimated_revenues.txt", "w");    //output file opened with write permisions “w”

    int target_year = 0;    //The year in which revenues (in millions) will first equal or exceed $1 trillion (a million million)

    target_year = predict(1000000.00);    //Because 1 trillion is equal a million million

    printf("\n\t\tAs the prediction, in the year %d, the revenues will likely exceed $1 trillion!\n", target_year);
    fprintf(outfile, "\t\tAs the prediction, in the year %d, the revenues will likely exceed $1 trillion!\n", target_year);
    

    //Print a table of estimated revenues for all the year from 1984 through the year when revenues should exceed $1 trillion
   
    
    printf("\n\tThe table of estimated revenues from 1984 to the year when the income may exceed $1 trillion\n");
    printf("\n\t\t\tThe year\t\t\tThe estimated revenues\n");

    fprintf(outfile, "\n\tThe table of estimated revenues from 1984 to the year when the income may exceed $1 trillion\n");
    fprintf(outfile, "\n\t\t\t\t\tThe year\t\t\t\t\tThe estimated revenues\n");

    int t = 1984;  double R = 0.0;
    for (t; t <= target_year; t++)
    {
        calculate_revenues(t-1984, &R);    //Because in the funciton, the year is determined since 1984

        printf("\t\t\t%6d\t\t\t\t%15.4lf\n", t, R);

        fprintf(outfile, "\t\t\t\t\t%6d\t\t\t\t\t\t%15.4lf\n", t, R);
    }
    

    fclose(outfile);


    return 0;   //The program was successful

}
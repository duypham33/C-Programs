
/*
      * Programmer: Duy Pham

      * Class: CptS 121, Spring 2021; Section 01; Lab Section 14

      * Programming Assignment:     Lab 5: Wonderful World World World of Iterative Statements 

      * Date: February 24, 2021

      * Description: This program performs four different tasks:
                      - Task 1: Computes the total quarterly dollar salary payments and determines the tax bracket
                      - Task 2: Calculates the average of an unknown number of real values
                      - Task 3: Calculates and returns the greatest common divisor of two integer numbers
                      - Task 4: Reads all numbers from a file and determines the highest and lowest numbers.

*/



#include "header.h"


int main(void)
{
    //Task 1  (Computes the total quarterly dollar salary payments and determines the tax bracket)
    printf("1) ");  //Task 1 starts

    FILE* infile = NULL; 

    infile = fopen("salaries.txt", "r");  //input file opened with read permisions “r”

    //Read the four salary payments from the file and display them to the screen
    int quarterly_salary1 = 0, quarterly_salary2 = 0, quarterly_salary3 = 0, quarterly_salary4 = 0;

    quarterly_salary1 = read_payment(infile);
    quarterly_salary2 = read_payment(infile);
    quarterly_salary3 = read_payment(infile);
    quarterly_salary4 = read_payment(infile);

    printf("The four quarterly dollar salary payments: $%d, $%d, $%d, $%d\n\n", quarterly_salary1, quarterly_salary2, quarterly_salary3, quarterly_salary4);



    //Caculate the sum of the quarterly payments
    int total_payments = 0;  total_payments = calculate_sum(quarterly_salary1, quarterly_salary2, quarterly_salary3, quarterly_salary4);
    
    printf("The sum of the quarterly payments: $%d\n\n", total_payments);


    //Determines the tax bracket 
    char tax_bracket = NULL; 
    tax_bracket = determine_tax_bracket(total_payments);

    fclose(infile);


    //Display the tax bracket to the screen
    display_tax_bracket(tax_bracket);








    //Task 2  (A program calculates the average of an unknown number of real values)
    printf("\n2) ");    //Task 2 starts

    FILE* outfile = NULL;

    infile = fopen("data.txt", "r");      //input file opened with read permisions “r”
    outfile = fopen("output.txt", "w");   //output file opened with write permisions “w”


    double value = 0.0, sum = 0.0; int count = 0;
   
    printf("Real values in the file:\n");

    while (!feof(infile))
    {
        fscanf(infile, "%lf", &value);
        printf("%lf\n", value);
        sum += value;
        count++; 

    }

    //Compute the average
    double average = 0.0;
    average = sum / count;

    //Print the average to the screen and also to the output file
    printf("The average of the real numbers: %lf\n", average);
    fprintf(outfile, "Average: %lf", average);



    fclose(infile);
    fclose(outfile);
        







    //Task 3 (Calculates the greatest common divisor of two integer numbers)
    printf("\n3) ");  //start task 3

    infile = fopen("data3.txt", "r");      //input file opened with read permisions “r”
    outfile = fopen("output3.txt", "w");   //output file opened with write permisions “w”

    //Read the two integer numbers from the input file 
    int number1 = 0, number2 = 0;
    number1 = read_integer(infile);
    number2 = read_integer(infile);

    printf("The two integers: %d  and  %d\n", number1, number2);


    //Determine the greatest common divisor
    int gcd = 0;
    gcd = greatest_common_divisor(number1, number2);


    //Print the GCD to the screen and also to the output file
    printf("The greast common division: %d\n", gcd);
    print_result(outfile, gcd);


    fclose(infile);
    fclose(outfile);








    //Task 4 (A program reads all numbers from a file and determines the highest and lowest numbers)
    printf("\n4) ");  //start task 4

    infile = fopen("data4.txt", "r");   //input file opened with read permisions “r”
   
    double num = 0.0;   int input_status = 0;

    //Read and display all real numbers to the screen 
    printf("Real numbers in the file:\n");
    for (input_status = fscanf(infile, "%lf", &num); input_status != EOF; input_status = fscanf(infile, "%lf", &num))
    {
        printf("%lf\n", num);
    }



    infile = fopen("data4.txt", "r");    //Re-open the input file with read permissions to find the maximum
    //Determines the highest 
    double max = 0.0;
    max = find_highest(infile);
    printf("\nThe highest value: %lf\n", max);
    fclose(infile);



    infile = fopen("data4.txt", "r");    //Re-open the input file with read permissions to find the minimum
    //Determines the lowest 
    double min = 0.0;
    min = find_lowest(infile);
    printf("The lowest value: %lf\n", min);



    fclose(infile);



    return 0;

}
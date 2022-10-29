
/*
      * Programmer: Duy Pham

      * Class: CptS 121, Spring 2021; Section 01; Lab Section 14

      * Programming Assignment:     Lab 11: More with Structs

      * Date: April 8, 2021   

      * Description: This program performs a console application that computes and displays the total payroll for hourly employees at a company.
                     Each employee is represented by a record in a file called payroll.txt. A record consists of the following:
                           -         Employee name (last, first)
                           -         Employee title (B or M)
                           -         Hours worked
                           -         Rate per hour
                  
                    Then write the following information to another file called paid.txt:
                           -         Total payroll (sum of all employees’ total payments)
                           -         Average total payment
                           -         Max total payment
                           -         Min total payment
*/



#include "header.h"


int main(void)
{

    FILE* infile = NULL, * outfile = NULL;

    infile = fopen("payroll.txt", "r");       //input file opened with read permisions “r”
    outfile = fopen("paid.txt", "w");         //output file opened with write permisions “w”


    Employee payroll[200] = { {"", ""}, '\0', 0.0, 0.0, 0.0 };        // the input file may not exceed 200 employee records      

    char line[100];      //the line read


    char* token_ptr = NULL;
    int payroll_index = 0;       //The index keep track payroll


    if (infile == NULL)
    {
        printf("The input file is empty!\n");
        fprintf(outfile, "The input file is empty!\n");
    }
    

    else
    {
        //We opened successfully


        while (fgets(line, 100, infile) != NULL)
        {

            // Using strtok () to separate the line of name into indvidual parts (last and first)

            // The below strtok () will give us the last name
            token_ptr = strtok(line, ",");

            strcpy(payroll[payroll_index].last, token_ptr);            


            //Then give us the first name
            token_ptr = strtok(NULL, "\n");
            strcpy(payroll[payroll_index].first, token_ptr);


            //Read the title
            fgets(line, 100, infile);
            payroll[payroll_index].title = convert_string_to_char(line);


            //Read the total number of hours worked
            fgets(line, 100, infile);
            payroll[payroll_index].hours_worked = atof(line);

            //Read the pay rate per hour
            fgets(line, 100, infile);
            payroll[payroll_index].payrate = atof(line);


            //Compute the total payment for the pay period 
            compute_total_payment(&payroll[payroll_index]);


            ++payroll_index;    //increment payrolls
        }

    }

    
    int num_payrolls = payroll_index;

    int i;   //The index for loop


    //Compute the total or sum of payments for all employees
    double total_payroll = 0.0;


    for (i = 0; i < num_payrolls; ++i)
    {
        total_payroll += payroll[i].total_payment;
    }


    //Compute the average payment per employee
    double average_payment = total_payroll / num_payrolls;

    //Compute the maximum payment and minimum payment
    double max = max_payment(payroll, num_payrolls);
    double min = min_payment(payroll, num_payrolls);


    //Display to the screen
    printf("\t    The record of payments for employees\n");
    printf("    Employee name\t\tTitle\t\tTotal payment\n");

    for (i = 0; i < num_payrolls; ++i)
    {
        printf("    %s %s              \t%c\t       \t%5.2lf\n", payroll[i].first, payroll[i].last, payroll[i].title, payroll[i].total_payment);
    }
    printf("\n**************************************************************************************************************\n");
    printf("\tTotal:   $%.2lf\n", total_payroll);
    printf("\tAverage: $%.2lf\n", average_payment);
    printf("\tMax:     $%.2lf\n", max);
    printf("\tMin:     $%.2lf\n", min);



    //Write the total, average, maximum, and minimum payments to paid.txt
    fprintf(outfile, "Total:   $%.2lf\n", total_payroll);
    fprintf(outfile, "Average: $%.2lf\n", average_payment);
    fprintf(outfile, "Max:     $%.2lf\n", max);
    fprintf(outfile, "Min:     $%.2lf\n", min);



    //Close the files
    fclose(infile);
    fclose(outfile);



    return 0;    //The program was successful
}
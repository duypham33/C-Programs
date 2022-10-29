
/*
      * Programmer: Duy Pham

      * Class: CptS 121, Spring 2021; Section 01; Lab Section 14

      * Programming Assignment:     Lab/Programming Final Exam 

      * Date:    May 4, 2021

      * Description: This program performs a console application that computes and displays the total charges for each customer of a telecommunications company.
                     Each customer’s profile is represented by a record in a file called customers.txt. A record consists of the following:
                           -         Customer name (last, first)
                           -         Customer plan (A or B)
                           -         Talk used in minutes
                           -         Data used in MB

                    Then sort customer plans based on their names (in reverse dictionary ordering ‘z’ – ‘a’). 
                    Compute the charges for each customer based on the plan for the customer, and the talk and data usages.
                    Finally, write the following information to another file called charges.txt:
                           -         Total charges (sum of all customers’ charges)
                           -         Average charges per customer
                           -         Max charges
                           -         Min charges
*/



#include "header.h"


int main(void)
{

    FILE* infile = NULL, * outfile = NULL;

    infile = fopen("customers.txt", "r");       //input file opened with read permisions “r”
    outfile = fopen("charges.txt", "w");         //output file opened with write permisions “w”

    Profile customers[100] = { {NULL}, '\0', 0, 0, 0.0 };  // the input file may not exceed 100 customer profiles


    char line[100];      //the line read
    char* token_ptr = NULL;
    int cus_index = 0;       //The index keep track of customers



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
          
            //First, read the name (last, first)       

            // The below strtok () will give us the name
            token_ptr = strtok(line, "\n");          
            strcpy(customers[cus_index].name, token_ptr);


            //Read the plan
            fgets(line, 100, infile);
            customers[cus_index].plan = convert_string_to_char(line);


            //Read number of minutes used for talking
            fgets(line, 100, infile);
            customers[cus_index].talk_minutes = atoi(line);


            //Read the amount of data used in MB
            fgets(line, 100, infile);
            customers[cus_index].data_MB = atoi(line);


            //Compute the total charges for the customer
            compute_total_charge(&customers[cus_index]);


            ++cus_index;      //increment the index
        }

    }

    

    int num_customers = cus_index;     //After the above loop, the index is the number of customers

    //Sort the array based on customers names ‘z’ – ‘a’
    sort_profiles(customers, num_customers);



    int i;   //The index for loop


    //Compute the sum of all customers’ charges
    double total_charges = 0.0;


    for (i = 0; i < num_customers; ++i)
    {
        total_charges += customers[i].charges;
    }


    //Compute the average charges per customer
    double average_charges = total_charges / num_customers;


    ////Compute the maximum charge and minimum charge
    double max = max_charge(customers, num_customers);
    double min = min_charge(customers, num_customers);



    //Display to the screen
    printf("\t    The record of charges for customers\n");
    printf("  Order   Customers name\t\tPlan\t\tCharges\n");

    for (i = 0; i < num_customers; ++i)
    {
        printf("   %d      %-20s           %c\t       \t%5.2lf\n", i + 1, customers[i].name, customers[i].plan, customers[i].charges);
    }
    printf("\n**************************************************************************************************************\n");
    printf("\tTotal:     $%.2lf\n", total_charges);
    printf("\tAverage:   $%.2lf\n", average_charges);
    printf("\tMax:       $%.2lf\n", max);
    printf("\tMin:       $%.2lf\n", min);




    //Write the total, average, maximum, and minimum payments to paid.txt
    fprintf(outfile, "Total:     $%.2lf\n", total_charges);
    fprintf(outfile, "Average:   $%.2lf\n", average_charges);
    fprintf(outfile, "Max:       $%.2lf\n", max);
    fprintf(outfile, "Min:       $%.2lf\n", min);


    //Close the files
    fclose(infile);
    fclose(outfile);



    return 0;    //The program was successful

}
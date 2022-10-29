
/*

    This file is to establish the definitions for all programmer-defined functions, aside from main ()

*/


#include "header.h"



//All the defined functions for task 1

int read_payment(FILE* infile)
{
    int salary_payment = 0;
    fscanf(infile, "%d", &salary_payment);
    return salary_payment;

}


int calculate_sum(int salary1, int salary2, int salary3, int salary4)
{
    int sum = 0;
    sum = salary1 + salary2 + salary3 + salary4;
    return sum;

}


char determine_tax_bracket(int total_payments)
{
    char tax_bracket = NULL;

    /*
        < $15,000 = low income; $15,000 - $200,000 = medium income; > $200,000 = high income
    */

    if (total_payments < 15000) { tax_bracket = 'l'; }          //‘l’ for low income
    else if (total_payments <= 200000) { tax_bracket = 'm'; }   //‘m’ for medium income
    else { tax_bracket = 'h'; }                                 //‘h’ for high income


    return tax_bracket;

}


void display_tax_bracket(char tax_bracket)
{
    if (tax_bracket == 'l') { printf("The tax bracket is low income!\n"); }
    if (tax_bracket == 'm') { printf("The tax bracket is medium income!\n"); }
    if (tax_bracket == 'h') { printf("The tax bracket is high income!\n"); }
}






//All the defined functions for task 3

int read_integer(FILE* infile)
{
    int number = 0;
    fscanf(infile, "%d", &number);
    return number;

}



int greatest_common_divisor(int num1, int num2)
{
    int a = abs(num1), b = abs(num2);   //change to the absolute values
    int gcd = 0;

    //Determine which are the higher and lower numbers
    int r1 = 0, r2 = 0;     
    if (a >= b) { r1 = a; r2 = b; }
    else { r1 = b; r2 = a; }
     


    int temp = 0;   //Temporary value (necessary to replace values through each loop)

    if (r2 == 0) { printf("The greast common divisor is undefined!\n"); return 0; }

    else
    {
        while (r2 != 0)
        {
            temp = r2;
            r2 = r1 % r2;
            r1 = temp;
        }


        gcd = r1;


        return gcd;
    }
}


void print_result(FILE* outfile, int gcd)
{
    fprintf(outfile, "The greast common division: %d", gcd);

}





//All the defined functions for task 4

double find_highest(FILE* infile)
{
    double num = 0.0; int input_status = 0; double max = 0.0;

    fscanf(infile, "%lf", &max);   //Assume max = the first value in the file

    
    for (input_status = fscanf(infile, "%lf", &num); input_status != EOF; input_status = fscanf(infile, "%lf", &num))
    {
        if (max < num) { max = num; }

    }

    return max;

}




double find_lowest(FILE* infile)
{
    double num = 0.0; int input_status = 0; double min = 0.0;

    fscanf(infile, "%lf", &min);       //Assume min = the first value in the file

    for (input_status = fscanf(infile, "%lf", &num); input_status != EOF; input_status = fscanf(infile, "%lf", &num))
    {
        if (min > num) { min = num; }

    }

    return min;

}
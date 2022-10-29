
/*

    This file is to establish the definitions for all programmer-defined functions, aside from main ()

*/


#include "header.h"



//All the defined functions 

char convert_string_to_char(char s[])
{
    return s[0];
}





void compute_total_payment(Employee* payroll_ptr)
{
    double payment = 0.0;
    double overtime = 0.0;

    /*
        Basic Employee (title B):

-         Payment = hours worked * rate per hour (excluding overtime)

-         Overtime = 1.5 * rate per hour (for each hour over 40 hours worked per week)

-         Total payment = payment + overtime

Manager (title M):

-         Payment = hours worked * rate per hour (excluding overtime)

-         Overtime = 1.8 * rate per hour (for each hour over 40 hours worked per week)

-         Total payment = payment + overtime
    */
    
    if (payroll_ptr->hours_worked <= 80.0)
    {
        payroll_ptr->total_payment = payroll_ptr->hours_worked * payroll_ptr->payrate;
    }


    else
    {

        if (payroll_ptr->title == 'B')     //Basic Employee (title B)
        {
            overtime = 1.5 * payroll_ptr->payrate * (payroll_ptr->hours_worked - 80.0);
        }


        else     //Manager (title M)
        {
            overtime = 1.8 * payroll_ptr->payrate * (payroll_ptr->hours_worked - 80.0);
        }



        payment = 80.0 * payroll_ptr->payrate;

        payroll_ptr->total_payment = payment + overtime;


    }





}


double max_payment(Employee payroll[], int num_payrolls)
{
    double max = payroll[0].total_payment;
    int i;   //the index

    for (i = 0; i < num_payrolls - 1; ++i)
    {
        if (payroll[i].total_payment < payroll[i + 1].total_payment)
        {
            max = payroll[i + 1].total_payment;
        }
    }

    return max;
}



double min_payment(Employee payroll[], int num_payrolls)
{
    double min = payroll[0].total_payment;
    int i;   //the index

    for (i = 0; i < num_payrolls - 1; ++i)
    {
        if (payroll[i].total_payment > payroll[i + 1].total_payment)
        {
            min = payroll[i + 1].total_payment;
        }
    }

    return min;
}
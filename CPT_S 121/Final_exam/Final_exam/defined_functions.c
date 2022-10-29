
/*

    This file is to establish the definitions for all programmer-defined functions, aside from main ()

*/


#include "header.h"



//All the defined functions 


char convert_string_to_char(char s[])
{
    /*
      This function converts a string with length of 1 to a char variable (necessary to read the plan of a customer from the input file)
    */
    return s[0];     
}



void compute_total_charge(Profile* customer_ptr)
{

    double pay_minutes_took = 0.0;
    double pay_data_used = 0.0;

    if (customer_ptr->plan == 'A')
    {
        /*
              Plan A Customers:
                  -  Up to 1000 minutes of talk for $35; $0.50 per minute thereafter (overage)
                  -	 Up to 10 GB of data for $25; $0.25 per MB thereafter (overage)   (1GB = 10000MB)
                  -	 Monthly charge: $60, excluding extra charges for overages
        */

        if (customer_ptr->talk_minutes <= 1000)  { pay_minutes_took = 35.0; }
        else { pay_minutes_took = 35.0 + 0.5 * (customer_ptr->talk_minutes - 1000.0); }
        
        if (customer_ptr->data_MB <= 10000) { pay_data_used = 25; }
        else { pay_data_used = 25.0 + 0.25 * (customer_ptr->data_MB - 10000.0); }    
    }


    else if (customer_ptr->plan == 'B')
    {
        /*
              Plan B Customers:
                  -  Up to 2000 minutes of talk for $55; $0.40 per minute thereafter (overage)
                  -	 Up to 20 GB of data for $30; $0.15 per MB thereafter (overage)   (1GB = 10000MB)
                  -	 Monthly charge: $85, excluding extra charges for overages
        */


        if (customer_ptr->talk_minutes <= 2000) { pay_minutes_took = 55.0; }
        else { pay_minutes_took = 55.0 + 0.4 * (customer_ptr->talk_minutes - 2000.0); }

        if (customer_ptr->data_MB <= 20000) { pay_data_used = 30.0; }
        else { pay_data_used = 30.0 + 0.15 * (customer_ptr->data_MB - 20000.0); }

    }


    customer_ptr->charges = pay_minutes_took + pay_data_used;

}


void swap_customers_profiles(Profile* cus1_ptr, Profile* cus2_ptr)
{
    Profile* temp_profile = (Profile*)malloc(sizeof(Profile));

    *temp_profile = *cus2_ptr;
    *cus2_ptr = *cus1_ptr;
    *cus1_ptr = *temp_profile;
}


void sort_profiles(Profile customers[], int num_customers)
{
    int i, j;     //The index for loop

    for (i = 0; i < num_customers - 1; ++i)
    {
        for (j = i + 1; j < num_customers; ++j)
        {
            if (strcmp(customers[i].name, customers[j].name) < 0)
            {
                swap_customers_profiles(&customers[i], &customers[j]);
            }
        }
    }
}





double max_charge(Profile customers[], int num_customers)
{
    double max = customers[0].charges;
    int i;   //the index for loop

    for (i = 0; i < num_customers; ++i)
    {
        if (max < customers[i].charges)
        {
            max = customers[i].charges;
        }
    }

    return max;
}




double min_charge(Profile customers[], int num_customers)
{
    double min = customers[0].charges;
    int i;   //the index for loop

    for (i = 0; i < num_customers; ++i)
    {
        if (min > customers[i].charges)
        {
            min = customers[i].charges;
        }
    }

    return min;

}
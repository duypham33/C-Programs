
/*

    This file is to establish the definitions for all programmer-defined functions, aside from main ()

*/


#include "header.h"



//All the defined functions for task 1

int is_prime(int n)
{  
    int flag = 0;

    if (n > 1)
    {
        if (n > 2)
        {
            int i;
            for (i = 2; i < sqrt((double)n) + 1; i++)
            {
                if (n % i == 0) { flag = 1; break; }
            }
        }
    }
    
    else { flag = 1; }
    
    
    return flag;      //if flag == 0, then n is prime
                      // if flag == 1, then n is not prime

}



int calculate_sum_digits(int n)
{
    int sum_digits = 0;

    while (n != 0)
    {
        sum_digits += (n % 10);
        n /= 10;
    }

    return sum_digits;
}





// The defined function for task 2

int calculate_factorial(int n)
{
   

    if (n == 0)
        return 1;

    else

        return (n * calculate_factorial(n - 1));

}



// The defined function for task 3

int calculate_Fibonacci(int n)
{
    if (n == 0 || n == 1)
        return n;

    else
        return (calculate_Fibonacci(n - 1) + calculate_Fibonacci(n - 2));

}
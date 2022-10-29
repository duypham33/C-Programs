
/*

    This file is to establish the definitions for all programmer-defined functions, aside from main ()

*/


#include "header.h"


double read_double(FILE* infile)
{
    double num = 0.0;
    fscanf(infile, "%lf", &num);
    return num;
}




int read_integer(FILE* infile)
{
    int num = 0;
    fscanf(infile, "%d", &num);
    return num;

}




double calculate_sum(double number1, double number2, double number3, double number4, double number5)
{
    double sum = 0.0;
    sum = number1 + number2 + number3 + number4 + number5;
    return sum;

}


double calculate_mean(double sum, int number)
{
    double mean = 0.0;
    if (number != 0) { mean = sum / number; return mean; }
    else 
          return - 1.0;

}

double calculate_deviation(double number, double mean)
{
    double deviation = 0.0;
    deviation = number - mean;
    return deviation;
}


double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number)
{
    double variance = 0.0;
    double sum = deviation1 * deviation1 + deviation2 * deviation2 + deviation3 * deviation3 + deviation4 * deviation4 + deviation5 * deviation5;
    variance = calculate_mean(sum, number);
    return variance;
}



double calculate_standard_deviation(double variance)
{
    double standard_deviation = 0.0;
    standard_deviation = sqrt(variance);
    return standard_deviation;

}


double find_max(double number1, double number2, double number3, double number4, double number5)
{
    double max = 0.0;
    max = number1;

    if (max <= number2) { max = number2; }  //to find max{num1,num2}
    if (max <= number3) { max = number3; }  //to find max{num1,num2,num3}
    if (max <= number4) { max = number4; }  //to find max{num1,num2,num3,num4}
    if (max <= number5) { max = number5; }  //to find max{num1,num2,num3,num4,num5}

    return max;
}



double find_min(double number1, double number2, double number3, double number4, double number5)
{
    double min = 0.0;
    min = number1;

    if (min >= number2) { min = number2; }  //to find min{num1,num2}
    if (min >= number3) { min = number3; }  //to find min{num1,num2,num3}
    if (min >= number4) { min = number4; }  //to find min{num1,num2,num3,num4}
    if (min >= number5) { min = number5; }  //to find min{num1,num2,num3,num4,num5}

    return min;

}



void print_double(FILE* outfile, double number)
{
    fprintf(outfile, "%.2lf\n", number);
   
}




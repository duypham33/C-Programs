

/*

  This is the header file that stores standard library includes, #defined and function prototypes

*/


#ifndef HEADER_H //guard code

#define HEADER_H


#define _CRT_SECURE_NO_WARNINGS //ignore the error about scanf()

#include<stdio.h> //necessary to use printf() and scanf()

#include<math.h> //necessary to use sqrt()

#define NUM 5



//Function prototype


/*
  Function:   double read_double ()

  Date Created: Feb 10, 2022

  Date Last Modifiled: Feb 10, 2022

  Description:  This function reads one double precision number from the input file

  Input parameters:  The infile

  Returns:  The floating-point value

  Preconditions:   The infile

  Postconditions:   The double number has been read and returned
*/
double read_double(FILE* infile);




/*
  Function:   int read_integer ()

  Date Created: Feb 10, 2022

  Date Last Modifiled: Feb 22, 2021

  Description:  This function reads one integer number from the input file.

  Input parameters:  The infile

  Returns:  The integer value

  Preconditions:    The infile

  Postconditions:  The integer number has been read and returned
*/
int read_integer(FILE* infile);



/*
  Function:   double calculate_sum ()

  Date Created: Feb 10, 2022

  Date Last Modifiled: Feb 10, 2022

  Description:  This function caculates the sum of five numbers number1, number2, number3, number4, and number5 and returns the result.

  Input parameters: The five double numbers

  Returns:  The sum of the five numbers

  Preconditions:   The five double numbers

  Postconditions:  The sum has been returned
*/
double calculate_sum(double number1, double number2, double number3, double number4, double number5);



/*
  Function:   double calculate_mean ()

  Date Created: Feb 10, 2022

  Date Last Modifiled: Feb 10, 2022

  Description:  This function determines the mean and returns the result

  Input parameters:  The sum and the number

  Returns:  The mean

  Preconditions:   The sum and the number

  Postconditions:  The mean has been returned
*/
double calculate_mean(double sum, int number);



/*
  Function:    double calculate_deviation ()

  Date Created: Feb 10, 2022

  Date Last Modifiled: Feb 10, 2022

  Description:  This function determines the deviation of number from the mean and returns the result

  Input parameters:  The number and the mean

  Returns:  The deviation 

  Preconditions:   The number and the mean

  Postconditions:   The deviation has been returned
*/
double calculate_deviation(double number, double mean);



/*
  Function:   double calculate_variance ()

  Date Created: Feb 10, 2022

  Date Last Modifiled: Feb 10, 2022

  Description:  This function determines the variance through the calculation

  Input parameters:  The five deviations and the number

  Returns:  The variance

  Preconditions:   The five deviations and the number

  Postconditions:  The variance has been returned
*/
double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number);



/*
  Function:    double calculate_standard_deviation ()

  Date Created: Feb 10, 2022

  Date Last Modifiled: Feb 10, 2022

  Description:  This function calculates the standard deviation as sqrt (variance) and returns the result

  Input parameters:  The variance

  Returns:  The standard deviation

  Preconditions:  The variance

  Postconditions:  The standard deviation has been returned
*/
double calculate_standard_deviation(double variance);



/*
  Function:  double find_max ()

  Date Created: Feb 10, 2022

  Date Last Modifiled: Feb 10, 2022

  Description:  This function determines the maximum number out of the five input parameters passed into the function, returning the max.

  Input parameters:  The five numbers

  Returns:   The max

  Preconditions:   The five numbers

  Postconditions:   The max has been returned
*/
double find_max(double number1, double number2, double number3, double number4, double number5);



/*
  Function:  double find_min ()

  Date Created: Feb 10, 2022

  Date Last Modifiled: Feb 10, 2022

  Description:  This function determines the minimum number out of the five input parameters passed into the function, returning the min.

  Input parameters:  The five numbers

  Returns:   The min

  Preconditions:   The five numbers

  Postconditions:   The min has been returned
*/
double find_min(double number1, double number2, double number3, double number4, double number5);





/*
  Function:  void print_double ()

  Date Created: Feb 10, 2022

  Date Last Modifiled: Feb 10, 2022

  Description:  This function prints a double precision number (to the hundredths place) to an output file.

  Input parameters:  The outfile and the double number

  Returns:  None

  Preconditions:   The outfile and the double number

  Postconditions:   The double number has been printed to the output file
*/
void print_double(FILE* outfile, double number);






#endif


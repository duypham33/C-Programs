
/*

  This is the header file that stores standard library includes, #defined and function prototypes

*/


#ifndef HEADER_H //guard code

#define HEADER_H


#define _CRT_SECURE_NO_WARNINGS //ignore the error about scanf()

#include<stdio.h> //necessary to use printf() and scanf()

#include<math.h>  //necessary to use abs()




//Function prototype





//All the function prototypes for task 1



/*
  Function:  

  Date Created: Feb 24, 2021

  Date Last Modifiled: Feb 24, 2021

  Description:  

  Input parameters:  

  Returns:  

  Preconditions:   

  Postconditions:   
*/
int read_payment(FILE* infile);


/*
  Function:

  Date Created: Feb 24, 2021

  Date Last Modifiled: Feb 24, 2021

  Description:  

  Input parameters:

  Returns:

  Preconditions:

  Postconditions:
*/
int calculate_sum(int salary1, int salary2, int salary3, int salary4);


/*
  Function:

  Date Created: Feb 24, 2021

  Date Last Modifiled: Feb 24, 2021

  Description:  

  Input parameters:

  Returns:

  Preconditions:

  Postconditions:
*/
char determine_tax_bracket(int total_payments);




/*
  Function:

  Date Created: Feb 24, 2021

  Date Last Modifiled: Feb 24, 2021

  Description:  

  Input parameters:

  Returns:

  Preconditions:

  Postconditions:
*/
void display_tax_bracket(char tax_bracket);







//All the function prototypes for task 3


/*
  Function:

  Date Created: Feb 24, 2021

  Date Last Modifiled: Feb 24, 2021

  Description:  

  Input parameters:

  Returns:

  Preconditions:

  Postconditions:
*/
int read_integer(FILE* infile);



/*
  Function:

  Date Created: Feb 24, 2021

  Date Last Modifiled: Feb 24, 2021

  Description:  

  Input parameters:

  Returns:

  Preconditions:

  Postconditions:
*/
int greatest_common_divisor(int num1, int num2);



/*
  Function:

  Date Created: Feb 24, 2021

  Date Last Modifiled: Feb 24, 2021

  Description:  

  Input parameters:

  Returns:

  Preconditions:

  Postconditions:
*/
void print_result(FILE* outfile, int gcd);






//All the function prototypes for task 4
/*
  Function:

  Date Created: Feb 24, 2021

  Date Last Modifiled: Feb 24, 2021

  Description:  

  Input parameters:

  Returns:

  Preconditions:

  Postconditions:
*/
double find_highest(FILE* infile);





/*
  Function:

  Date Created: Feb 24, 2021

  Date Last Modifiled: Feb 24, 2021

  Description:  

  Input parameters:

  Returns:

  Preconditions:

  Postconditions:
*/
double find_lowest(FILE* infile);




#endif

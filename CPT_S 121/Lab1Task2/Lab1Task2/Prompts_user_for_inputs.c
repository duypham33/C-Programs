/*
      * Programmer: Duy Pham
      
      * Class: CptS 121, Spring 2021; Lab Section 14
      
      * Programming Assignment: Lab1Task2
      
      * Date: January 28, 2021
      
      * Description: This program prompts the user for:
        a) two integer numbers and two floating-point numbers
        b) Ohm’s Law and determines the voltage
        c) Joule’s Law and determines the power
        d) the third order polynomial equation provided and determines the y value
        e) the circumference of circle equation provided and determines the circumference value

*/

#define _CRT_SECURE_NO_WARNINGS //ignore the error about scanf()

#include<stdio.h> //necessary to use printf() and scanf()

int main(void)
{
    // a)
          printf("a) ");
    int number1_int = 0, number2_int = 0; //reserves two memory blocks for integers
    double number1_float = 0.0, number2_float = 0.0; //reserves two memory blocks for floating-point numbers

    printf("Enter the two integer values: "); //ask the user
        scanf("%d%d", &number1_int, &number2_int);
       
        printf("Enter the two floating-point values: ");   //ask the user
        scanf("%f%f", &number1_float, &number2_float);



   // b)     
        printf("\nb) ");
        int I = 0; //the current
        int R = 0; //the resistance of the circuit
           printf("Enter the values of the current and the circuit resistance: ");
           scanf("%d%d", &I, &R);
        int V; //the voltage
           V = I * R;
           printf("The value of the voltage (V=IR): %d\n", V);
           
     
    // c)
           printf("\nc) ");
           V = 0, R = 0;  //reset the voltage and the circuit resistance
           printf("Enter the values of the voltage and the circuit resistance: ");
           scanf("%d%d", &V, &R);

           double P = 0; //the power
           P = (double)(V*V) / R;

           printf("The value of the power ( P=(V^2)/R ): %lf\n", P);

    
    // d)
           printf("\nd) ");
           int a, b, c, d; int x; 
     printf("Enter coefficients of the third order polynomial equation y = 3 * ax3 + (1/4) * bx2 + 10 * cx + (-5) * d: ");
     scanf("%d%d%d%d", &a, &b, &c, &d);

     printf("Enter the value of x: "); scanf("%d", &x);

     double y = 0.0;
     y = 3 * a * x * x * x + ((double)1 / 4) * b * x * x + 10 * c * x + (-5) * d;

     printf("The value of y: %lf\n", y);
       

     // e)
            printf("\ne) ");
            double radius = 0.0; 
            const double PI = 3.141592;
            printf("Enter the value of the radius: "); scanf("%lf", &radius);

            double circumference;
            circumference = 2 * PI * radius;
            printf("The value of the circumference of the circle (circumference = 2*PI*radius): %lf\n ", circumference);



         return 0; //the program was successful

}

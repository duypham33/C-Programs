

/*

    This file is to establish the definitions for 7 programmer-defined functions, aside from main ()

*/


#include "equations.h"


// 1)Function for calculating Newton’s Second Law of Motion
double calculate_newtons_2nd_law(double mass, double acceleration) //function header
{
	//function definition
	double force = 0.0;
	force = mass * acceleration; //compute the force by the formula
	return force; 
}



// 2)Function for calculating the volume_cylinder by the formula
double calculate_volume_cylinder(double radius, double height) //function header
{
	//function definition
	double volume_cylinder = 0.0;
	volume_cylinder = PI * (radius * radius) * height;  //compute the volume_cylinder by the formula
	return volume_cylinder; 
}



// 3)Function for performing character encoding 
char perform_character_encoding(char plaintext_character, int shift) //function header
{
	//function definiton
	char encoded_character = '\0';
	encoded_character = (plaintext_character - 'A') + 'a' - shift;  //get the encoded character by the formula
	return encoded_character;

}



// 4)Function for calculating the distance between two points
double calculate_distance_between_two_points(double x1, double y1, double x2, double y2)  //function header
{
	//function definition
	double distance = 0.0;
	distance = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));  //compute the distance between those two points by the formula
	return distance;
}



// 5)Function for calculating the tangent
double calculate_tan_theta(double theta) //function header
{
	//function definiton
	double tan_theta = 0.0;
	tan_theta = sin(theta) / cos(theta);   //compute tan(theta) by the formula
	return tan_theta;
}



// 6)Function for calculating total parallel resistance
double calculate_total_resistance (int R1, int R2,int R3) //function header
{
	//funciton definition
	double total_resistance = 0.0;
	total_resistance = (double)1 / ((double)1 / R1 + (double)1 / R2 + (double)1 / R3);   //compute the total resistance by the formula
	return total_resistance;

}


// 7)Function for calculating the general equation
double calculate_general_equation(double b, double z, double x, int a)  //function header
{
	//function definition
	double y = 0.0;
	y = ((double)2 / 3) - b + z * x / (a % 2) + PI;   //compute the value of y by the general equation
	return y;
}

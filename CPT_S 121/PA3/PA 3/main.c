
/*
      * Programmer: Duy Pham

      * Class: CptS 121, Spring 2022; 

      * Programming Assignment: PA 3 Statistical Analysis of Student Records

      * Date: February 10, 2021

      * Description: This program processes numbers, corresponding to student records read in from a file, does some computations and writes the results to an output file.
        
*/


#include "header.h"


int main(void)
{    
    FILE* infile = NULL, * outfile = NULL;


    infile = fopen("input.dat", "r");   //input file opened with read permisions “r”
    outfile = fopen("output.dat", "w"); //output file opened with write permisions “w”


    int id1 = 0, id2 = 0, id3 = 0, id4 = 0, id5 = 0;      // Student IDs (8 digit integer numbers) of the five students respectively
    double gpa1 = 0.0, gpa2 = 0.0, gpa3 = 0.0, gpa4 = 0.0, gpa5 = 0.0;   //GPAs (floating-point values to the hundredths place) of the five students respectively
    int cls_std1 = 0, cls_std2 = 0, cls_std3 = 0, cls_std4 = 0, cls_std5 = 0;  //Class Standings (1 - 4, where 1 is a freshmen, 2 is a sophomore, 3 is a junior, and 4 is a senior)
    double age1 = 0.0, age2 = 0.0, age3 = 0.0, age4 = 0.0, age5 = 0;  // Ages (floating-point values) of the five students respectively


    //Read the student records from the input file and display them to the screen
    printf("\t\t\tSTUDENT RECORD\n");
    printf("\tRecord 1)\n");
    id1 = read_integer(infile);          printf("\tStudent ID#: %d\n", id1);
    gpa1 = read_double(infile);          printf("\tGPA: %.2lf\n", gpa1);
    cls_std1 = read_integer(infile);     printf("\tClass Standing: %d\n", cls_std1);
    age1 = read_double(infile);          printf("\tAge: %.2lf\n\n", age1);


    printf("\tRecord 2)\n");
    id2 = read_integer(infile);          printf("\tStudent ID#: %d\n", id2);
    gpa2 = read_double(infile);          printf("\tGPA: %.2lf\n", gpa2);
    cls_std2 = read_integer(infile);     printf("\tClass Standing: %d\n", cls_std2);
    age2 = read_double(infile);          printf("\tAge: %.2lf\n\n", age2);

    printf("\tRecord 3)\n");
    id3 = read_integer(infile);          printf("\tStudent ID#: %d\n", id3);
    gpa3 = read_double(infile);          printf("\tGPA: %.2lf\n", gpa3);
    cls_std3 = read_integer(infile);     printf("\tClass Standing: %d\n", cls_std3);
    age3 = read_double(infile);          printf("\tAge: %.2lf\n\n", age3);

    printf("\tRecord 4)\n");
    id4 = read_integer(infile);          printf("\tStudent ID#: %d\n", id4);
    gpa4 = read_double(infile);          printf("\tGPA: %.2lf\n", gpa4);
    cls_std4 = read_integer(infile);     printf("\tClass Standing: %d\n", cls_std4);
    age4 = read_double(infile);          printf("\tAge: %.2lf\n\n", age4);

    printf("\tRecord 5)\n");
    id5 = read_integer(infile);          printf("\tStudent ID#: %d\n", id5);
    gpa5 = read_double(infile);          printf("\tGPA: %.2lf\n", gpa5);
    cls_std5 = read_integer(infile);     printf("\tClass Standing: %d\n", cls_std5);
    age5 = read_double(infile);          printf("\tAge: %.2lf\n\n", age5);



    //Caculate sums of the GPAs, class standings and ages
    double sum_gpas = 0.0, sum_cls_stds = 0.0, sum_ages = 0.0;
   
    sum_gpas = calculate_sum(gpa1, gpa2, gpa3, gpa4, gpa5);
    sum_cls_stds = calculate_sum((double)cls_std1, (double)cls_std2, (double)cls_std3, (double)cls_std4, (double)cls_std5);
    sum_ages = calculate_sum(age1, age2, age3, age4, age5);

    printf("The sum of the GPAs: %.2lf\n", sum_gpas);
    printf("The sum of the class standings: %.2lf\n", sum_cls_stds);
    printf("The sum of the ages: %.2lf\n\n", sum_ages);


    //Calculates the mean of the GPAs, class standings and ages
    double mean_gpas = 0.0, mean_cls_stds = 0.0, mean_ages = 0.0;

    mean_gpas = calculate_mean(sum_gpas, NUM);
    mean_cls_stds = calculate_mean(sum_cls_stds, NUM);
    mean_ages = calculate_mean(sum_ages, NUM);

    printf("The mean of the GPAs: %.2lf\n", mean_gpas);
    printf("The mean of the class standings: %.2lf\n", mean_cls_stds);
    printf("The mean of the ages: %.2lf\n\n", mean_ages);

    //Write the three results to the output file
    print_double(outfile, mean_gpas);
    print_double(outfile, mean_cls_stds);
    print_double(outfile, mean_ages);



    //Calculates the deviation of each GPA from the mean
    double deviation1 = 0.0, deviation2 = 0.0, deviation3 = 0.0, deviation4 = 0.0, deviation5 = 0.0;
    deviation1 = calculate_deviation(gpa1, mean_gpas);
    deviation2 = calculate_deviation(gpa2, mean_gpas);
    deviation3 = calculate_deviation(gpa3, mean_gpas);
    deviation4 = calculate_deviation(gpa4, mean_gpas);
    deviation5 = calculate_deviation(gpa5, mean_gpas);

    printf("The deviation of GPA1: %.2lf\n", deviation1);
    printf("The deviation of GPA2: %.2lf\n", deviation2);
    printf("The deviation of GPA3: %.2lf\n", deviation3);
    printf("The deviation of GPA4: %.2lf\n", deviation4);
    printf("The deviation of GPA5: %.2lf\n\n", deviation5);


    //Calculates the variance of the GPAs
    double variance_gpas = 0.0;
    variance_gpas = calculate_variance(deviation1, deviation2, deviation3, deviation4, deviation5, NUM);
    printf("The variance of the GPAs: %.2lf\n\n", variance_gpas);

    //Calculates the standard deviation of the GPAs
    double standard_deviation_gpas = 0.0;
    standard_deviation_gpas = calculate_standard_deviation(variance_gpas);
    printf("The standard deviation of the GPAs: %.2lf\n\n", standard_deviation_gpas);
    
    //Write the result to the output file
    fprintf(outfile, "\n"); 
    print_double(outfile, standard_deviation_gpas);


    //Determines the min of the GPAs
    double min_gpas = 0.0;  min_gpas = find_min(gpa1, gpa2, gpa3, gpa4, gpa5);
    printf("The min of the GPAs: %.2lf\n", min_gpas);

    //Determines the max of the GPAs
    double max_gpas = 0.0;  max_gpas = find_max(gpa1, gpa2, gpa3, gpa4, gpa5);
    printf("The max of the GPAs: %.2lf\n", max_gpas);

    //Write the min and max of the GPAs to the output file
    print_double(outfile, min_gpas);
    print_double(outfile, max_gpas);


    //Close the input and output files
    fclose(infile);   
    fclose(outfile);


    return 0; //the program was successful

}
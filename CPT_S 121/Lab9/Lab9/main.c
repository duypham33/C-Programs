
/*
      * Programmer: Duy Pham

      * Class: CptS 121, Spring 2021; Section 01; Lab Section 14

      * Programming Assignment:     Lab 9: Strings

      * Date: March 25, 2021

      * Description: This program performs two different tasks:
                  - Task 1: a program that reverses strings. The function should return a pointer to the reversed string. 
                            Implement a solution to this function using array notation only. Then, rewrite the function using pointer notation and pointer arithmetic only.

                  - Task 2: a program that tests the following functions
                             char* my_strcpy(char* destinaiton, const char* source)
                             char* my_strcat(char* destination, const char* source)
                             int my_strcmp(const char* s1, const char* s2)
                             int my_strlen(const char* s)
*/



#include "header.h"


int main(void)
{

    //Task 1
    printf("1) ");   //start task 1


    //We apply the functions defined to reverse the following sentences

    char sentence[50] = "Do you use Microsoft products or services?";
    printf("Our example sentence 1: %s\n", sentence);

    //Use the the string_reverse() function using array notation
    char* reversed_sentence;
    reversed_sentence = string_reverse(sentence);

    printf("The sentence 1 after reversing by array notation: ");
    puts(reversed_sentence);



    //Give the sentence 2
    char sentence2[50] = "How do you take to keep your skills current?";
    printf("\nOur example sentence 2: %s\n", sentence2);

    //Use the the string_reverse() function using pointer notaiton
    char* ptr_rev_sentence;
    ptr_rev_sentence = string_reverse_ptr(sentence2);

    printf("The sentence 2 after reversing by pointer notation: ");
    puts(ptr_rev_sentence);




    //Task 2
    printf("\n2) ");    //start task 2

    //We apply the functions defined to test them

    //Copy string
    char obj1[20];
    char obj2[20] = "spoon";

    printf("Obj: ");
    puts(obj2);

    
    my_strcpy(obj1, obj2);
    printf("Obj (copied): ");
    puts(obj1);


    //Append strings
    printf("\n");
    char dept[30] = "Cpts ";
    char cour_num[30] = "121 Spring!";

    my_strcat(dept, cour_num);
        printf("The course: ");
        puts(dept);



        //Compare strings
        printf("\n");
        char s1[30] = "canxi";
        char s2[30] = "canx";

        printf("String 1: "); puts(s1);
        printf("String 2: "); puts(s2);
        printf("Strcmp: %d\n", my_strcmp(s1, s2));




        //String length
        char id[30] = "17AI3Kl90";
        printf("\nThe ID: "); puts(id);
        printf("The number of characters in the ID: %d\n", my_strlen(id));

    return 0;  //The program was successful

}
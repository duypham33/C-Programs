
/*

    This file is to establish the definitions for all programmer-defined functions, aside from main ()

*/


#include "header.h"



//All the defined functions for task 1

char* string_reverse(char str[])
{
    int i;   //index
    int count = 0;     //count the number of characters (except the NULL character at the end) in the string

    for (i = 0; str[i] != '\0'; i++)
    {
        ++count;
    }


    //Reverse the string
    char temp;
    for (i = 0; i < count / 2; i++)       //just need to do the process of swap for a half of string length
    {
          //We swap the ith character and the [count - 1 -i]th character
        temp = str[i];
        str[i] = str[count - 1 - i];
        str[count - 1 - i] = temp;
    }

    return str;
}




char* string_reverse_ptr(char* str)
{
    int i;   //index
    int count = 0;     //count the number of characters (except the NULL character at the end) in the string

    for (i = 0; *(str + i) != '\0'; i++)
    {
        count++;
    }

    //Reverse the string
    char temp;

    for (i = 0; i < count / 2; i++)       //just need to do the process of swap for a half of string length
    {
        //We swap the ith character and the [count - 1 -i]th character
        temp = *(str + i);

        *(str + i) = *(str + count - 1 - i);
        *(str + count - 1 - i) = temp;
    }

    return str; 
}





//All the defined functions for task 2

char* my_strcpy(char* destinaiton, const char* source)
{
    int i;

    for (i = 0; *(source + i) != '\0'; i++)
    {
        *(destinaiton + i) = *(source + i);
    }

    *(destinaiton + i) = '\0';

    return destinaiton;
}





char* my_strcat(char* destination, const char* source)
{
    int i;

    //First, we find the position of the NULL character at the end of the string pointed to by destination
    for (i = 0; *(destination + i) != '\0'; i++)
    {

    }
    int last_post = i;   // i is currently the position of the NULL character at the end of the string pointed to by destination


    //We start append a copy of the string pointed to by source to this position
    for (i = 0; *(source + i) != '\0'; i++)
    {
        *(destination + last_post + i) = *(source + i);
    }


    *(destination + last_post + i) = '\0';

    return destination;

}




int my_strcmp(const char* s1, const char* s2)
{
    int flag = 2;    //initialize flag != 0, 1, and -1

    int i1, i2;      //to convert char *s1 and char *s2 into integer for comparision

    int i = 0;    //index

    do
    {
        i1 = *(s1 + i);
        i2 = *(s2 + i);

        if (i1 < i2)
        {
            flag = -1;  break;   //break the loop
        }

        else if (i1 > i2)
        {
            flag = 1;   break;   //break the loop
        }

        else if (i1 == i2)
        {
            flag = 0;
        }

        ++i;     //increment the index


    } while (*(s1 + i) != '\0' || *(s2 + i) != '\0'); //The loop only stops without break, right after the index goes through NULL characters of the two strings at the same time  



    return flag;

}





int my_strlen(const char* s)
{
    int length = 0;

    int i;    //index

    for (i = 0; *(s + i) != '\0'; i++)
    {
        ++length;
    }

    return length;

}
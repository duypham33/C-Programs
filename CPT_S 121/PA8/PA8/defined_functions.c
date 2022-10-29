
/*

    This file is to establish the definitions for all programmer-defined functions, aside from main ()

*/


#include "header.h"



 //The defined function for task 1

char* my_str_n_cat(char* destination, const char* source, unsigned int n)
{

    int i;

    //First, we find the position of the NULL character at the end of the string pointed to by destination
    for (i = 0; *(destination + i) != '\0'; i++)
    {

    }

    int last_post = i;   // i is currently the position of the NULL character at the end of the string pointed to by destination


    //We start append a copy of the string pointed to by source to this position
    
    i = 0;   //reset i
    while (*(source + i) != '\0' && i < n)
    {
        *(destination + last_post + i) = *(source + i);

        ++i;
    }

    *(destination + last_post + i) = '\0';



    return destination;

}





 //The defined function for task 2
int binary_search(int values[], int target, int num_values)
{
    
    int found = 0, /* false */
    left = 0,
    right = num_values,
        mid = 0,
    targetindex = -1;

    while (!found && left <= right)
    {
        mid = (left + right) / 2;
        if (target == values[mid])
        {
            found = 1; /* true */
            targetindex = mid;
        }

        else if (target < values[mid])
            right = mid - 1;
        else /* target > values[mid] */
            left = mid + 1;
    }
          

    if (found)
    {        
        return targetindex;
    }
        
    else
        return -1;     // -1 means not found
}





//The defined function for task 3

//Function that sorts an array of strings based on their ASCII values
void bubble_sort(char* str[], int size)
{
    for (int i = 0; i < (size - 1); i++)
    {
        for (int j = 0; j < (size - i - 1); j++)
        {
            if (strcmp(str[j], str[j + 1]) > 0)
            {
                char* temp = str[j + 1];
                str[j + 1] = str[j];
                str[j] = temp;
            }

        }

    }

}



 //The defined function for task 4

int is_palindrome(char* str, int length)
{
    if (length <= 1)      //Base case
    {
        return 1;
    }

    else if (length == 2 && *str != ' ' && *(str+1) != ' ')   //Base case
    {
        if (*str == *(str + 1))
            return 1;

        else 
            return 0;
    }


    else       //length > 2
    {

        int start = 0, end = length - 1;
        int count = 0;
        int i = 0;     //The index for loops

        for (i = 0; i < length; i++)
        {
            if (*(str + start +i) != ' ') { break; }        
        }

        start += i;
        count += i;


        for (i = 0; end - i >= start; i++)
        {
            if (*(str + end - i) != ' ') { break; }
        }

        end -= i;
        count += i;
        
        if (length - count == 1)
        {
            return 1;
        }

        else if (*(str + start) != *(str + end))
        {
            return 0;
        }

        else      //*(str + start) == *(str + end)
        {
            ++start;
            --end;
            count += 2;

            return (is_palindrome(str + start, length - count));      //Recursion
        }

    }


}






//The defined functions for task 5

int is_prime(unsigned int n)
{
    int flag = 1;   //0 is false, 1 is true

    if (n < 2)
    {
        flag = 0;
    }

    else if (n == 2)
    {
        flag = 1;
    }

    else
    {
        int i;
        for (i = 2; i <= n / 2 + 1; i++)
        {
            if (n % i == 0)
            {
                flag = 0;
                break;
            }
        }
    }

    return flag;

}


int sum_primes(unsigned int n)
{
    int sum = 0;

    if (n < 2)   //Base case
    {
        sum = 0;
    }

    else   //n >= 2
    {
        if (is_prime(n) == 1)     // n is a prime number
        {
            sum = n + sum_primes(n - 1);    //Recursion
        }

        else   // n is not a prime number
        {
            sum = sum_primes(n - 1);    //Recursion
        }
    }

    return sum;
}




//The defined functions for task 6

void init_occ_array(Occurrences occ[], int size)
{
    for (int i = 0; i < size; i++)
    {
        occ[i].num_occurrences = 0;
        occ[i].frequency = 0.0;
    }
}




void maximum_occurrences(char* string, Occurrences occ[], int* max_occ, char* char_occ_max)
{

    int num_chars = strlen(string);

    int i,    //The index for loops
        k = 0;
    

    for (i = 0; i < num_chars; i++)
    {
        k = (int)*(string + i);

        ++occ[k].num_occurrences;
    }

    k = (int)*string;
    *max_occ = occ[k].num_occurrences;
    *char_occ_max = *string;
    
    
    for (i = 0; i < num_chars; i++)
    {
        k = (int)*(string + i);

        if (occ[k].frequency == 0.0)
        {
            occ[k].frequency = (double)occ[k].num_occurrences / num_chars;
        }

        if (*max_occ < occ[k].num_occurrences)
        {
            *max_occ = occ[k].num_occurrences;
            *char_occ_max = *(string + i);
        }
    }
    
    
    printf("The maximum number of occurrences of characters in the string is %d with the corresponding characters ", *max_occ);

    int flag[123] = { 0 };

    for (i = 0; i < num_chars; i++)
    {
        k = (int)*(string + i);

        if (occ[k].num_occurrences == *max_occ && flag[k] == 0)
        {
            printf("%c ", *(string + i));

            flag[k] = 1;
        }
    }

    printf("\n");
    
    
}




 //The defined functions for task 7

/*
   We will work with the two-dimensional array similarly to the 1D array by using the index i = 0 - (num_rows * num_cols), 

              arr[i / num_cols][i % num_cols]
 */



int is_consective(int arr[][NUM_COLS], int num_rows, int num_cols, int index)
{
    int flag = 0;   //0 is false, 1 is true 

    if (arr[index / num_cols][index % num_cols] == arr[(index + 1) / num_cols][(index + 1) % num_cols])
    {
        flag = 1;
    }

    return flag;
}




int num_consective_integers(int arr[][NUM_COLS], int num_rows, int num_cols, int index)
{
    int count = 2;   //Already counted the two first numbers in the sequence
    int i;     //The index for loop

    for (i = index + 2; i < num_rows * num_cols; i++)
    {
        if (arr[i / num_cols][i % num_cols] == arr[index / num_cols][index % num_cols])
        {
            count++;
        }

        else { break; }
    }

    return count;
}




int target_index_max_consective_integers(int arr[][NUM_COLS], int num_rows, int num_cols, int* max_ptr)
{
    int i, j, num_consec = 0;
    int b[100] = { 0 };
    int size = num_rows * num_cols;

    for (i = 0; i < size - 1; i++)
    {
        if (is_consective(arr, num_rows, num_cols, i) == 1)
        {
            b[num_consec] = i;
            num_consec++;

            for (j = i + 2; j < size; j++)
            {
                if (arr[j / num_cols][j % num_cols] != arr[i / num_cols][i % num_cols])
                {
                    i = j - 1;
                    break;
                }
            }
        }
    }


    int c[50] = { 0 };

    for (i = 0; i < num_consec; ++i)
    {
        c[i] = num_consective_integers(arr, num_rows, num_cols, b[i]);
    }


    *max_ptr = c[0];
    int target_index = b[0];


    for (i = 1; i < num_consec; ++i)
    {
        if (*max_ptr < c[i])
        {
            *max_ptr = c[i];
            target_index = b[i];
        }
    }

    return target_index;
}




void max_consecutive_integers(int arr[][NUM_COLS], int num_rows, int num_cols, int** address_max_consec_ptr, int* num_consec_values_ptr)
{

    int target_index = target_index_max_consective_integers(arr, num_rows, num_cols, num_consec_values_ptr);

    int target_row_index = target_index / num_cols;
    int target_col_index = target_index % num_cols;


    *address_max_consec_ptr = &arr[target_row_index][target_col_index];

    printf("\nThe address of the maximum consecutive sequence of the same integer is: row %d, column %d (%d)\n", target_row_index, target_col_index, *address_max_consec_ptr);

    printf("That number is %d with the length is %d\n", arr[target_row_index][target_col_index], *num_consec_values_ptr);
}
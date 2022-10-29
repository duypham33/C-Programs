// In this example, we'll work with C strings

// History: 3/26 - We separated each of the data lines in the file
//                 into substrings. We then placed the attributes
//                 into an array of structs.
//          3/24 - We implemented a version of strcpy (),
//                 called my_strcpy_ptr (), that uses pointer
//                 notation only. Started reading our data.csv
//                 file and separating into substrings with strtok ().
//          3/22 - We applied strcat (), strncat (), strcmp (), putchar ().
//                 We also wrote our own version of strcpy () called my_strcpy ()
//          3/19 - Introduced <string.h>. We applied strlen (), strcpy (),
//                 and strncpy (). We used puts () and fputs (), but these
//                 are found in <stdio.h>.

#include "StringApp.h"

int main(void)
{
	FILE* infile = fopen("data.csv", "r");
	char line[100] = "", *token_ptr = NULL;
	char lines[20][100] = { "", "", "" };
	int line_count = 0;
	Student s1 = {"", "", -1};
	strcpy(s1.last, "smith");
	puts(s1.last);
	s1.id = 88888888;
	printf("id: %d\n", s1.id);
	Student students[20] = { {"", "", -1}, {"", "", -1} };

	if (infile != NULL)
	{
		// we opened successfully
		// fgets () grabs and entire line, even one with whitspace characters
		fgets(lines[line_count], 100, infile); // this is the header line; treat it separately
		puts(lines[line_count]);
		++line_count;

		while (fgets(lines[line_count], 100, infile) != NULL)
		{
			puts(lines[line_count]); // show the line that we just read from file; it's a data line
			// the below strtok () will give us the last name
			token_ptr = strtok(lines[line_count], ","); // using strtok () to separate the line into indvidual parts
			//puts(lines[line_count]);
			strcpy(students[line_count - 1].last, token_ptr);
			//printf("last: %s\n", token_ptr);
			printf("students[%d].last = %s\n", line_count - 1,
				students[line_count - 1].last);

			token_ptr = strtok(NULL, ","); // first name
			strcpy(students[line_count - 1].first, token_ptr);
			printf("students[%d].first = %s\n", line_count - 1,
				students[line_count - 1].first);
			//printf("first: %s\n", token_ptr);

			token_ptr = strtok(NULL, "\n");
			students[line_count - 1].id = atoi(token_ptr);
			printf("students[%d].id = %d\n", line_count - 1,
				students[line_count - 1].id);
			//printf("id: %s\n", token_ptr);
			
			++line_count;
		}
	}

	//char name[100] = {'b', 'o', 'b', '\0'};
	//char name2[] = "jane", name3[100] = ""; // "" empty string, name3[0] = '\0'
	//const char* name4 = "john"; // the space in which the string is in immutable memory

	////name4[2] = 'n'; // immutable

	////printf("name: %s\n", name);

	//printf("strlen: %d\n", strlen(name2));

	////name3 = name2;
	//strcpy(name3, name2);
	//printf("strcpy: %s\n", name3);

	//strncpy(name3, name2, 99);
	//name[99] = '\0';

	//puts(name3);
	//fputs(name3, stdout);
	//putchar('\n');
	//// concatenation append
	//strcat(name3, "austin");
	//puts(name3);

	//// name3 - janeaustin
	//strncat(name3, "III", 5);
	//puts(name3);

	//// strcmp ()
	//printf("strcmp (): %d\n", strcmp("cat", "cat")); // returns 0
	//printf("strcmp (): %d\n", strcmp("cat", "dog")); // returns -1
	//printf("strcmp (): %d\n", strcmp("dog", "cat")); // returns 1
	//printf("strcmp (): %d\n", strcmp("cars", "cat")); // returns -1
	//printf("strcmp (): %d\n", strcmp("cars", "Cat")); // returns 1

	////strcpy()
	//char* result_ptr = NULL;

	///*result_ptr = my_strcpy(name, "cat");
	//puts(name);
	//puts(result_ptr);*/

	//result_ptr = my_strcpy_ptr(name, "cat");
	//puts(name);
	//puts(result_ptr);

	return 0;
}
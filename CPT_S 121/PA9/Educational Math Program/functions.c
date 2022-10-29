
/*

	This file is to establish the definitions for all programmer-defined functions, aside from main ()

*/


#include "header.h"


//All the function definitions


void print_menu()
{
	printf("\tEducational Math Program\n");
	printf("  1. Learn about how to use the program\n");
	printf("  2. Enter initials\n");
	printf("  3. Load previous progress\n");
	printf("  4. Difficulty selection\n");
	printf("  5. Start a new sequence of problems\n");
	printf("  6. Save and Quit\n");
	
	printf("**********************************************\n\n");

}


int get_user_option()
{
	int opt = 0;

	while (opt < 1 || opt > 6)
	{
		// Prompt the user for menu option
		printf(" Please, enter your menu option (1-6): ");
		scanf("%d", &opt);

		if (opt > 0 && opt < 6)   //Got valid option 
			break;

		printf(" Your option is invalid! Please, try again!\n\n");
	}

	return opt;
}


void display_tutorial()
{
	printf("                                    TUTORIAL \n");
	printf(" There are five different levels of Mathematics problems for you to practice.\n");
	printf(" You can earn points for correct answers and loses points for incorrect answers\n");
	printf(" The number of points depends on the difficulty of the problem.\n");
	printf(" You would enter your initials to save your record of your total point.\n");
	printf(" And you can load your latest record from prior progress through your initials.\n");
	printf("   ***********************  PRACTICE MAKES PERFECT  ***********************\n\n");
}


char* get_initials(char* initials)
{
	getchar();
	printf(" Please, enter your initials (first middle last): ");
	gets(initials);
	
	return initials;
}



int select_difficulty()
{
	printf(" 1. Level Easy\n");
	printf(" 2. Level Fair\n");
	printf(" 3. Level Intermediate\n");
	printf(" 4. Level Hard\n");
	printf(" 5. Level Impossible\n");
	printf("*****************************\n\n");

	int level = 0;
	while (level < 1 || level > 5)
	{
		printf(" Please, enter a Level you would like to practice (1-5): ");
		scanf("%d", &level);

		if (level > 0 && level < 6)
			break;

		printf(" Your chosen level is invalid! Please, try again!\n\n");
	}

	system("cls");  //Clear the screen
	printf("\n");
	switch (level)
	{
	case 1: 
		printf(" This level includes addition and subtraction problems, with positive single digit operands and up to three terms only.\n");
		printf(" One point for each question at this level.\n");
		break;
	case 2:
		printf(" This level includes multiplication problems, with positive single digit operands and up to two terms only.\n");
		printf(" Two points for each question at this level.\n");
		break;
	case 3:
		printf(" This level includes division problems, with positive single digit operands and up to two terms only.\n");
		printf(" Three points for each question at this level.\n");
		break;
	case 4:
		printf(" This level includes a mix of addition, subtraction, multiplication, and division problems, with positive and negative single digit operands and up to three terms only.\n");
		printf(" Four points for each question at this level.\n");
		break;
	case 5:
		printf(" This level includes a mix of addition, subtraction, multiplication, and division problems, with positive and negative two and three digit operands and up to four terms only.\n");
		printf(" Five points for each question at this level.\n");
		break;
	
	}

	printf("\n Please, hit the ENTER button to start!");
	getch();
	printf("\n\n******************************************\n\n");

	return level;
}


void print_operator(int operator_type)
{
	switch (operator_type)
	{
	case 0:   // Addition
		printf("+  ");
		break;

	case 1:   // Subtraction
		printf("-  ");
		break;

	case 2:   // Multiplication
		printf("x  ");
		break;

	case 3:   // Division
		printf("/  ");
		break;
	}
}


int perform_operation(int op1, int op2, int operator_type)
{
	int answer = 0;
	if (operator_type == 0)        // Addition
		answer = op1 + op2;
	else if (operator_type == 1)   // Subtraction
		answer = op1 - op2;
	else if (operator_type == 2)   // Multiplication
		answer = op1 * op2;
	else                           // Division
		answer = op1 / op2;

	return answer;
}


int generate_number(int lower_bound, int upper_bound)
{
	return (rand() % (upper_bound - lower_bound + 1)) + lower_bound;
}



int easy(int hard_level)
{
	int lower_bound = 0, upper_bound = 9;
	int num_operands = (rand() % 2 + 2);    //Generate number of operands (2 or 3)

	//Within each level, problems should become a little more difficult as the user enters correct answers
	if (hard_level == 2)
		lower_bound = 2;
	else if (hard_level == 3)
	{
		lower_bound = 4;
		num_operands = 3;
	}
		

	int op = generate_number(lower_bound, upper_bound);    //Generate positive single digit
	int operator_type = (rand() % 2);   // 0 is addition, 1 is subtraction
	int answer = op;       //The answer of operations

	printf("%d  ", op);

	for (int i = num_operands; i > 1; i--)
	{
		print_operator(operator_type);
		op = generate_number(lower_bound, upper_bound);    //Generate positive single digit
		printf("%d  ", op);

		answer = perform_operation(answer, op, operator_type);
	}

	printf("=  ?\n");

	return answer;
}




int fair(int hard_level)
{
	int lower_bound = 0, upper_bound = 9;

	//Within each level, problems should become a little more difficult as the user enters correct answers
	if (hard_level == 2)
		lower_bound = 2;
	else if (hard_level == 3)
		lower_bound = 5;

	int op1 = generate_number(lower_bound, upper_bound);    //Generate positive single digit
	int op2 = generate_number(lower_bound, upper_bound);    //Generate positive single digit

	printf("%d  x  %d  =  ?\n", op1, op2);
	
	return (op1 * op2);   //The answer of multiplication
}




void intermediate(int* quotient, int* remainder, int hard_level)
{
	int lower_bound = 0, upper_bound = 9;

	//Within each level, problems should become a little more difficult as the user enters correct answers
	if (hard_level == 2)
		lower_bound = 2;
	else if (hard_level == 3)
		lower_bound = 4;

	int op1 = generate_number(lower_bound, upper_bound);    //Generate positive single digit
	int op2 = generate_number(lower_bound + 1, upper_bound);    //Generate positive single digit (from 1 - 9)

	printf("%d  /  %d  =  ?  R  ?\n", op1, op2);

	*quotient = op1 / op2;
	*remainder = op1 % op2;
}


int generate_denominator(int num, int lower_bound, int upper_bound)
{
	num = abs(num);
	int num_denominator = 0;
	int generate_denominator = 0;

	if (num == 0)
		generate_denominator = generate_number(lower_bound, upper_bound);

	else
	{
		for (int i = lower_bound; i <= num / 2 + 1; i++)
		{
			if (i <= upper_bound)
			{
				if (num % i == 0)
					num_denominator++;
			}

			else
				break;
		}

		if (num <= upper_bound)
			num_denominator++;    //Includes the number itself

		int denomnt_pos = generate_number(1, num_denominator);

		if (denomnt_pos == num_denominator)
			generate_denominator = num;

		else
		{
			for (int i = lower_bound; i <= num / 2 + 1; i++)
			{
				if (num % i == 0)
				{
					denomnt_pos--;

					if (denomnt_pos == 0)
						generate_denominator = i;
				}
			}
		}

	}

	
	// Generate the sign of the denominator (0 is for positive, 1 is for negative)
	int sign = rand() % 2;
	if (sign == 0)
		return generate_denominator;
	else
		return -generate_denominator;
}




int generate_number2(int lower_bound, int upper_bound)
{
	int num = generate_number(3, upper_bound);
	return ((rand() % 2 == 0) ? num : -num);
}




int hard(int hard_level)
{
	int lower_bound = -9, upper_bound = 9;

	//Generate negative-positive single digit
	int op1 = (hard_level == 1) ? generate_number(lower_bound, upper_bound) : generate_number2(lower_bound, upper_bound);
	int operator_type = (rand() % 4);   // 0 is addition, 1 is subtraction, 2 is multiplication, 3 is division
	
	//Generate negative-positive single digit
	int op2 = (hard_level == 1) ? generate_number(lower_bound, upper_bound) : generate_number2(lower_bound, upper_bound);      
	printf("%d  ", op1);
	print_operator(operator_type);

	if (operator_type == 3)  //Division
		op2 = (hard_level == 1) ? generate_denominator(op1, 1, 9) : generate_denominator(op1, 2, 9);
	
	printf("%d  ", op2);
	int num_operands = (rand() % 2 + 2);    //Generate number of operands (2 or 3)
	if (hard_level > 1)
		num_operands = 3;
	
	int answer = 0;

	if (num_operands == 2)
		answer = perform_operation(op1, op2, operator_type);

	else   // num_operands = 3
	{
		int operator_type2 = (rand() % 4);  // 0 is addition, 1 is subtraction, 2 is multiplication, 3 is division
		print_operator(operator_type2);

		//Generate negative-positive single digit
		int op3 = (hard_level == 1) ? generate_number(lower_bound, upper_bound) : generate_number2(lower_bound, upper_bound);

		if (operator_type < 2)
		{
			if (operator_type2 == 3)
				op3 = (hard_level == 1) ? generate_denominator(op2, 1, 9) : generate_denominator(op2, 2, 9);
			
			printf("%d  ", op3);

			if (operator_type2 > 1)
			{
				answer = perform_operation(op2, op3, operator_type2);
				answer = perform_operation(op1, answer, operator_type);
			}
			
			else
			{
				answer = perform_operation(op1, op2, operator_type);
				answer = perform_operation(answer, op3, operator_type2);
			}
		}

		else
		{
			answer = perform_operation(op1, op2, operator_type);

			if (operator_type2 == 3)
				op3 = (hard_level == 1) ? generate_denominator(answer, 1, 9) : generate_denominator(answer, 2, 9);

			printf("%d  ", op3);
			answer = perform_operation(answer, op3, operator_type2);
		}
	}


	printf("=  ?\n");

	return answer;
}




int impossible()
{
	int lower_bound = 10, upper_bound = 999;
	int op1 = generate_number(lower_bound, upper_bound);  //Generate negative-positive two and three digit operand

	int operator_type1 = (rand() % 4);   // 0 is addition, 1 is subtraction, 2 is multiplication, 3 is division

	int op2 = generate_number(lower_bound, upper_bound);  //Generate negative-positive two and three digit operand
	printf("%d  ", op1);
	print_operator(operator_type1);

	if (operator_type1 == 3)  //Division
		op2 = generate_denominator(op1, 10, 999);

	printf("%d  ", op2);

	int answer = 0;

	
	int operator_type2 = (rand() % 4);  // 0 is addition, 1 is subtraction, 2 is multiplication, 3 is division
	int operator_type3 = (rand() % 4);  // 0 is addition, 1 is subtraction, 2 is multiplication, 3 is division
	print_operator(operator_type2);

	int op3 = generate_number(lower_bound, upper_bound);  //Generate negative-positive two and three digit operand
	int op4 = generate_number(lower_bound, upper_bound);  //Generate negative-positive two and three digit operand

	if (operator_type1 < 2)
	{
		if (operator_type2 == 3)
			op3 = generate_denominator(op2, 10, 999);

		printf("%d  ", op3);
		print_operator(operator_type3);

		if (operator_type3 == 3)
		{
			if(operator_type2 < 2)
				op4 = generate_denominator(op3, 10, 999);

			else
				op4 = generate_denominator(perform_operation(op2, op3, operator_type2), 10, 999);
		}

		printf("%d  ", op4);
	

		if (operator_type2 < 2 && operator_type3 < 2)
		{
			answer = perform_operation(op1, op2, operator_type1);
			answer = perform_operation(answer, op3, operator_type2);
			answer = perform_operation(answer, op4, operator_type3);
		}

		else if (operator_type2 < 2 && operator_type3 >= 2)
		{
			answer = perform_operation(op3, op4, operator_type3);
			answer = perform_operation(perform_operation(op1, op2, operator_type1), answer, operator_type2);
		}

		else if (operator_type2 >= 2 && operator_type3 < 2)
		{
			answer = perform_operation(op2, op3, operator_type2);
			answer = perform_operation(op1, answer, operator_type1);
			answer = perform_operation(answer, op4, operator_type3);
		}

		else if (operator_type2 >= 2 && operator_type3 >= 2)
		{
			answer = perform_operation(op2, op3, operator_type2);
			answer = perform_operation(answer, op4, operator_type3);
			answer = perform_operation(op1, answer, operator_type1);
		}
	}

	else
	{
		answer = perform_operation(op1, op2, operator_type1);

		if (operator_type2 == 3)
			op3 = generate_denominator(answer, 10, 999);

		printf("%d  ", op3);
		print_operator(operator_type3);

		if (operator_type3 == 3)
		{
			if (operator_type2 < 2)
				op4 = generate_denominator(op3, 10, 999);

			else
				op4 = generate_denominator(perform_operation(answer, op3, operator_type2), 10, 999);
		}

		printf("%d  ", op4);

		if (operator_type2 < 2 && operator_type3 < 2)
		{			
			answer = perform_operation(answer, op3, operator_type2);
			answer = perform_operation(answer, op4, operator_type3);
		}

		else if (operator_type2 < 2 && operator_type3 >= 2)
		{
			answer = perform_operation(answer, perform_operation(op3, op4, operator_type3), operator_type2);
		}

		else
		{
			answer = perform_operation(answer, op3, operator_type2);
			answer = perform_operation(answer, op4, operator_type3);
		}
	}


	printf("=  ?\n");

	return answer;
}






void generate_message(int incorrect_correct, int level)
{
	int i = rand() % 3;

	if (incorrect_correct == 0)    // 0 is incorrect
	{
		if (i == 0)
			printf("\n Your answer is incorrect! You lost %d point(s)!\n", level);
		else if (i == 1)
			printf("\n Sorry, your answer is not correct! You failed %d point(s)!\n", level);
		else
			printf("\n Wrong answer! Your point lost \%d point(s)!\n", level);
	}

	else if (incorrect_correct == 1)   // 1 is correct
	{
		if (i == 0)
			printf("\n Your answer is correct! You earned %d point(s)!\n", level);
		else if (i == 1)
			printf("\n Great job! You got %d point(s)!\n", level);
		else
			printf("\n Congratulations! Get your %d point(s)!\n", level);
	}
}



void run(int level)
{
	int num_correct = 0;
	int hard_level = 1;

	for (int i = 0; i < 10; i++)
	{
		int answer = 0;
		int quotient = 0, remainder = 0;

		printf(" POINT:  %d\n\n", POINT);

		switch (level)
		{
		case 1:
			answer = easy(hard_level);
			break;
		case 2:
			answer = fair(hard_level);
			break;

		case 3:
			intermediate(&quotient, &remainder, hard_level);
			break;

		case 4:
			answer = hard(hard_level);
			break;

		case 5:
			answer = impossible();
			break;

		default:
			break;
		}

		if (level != 3)
		{
			int user_ans = -1;
			printf(" Answer:  ");
			scanf("%d", &user_ans);

			generate_message(answer == user_ans, level);

			if (answer == user_ans)
			{
				num_correct++;
				POINT += level;
			}

			else
			{
				POINT -= level;

				if (POINT < 0)
					POINT = 0;
			}
				
		}

		else   // level = 3
		{
			int user_quotient = -1, user_remainder = -1;
			printf(" Answer:  quotient = ");
			scanf("%d", &user_quotient);

			printf("          remainder = ");
			scanf("%d", &user_remainder);

			generate_message((user_quotient == quotient && user_remainder == remainder), level);

			if (user_quotient == quotient && user_remainder == remainder)
			{
				num_correct++;
				POINT += level;
			}

			else
			{
				POINT -= level;

				if (POINT < 0)
					POINT = 0;
			}
		}

		//Within each level, problems should become a little more difficult as the user enters correct answers
		if (num_correct == 3)
			hard_level = 2;
		else if (num_correct == 5)
			hard_level = 3;


		if (i < 9)
		{
			printf(" Please, hit ENTER to continue!");
			getch();
			system("cls");   //Clear the screen
		}
	}
}




int search_lastest_record(FILE* infile, char* initials)
{
	char temp[10] = "";
	int temp_point = 0;
	int found = 0;

	while (!feof(infile))
	{
		fscanf(infile, "%s", temp);
		fscanf(infile, "%d\n", &temp_point);

		if (strcmp(initials, temp) == 0)
		{
			POINT = temp_point;
			found = 1;
		}
	}

	return found;
}
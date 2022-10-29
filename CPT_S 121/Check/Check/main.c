

#include "header.h"


int main(void)
{
	int arr[10];
	
	for (int i = 0; i < 10; i++)
	{
		printf("Enter the value for arr[%d]: ", i);
		scanf("%d", &arr[i]);
	}


	printf("\n\n\n\n Arr = {");
	for (int i = 0; i < 10; i++)
	{
		printf("%d   ", arr[i]);
	}
	printf("}\n");

	return 0;
}
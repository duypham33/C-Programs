// This example illustrates how to work
// with dynamic memory and linked lists.

// 4/26 - Implemented insert_in_order () and delete_item ().
// 4/23 - Implemented print_list (), delete_at_front (),
//        and started insert_in_order ();
// 4/21 - Define struct Node and struct Data. Implemented
//        make_node () and insert_at_front ().
// 4/19 - Discussed and worked with malloc () and dynamic memory.
//        Defined our struct Node, which will be used in our
//        linked list.

#include "LinkedList.h"

int main(void)
{
	Node* head_ptr = NULL; // empty list
	int success = 0;
	Data item = { "eggs" };
	char str[100] = "";

	/*success = insert_at_front(&head_ptr, item);
	strcpy(item.grocery_item, "eggs");
	success = insert_at_front(&head_ptr, item);
	strcpy(item.grocery_item, "milk");
	success = insert_at_front(&head_ptr, item);*/

	success = insert_in_order(&head_ptr, item);
	strcpy(item.grocery_item, "bananas");
	success = insert_in_order(&head_ptr, item);
	strcpy(item.grocery_item, "milk");
	success = insert_in_order(&head_ptr, item);
	strcpy(item.grocery_item, "ham");
	success = insert_in_order(&head_ptr, item);

	print_list(head_ptr);

	success = delete_item(&head_ptr, "ham");
	/*if (success)
	{
		puts(str);
	}*/
	print_list(head_ptr);
	/*printf("head_ptr->item: %s\n",
		head_ptr->item.grocery_item);*/



	/*int* mem_ptr = NULL;
	int num = 0, count = 0;*/
	//int* arr_ptrs[100] = { NULL };
	
	//srand((unsigned int)time(NULL));

	//printf("Enter a number, so we can allocate that number of integers: ");
	//scanf("%d", &num);

	//while (count < num)
	//{
	//	// reusing the same pointer causes memory leaks!!!
	//	// memory leaks are a major issue!!!
	//	// we'll fix with our dynamic data structure - linked list
	//	mem_ptr = (int*)malloc(sizeof(int));
	//	*mem_ptr = rand();

	//	printf("start address: %d mem: %d\n", mem_ptr, 
	//		*mem_ptr);
	//	++count;
	//}


	return 0;
}
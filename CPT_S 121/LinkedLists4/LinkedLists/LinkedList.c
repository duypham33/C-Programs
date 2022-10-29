#include "LinkedList.h"

Node* make_node(Data new_item)
{
	Node* mem_ptr = (Node*)malloc(sizeof(Node));

	if (mem_ptr != NULL)
	{
		// succeeded at allocating space for a Node
		// initialize the Node
		mem_ptr->next_ptr = NULL;
		//mem_ptr->item = new_item; // struct assignment
		strcpy(mem_ptr->item.grocery_item,
			new_item.grocery_item);
	}

	return mem_ptr;
}

int insert_at_front(Node** head_ptr, 
	Data new_item)
{
	Node* mem_ptr = make_node(new_item);
	int success = 0;

	if (mem_ptr != NULL)
	{
		// allocated a Node successfully
		success = 1;

		if (*head_ptr == NULL)
		{
			// list is empty
			*head_ptr = mem_ptr;
		}
		else
		{
			// list is not empty
			mem_ptr->next_ptr = *head_ptr;
			*head_ptr = mem_ptr;
		}
	}

	return success;
}

void print_list(Node* head_ptr)
{
	printf("--> ");

	while (head_ptr != NULL)
	{
		printf("%s --> ",
			head_ptr->item.grocery_item);
		head_ptr = head_ptr->next_ptr;
	}

	putchar('\n');
}

// insert grocery item in a - z order.
// 4/23 - function is not complete. we'll complete
// on Monday 4/26
int insert_in_order(Node** head_ptr,
	Data new_item)
{
	int success = 0;
	Node* mem_ptr = make_node(new_item);
	Node* cur_ptr = *head_ptr, * prev_ptr = NULL;

	if (mem_ptr != NULL)
	{
		// successfully allocated space for Node
		success = 1;

		// insert into empty list?
		if (*head_ptr == NULL)
		{
			*head_ptr = mem_ptr;
		}
		else
		{
			// inserting into a non empty list
			while (cur_ptr != NULL &&
				strcmp(mem_ptr->item.grocery_item,
				cur_ptr->item.grocery_item) > 0)
			{
				prev_ptr = cur_ptr;
				cur_ptr = cur_ptr->next_ptr;
			}

			// inserting at front?
			if (prev_ptr == NULL)
			{
				*head_ptr = mem_ptr;
				mem_ptr->next_ptr = cur_ptr;
			}
			else
			{
				// inserting in middle or at end
				mem_ptr->next_ptr = cur_ptr;
				prev_ptr->next_ptr = mem_ptr;
			}
		}
	}

	return success;
}

// the returned data could also be of struct Data type
// instead of char *
int delete_at_front(Node** head_ptr,
	char* return_string) 
{
	Node* mem_ptr = *head_ptr;
	int success = 0;

	//if (*head_ptr == NULL)
	//{
	//	// list is empty
	//}

	if (*head_ptr != NULL)
	{
		// list is not empty
		success = 1;
		strcpy(return_string,
			(*head_ptr)->item.grocery_item);

		// removing the Node
		*head_ptr = (*head_ptr)->next_ptr;
		free(mem_ptr);
	}

	return success;
}

int delete_item(Node** head_ptr,
	char* grocery_item)
{
	int success = 0;
	Node* cur_ptr = *head_ptr, * prev_ptr = NULL;

	//if (*head_ptr == NULL)
	//{
	//	// empty list
	//}
	if (*head_ptr != NULL)
	{
		while (cur_ptr != NULL && strcmp(grocery_item, 
			cur_ptr->item.grocery_item) != 0)
		{
			prev_ptr = cur_ptr;
			cur_ptr = cur_ptr->next_ptr;
		}

		//if (cur_ptr == NULL)
		//{
		//	// reached end of list
		//}
		if (cur_ptr != NULL)
		{
			if (prev_ptr == NULL) // delete front?
			{
				(*head_ptr) = cur_ptr->next_ptr;
				/*free(cur_ptr);
				success = 1;*/
			}
			else
			{
				// node deleting in middle or at end
				prev_ptr->next_ptr = cur_ptr->next_ptr;
				/*free(cur_ptr);
				success = 1;*/
			}

			free(cur_ptr);
			success = 1;
		}
	}

	return success;
}
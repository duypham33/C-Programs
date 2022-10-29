#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h> // malloc (), calloc (), free ()
#include <time.h>

typedef struct data
{
	char grocery_item[50]; // grocery item
} Data;

typedef struct node
{
	//int id;
	Data item; // 50 bytes
	struct node* next_ptr; // 4 bytes
} Node;

Node* make_node(Data new_item);
int insert_at_front(Node** head_ptr, 
	Data new_item);
int insert_in_order(Node** head_ptr,
	Data new_item);
// the returned data could also be of struct Data type
// instead of char *
int delete_at_front(Node** head_ptr,
	char* return_string);

int delete_item(Node** head_ptr,
	char* grocery_item);

void print_list(Node *head_ptr);

#endif

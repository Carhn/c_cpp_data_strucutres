// Preprocessor protection
#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

// Header files
#include <stdio.h>
#include <stdlib.h>
#include "constants.h"

// Generic linked list data structure
typedef struct LL_Node
{

   int data;
   struct LL_Node *next_node;
   
} LL_Node;

// Function prototypes

// Insert a node at the front
void insert_at_front( LL_Node **head_ptr, int new_data );

// Insert a node at the end
void insert_at_end( LL_Node **head_ptr, int new_data );

// Insert a node
void insert_node( LL_Node **insertion_ptr, int new_data );

// Delete node
void delete_node( LL_Node **head_ptr, int target );

// Search for a node
int search( LL_Node *head_ptr, int target );

// Purge linked list
void purge( LL_Node **head_ptr );

// Print linked list
void print_list( LL_Node *head_ptr );

#endif // SINGLY_LINKED_LIST.H
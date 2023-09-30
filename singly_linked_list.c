// Header files
#include "singly_linked_list.h"


// Singly linked list management functions

void delete_node( LL_Node **head_ptr, int target )
{
   // Declare and initialize variables
   LL_Node *working_ptr = *head_ptr;
   LL_Node *temp_ptr = NULL;

   // Check for empty list
   if( *head_ptr == NULL )
   {   
      // Print error message
         // Functions: printf()
      printf( "Deletion Error: This linked list is empty\n" );
   }

   // Check if head pointer matches search target
   else if( working_ptr->data == target )
   {
      // Advance head pointer
      *head_ptr = working_ptr->next_node;

      // Free working node
         // Functions: free()
      free( working_ptr );
   }

   // Traverse list until at node prior to target
   else
   {
      // Loop while not target or NULL
      while( working_ptr != NULL && working_ptr->next_node->data != target )
      {
         // Advance working pointer
         working_ptr = working_ptr->next_node;
      }

      // If working pointer isn't NULL, then target has been found
      if( working_ptr != NULL )
      {
         // Set temp pointer to working pointer
         temp_ptr = working_ptr->next_node;

         // Set working pointer's next node to temp pointer's next node
         working_ptr->next_node = temp_ptr->next_node;

         // Free temp pointer
            // Functions: free()
         free( temp_ptr );
      }
      // Otherwise, target node was not found
      else
      {
         // Print error message
            // Functions: printf()
         printf( "Deletion Error: Target node not found.\n" );
      }
   }
}

void insert_node( LL_Node **insertion_ptr, int new_data )
{
   // Declare & initialize variables
   LL_Node *working_ptr = *insertion_ptr;
   LL_Node *new_node = NULL;

   // Allocate memory to new node
      // Functions: malloc()
   new_node = ( LL_Node *)malloc( sizeof( LL_Node ) );

   // Assign new node's next node to NULL
   new_node->next_node = NULL;

   // Assign data to the new node
   new_node->data = new_data;

   // Check  for empty list
   if( *insertion_ptr == NULL )
   {
      // Set insertion point to new node
      *insertion_ptr = new_node;
   }
   // Otherwise, insert new node at given pointer
   else
   {
      // Assign new node to insertion pointer's next node
      new_node->next_node = working_ptr->next_node;

      // Reassign insertion pointer's next node to new node
      working_ptr->next_node = new_node;
   }
}

void insert_at_end( LL_Node **head_ptr, int new_data )
{
   // Delcare & initialize variables
   LL_Node *working_ptr = *head_ptr;
   LL_Node *new_node = NULL;

   // Allocate memory to new node
      // Functions: malloc()
   new_node = ( LL_Node *)malloc( sizeof( LL_Node ) );

   // Assign new node's next node to NULL
   new_node->next_node = NULL;

   // Assign data to the new node
   new_node->data = new_data;

   // Check for empty list
   if( *head_ptr == NULL )
   {
      // Set head pointer to new node
      *head_ptr =  new_node;
   }
   else
   {
      // Traverse list until end
      while( working_ptr->next_node != NULL )
      {
         // Advance working pointer
         working_ptr = working_ptr->next_node;
      }

      // Set working pointer's next node to new node
      working_ptr->next_node = new_node;
   }
}

void insert_at_front( LL_Node **head_ptr, int new_data )
{
   // Declare & initialize variables
   LL_Node *new_node = NULL;

   // Allocate memory to new node
      // Functions: malloc()
   new_node = ( LL_Node * )malloc( sizeof( LL_Node ) );

   // Assign new node's next node to NULL
   new_node->next_node = NULL;

   // Assign data to the new node
   new_node->data = new_data;

   // Check if linked list is empty
   if( *head_ptr == NULL )
   {
      // Set head pointer to new node
      *head_ptr = new_node;
   }

   // Otherwise, add to start of list
   else
   {
      // Set new node's next to head pointer
      new_node->next_node = *head_ptr;

      // Set head pointer to new node
      *head_ptr = new_node;
   }
}

void print_list( LL_Node *head_ptr )
{
   // Declare & initialize variables
   LL_Node *working_ptr = head_ptr;

   // Check for empty list
   if( head_ptr == NULL )
   {
      // Print error message
      printf( "Print Error: This linked List is empty.\n" );
   }
   else
   {
      // Traverse list until node is NULL
      while( working_ptr != NULL )
      {
         // Print current node
            // Functions: printf()
         printf( "%d\n", working_ptr->data );

         // Advance working pointer
         working_ptr = working_ptr->next_node;
      }
   }
}

void purge( LL_Node **head_ptr )
{
   // Declare & initialize variables
   LL_Node *working_ptr = *head_ptr;

   if( *head_ptr != NULL )
   {
      // Recursively traverse list
         // Functions: purge()
      purge( &working_ptr->next_node);

      // Free current node
         // Functions: free()
      free( working_ptr );

      // Set head pointer to NULL
      *head_ptr = NULL;
   }
}

int search( LL_Node *head_ptr, int target )
{
   // Guard against empty list
   if( head_ptr != NULL )
   {
      // Check if current node matches search target
      if( head_ptr->data == target )
      {
         // Return as founc
         return FOUND;
      }

      // Check next node; recursively
      return( search( head_ptr->next_node, target ) );
      
   }
printf("not found\n");
   return NOT_FOUND;

}


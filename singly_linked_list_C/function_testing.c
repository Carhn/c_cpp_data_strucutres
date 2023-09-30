// Header files
#include "singly_linked_list.h"

// Main for testing linked list functions
int main()
{
   // Declare & initialize variables
   LL_Node *test_node = NULL;
   int results;
   int test_data = 6;
   int test_data_2 = 7;
   int test_data_3 = 3;
   int test_data_4 = 9;

   // Function testing

      // Test insert_at front
         printf( "Testing insert at front\n" );

         // Test insertion to empty list
         insert_at_front( &test_node, test_data );
         print_list( test_node );

         // Test insertion to existing list
         insert_at_front( &test_node, test_data_2 );
         print_list( test_node );

      // Test insert_at_end
         printf( "\nTesting insert at end\n" );

         //Test insertion to existing list
         insert_at_end( &test_node, test_data_4 );
         print_list( test_node );

      // Test insertion at specific node
         printf( "\nTesting insertion at point\n");

         // Test insertion after second node
         insert_node( &test_node->next_node, test_data_3 );
         print_list( test_node );

      // Test node search
         printf( "\nTest node search\n" );

         // Search front node
         results = search( test_node, test_data );
         printf("Results: %d\n", results );

         // Search end node
         results = search( test_node, test_data_4 );
         printf("Results: %d\n", results );

         // Search for specific node
         results = search( test_node, test_data_3 );
         printf("Results: %d\n", results );

         // Search for non-existing value
         results = search( test_node, 13);
         printf("Results: %d\n", results );

      // Test deletion of node
         printf("\nTesting Deletion\n");

         // Test deletion of first node in list
         delete_node( &test_node, test_data_2 );
         print_list( test_node );
         printf("\n");

         // Test deletion of middle node in list
         delete_node( &test_node, test_data_3 );
         print_list( test_node );
         printf("\n");

         // Test deletion of last node in list
         delete_node( &test_node, test_data_4 );
         print_list( test_node );
         printf("\n");

      // Test purge of list
      insert_at_front( &test_node, test_data_3 );
      insert_at_front( &test_node, test_data_4);
      insert_at_end( &test_node, test_data_2 );      
      print_list( test_node );
      purge( &test_node );
      print_list( test_node );


   // End program
   return 0;
}
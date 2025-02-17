// Fig. 12.3: fig12_03.c
// Inserting and deleting nodes in a list
#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

int main( void )
{ 
   LLPtr startPtr = NULL;
   unsigned int choice;
   int item;
   char name[50];

   instructions();
   printf( "? ");
   scanf( "%u", &choice);

   while ( choice != 3 ) { 

      switch ( choice ) { 
         case 1:
            printf( "Enter id and name: " );
            scanf( "%d %s", &item, name );
            insert( &startPtr, item, name);
            printList( startPtr );
            printList_reverse( startPtr );
            break;
         case 2:

            if ( !isEmpty( startPtr ) ) { 
               printf( "%s", "Enter number to be deleted: " );
               scanf( "%d", &item );

               if ( deletes( &startPtr, item ) ) {
                  printf( "%d deleted.\n", item );
                  printList( startPtr );
                  printList_reverse( startPtr );
               }
               else {
                  printf( "%d not found.\n\n", item );
               }
            }
            else {
               puts( "List is empty.\n" );
            }

            break;
         default:
            puts( "Invalid choice.\n" );
            instructions();
            break;
      }

      printf( "? " );
      scanf( "%u", &choice );
   }
  /* Clear all nodes at the end of nodes*/
   clear(&startPtr);
   puts( "End of run." );
}

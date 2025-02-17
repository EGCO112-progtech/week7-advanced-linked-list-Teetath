#include <string.h>
struct Node {
   int data;
   char name[50];
   struct Node *nextPtr;
   struct Node *pPtr;
};

typedef struct Node LLnode;
typedef LLnode *LLPtr;

int deletes( LLPtr *sPtr, int value );
int isEmpty( LLPtr sPtr );
void insert( LLPtr *sPtr, int value ,char *name);
void printList( LLPtr currentPtr );
void printList_reverse( LLPtr currentPtr );
void instructions( void );

void instructions( void )
{
   puts( "Enter your choice:\n"
      "   1 to insert an element into the list.\n"
      "   2 to delete an element from the list.\n"
      "   3 to end." );
}

void insert( LLPtr *sPtr, int value ,char *NAME)
{
   LLPtr newPtr;
   LLPtr previousPtr;
   LLPtr currentPtr;

   newPtr =(LLPtr) malloc( sizeof( LLnode ) );

   if ( newPtr != NULL ) {
      newPtr->data = value;
      strcpy(newPtr->name,NAME);
      newPtr->nextPtr = NULL;
    
      previousPtr = NULL;
      currentPtr = *sPtr;

      while ( currentPtr != NULL && value > currentPtr->data ) {
         previousPtr = currentPtr;
         currentPtr = currentPtr->nextPtr;
      }

      if (!previousPtr) {
         newPtr->nextPtr = *sPtr;
         newPtr->pPtr = NULL;
         if((*sPtr)){
            (*sPtr)->pPtr = newPtr;
            (*sPtr) = newPtr;
         }
         else
            (*sPtr) = newPtr;
      }
      else {
         previousPtr->nextPtr = newPtr;
         newPtr->nextPtr = currentPtr;
         if(currentPtr)
         currentPtr->pPtr = newPtr;
         newPtr->pPtr = previousPtr;
      }
   }
   else {
      printf( "%d not inserted. No memory available.\n", value );
   }
}

int deletes( LLPtr *sPtr, int value )
{
   LLPtr previousPtr;
   LLPtr currentPtr;
   LLPtr tempPtr;

   if ( value == ( *sPtr )->data ) {
      tempPtr = *sPtr;
      *sPtr = ( *sPtr )->nextPtr;
      if(tempPtr->pPtr)
         ( *sPtr )->pPtr = tempPtr->pPtr;
      free( tempPtr );
      return value;
   }
   else {
      previousPtr = *sPtr;
      currentPtr = ( *sPtr )->nextPtr;

      while ( currentPtr != NULL && currentPtr->data != value ) {
         previousPtr = currentPtr;
         currentPtr = currentPtr->nextPtr;
      }

      if ( currentPtr != NULL ) {
         tempPtr = currentPtr;
         previousPtr->nextPtr = currentPtr->nextPtr;
         if(currentPtr->nextPtr)currentPtr = currentPtr->nextPtr;
         currentPtr->pPtr = previousPtr;
         free( tempPtr );
         return value;
      }
   }

   return '\0';
}

int isEmpty( LLPtr sPtr )
{
   return sPtr == NULL;
}

void printList( LLPtr currentPtr )
{
   if ( isEmpty( currentPtr ) ) {
      puts( "List is empty.\n" );
   }
   else {
      puts( "The list is:" );

      while ( currentPtr->nextPtr!= NULL ) {
         printf( "%d %s -->", currentPtr->data ,currentPtr->name);
         currentPtr = currentPtr->nextPtr;
      }

      printf( "%d %s -->NULL\n",currentPtr->data ,currentPtr->name);
   }
}

void printList_reverse( LLPtr currentPtr )
{
   if ( isEmpty( currentPtr ) ) {
      puts( "List is empty.\n" );
   }
   else {
      if(!currentPtr->nextPtr){
         while ( currentPtr->pPtr != NULL ) {
            printf( "%d %s -->", currentPtr->data ,currentPtr->name);
            currentPtr = currentPtr->pPtr;
         }
      }else{
         while ( currentPtr->nextPtr != NULL ) {
            currentPtr = currentPtr->nextPtr;
         }
         while ( currentPtr->pPtr != NULL ) {
            printf( "%d %s -->", currentPtr->data ,currentPtr->name);
            currentPtr = currentPtr->pPtr;
         }
      }
      printf( "%d %s -->NULL\n",currentPtr->data ,currentPtr->name);
   }
}

void clear(LLPtr *sPtr){
   LLPtr previousPtr;
   LLPtr currentPtr;
   previousPtr = NULL;
   currentPtr = *sPtr;
   while (currentPtr) {
      previousPtr = currentPtr;
      printf("delete %d\n", currentPtr->data);
      currentPtr = currentPtr->nextPtr;
      free(previousPtr);
   }
}
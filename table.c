#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "table.h"
//Blessings Manatsa


// Linked list node definition
typedef struct NODE Node;

struct NODE
{
  char *string;
  Node *next;
};

static Node *top = NULL;
static int numNodes = 0;

// used to track where we are for the list traversal methods
static Node *traverseNode = NULL;

static void validateTableState()
{
    int i;
  if ( numNodes == 0 )
    assert( top == NULL );
  else if ( numNodes == 1 )
    assert( top->next == NULL );
  else
    assert( top != NULL && top->next != NULL );

//  test the structure of the list via a test/use of the iterator functions.
  #ifndef NDEBUG
  //limit the number of nodes we go through to make sure we don't waste too much time here...
  #define LOOP_LIMIT 100
  Node *curr = top;
  for (i = 0; NULL != curr && i < LOOP_LIMIT; i++)
  {
      assert(NULL != curr->string);
      curr = curr->next;
  }
  #endif
}


// empty the Table so that we clear all memory and can start a fresh list
void emptyTable()
{
  Node *curr = top;

  validateStateTable();

  while ( top != NULL )
  {
    top = top->next;
    free( curr->string );
    curr->string = NULL;
    free( curr );

    curr = top;

    numNodes--;
  }

  validateTableState();
}

int size( )
{
    assert(numNodes >= 0);
    return numNodes;
}

// add an element to the beginning of the linked list
Boolean insert( char const * const new_string )
{
  validateTableState();
  Boolean rc = true;
  Node *newNode = NULL;
  assert(new_string != NULL);

  newNode = (Node *)malloc( sizeof( Node ) );
  assert(newNode != NULL);

  newNode->next = top;
  top = newNode;

  // note that we need to have space for the string as well!
  newNode->string = (char *)malloc( strlen(new_string) + 1 );
  assert( newNode->string != NULL );
  strcpy( newNode->string, new_string );
  numNodes++;
  validateTableState();

  return rc;
}


// remove an element with the given string
Boolean delete( char const * const target )
{
  validateTableState();
  Boolean deleted = false;
  Node *curr = top;
  Node *prev = NULL;
  assert(curr != NULL);
    assert( (curr == NULL) || (curr->string != NULL) );

  while ( curr != NULL && strcmp( target, curr->string ) != 0 )
  {
    prev = curr;
    curr = curr->next;
  }

  if ( curr != NULL )
  {
    if ( prev != NULL )
      prev->next = curr->next;
    else
      top = curr->next;

    free( curr->string );
    free( curr );
    deleted = true;
    numNodes--;
    validateTableState();
  }

  return deleted;
}

// tells us whether or not the given string is in the list
Boolean search( char const * const target )
{
  Boolean found = false;
  Node *curr = top;
  int count = 0;
  validateTableState();
  assert(curr != NULL);

  while ( curr != NULL && !found )
  {
      assert(target != NULL);
      assert(curr->string != NULL);
    if ( strcmp( target, curr->string ) == 0 )
    {
      found = true;
      assert( count <= numNodes );//this assert will check if we are still in the list
    }

    else
    {
      curr = curr->next;
      count++;
    }
  }
  assert( found || (count == numNodes) );//if not found end the list

  return found;
}


// starts a list traversal by getting the data at top
char * firstItem()
{
  traverseNode = top->next;

  validateTableState();
  assert(top->string != NULL);
  // make sure we're still in our list...
    assert( num_traversals <= numNodes );


  return top->string;
}


// gets the data at the current traversal node and increments the traversal
char * nextItem()
{
  char *item = NULL;
   validateTableState();

  // no need to go past the end of the list...
  if ( traverseNode != NULL )
  {
    assert(item != NULL);
    item = traverseNode->string;
    traverseNode = traverseNode->next;
  }
  // make sure we're still in our list...
    assert( num_traversals <= numNodes );


  return item;
}

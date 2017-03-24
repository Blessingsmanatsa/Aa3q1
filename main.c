#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "table.h"
#define T_SIZE 4
#define T_SIZE2 2
#define BUFFER 1000000


//-------------------------------------------------------------------------------------
// CONSTANTS and TYPES
//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
// VARIABLES
//-------------------------------------------------------------------------------------

static int testsPassed;
static int testsFailed;
static int currentSize;

//-------------------------------------------------------------------------------------
// PROTOTYPES
//-------------------------------------------------------------------------------------

void testEmpty();
void testInsert();
void testRemove();
void testFound( int size, char *strings[] );
void testNotFound( int size, char *strings[] );
void testSize();
void testLeaks();
void suite();
void cleanSuite();

//-------------------------------------------------------------------------------------
// FUNCTIONS
//-------------------------------------------------------------------------------------


int main( int argc, char *argv[] )
{
  suite();
  printf( "Initiating tests.\n\n" );
  testEmpty();
  testInsert();
  testRemove();
  testLeaks();

  cleanSuite();
  printf( "\nTests completed successfully.\n" );

  return EXIT_SUCCESS;
}

//A suite is represented by one XML file. It can contain one or more tests and is defined by the <suite> tag.

void suite()
{
  testsPassed = 0;
  testsFailed = 0;
  currentSize = 0;
}

// Test boundary conditions on an empty list

void testEmpty()
{
  char *emptyArray[1] = {"Nothing there"};

  testNotFound( 1, emptyArray );
  delete( "No Nodes" );
  testSize();
}

void testSize()
{
  char *string;
  int size;

  printf( "\nTesting size of list:\n" );
  string = firstItem();
  size = 0;
  while ( string != NULL )
  {
    size++;
    string = nextItem();
  }
  printf( "The size of list is %d\n", size );

  if ( size == currentSize )
  {
    testsPassed++;
  }
  else
  {
    testsFailed++;
  }
}


// Test adding elements to list

void testInsert()
{
  char *newString[T_SIZE] = {"Node4", "Node3", "Node2", "Node1"};
  char *notChar[1] = {"Not"};
  int i;

  printf( "\nTesting insertions:\n" );
  for ( i=0; i<T_SIZE ; i++ )
  {
    printf( "\"%s\"\n", newString[i] );
    insert( newString[i] );
    currentSize++;
  }
  testFound(T_SIZE, newString );
  testNotFound( 1, notChar );
  testSize();
}

void testRemove()//removing an elemnt from the list
{
  char *deleteStrings[T_SIZE2] = {"Node4", "Node1"};
  char *newStrings[T_SIZE2] = {"Node3", "Node2"};
  int i;

  printf( "\nTesting delete:\n" );
  for ( i=0 ; i<T_SIZE2 ; i++ )
  {
    printf( "\"%s\"\n", deleteStrings[i] );
    delete( deleteStrings[i] );
    currentSize--;
  }

  testFound(T_SIZE2, newStrings );
  testNotFound(T_SIZE2, deleteStrings );
  testSize();
}

void testFound( int size, char *strings[] )
{
  char *target;
  Boolean result;
  int i;

  printf("\nTesting searching method from the elements that are in the list:\n");
  for ( i=0 ; i<size ; i++ )
  {
    target = strings[i];
    result = search( target );

    if (result)
    {
      printf( "\"%s\" was found\n", target );
      testsPassed++;
    }
    else
    {
      printf( "\"%s\" was not found\n", target );
      testsFailed++;
    }
  }
}

// Ensure that a set of elements is not in the list

void testNotFound( int size, char *strings[] )
{
  char *target;
  Boolean result;
  int i;

  printf( "\nTesting searching method from the elements that are in the list:\n" );
  for ( i=0 ; i<size ; i++ )
  {
    target = strings[i];
    result = search( target );

    if (result)
    {
      printf( "\"%s\" was found\n", target );
      testsFailed++;
    }
    else
    {
      printf( "\"%s\" was not found\n", target );
      testsPassed++;
    }
  }
}
void testLeaks()
{
  int i;
  char * string1[1] = { "hi" };

  for ( i=0 ; i<BUFFER ; i++ )
  {
    insert( string1[0] );
    currentSize++;
  }

  testFound( 1, string1 );
  testSize();

  for ( i=0 ; i<BUFFER ; i++ )
  {
    delete( string1[0] );
    currentSize--;
  }

  testNotFound( 1, string );
  testSize();
}


void cleanSuite()
{
  clearTable();
  currentSize = 0;
  testSize();

  printf( "\nTest results:\n" );
  printf( "%d tests were run.\n", testsPassed+testsFailed );
  printf( "%d tests passed.\n", testsPassed );
  printf( "%d tests failed.\n", testsFailed );
}


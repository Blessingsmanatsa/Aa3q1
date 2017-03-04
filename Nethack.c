#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//-------------------------------------------------------------------------------------
// CONSTANTS and TYPES
//-------------------------------------------------------------------------------------

#define MAX_DIMENSION 20
// constant defination of the dungeon
const char WALL        = '-';
const char ILLUM_BFORE = '.';
const char CAN_ILLU   = '-';
const char LIGHT      = '&';
const char UP         = '^';
const char LEFT       = '<';
const char RIGHT      = '>';
const char DOWN       = 'V';

struct DUNGEON
{
    int row;
    int col;
};
typedef DUNGEON Dungeon ;


struct CELL_NODE
{
  Cell     cell;
  CellNode *next;
};
typedef struct CELL_NODE CellNode;

CellNode *top = NULL;

// a 2D array used to store the DUNGEON
char array[MAX_DIMENSION][MAX_DIMENSION];
int x;
int y;

int main(int argc ,char* argv[])
{
    int count = 0;
    int x;

   if ( argc != 2 ) /* argc should be 2 for correct execution */
    {
        /* We print argv[0] assuming it is the program name */
        printf( "usage: %s filename", argv[0] );
    }
    else
    {
        // We assume argv[1] is a filename to open
        FILE *file = fopen( argv[1], "r" );

        /* fopen returns 0, the NULL pointer, on failure */
        if ( file == 0 )
        {
            printf( "Could not open file\n" );
        }
        else
        {
            character = fgets(fileName, MaxSize,stdin);
            while  ( ( x = fgetc( file ) ) != EOF )
            {
                printf( "%c", x );
            }
            fclose( file );
        }
    }
    return EXIT_SUCCESS;
}

void input()

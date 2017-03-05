#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//-------------------------------------------------------------------------------------
// CONSTANTS and TYPES
//-------------------------------------------------------------------------------------

#define MAX_DIMENSION 30
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
    char array[MAX_DIMENSION][MAX_DIMENSION];// a 2D array used to store the DUNGEON
    int row;
    int col;
    int moves;
};
typedef DUNGEON Dungeon ;


struct CELL_NODE
{
  Cell     cell;
  CellNode *next;
};
typedef struct CELL_NODE CellNode;

typedef enum BOOL { false, true } Boolean;

CellNode *top = NULL;



int main(int argc ,char* argv[])
{
    Dungeon dungArr;
    int count = 0;
    int x;
    int i,j;
    char *character;

    char line[MAX_DIMENSION];
    /*
    int row, col;
  char ch;
  char line[MAX_DIMENSION];
  char *linePtr;
  char *next;
  */

   if ( argc != 2 ) /* argc should be 2 for correct execution */
    {
        /* We print argv[0] assuming it is the program name */
        printf( "usage: %s filename", argv[0] );
    }
    else
    {
        // We assume argv[1] is a filename to open
        FILE *file = fopen( argv[1], "r" );


        character = fgets(fileName, MAX_DIMENSION,argv[1]);
        fscanf (file, "%d %d %d", &dungArr.rol, &dungArr.col, dungArr.moves);

        while  ( character != EOF )
        {
            fscanf(file,  "%d" "%d" "%d", &row,&col ,&moves)
            x = fgetc( file );

              if ( x != '\n' && x != '\r' )
                 {
                        array[i][j] = x;

                    if ( ++j >= col )
                        {
                            j = 0;
                            if ( ++i >= row )
                            {
                                break;
                            }
                        }
                }
            printf( "%c", x );
        }
        fclose( file );

    }
    return EXIT_SUCCESS;
}
void checkState(){

}
void input(){

}
void createDungeon(){
    int i,j;
    Dungeon dungArr1;

     /* initialize the dungeon to empty */
  for (i = 0; i < dungArr1.row+2; i++)
     for (j = 0; j < dungArr1.col+2; j++)
       dungArr1.array[i][j] = '.';

    /* mark the borders of the dungArr1 with |'s */
    for (i=0; i < dungArr1.row+2; i++)
    {
        dungArr1.array[0][0] = '+';
        dungArr1.array[i][1] = '-';
        dungArr1.arr[i][dungArr1.col+1] = '-';
    }
    for (i=0; i <dungArr1.col+2; i++)
    {
       dungArr1.array[0][i] = '|';
       dungArr1.array[dungArr1.row+1][i] = '|';
    }

}

void printDungeon(){

  int i;
   int j;
  checkState();

  // standard printing of a matrix
  for (  i=0 ; i < dungArr1.row+2; i++ )
  {
    for (  j=0 ; j < dungArr1.col+2  ; j++ )
    {
      printf( "%c", array[i][j] );
    }
    printf( "\n" );
  }

  printf( "\n" );

  checkState();

}

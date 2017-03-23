#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>


// NAME: Blessings Manatsa
// STUDENT NUMBER: 7759480
// COURSE: COMP 2160, SECTION: A1
// INSTRUCTOR:
// ASSIGNMENT: assignment 1, QUESTION: question 1
//

//-------------------------------------------------------------------------------------
// CONSTANTS and TYPES


//-------------------------------------------------------------------------------------
#define MAX_DIMENSION 500
// constant defination of the dungeon
const char WALL        = '~';
const char ILLUM_BFORE = '.';
const char CAN_ILLU   = ' ';
const char LIGHT      = '@';
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
typedef struct DUNGEON Dungeon ;

typedef enum BOOL { false, true } Boolean;

void checkState();
void solveDung( int move, Dungeon dungArr1);
void illuminate(Dungeon dungArr1);
void printDungeon(Dungeon dungArr2);
void createDungeon();


int main(int argc,char* argv[])
{
    Dungeon dungArr;
    int count = 0;
    int x;
    int i,j;

    char title[MAX_DIMENSION];
    char *character;



    if ( argc != 2 ) /* argc should be 2 for correct execution */
    {
        /* We print argv[0] assuming it is the program name */
        printf( "usage: %s filename", argv[0] );
    }
    else
    {
        // We assume argv[1] is a filename to open
        FILE *file = fopen( argv[1], "r" );


        character = fgets(title, MAX_DIMENSION,file);
        printf( "%s \n", character);
        fscanf (file, "%d %d %d", &dungArr.row, &dungArr.col, &dungArr.moves);
        x = fgetc( file );
        assert(x != EOF );
        while(character != NULL)
        {
            // len_tmp = strlen(title) - 1; /* -1 because of the newline. */

            /* Just kill the newline with an extra '\0'. */
            //if(title[len_tmp] == '\n')
            //    title[len_tmp] = '\0';

            createDungeon(dungArr);

            for (i = 0; i < dungArr.row; i++)
                for (j = 0; j < dungArr.col; j++)
                    assert(x != '\n' );
            assert(x != '\r');

            if ( x != '\n' && x != '\r' )
            {
                dungArr.array[i][j] = x;

                if ( ++j >= dungArr.col )
                {
                    j = 0;
                    if ( ++i >= dungArr.row )
                    {
                        break;
                    }
                }

                printf( "%c", x );
            }
        }
        count++;

        if (count == dungArr.row )
            for (i = 1; i < dungArr.moves; i++)
            {

                x = fgetc( file );
                if ( x != '\n' && x != '\r' )
                {
                    solveDung( x, dungArr);

                }
            }


        printDungeon(dungArr);
        fclose( file );

    }


    return EXIT_SUCCESS;
}

// we check a cell over and over again...
void checkState(Dungeon dungArr1)
{
    int i,j;
    int x;
//     x = fgetc( file );

    assert(dungArr1.row > 0);
    assert(dungArr1.row <= MAX_DIMENSION);
    assert(dungArr1.col > 0);
    assert(dungArr1.col <= MAX_DIMENSION);

#ifndef NDEBUG

    for (  i=0 ; i < dungArr1.row+2; i++ )
    {
        for (  j=0 ; j < dungArr1.col+2  ; j++ )
        {
            printf( "%c", dungArr1.array[i][j] );
        }
        printf( "\n" );
    }
#endif


}
void solveDung( int move, Dungeon dungArr1)
{

    checkState(dungArr1); //it the invariant the check the state of the method

    int i,j;
    int numMoves = 0;

    for (i = 0; i < dungArr1.row; i++)
        for (j = 0; j < dungArr1.col; j++)

            if(dungArr1.array[i][j] == '@')
            {
                if(move == '^')
                {
                    dungArr1.array[i][j - 1] = '@'; //move char @ at proper position
                    illuminate(dungArr1); //re-evaluate illumination
                    // numMoves++; //increment
                    printf("Move %d :\n", numMoves);
                }

                else if(move == 'V')
                {
                    dungArr1.array[i][j + 1] = '@'; //move char @ at proper position
                    illuminate(dungArr1); //re-evaluate illumination
                    numMoves++; //increment
                    printf("Move %d :\n", numMoves);
                }

                else if(move == '<')
                {
                    dungArr1.array[i - 1][j ] = '@'; //move char @ at proper position
                    illuminate(dungArr1); //re-evaluate illumination
                    numMoves++; //increment
                    printf("Move %d :\n", numMoves);
                }

                else
                {
                    dungArr1.array[i +1][j] = '@'; //move char @ at proper position
                    illuminate(dungArr1); //re-evaluate illumination
                    numMoves++; //increment
                    printf("Move %d :\n", numMoves);
                }
            }
    checkState(dungArr1); //it the invariant the check the state of the method
}


void illuminate(Dungeon dungArr1)
{

    checkState(dungArr1); //it the invariant the check the state of the method

    Boolean cNTilluminate = false;
    int distance ;
    int i,j,x1, x2,y1,y2;
    int count =0;


    for (i = 0; i < dungArr1.row; i++)
        for (j = 0; j < dungArr1.col; j++)


            if(dungArr1.array[i][j] == WALL && dungArr1.row < 0 && dungArr1.row >= dungArr1.row +1 && dungArr1.col < 0 && dungArr1.col >= dungArr1.col +1 )
            {
                cNTilluminate = false;
            }


            else
            {
                if(dungArr1.array[i][j] == LIGHT )
                {
                    count++ ;
                    x1 = i;
                    x2 = j;
                }
                if(dungArr1.array[i][j] != LIGHT)
                y1 = i;
                y2 = j;

                distance = sqrt((x2-x1)^2 + (y2-y1)^2);
                if(distance == 1) //if any char is 1 step away from array, illuminate it
                {
                    dungArr1.array[i][j] = '#';
                }


                else if(distance == 2) //if any char is 2 steps away from array, illuminate it
                {
                    dungArr1.array[i][j] = '=';
                }

                else if(distance == 3) //if any char is 3 steps away from array, illuminate it
                {
                    dungArr1.array[i][j] = '-';
                }


                else if(dungArr1.array[i][j] == ILLUM_BFORE )
                {

                    dungArr1.array[i][j] = ',';

                }
                else
                {
                    dungArr1.array[i][j] = CAN_ILLU ;

                }

            }
    checkState(dungArr1);


}

void createDungeon(Dungeon dungArr1)
{

    checkState(dungArr1);
    int i,j;

    //initialize the dungeon to empty /
    for (i = 0; i < dungArr1.row+2; i++)
        for (j = 0; j < dungArr1.col+2; j++)
            dungArr1.array[i][j] = '.';

    /* mark the borders of the dungArr1 with |'s */
    for (i=0; i < dungArr1.row+2; i++)
    {
        dungArr1.array[0][0] = '+';
        dungArr1.array[i][1] = '-';
        dungArr1.array[i][dungArr1.col+1] = '-';
    }
    for (i=0; i <dungArr1.col+2; i++)
    {
        dungArr1.array[0][i] = '|';
        dungArr1.array[dungArr1.row+1][i] = '|';
    }

}

void printDungeon(Dungeon dungArr2)
{

    int i;
    int j;
    checkState(dungArr2);

    // standard printing of a matrix
    for (  i=0 ; i < dungArr2.row+2; i++ )
    {
        for (  j=0 ; j < dungArr2.col+2  ; j++ )
        {
            printf( "%c", dungArr2.array[i][j] );
        }
        printf( "\n" );
    }

    printf( "\n" );

    checkState(dungArr2);

}

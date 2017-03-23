#ifndef _TABLE_H
#define _TABLE_H

typedef enum BOOL { false, true } Boolean;

Boolean insert( char const * const new_string );
Boolean delete( char const * const target );
void emptyTable();
Boolean search( char const * const target );
char * firstItem();
char * nextItem();

#endif

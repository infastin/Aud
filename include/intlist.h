#ifndef _INTLIST_H
#define _INTLIST_H

#include "list.h"

DeclareHeaderList(Int, int)
DeclareHeaderList(IntP, int*)

/* Sort list using quick sort */
void SortIntList(IntList **list);

/* Sort list backward using quck sort */
void RSortIntList(IntList **list);

#endif

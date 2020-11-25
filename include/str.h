#pragma once

#include "vector.h"

DeclareHeaderVector(String, char*, Pointer)

/* Return string length */
int StringLength(const char *string);

/* Find FIND in STRING
 *
 * Return:
 * ● Two-dimensional int array (vector int**, where int* not vectors)
 * where each array contains the index of the start of the entry (i: 0)
 * and the index of the end of the entry (i: 1);
 * ● NULL if string length equal zero. 
 */
int **FindString(const char *string, const char *find);

/* Return number of found FIND in STRING */
int CountString(const char *string, const char *find);

/* Replace FIND in STRING with REPLACE
 * 
 * Return:
 * ● String (char*);
 * ● NULL if string length equal zero.
 */
char *ReplaceString(const char *string, const char *find, const char *replace);

/* Split string with delimiter
 * 
 * Return:
 * ● Array of strings (vector char**, where char* also vectors);
 * ● NULL if string length equal zero.
 */
char **SplitString(const char *string, char delimiter);

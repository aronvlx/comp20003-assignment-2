#ifndef _CSV_H_
#define _CSV_H_

#include <stdio.h>

#include "data.h"

/* reads a single line from fp into a string without newlines and returns 
NULL when reaching EOF */
char *readLine(FILE *fp);

/* Splits line in place into x NUM_FIELDS and stripping quotes "" from 
quoted filds without mistaking commas , as delimiters */
int splitCSVLine(char *line, char *fields[NUM_FIELDS]);

#endif /* _CSV_H_ */

#ifndef _BIT_H_
#define _BIT_H_

/* "bit.h" and "bit.c" provided by COMP20003 as per assignment specifications.
 Modified to add a comparison function */

/* Number of bits in a single character. */
#define BITS_PER_BYTE 8

int getBit(char *s, unsigned int bitIndex);

/* compares two strings bit by bit, similarly to strcmp but by each bit. 
Stops at the first difference or when fully matched, counted in *compCount. */
int compareBits(char *a, char *b, unsigned long *compCount);

#endif /* _BIT_H_ */

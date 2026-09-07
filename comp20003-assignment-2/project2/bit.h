#ifndef _BIT_H_
#define _BIT_H_

/* "bit.h" and "bit.c" and "createStem.c" provided by COMP20003 as per assignment specifications.
 Modified to add a comparison function and createStem moved into bit.c */

/* Number of bits in a single character */
#define BITS_PER_BYTE 8

int getBit(char *s, unsigned int bitIndex);

/* compares two strings bit by bit, similarly to strcmp but by each bit. 
Stops at the first difference or when fully matched, counted in *compCount. */
int compareBits(char *a, char *b, unsigned long *compCount);

/* Allocates new memory to hold the numBits specified and fills the allocated
    memory with the numBits specified starting from the startBit of the oldKey
    array of bytes. */
char *createStem(char *oldKey, unsigned int startBit, unsigned int numBits);

#endif /* _BIT_H_ */

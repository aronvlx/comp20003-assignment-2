#include "bit.h"
#include <assert.h>

// idea: compare bit by bit

int getBit(char *s, unsigned int bitIndex){
    assert(s);
    unsigned int byte = bitIndex / BITS_PER_BYTE;
    unsigned int indexFromLeft = bitIndex % BITS_PER_BYTE;
    /* 
        Since we split from the highest order bit first, the bit we are interested
        will be the highest order bit, rather than a bit that occurs at the end of the
        number. 
    */
    unsigned int offset = (BITS_PER_BYTE - (indexFromLeft) - 1) % BITS_PER_BYTE;
    unsigned char byteOfInterest = s[byte];
    unsigned int offsetMask = (1 << offset);
    unsigned int maskedByte = (byteOfInterest & offsetMask);
    /*
        The masked byte will still have the bit in its original position, to return
        either 0 or 1, we need to move the bit to the lowest order bit in the number.
    */
    unsigned int bitOnly = maskedByte >> offset;
    return bitOnly;
}

/* compares two strings bit by bit, similarly to strcmp but by each bit. Stops at the first difference or when fully matched, counted in *compCount. */
int compareBits(char *a, char *b, unsigned long *compCount) {
    unsigned int i = 0;

    while (1) {
        int bitA = getBit(a,i);
        int bitB = getBit(b,i);
        (*compCount)++;

        if (bitA != bitB) return bitA - bitB;

        //check for \0 to see ending

        if (i % BITS_PER_BYTE == BITS_PER_BYTE - 1) {
            unsigned byteIdx = i / BITS_PER_BYTE;

            if (a[byteIdx] == '\0') return 0;
        }

        i++;
    }
}

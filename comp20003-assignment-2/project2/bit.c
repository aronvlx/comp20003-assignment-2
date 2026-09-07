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

/* Allocates new memory to hold the numBits specified and fills the allocated
    memory with the numBits specified starting from the startBit of the oldKey
    array of bytes. */
char *createStem(char *oldKey, unsigned int startBit, unsigned int numBits){
    assert(oldKey);
    /* Calculate whether any additional bytes are needed to store the stem due
        to not fitting exactly in a byte. */
    int extraBytes = 0;
    if((numBits % BITS_PER_BYTE) > 0){
        extraBytes = 1;
    }
    int totalBytes = (numBits / BITS_PER_BYTE) + extraBytes;
    char *newStem = malloc(sizeof(char) * totalBytes);
    assert(newStem);
    /* Zero all values in stem initially, so that OR operation is well 
        defined. */
    for(unsigned int i = 0; i < totalBytes; i++){
        newStem[i] = 0;
    }
    /* For each bit, follow getBit logic to find the location to insert the bit 
        and add the bit to the new stem. */
    for(unsigned int i = 0; i < numBits; i++){
        /* Calculate a mask for the bit to add to the stem */
        unsigned int indexFromLeft = i % BITS_PER_BYTE;
        unsigned int offset = (BITS_PER_BYTE - indexFromLeft - 1) % BITS_PER_BYTE;
        unsigned int bitMaskForPosition = 1 << offset;
        unsigned int bitValueAtPosition = getBit(oldKey, startBit + i);
        /* Calculate the byte which the new bit will be placed in. */
        unsigned int byteInNewStem = i / BITS_PER_BYTE;
        /* Add 0 or 1 to the stem at the appropriate bit. */
        newStem[byteInNewStem] |= bitMaskForPosition * bitValueAtPosition;
    }
    return newStem;
}

#ifndef _DATA_H_
#define _DATA_H_

#include <stdio.h>

#define NUM_FIELDS 16
#define MAX_LINE_LEN 511
#define MAX_FIELD_LEN 127

typedef struct record {
    char *key;
    char *taxa;
    char *kingdom;
    char *phylum;
    char *classType; //name classType to avoid collision with class 
    char *order;
    char *family;
    char *genus;
    char *species;
    char *common_name;
    char *identificat;
    char *data_resour;
    char *sighting_da;
    long double longitude;
    long double latitude;
    char *ezi_add;
} record_t;

/* Duplicates src into a malloc buffer of exact length. */
char *allocateString(const char *src);

/* creates new record record_t by copying each of the 16 csv fields 
into the structs fields */
record_t *createRecord(char *fields[NUM_FIELDS]);

/* frees a record and each string field in it */
void freeRecord(record_t *rec);

/* parses next csv data line retrieved from fp into a record. */
record_t *readNextRecord(FILE *fp);

/* writes one record at a time into file out as per assignments required 
output format. */
void writeRecord(FILE *out, const record_t *rec);

#endif /* _DATA_H_ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "data.h"
#include "csv.h"

// Idea: form a struct of where each string 
// is a dynamically allocated length for maximum space efficiency
// Retrieve from record struct -> malloc each line -> 
// assign mallocs to each line in new struct
// print csv and free old, now redundant rec struct and proceed
// with using the new space efficient structure.

/* Duplicates src into a malloc buffer of exact length. */
char *allocateString(const char *src) {
    if (src == NULL) return NULL;

    size_t len = strlen(src);
    char *dest = (char *)malloc(sizeof(char)*(len + 1));
    assert(dest != NULL);

    strcpy(dest, src);
    return dest;
}

/* creates new record record_t by copying each of the 16 csv fields into the structs fields */
record_t *createRecord (char *fields[NUM_FIELDS]) {
    record_t *rec = (record_t *)malloc(sizeof(record_t));
    assert(rec != NULL);

    rec->key            = allocateString(fields[ 0]);
    rec->taxa           = allocateString(fields[ 1]);
    rec->kingdom        = allocateString(fields[ 2]);
    rec->phylum         = allocateString(fields[ 3]);
    rec->classType      = allocateString(fields[ 4]);
    rec->order          = allocateString(fields[ 5]);
    rec->family         = allocateString(fields[ 6]);
    rec->genus          = allocateString(fields[ 7]);
    rec->species        = allocateString(fields[ 8]);
    rec->common_name    = allocateString(fields[ 9]);
    rec->identificat    = allocateString(fields[10]);
    rec->data_resour    = allocateString(fields[11]);
    rec->sighting_da    = allocateString(fields[12]);
    rec->latitude       = strtold(fields[13], NULL );
    rec->longitude      = strtold(fields[14], NULL );
    rec->ezi_add        = allocateString(fields[15]);

    return rec;
}

/* parses next csv data line retrieved from fp into a record. */
record_t *readNextRecord (FILE *fp) {
    char *line = readLine(fp);
    if (line == NULL) return NULL;

    char *fields[NUM_FIELDS];

    int numFields = splitCSVLine(line, fields); // gets number of field count
    assert(numFields == NUM_FIELDS);

    record_t *rec = createRecord(fields);
    free(line);

    return rec;
}

/* writes one record at a time into file out as per assignments required output format. */
void writeRecord(FILE *out, const record_t *rec) {
    if (out == NULL || rec == NULL) return;
 
    fprintf(out,
            "--> KEY: %s || "
            "Taxa: %s || "
            "Kingdom: %s || "
            "Phylum: %s || "
            "Class: %s || "
            "Order: %s || "
            "Family: %s || "
            "Genus: %s || "
            "Species: %s || "
            "Common_Name: %s || "
            "Identifcat: %s || "
            "Data_Resour: %s || "
            "Sighting_Da: %s || "
            "latitude: %.5Lf || "
            "longitude: %.5Lf || "
            "EZI_ADD: %s || \n",
            rec->key,
            rec->taxa,
            rec->kingdom,
            rec->phylum,
            rec->classType,
            rec->order,
            rec->family,
            rec->genus,
            rec->species,
            rec->common_name,
            rec->identificat,
            rec->data_resour,
            rec->sighting_da,
            rec->latitude,
            rec->longitude,
            rec->ezi_add);
}

/* frees a record and each string field in it */
void freeRecord(record_t *rec) {
    if (rec == NULL) return;

    free(rec->key);
    free(rec->taxa);
    free(rec->kingdom);
    free(rec->phylum);
    free(rec->classType);
    free(rec->order);
    free(rec->family);
    free(rec->genus);
    free(rec->species);
    free(rec->common_name);
    free(rec->identificat);
    free(rec->data_resour);
    free(rec->sighting_da);
    free(rec->ezi_add);

    free(rec);
}

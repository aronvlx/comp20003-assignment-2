#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
 
#include "csv.h"
 
// Idea: read csv line by line, splitting data into fields

/* copies len characters of src as well as +1 space for '\0' in an exact sized malloc buffer */
static char *duplicateLine(const char *src, size_t len) {
    char *copy = (char *)malloc(len + 1);
    assert(copy != NULL);
    memcpy(copy, src, len + 1);
    return copy;
}
 
/* reads a single line from fp into a string without newlines and returns NULL when reaching EOF */
char *readLine(FILE *fp) {
    assert(fp != NULL);
 
    // fgets() keeps \n so +1, and need +1 or \0
    char buf[MAX_LINE_LEN + 2];
 
    if (fgets(buf, sizeof(buf), fp) == NULL) return NULL;
 
    size_t len = strlen(buf);
 
    while (len > 0 &&
          (buf[len - 1] == '\n' ||
           buf[len - 1] == '\r')) { len--; }
    buf[len] = '\0';
 
    return duplicateLine(buf, len);
}
    
/* Splits line in place into x NUM_FIELDS and stripping quotes "" from quoted filds without mistaking commas , as delimiters */
int splitCSVLine(char *line, char *fields[NUM_FIELDS]) {
    assert(line != NULL);
 
    // scan through and build fields 
    int fieldIdx = 0;
    char *p = line;
 
    while (fieldIdx < NUM_FIELDS) {
        char *newField;
 
        if (*p == '"') {
            p++;
            newField = p;
 
            while (*p != '\0' && *p != '"') p++;
 
            if (*p == '"') {*p = '\0'; p++;}
        } else {
            newField = p;
 
            while (*p != '\0' && *p != ',') p++;
        }
 
        fields[fieldIdx++] = newField;
 
        if (*p == ',') {*p = '\0'; p++;}
        else {*p = '\0'; break;}
    }
 
    return fieldIdx;
}

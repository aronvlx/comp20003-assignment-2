#ifndef _SEARCH_H_
#define _SEARCH_H_

#include <stddef.h>

#include "list.h"
#include "data.h"

#define INIT_MATCH_CAP 2

typedef struct searchResult {
    record_t **matches;
    size_t numMatches;
    size_t capacity;

    unsigned long bitComps;
    unsigned long nodeComps;
    unsigned long strComps;
} searchResult_t;

/* scans each node in list to match a key to that key, collecting matches 
including duplicates count bit/node/str comparisons */
searchResult_t *searchKey(list_t *list, char *key);

/* frees a search rsult and array, maintaining matched records in the list */
void freeResult(searchResult_t *result);

#endif /* _SEARCH_H_ */

#include <stdlib.h>
#include <assert.h>
 
#include "search.h"
#include "bit.h"

/* (static) appends rec (record) to result's array, using amortization: doubling array capacity when full to maintain O(n) and O(1) insertion */
static void addRecordMatch(searchResult_t *result, record_t *rec) {
    if (result->numMatches == result->capacity) {
        // use amortized to reduce big O from O(n^2) to O(n)
        result->capacity = (result->capacity == 0)
                           ? INIT_MATCH_CAP
                           : result->capacity * 2;

        result->matches = (record_t **)realloc(
            result->matches, result->capacity * sizeof(record_t *));
        
        assert(result->matches!=NULL);
    }

    result->matches[result->numMatches] = rec;
    result->numMatches++;
}

/* scans each node in list to match a key to that key, collecting matches including duplicates count bit/node/str comparisons */
searchResult_t *searchKey(list_t *list, char *key) {
    assert(list != NULL && key != NULL);

    searchResult_t *result = (searchResult_t *)malloc(sizeof(searchResult_t));
    assert(result != NULL);

    result->matches = NULL;
    result->numMatches = 0;
    result->capacity = 0;
    result->bitComps = 0;
    result->nodeComps = 0;
    result->strComps = 0;

    node_t *curr = list->head;

    for ( ; curr!= NULL; curr = curr->next) {
        result->strComps++; // potential useful info for assignment 2
        result->nodeComps++; // potential useful info for assignment 2

        int cmp = compareBits((curr->data->key), key, &result->bitComps);
        if (cmp == 0) addRecordMatch(result, curr->data); // append record to results
    }

    return result;
}

/* frees a search rsult and array, maintaining matched records in the list */
void freeResult(searchResult_t *result) {
    if (result == NULL) return;
 
    free(result->matches);
    free(result);
}

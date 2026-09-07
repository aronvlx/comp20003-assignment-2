#include <stdio.h>
#include <stdlib.h>

#include "data.h"
#include "csv.h"
#include "list.h"
#include "search.h"

static list_t *loadDictionary(const char *csvFile);
static void runStage1(list_t *dict, FILE *out);

/* opens csvFile, skipping header line and reading every row into a linked 
list created with createList */
static list_t *loadDictionary(const char *csvFile) {
    FILE *csvFp = fopen(csvFile, "r");
    if (csvFp == NULL) exit(EXIT_FAILURE);

    // first line is header as per specifications, not needed
    char *header = readLine(csvFp);
    free(header);

    list_t *dict = createList();

    record_t *rec;
    while ((rec = readNextRecord(csvFp)) != NULL) listAppend(dict,rec);

    fclose(csvFp);
    return dict;
}

/* Reads keys taken from stdin and writes each query matches or NOTFOUND 
in case of none to out and posting a summary of comparison counts into stdout 
(also isolate assignment 1 specific parts as prep for assignment 2) */
static void runStage1(list_t *dict, FILE *out) {
    char *queryKey;

    while ((queryKey = readLine(stdin)) != NULL) {
        searchResult_t *result = searchKey(dict, queryKey);

        fprintf(out, "%s\n", queryKey);
        if (result->numMatches == 0) { 
            fprintf(out, "NOTFOUND\n");
        } else { 
            for (size_t i = 0; i < result->numMatches; i++) {
                writeRecord(out, result->matches[i]);
            }
        }

    printf("%s --> %zu records found - comparisons: b%lu n%lu s%lu\n",
           queryKey,
           result->numMatches,
           result->bitComps,
           result->nodeComps,
           result->strComps
          );

    freeResult(result);
    free(queryKey);

    }
}

/* validates cli arguments, opens output file, loads dictionary and 
runs stage 1*/
int main(int argc, char *argv[]) {
    //aexpects exactly 4 args: program name, stage, csv file, output file
    if (argc != 4) return EXIT_FAILURE;

    // expected commands in same order
    const char *csvFile = argv[2];
    const char *outFile = argv[3];

    FILE *outFp = fopen(outFile, "w");
    if (outFp == NULL) return EXIT_FAILURE;

    list_t *dict = loadDictionary(csvFile);

    runStage1(dict, outFp);

    fclose(outFp);
    freeList(dict);

    return EXIT_SUCCESS;
}

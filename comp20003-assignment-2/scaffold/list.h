#ifndef _LIST_H_
#define _LIST_H_

#include "data.h"

typedef struct node node_t;

struct node {
    record_t *data;
    node_t *next;
};

typedef struct list {
    node_t *head;
    node_t *tail;
    size_t size;
} list_t;

/* allocs and returns new empty linked list */
list_t *createList(void);

/* appends record to tail of list in O(1) time */
void listAppend(list_t *list, record_t *record);

/* frees each node in list, each record in each node and the list */
void freeList(list_t *list);

#endif /* _LIST_H_ */

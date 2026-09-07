#include <stdlib.h>
#include <assert.h>

#include "list.h"

// Idea: create a list structure with head and tail pointers
// such that records can be appended in O(1) time and maintain ordering

/* allocs and returns new empty linked list */
list_t *createList(void) {
    list_t *list = (list_t *)malloc(sizeof(list_t));
    assert(list != NULL);
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return list;
}

/* appends record to tail of list in O(1) time */
void listAppend(list_t *list, record_t *record) {
    assert(list != NULL && record != NULL);

    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    assert(new_node != NULL);
    new_node->data = record;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->size++;
}

/* frees each node in list, each record in each node and the list */
void freeList(list_t *list) {
    if (list == NULL) return;

    node_t *curr = list->head;
    while (curr != NULL) {
        node_t *tmp = curr;
        curr = curr->next;
        freeRecord(tmp->data);
        free(tmp);
    }
    free(list);
}

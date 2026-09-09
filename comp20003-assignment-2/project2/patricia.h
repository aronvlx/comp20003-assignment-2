#ifndef _PATRICIA_H_
#define _PATRICIA_H_

#include <stdlib.h>
#include <stdio.h>
#include "data.h"
#include "list.h"

#define MAX_NUM_BRANCHES 2
#define BRANCH_A 0
#define BRANCH_B 1

typedef struct patricia_node patricia_node_t;

struct patricia_node {
    char *stem;
    unsigned int stemBitCount;
    char *key;
    list_t *records;
    patricia_node_t *branch[2];
};

typedef struct patricia_tree {
    patricia_node_t *root;
    size_t nodeCount;
    size_t recordCount;
} patricia_tree_t;

patricia_tree_t *patriciaCreateTree(void);

patricia_node_t *patriciaCreateNode(char *stem, unsigned int stemBitCount, const char *key, record_t *record);

void patriciaInsertNode(patricia_tree_t *tree, const char *key, record_t *record);

void patriciaTreeTraverse(patricia_node_t *node, node_action_t action, void *context);

void patriciaFreeNode(patricia_node_t *node);

void patriciaFreeTree(patricia_tree_t *tree);

#endif

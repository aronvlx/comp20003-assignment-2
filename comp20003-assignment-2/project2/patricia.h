#ifndef _PATRICIA_H_
#define _PATRICIA_H_

#include <stdlib.h>

typedef struct patricia_node patricia_node_t;

struct patricia_node {

}

typedef struct patricia_tree {

} patricia_tree_t;

patricia_tree_t *patriciaCreateTree(void);

patricia_node_t *patriciaCreateNode();

void patriciaInsertNode();

void patriciaTreeTraverse();

void patriciaFreeNode(patricia_node_t *node);

void patriciaFreeTree(patricia_tree_t *tree);

#endif

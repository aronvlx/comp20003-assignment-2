#include "patricia.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static char *stringDuplicate(const char *src) {
    if (!src) return NULL;
    
    
}


patricia_tree_t *patriciaCreateTree(void) {
     patricia_tree_t *tree = malloc(sizeof(patricia_tree_t));
     assert(tree);

     tree->root = NULL;
     tree->nodeCount = 0;
     tree->recordCount = 0;

     return tree;
}

patricia_node_t *patriciaCreateNode();

void patriciaTreeTraverse(patricia_node_t *node, node_action_t action, void *context) {
    if (!node) return;
    if (node->records != NULL && node->key != NULL) action(node, context);

    if (node->branch[BRANCH_A] != NULL) {
        patriciaTreeTraverse(node->branch[BRANCH_A], action, context);
    }
    if (node->branch[BRANCH_A] != NULL) {
        patriciaTreeTraverse(node->branch[BRANCH_B], action, context);
    }
}

void patriciaFreeNode (patricia_node_t *node) {
    if (!node) return;

    patriciaFreeNode(node->branch[BRANCH_A]);
    patriciaFreeNode(node->branch[BRANCH_B]);

    if (node->stem != NULL) {
        free(node->key);
        node->stem = NULL;
    }

    if (node->key != NULL) {
        free(node->key);
        node->key = NULL;
    }

    if (node->records != NULL) {
        freeList(node->records);
        node->records=NULL;
    }

}

void patriciaFreeTree(patricia_tree_t *tree) {
    if (!tree) return;

    if (tree->root != NULL) {
        patriciaFreeNode(tree->root);
        tree->root = NULL;
    }
    free(tree);
}

//
// Created by thiago on 05/04/2020.
//

#include "Stack.h"

void initStack(struct TpStackChar **stack) {
    *stack = NULL;
}

bool isEmptyStack(struct TpStackChar *stack) {
    return stack == NULL;
}

struct TpStackChar *createNodeStack(char info) {
    struct TpStackChar *node = (struct TpStackChar *) malloc(sizeof(struct TpStackChar));
    node->info = info;
    node->next = NULL;

    return node;
}

void push(struct TpStackChar **stack, char info) {
    struct TpStackChar *node = createNodeStack(info);
    if (*stack == NULL) {
        *stack = node;
    } else {
        node->next = *stack;
        *stack = node;
    }
}

char pop(struct TpStackChar **stack) {
    struct TpStackChar *node = *stack;
    char info = node->info;
    *stack = node->next;
    free(node);
    return info;
}

char topInfo(struct TpStackChar *stack) {
    return stack->info;
}

void printStack(struct TpStackChar *stack) {
    struct TpStackChar *node = stack;
    while (node != NULL) {
        if (node->next == NULL) {
            printf("%c", node->info);
        } else {
            printf("%c, ", node->info);
        }
        node = node->next;
    }
}
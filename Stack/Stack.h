//
// Created by thiago on 05/04/2020.
//

#ifndef DATASTRUCTURES_STACK_H
#define DATASTRUCTURES_STACK_H

#include "../global.h"

struct TpStackChar {
    char info;
    struct TpStackChar *next;
};

char menuStack(void);

void executeStack(void);

char inputInfoStack();

// Operations Stack
void initStack(struct TpStackChar **stack);

bool isEmptyStack(struct TpStackChar *stack);

struct TpStackChar *createNodeStack(char info);

void push(struct TpStackChar **stack, char info);

char pop(struct TpStackChar **stack);

char topInfo(struct TpStackChar *stack);

void printStack(struct TpStackChar *stack);

#endif //DATASTRUCTURES_STACK_H

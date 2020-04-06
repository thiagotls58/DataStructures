//
// Created by thiago on 05/04/2020.
//

#include "Stack.h"

char menuStack(void) {
    clearTerminal();
    printf("Stack\n");
    printf("[1] - Init\n");
    printf("[2] - Push\n");
    printf("[3] - Pop\n");
    printf("[4] - Top Info\n");
    printf("[5] - Empty \n");
    printf("[6] - Print Stack \n");
    return toupper(getchar());
}

void executeStack(void) {
    struct TpStackChar *stack;
    char option, info;
    do {
        option = menuStack();
        switch (option) {
            case '1': {
                clearTerminal();
                initStack(&stack);
                printf("The stack was successfully initialized");
                pauseTerminal();
                break;
            }
            case '2': {
                clearTerminal();
                info = inputInfoStack();
                while (info != '0') {
                    push(&stack, info);
                    printf("Info inserted in the stack");
                    pauseTerminal();
                    info = inputInfoStack();
                }
                break;
            }
            case '3': {
                clearTerminal();
                if (isEmptyStack(stack)) {
                    printf("The stack is empty");
                } else {
                    info = pop(&stack);
                    printf("The info '%c' has been removed from the stack", info);
                }
                pauseTerminal();
                break;
            }
            case '4': {
                clearTerminal();
                if (isEmptyStack(stack)) {
                    printf("The stack is empty");
                } else {
                    info = topInfo(stack);
                    printf("The top info of the stack  is the: '%c'", info);
                }
                pauseTerminal();
                break;
            }
            case '5': {
                clearTerminal();
                if (isEmptyStack(stack)) {
                    printf("Yes!");
                } else {
                    printf("No!");
                }
                pauseTerminal();
                break;
            }
            case '6': {
                clearTerminal();
                if (isEmptyStack(stack)) {
                    printf("The stack is empty");
                } else {
                    printf("Stack ");
                    printf("[");
                    printStack(stack);
                    printf("]\n");
                }
                pauseTerminal();
                break;
            }
        }

    } while (option != 81);
}

char inputInfoStack() {
    clearTerminal();
    printf("Info: ");
    char info;
    clearKeyboardBuffer();
    scanf("%c", &info);
    return info;
}

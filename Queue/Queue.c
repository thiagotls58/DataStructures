//
// Created by thiago on 05/04/2020.
//

#include "Queue.h"

char menuQueue(void) {
    clearTerminal();
    printf("Queue\n");
    printf("[1] - Init\n");
    printf("[2] - Enqueue\n");
    printf("[3] - Dequeue\n");
    printf("[4] - First Info\n");
    printf("[5] - Empty \n");
    printf("[6] - Print Queue \n");
    return toupper(getchar());
}

void executeQueue(void) {
    struct TpQueueChar *queue;
    char option, info;
    do {
        option = menuQueue();
        switch (option) {
            case '1': {
                clearTerminal();
                init(&queue);
                printf("The queue was successfully initialized");
                pauseTerminal();
                break;
            }
            case '2': {
                clearTerminal();
                info = inputInfoQueue();
                while (info != '0') {
                    enqueue(&queue, info);
                    printf("Element inserted in the queue");
                    pauseTerminal();
                    info = inputInfoQueue();
                }
                break;
            }
            case '3': {
                clearTerminal();
                if (isEmpty(queue)) {
                    printf("The queue is empty");
                } else {
                    info = dequeue(&queue);
                    printf("The info '%c' has been removed from the queue", info);
                }
                pauseTerminal();
                break;
            }
            case '4': {
                clearTerminal();
                if (isEmpty(queue)) {
                    printf("The queue is empty");
                } else {
                    info = firstInfo(queue);
                    printf("The first info of the queue  is the: '%c'", info);
                }
                pauseTerminal();
                break;
            }
            case '5': {
                clearTerminal();
                if (isEmpty(queue)) {
                    printf("Yes!");
                } else {
                    printf("No!");
                }
                pauseTerminal();
                break;
            }
            case '6': {
                clearTerminal();
                if (isEmpty(queue)) {
                    printf("The queue is empty");
                } else {
                    printf("Queue ");
                    printf("[");
                    printStack(queue);
                    printf("]\n");
                }
                pauseTerminal();
                break;
            }
        }

    } while (option != 81); // => Q
}

char inputInfoQueue() {
    clearTerminal();
    printf("Info: ");
    char info;
    clearKeyboardBuffer();
    scanf("%c", &info);
    return info;
}

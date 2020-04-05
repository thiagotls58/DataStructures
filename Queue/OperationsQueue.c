//
// Created by thiago on 05/04/2020.
//

#include "Queue.h"

void init(struct TpQueueChar** queue) {
    *queue = NULL;
}

bool isEmpty(struct TpQueueChar* queue) {
    return queue == NULL;
}

struct TpQueueChar* createNodeQueue(char info) {
    struct TpQueueChar* node = (struct TpQueueChar*)malloc(sizeof(struct TpQueueChar));
    node->info = info;
    node->next = NULL;

    return node;
}

void enqueue(struct TpQueueChar** queue, char info) {
    struct TpQueueChar* node = createNodeQueue(info);
    if (*queue == NULL) {
        *queue = node;
    } else {
        struct TpQueueChar* aux = *queue;
        while(aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = node;
    }
}

char dequeue(struct TpQueueChar** queue) {
    struct TpQueueChar* node = *queue;
    char info = node->info;
    *queue = node->next;
    free(node);
    return info;
}

char firstInfo(struct TpQueueChar* queue) {
    return queue->info;
}

void printStack(struct TpQueueChar* queue) {
    struct TpQueueChar* node = queue;
    while(node != NULL) {
        if (node->next == NULL) {
            printf("%c", node->info);
        } else {
            printf("%c, ", node->info);
        }
        node = node->next;
    }
}
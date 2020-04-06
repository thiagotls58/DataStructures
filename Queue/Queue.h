//
// Created by thiago on 05/04/2020.
//

#ifndef DATASTRUCTURES_QUEUE_H
#define DATASTRUCTURES_QUEUE_H

#include "../global.h"

struct TpQueueChar {
    char info;
    struct TpQueueChar *next;
};

char menuQueue(void);

void executeQueue(void);

char inputInfoQueue();

// Operations Queue
void initQueue(struct TpQueueChar **queue);

bool isEmptyQueue(struct TpQueueChar *queue);

struct TpQueueChar *createNodeQueue(char info);

void enqueue(struct TpQueueChar **queue, char info);

char dequeue(struct TpQueueChar **queue);

char firstInfo(struct TpQueueChar *queue);

void printQueue(struct TpQueueChar *queue);

#endif //DATASTRUCTURES_QUEUE_H

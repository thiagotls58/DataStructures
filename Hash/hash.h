//
// Created by thiago on 10/04/2020.
//

#ifndef DATASTRUCTURES_HASH_H
#define DATASTRUCTURES_HASH_H

#include "../global.h"

#define HASH_TABLE_SIZE 1024
#define DATA_SIZE 4096
#define INFO_SIZE 140

struct node {
    int idRecord;
    int position;
    struct node *next;
};

struct record {
    int idRecord;
    char info[INFO_SIZE];
};

char menuHash(void);
void executeHash(void);

void initTableHash(struct node *tableHash[], struct record data[], int *logicalSize);
void insertTableHash(struct node *tableHash[], struct record data[], int *logicalSize);
int calculateHash(int key);
void sequentialSearch(struct node *start, int key, struct node **aux);
void insertNeatly(struct node **start, int idRecord, int position);
void consultHash(struct node tableHash[], struct record data[]);
struct node *consultInTableHash(struct node *tableHash[], int idRecord);
void showAll(struct record data[], int logicalSize);
void deleteHash(struct node **start, int idRecord);
void deleteData(struct record data[], int position, int *logicalSize);
void deleteRecord(struct node *tableHash[], struct record data[], int *logicalSize);
void deleteTableHash(struct node *tableHash[], struct record data[], int *logicalSize);
bool isEmpty(int logicalSize);
void printRecord(struct record auxRecord);


#endif //DATASTRUCTURES_HASH_H

//
// Created by thiago on 10/04/2020.
//

#include "hash.h"

void initTableHash(struct node *tableHash[], struct record data[], int *logicalSize) {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        tableHash[i] = NULL;
    }
    for (int j = 0; j < DATA_SIZE; ++j) {
        data[j].idRecord = 0;
        strcpy(data[j].info, "NULL");
    }
    (*logicalSize) = 0;
}

void insertTableHash(struct node *tableHash[], struct record data[], int *logicalSize) {
    struct record newRecord;
    struct node *aux;
    int address;

    printf("\nId Record: ");
    scanf("%d", &newRecord.idRecord);
    while(newRecord.idRecord > 0) {
        address = calculateHash(newRecord.idRecord);
        sequentialSearch(tableHash[address], newRecord.idRecord, &aux);
        if (aux == NULL) {
            printf("\nInfo: ");
            clearKeyboardBuffer();
            fgets(newRecord.info, INFO_SIZE, stdin);
            data[*logicalSize] = newRecord;
            insertNeatly(&tableHash[address], newRecord.idRecord, *logicalSize);
            (*logicalSize)++;
            printf("\nInformation was successfully inserted");
        } else {
            printf("The Id Record already exists");
        }

        printf("\nId Record: ");
        scanf("%d", &newRecord.idRecord);
    }
}

int calculateHash(int key) {
    return key % HASH_TABLE_SIZE;
}

void sequentialSearch(struct node *start, int key, struct node **aux) {
    *aux = start;
    while((*aux) != NULL && (*aux)->idRecord != key) {
        (*aux) = (*aux)->next;
    }
}

void insertNeatly(struct node **start, int idRecord, int position) {
    struct node *current;
    struct node *previous;
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->idRecord = idRecord;
    newNode->position = position;
    newNode->next = NULL;

    if(*start == NULL) {
        // first insertion
        *start = newNode;
    } else if (newNode->idRecord < (*start)->idRecord) {
        // insert at the beginning
        newNode->next = *start;
        *start = newNode;
    } else {
        current = *start;
        while (current->next != NULL && current->idRecord < newNode->idRecord) {
            previous = current;
            current = current->next;
        }
        if (current->idRecord < newNode->idRecord) {
            // insert at the end
            current->next  = newNode;
        } else {
            // insert in the middle
            newNode->next = current;
            previous->next = newNode;
        }
    }
}

struct node *consultInTableHash(struct node *tableHash[], int idRecord) {
    struct node *auxNode;
    int address;
    address = calculateHash(idRecord);
    sequentialSearch(tableHash[address], idRecord, &auxNode);
    if (auxNode!= NULL) {
        return auxNode;
    } else {
        return NULL;
    }
}

void consultHash(struct node tableHash[], struct record data[]) {
    struct node *auxNode;
    struct record auxRecord;
    int idRecord;
    printf("\nId Record: ");
    scanf("%d", &idRecord);
    while (idRecord > 0) {
        auxNode = consultInTableHash(tableHash, idRecord);
        if (auxNode != NULL) {
            auxRecord = data[auxNode->position];
            printRecord(auxRecord);
        } else {
            printf("\nRecord not found");
        }
        printf("\nId Record: ");
        scanf("%d", &idRecord);
    }
}

void showAll(struct record data[], int logicalSize) {
    printf("\nThis is all records:");
    for (int i = 0; i < logicalSize; ++i) {
        printRecord(data[i]);
    }
}

void deleteHash(struct node **start, int idRecord) {
    struct node *current;
    struct node *previous;

    current = *start;
    while(current != NULL && current->idRecord != idRecord) {
        previous = current;
        current = current->next;
    }
    if (current != NULL) {
        if ((*start)->idRecord == current->idRecord) {
            *start = current->next;
        } else {
            previous->next = current->next;
        }
        free(current);
        printf("\nThe record %d has been deleted", idRecord);
    } else {
        printf("\nRecord %d not found", idRecord);
    }
}

void deleteData(struct record data[], int position, int *logicalSize) {
    struct record auxRecord = data[position];
    int i = position;
    while (i < (*logicalSize) - 1) {
        data[i] = data[i+1];
        i++;
    }
    (*logicalSize)--;
}

void deleteRecord(struct node *tableHash[], struct record data[], int *logicalSize) {
    struct node *auxNode;
    int idRecord;
    char option;
    int address;
    printf("\nId Record: ");
    scanf("%d", &idRecord);
    while (idRecord > 0) {
        auxNode = consultInTableHash(tableHash, idRecord);
        if (auxNode != NULL) {
            printRecord(data[auxNode->position]);
            printf("Do you want to delete? [y/n] ");
            clearKeyboardBuffer();
            scanf("%c", &option);
            if (toupper(option) == 'Y') {
                address = calculateHash(idRecord);
                deleteHash(&tableHash[address], idRecord);
                deleteData(data, auxNode->position, &*logicalSize);
            }
        } else {
            printf("\nRecord %d not found", idRecord);
        }

        printf("\nId Record: ");
        scanf("%d", &idRecord);
    }
}

void deleteTableHash(struct node *tableHash[], struct record data[], int *logicalSize) {
    struct record auxRecord;
    int address, i;

    i = 0;
    while (i < *logicalSize) {
        auxRecord = data[i];
        address = calculateHash(auxRecord.idRecord);
        deleteHash(&tableHash[address], auxRecord.idRecord);
        deleteData(data, i, &*logicalSize);
    }
}

bool isEmpty(int logicalSize) {
    return logicalSize == 0;
}

void printRecord(struct record auxRecord) {
    printf("\nRecord data:");
    printf("\nId Record: %d - Info: %s", auxRecord.idRecord, auxRecord.info);
}




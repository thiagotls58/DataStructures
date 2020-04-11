//
// Created by thiago on 10/04/2020.
//

#include "hash.h"

char menuHash(void) {
    clearTerminal();
    printf("Hash\n");
    printf("[1] - Init Table Hash\n");
    printf("[2] - Insert Record\n");
    printf("[3] - Consult\n");
    printf("[4] - Show All\n");
    printf("[5] - Delete Record\n");
    printf("[6] - Delete All Records\n");
    printf("[7] - Is Empty\n");
    return toupper(getchar());
}

void executeHash(void) {
    char option;
    int logicalSize;
    struct node *tableHash[HASH_TABLE_SIZE];
    struct record data[DATA_SIZE];

    do {
        option = menuHash();
        switch (option) {
            case '1': {
                clearTerminal();
                initTableHash(tableHash, data, &logicalSize);
                printf("The table hash was successfully initialized");
                pauseTerminal();
                break;
            }
            case '2': {
                clearTerminal();
                insertTableHash(tableHash, data, &logicalSize);
                pauseTerminal();
                break;
            }
            case '3': {
                clearTerminal();
                if(!isEmpty(logicalSize)) {
                    consultHash(tableHash, data);
                } else {
                    printf("The hash table is empty");
                }
                pauseTerminal();
                break;
            }
            case '4': {
                clearTerminal();
                if(!isEmpty(logicalSize)) {
                    showAll(data, logicalSize);
                } else {
                    printf("The hash table is empty");
                }
                pauseTerminal();
                break;
            }
            case '5': {
                clearTerminal();
                if(!isEmpty(logicalSize)) {
                    deleteRecord(tableHash, data, &logicalSize);
                } else {
                    printf("The hash table is empty");
                }
                pauseTerminal();
                break;
            }
            case '6': {
                clearTerminal();
                if(!isEmpty(logicalSize)) {
                    deleteTableHash(tableHash, data, &logicalSize);
                } else {
                    printf("The hash table is empty");
                }
                pauseTerminal();
                break;
            }
            case '7': {
                clearTerminal();
                if(isEmpty(logicalSize)) {
                    printf("Yes.");
                } else {
                    printf("No.");
                }
                pauseTerminal();
                break;
            }
        }
    }while (option != 81);
}




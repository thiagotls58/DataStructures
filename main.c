#include "main.h"

char menu(void) {
    clearTerminal();
    printf("[1] - Stack\n");
    printf("[2] - Queue\n");
    printf("[3] - Hash\n");
    return toupper(getchar());
}

void execute(void) {
    char option;
    do {
        option = menu();
        switch (option) {
            case '1': {
                clearTerminal();
                printf("Stack");
                executeStack();
                break;
            }
            case '2': {
                clearTerminal();
                executeQueue();
                break;
            }
            case '3': {
                clearTerminal();
                executeHash();
                break;
            }
        }

    } while (option != 81); // => Q
}

int main() {
    execute();
    clearTerminal();
    printf("\nGoing out...\n");
    return EXIT_SUCCESS;
}

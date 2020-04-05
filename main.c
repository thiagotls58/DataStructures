#include "main.h"

char menu(void) {
    clearTerminal();
    printf("[1] - Stack\n");
    printf("[2] - Queue\n");
    fflush(stdin);
    return getchar();
}

void execute(void) {
    char option;
    do {
        option = menu();
        switch (option) {
            case '1': {
                clearTerminal();
                printf("Stack");
                //executeStack();
                pauseTerminal();
                break;
            }
            case '2': {
                clearTerminal();
                printf("Queue");
                //executeQueue();
                pauseTerminal();
                break;
            }

        }

    } while (option != 81); // => Q
}

int main() {
    execute();
    pauseTerminal();
    return 0;
}

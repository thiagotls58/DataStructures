//
// Created by thiago on 05/04/2020.
//

#include "global.h"

void clearTerminal(void) {
    system(CLEAR);
}

void pauseTerminal(void) {
    if (PAUSE == 1) {
        system("pause");
    } else if (PAUSE == 0) {
        for (int i = 0; i < 2; ++i) {
            printf("\n");
        }
        system("read -p \"Press ENTER to continue\" continue");
    }
}

void clearKeyboardBuffer(void) {
    int key = 0;
    while((key = getchar()) != '\n' && key != EOF) {}
}

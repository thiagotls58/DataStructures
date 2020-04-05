//
// Created by thiago on 05/04/2020.
//

#ifndef DATASTRUCTURES_GLOBAL_H
#define DATASTRUCTURES_GLOBAL_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

#ifdef WIN32
#define PAUSE 1
#else
#define PAUSE 0
#endif

void clearTerminal(void);
void pauseTerminal(void);
void clearKeyboardBuffer(void);

#endif //DATASTRUCTURES_GLOBAL_H

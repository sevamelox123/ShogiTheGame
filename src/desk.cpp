#include <cstdio>
#include <ncurses.h>
#include "desk.h"

Desk::Desk()
{

}
void Desk::printDesk()
{
    for (int i = 0;i < 9;i++) {
        for (int j = 0;j < 9;j++) {
            printw("=====");
        }
        printw("\n");
        for (int j = 0;j < 3;j++) {
            for (int k = 0;k < 9;k++) {
                printw("|   |");
            }
            printw("\n");
        }
    }
    for (int j = 0;j < 9;j++) {
        printw("=====");
    }
}



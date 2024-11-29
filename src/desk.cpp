#include <cstdio>
// #include <ncurses.h>
#include "desk.h"
#include <vector>

Desk::Desk()
{
}
void Desk::printDesk()
{
    // move(0, 0);
    // for (int i = 0; i < 9; i++)
    // {
    //     for (int j = 0; j < 9; j++)
    //     {
    //         printw("=====");
    //     }
    //     printw("\n");
    //     for (int j = 0; j < 3; j++)
    //     {
    //         for (int k = 0; k < 9; k++)
    //         {
    //             printw("|   |");
    //         }
    //         printw("\n");
    //     }
    // }
    // for (int j = 0; j < 9; j++)
    // {
    //     printw("=====");
    // }
    // for (int y = 0;y < 9;y++) {
    //     for (int x = 0;x < 9;x++) {
    //         if (desk[y][x] == nullptr) continue;
    //         for (int i = 1;i <= 3;i++) {
    //             move(desk[y][x]->GetCoordinates().y * 4 + i, desk[y][x]->GetCoordinates().x * 5 + 1);
    //             if (i % 2 == 1)
    //                 printw("###");
    //             else {
    //                 printw("#");
    //                 printw("%lc", desk[y][x]->GetSymbol());
    //                 // printw("歩");
    //                 printw("#");
    //             }
    //         }
    //     }
    // }
}

void Desk::AddPiece(Piece *p)
{
    desk[p->GetCoordinates().y][p->GetCoordinates().x] = p;
    // for (int i = 1; i <= 3; i++)
    // {
    //     move(p->GetCoordinates().y * 4 + i, p->GetCoordinates().x * 5 + 1);
    //     printw("OOO");
    // }
}
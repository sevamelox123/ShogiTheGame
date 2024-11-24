#pragma once

#include <cstdio>
#include <ncurses.h>
#include "structs.h"
#include "shoga.h"


class Desk
{
public:
    Desk();
    void printDesk();
    void AddPiece(Piece*);


private:
    Piece *desk[9][9] = {nullptr};

};
#pragma once

#include <cstdio>
// #include <ncurses.h>
#include "structs.h"
#include "shoga.h"


class Desk
{
private:
    Piece *desk[9][9] = {nullptr};
public:
    Desk();
    void AddPiece(Piece*);
    Piece* GetPiece(Vector2D pos);
};
#pragma once

#include <ncurses.h>
#include "structs.h"

class Piece
{
protected:
    int x, y;
    Sides side;

public:
    Piece(int x, int y, Sides side);
    Vector2D GetCoordinates();
    const wchar_t symbol = 0;
};
class Pawn : public Piece
{
public:
    Pawn(int x, int y, Sides side) : Piece(x, y, side) {}
    const wchar_t symbol = L'歩';
};
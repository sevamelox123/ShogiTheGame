#pragma once

#include "structs.h"

class Piece
{
protected:
    int x, y;
    Sides side;
    // wchar_t symbol;
    int symbol;
public:
    Piece(int x, int y, Sides side);
    Vector2D GetCoordinates();
    int GetSymbol();
};
class Pawn : public Piece
{
public:
    Pawn(int x, int y, Sides side) : Piece(x, y, side) {
        symbol = L'歩';
    }
};
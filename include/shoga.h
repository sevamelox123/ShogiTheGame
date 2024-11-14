#ifndef SHOGA_H
#define SHOGA_H

#include <ncurses.h>
#include "structs.h"

class Piece
{
private:
    int x, y;
    Sides side;

public:
    Piece(int x, int y, Sides side);
    int GetCoordinates();
};
class Pawn : public Piece
{
public:
    Pawn(int x, int y, Sides side) : Piece(x, y, side) {}
};

#endif
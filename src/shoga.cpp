#include <ncurses.h>
#include "shoga.h"

Piece::Piece(int _x, int _y, Sides _side)
{
    x = _x;
    y = _y;
    side = _side;
}

Vector2D Piece::GetCoordinates()
{
    return Vector2D{x, y};
}

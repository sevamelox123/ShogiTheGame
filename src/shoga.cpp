#include <ncurses.h>
#include "shoga.h"

Piece::Piece(int _x, int _y, Sides _side) {
    x = _x;
    y = _y;
    side = _side;
}

int Piece::GetCoordinates() {
    return x,y;
}

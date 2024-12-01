#include <cstdio>
// #include <ncurses.h>
#include "desk.h"
#include <vector>

Desk::Desk()
{
}

void Desk::AddPiece(Piece *p)
{
    desk[p->GetCoordinates().y][p->GetCoordinates().x] = p;
}

Piece* Desk::GetPiece(Vector2D pos) {
    return desk[pos.y][pos.x];
}
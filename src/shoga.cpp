// #include <ncurses.h>
#include "shoga.h"
#include "desk.h"

inline bool IsValidCoordinates(int x, int y) {
    return (x >= 0 && x <= 8 && y >= 0 && y <= 8);
}

inline bool IsValidCoordinates(Vector2D pos) {
    return (pos.x >= 0 && pos.x <= 8 && pos.y >= 0 && pos.y <= 8);
}

Piece::Piece(int _x = 0, int _y = 0, Sides _side = Sides::Sente)
{
    x = _x;
    y = _y;
    side = _side;
}

Vector2D Piece::GetCoordinates()
{
    return Vector2D{x, y};
}

wchar_t Piece::GetSymbol()
{
    return symbol;
}

Sides Piece::GetSide() {
    return side;
}

Moves Piece::GetAvaliableMoves(void* desk) {
    return Moves{0, nullptr};
}

PieceForms Piece::GetAvaliableForms(void* desk, Vector2D pos) {
    return PieceForms{nullptr, nullptr};
}

Pawn::Pawn(int x, int y, Sides side) : Piece(x, y, side) {
    symbol = L'歩';
}

Moves Pawn::GetAvaliableMoves(void* desk) {
    int y_delta;

    if (side == Sides::Sente) {
        y_delta = -1;
    }
    else {
        y_delta = 1;
    }

    if (IsValidCoordinates(x, y + y_delta)) {
        if (static_cast<Desk*>(desk)->GetPiece(Vector2D{x, y + y_delta}) == nullptr || static_cast<Desk*>(desk)->GetPiece(Vector2D{x, y + y_delta})->GetSide() != side) {
            return Moves{1, new Vector2D{x, y + y_delta}};
        }
    }
    else {
        return Moves{0, nullptr};
    }

    return Moves{0, nullptr};
}
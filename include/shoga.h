#pragma once

#include "structs.h"

inline bool IsValidCoordinates(int x, int y);
inline bool IsValidCoordinates(Vector2D pos);

class Piece
{
protected:
    int x, y;
    Sides side;
    wchar_t symbol;
public:
    Piece(int x, int y, Sides side);
    Vector2D GetCoordinates();
    wchar_t GetSymbol();
    virtual Moves GetAvaliableMoves(void* desk);
    virtual PieceForms GetAvaliableForms(void* desk, Vector2D pos);
    Sides GetSide();
};

class Pawn : public Piece
{
public:
    Pawn(int x, int y, Sides side);
    Moves GetAvaliableMoves(void* desk);
};
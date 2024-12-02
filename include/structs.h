#pragma once

enum class Sides {Sente = 1, Gote = 2}; // Black and white (in written order)
enum class AlphaCoordinates {a = 0, b = 1, c = 2, d = 3, e = 4, f = 5, g = 6, h = 7, i = 8};

struct Vector2D {
    int x;
    int y;
};

struct Moves {
    int moves_count;
    Vector2D* moves;
};

struct PieceForms {
    void* form1;
    void* form2;
};

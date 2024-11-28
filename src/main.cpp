// #include <ncurses.h> 
#include <locale.h>
#include "desk.h"
#include "shoga.h"
#include <cstdio>
#include "raylib.h"

const int screenWidth = 800;
const int screenHeight = 450; 

int main(int argc,char *argv[])
{
  setlocale(LC_ALL, "");
  // initscr();
  
  // Pawn pawn = Pawn(2, 2, Sides::先手);

  // int row, col;
  // getmaxyx(stdscr, row, col);
  // move(row, col);
  // refresh();
  // Desk desk = Desk();
  // desk.printDesk();
  // desk.AddPiece(&pawn);
  // desk.printDesk();
  // getch();
  
  // endwin(); 

  InitWindow(screenWidth, screenHeight, "raylib [text] example - raylib fonts");
  
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    
  }

  CloseWindow(); 

  return 0;
}
#include <ncurses.h> 
#include <locale.h>
#include "desk.h"
#include "shoga.h"
#include <cstdio>

int main(int argc,char *argv[])
{
  setlocale(LC_ALL, "");
  initscr();
  
  Pawn pawn = Pawn(2, 2, Sides::先手);

  int row, col;
  getmaxyx(stdscr, row, col);
  move(row, col);
  refresh();
  Desk desk = Desk();
  desk.printDesk();
  desk.AddPiece(&pawn);
  desk.printDesk();
  getch();
  
  endwin(); 
  return 0;
}
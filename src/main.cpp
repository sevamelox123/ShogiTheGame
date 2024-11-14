#include <ncurses.h> 
#include "desk.h"
#include "shoga.h"
#include <cstdio>

int main(int argc,char *argv[])
{
  initscr();
  
  Pawn pawn = Pawn(5, 0, Sides::先手);

  int row, col;
  getmaxyx(stdscr, row, col);
  move(row, col);
  refresh();
  Desk desk = Desk();
  desk.printDesk();
  getch();
  
  endwin(); 
  return 0;
}
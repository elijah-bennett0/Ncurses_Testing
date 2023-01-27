#include <curses.h>
#include <stdlib.h>
#include <stdio.h>

// addstr -> prints string
// addch  -> prints single char
// printw -> equivalent to printf
int main(void) {
	initscr();

	

	long cols = strtol(getenv("COLUMNS"), NULL, 10);
	long lines = strtol(getenv("LINES"), NULL, 10);
	

	int x, y;
	x = 10;
	y = 10;


	WINDOW* win = newwin(10, 10, y, x);


	refresh();


	box(win, 0, 0);
	mvwprintw(win, 1, 1, "Box Test");
	wrefresh(win);


	getch();
	endwin();

	return 0;
}

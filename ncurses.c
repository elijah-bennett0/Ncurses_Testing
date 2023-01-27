#include <curses.h>
#include <stdlib.h>
#include <stdio.h>

// addstr -> prints string
// addch  -> prints single char
// printw -> equivalent to printf
int main(void) {
	initscr();

	/*

	const char* columns_str = getenv("COLUMNS");
	const char* lines_str = getenv("LINES");

        int cols = strtol(columns_str, NULL, 10);
	int lines = strtol(lines_str, NULL, 10);
	*/


	int x = 0, y = 0;

	FILE* p;
	int ch;


	p = popen("python3 test.py", "r");

	if (p == NULL) {

		addstr("Bad");
		refresh();

	}


	WINDOW* win = newwin(LINES, COLS, y, x);

	box(win, 0, 0);
	mvwprintw(win, 1, 1, "Box Test");

//	wmove(win, 150, 150);
	refresh(); // DONT REMOVE

	int i = 0;
	while ((ch=fgetc(p)) != EOF) {
		mvwaddch(win, 50, 50+i, ch);
		i++;
	}
	pclose(p);

	refresh();
	wrefresh(win);
	getch();
	endwin();

	return 0;
}

#include <conio.h>
#include <stdio.h>

#define clear clrscr
#define get_char getch
#define text_color textcolor
#define printf cprintf

int ROWS = 24, COLUMNS = 80; /* Just guesses */
char _t_temp = 0;
int _t_index = 0;
char _t_result = 0;

void startup() {
	/*
	This seems to get the size in PIXELS, using graphics.h
	(it was an attempt to get the size in CHARACTERS), which
	is why I commented it out, but I still want to save it for future reference.

	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	ROWS = getmaxx();
	COLUMNS = getmaxy();
	closegraph();
	*/
}

void done() {
	/* Does nothing (yet) in DOS */
}

void center(unsigned char length, const char *string, ...) {
	length = (COLUMNS - length) / 2;
	for (_t_index = 0; _t_index < length; _t_index++)
		printf(" ");
	printf(string, ...);
	printf("\r\n");
}

void get_string(char *str, int max) {
	fgets(str, max, stdin);
	for (_t_index=0; _t_index<max; _t_index++)
		if (str[_t_index] == '\r' || str[_t_index] == '\n')
			str[_t_index] = 0;
}

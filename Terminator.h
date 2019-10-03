#ifndef _TERMINATOR_H
#define _TERMINATOR_H

#include <stdio.h>

#define VIC20		0
#define C64			1
#define LINUX		2
#define WINDOWS		3

char _t_temp = 0;
int _t_index = 0;
char _t_result = 0;
va_list va_args;

#if BUILD_TARGET == VIC20

#include <6502.h>
#include <conio.h>

#define ROWS 23
#define COLUMNS 22
#define BLACK 0
#define WHITE 1
#define RED 2
#define GREEN 5
#define BLUE 6
#define CYAN 3
#define MAGENTA 4
#define YELLOW 7

#define clear clrscr
void startup() {
	textcolor(WHITE);
	bgcolor(BLACK);
	bordercolor(BLACK);
}
void done() {
	textcolor(BLUE);
	bgcolor(WHITE);
	bordercolor(CYAN);
}
#define text_color textcolor
void get_string(char *str, int max) {
	// Not supported on the VIC-20.
	// Segment "RODATA" (or sometimes "DATA" or sometimes "BSS") Mumbo-McJumbo von Gobble-dee-goozenberg :P
	// (meaning: memory overflow problem only the cc65 devs can understand or dream to resolve.  Can you be more cryptic dude?)
}
char get_char() {
	cursor(1);
	while (_t_temp = cgetc()) {
		cputc(_t_temp);
		if (_t_temp == '\n')
			return _t_result;
		_t_result = _t_temp;
	}
	return _t_temp;
}
void center(unsigned char length, const char *string, ...) {
	// If the VIC-20 or cc65 or some mysterious combination
	// can't even manage get_string, no way this will ever work!
}
#define printf cprintf

#elif BUILD_TARGET == C64

#include <6502.h>
#include <peekpoke.h>

#define ROWS 25
#define COLUMNS 40
#define BLACK 0
#define WHITE 1
#define RED 2
#define GREEN 3
#define BLUE 4
#define CYAN 5
#define MAGENTA 6
#define YELLOW 7

struct regs _sysParam1;
void clear() {
	_sysParam1.pc = 0xE544;
	_sys(&_sysParam1);
}
void startup() {
	POKE(53280L, 0);
	POKE(53281L, 0);
	POKE(646, 1);
}
void done() {
	POKE(53280L, 14);
	POKE(53281L, 6);
	POKE(646, 14);
}
void text_color(char color) {
	/*
	For the full list of color codes,
	see http://sta.c64.org/cbm64col.html
	*/
	switch (color) {
	case BLACK:
	case WHITE:
	case RED:
		POKE(646, color); break;
	case GREEN:
		POKE(646, 5); break;
	case BLUE:
		POKE(646, 6); break;
	case MAGENTA:
		POKE(646, 10); break;
	case CYAN:
		POKE(646, 3); break;
	case YELLOW:
		POKE(646, 7); break;
	}
}
void get_string(char *str, int max) {
	_t_index = 0;
	while (_t_temp = getchar()) {
		if (_t_temp == '\n') break;
		if (_t_index < max - 1)
			str[_t_index] = _t_temp;
		_t_index++;
	}
}
char get_char() {
	while (_t_temp = getchar()) {
		if (_t_temp == '\n')
			return _t_result;
		else _t_result = _t_temp;
	}
	return _t_temp;
}
void center(unsigned char length, const char *string, ...) {
	length = (COLUMNS - length) / 2;
	for (_t_index = 0; _t_index < length; _t_index++)
		printf(" ");
	va_start (va_args, string);
	vprintf(string, va_args);
	va_end (va_args);
	printf("\n");
}

#elif BUILD_TARGET == LINUX

#include <sys/ioctl.h>
#include <unistd.h>
#include <stdarg.h>

unsigned char ROWS = 80;
unsigned char COLUMNS = 20;
#define BLACK 0
#define WHITE 1
#define RED 2
#define GREEN 3
#define BLUE 4
#define CYAN 5
#define MAGENTA 6
#define YELLOW 7

void clear() { printf("\033c"); }
void startup() {
	struct winsize size;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
	ROWS = size.ws_row;
	COLUMNS = size.ws_col;
}
void done() {

}
void text_color(char color) {
	/*
	Dark gray               "\e[1;030m"
	Dark red                "\e[0;031m"
	Dark green              "\e[0;032m"
	Dark yellow (gold?)     "\e[0;033m"
	Dark blue               "\e[0;034m"
	Dark magenta (purple?)  "\e[0;035m"
	Dark cyan (teal?)       "\e[0;036m"
	Gray (lighter?)         "\e[0;037m"
	Microsoft naming conventions for ya. :)
	*/
	switch (color) {
	case BLACK:
		printf("\e[0;030m"); break;
	case WHITE:
		printf("\e[1;037m"); break;
	case RED:
		printf("\e[1;031m"); break;
	case GREEN:
		printf("\e[1;032m"); break;
	case BLUE:
		printf("\e[1;034m"); break;
	case MAGENTA:
		printf("\e[1;035m"); break;
	case CYAN:
		printf("\e[1;036m"); break;
	case YELLOW:
		printf("\e[1;033m"); break;
	}
}
void get_string(char *str, int max) {
	_t_index = 0;
	while (_t_temp = getchar()) {
		if (_t_temp == '\n') break;
		if (_t_index < max - 1)
			str[_t_index] = _t_temp;
		_t_index++;
	}
}
char get_char() {
	while (_t_temp = getchar()) {
		if (_t_temp == '\n')
			return _t_result;
		else _t_result = _t_temp;
	}
	return _t_temp;
}
void center(unsigned char length, const char *string, ...) {
	length = (COLUMNS - length) / 2;
	for (_t_index = 0; _t_index < length; _t_index++)
		printf(" ");
	va_start (va_args, string);
	vprintf(string, va_args);
	va_end (va_args);
	printf("\n");
}

#elif BUILD_TARGET == WINDOWS

#include <string.h>
#include <Windows.h>

unsigned char ROWS = 80;
unsigned char COLUMNS = 20;
#define BLACK 0
#define WHITE 1
#define RED 2
#define GREEN 3
#define BLUE 4
#define CYAN 5
#define MAGENTA 6
#define YELLOW 7

void clear() {
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	unsigned long written;
	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
}
void startup() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	COLUMNS = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	ROWS = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}
void done() {

}
void text_color(char color) {
	unsigned short flags = 0;
	if (color == BLACK) flags = 0;
	else if (color == WHITE) flags = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
	else if (color == RED) flags = FOREGROUND_RED | FOREGROUND_INTENSITY;
	else if (color == GREEN) flags = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
	else if (color == BLUE) flags = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
	else if (color == CYAN) flags = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
	else if (color == MAGENTA) flags = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
	else if (color == YELLOW) flags = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), flags);
}
void get_string(char *str, int max) {
	_t_index = 0;
	while (_t_temp = getchar()) {
		if (_t_temp == '\n') break;
		if (_t_index < max - 1)
			str[_t_index] = _t_temp;
		_t_index++;
	}
}
char get_char() {
	while (_t_temp = getchar()) {
		if (_t_temp == '\n')
			return _t_result;
		else _t_result = _t_temp;
	}
	return _t_temp;
}
void center(unsigned char length, const char *string, ...) {
	length = (COLUMNS - length) / 2;
	for (_t_index = 0; _t_index < length; _t_index++)
		printf(" ");
	va_start (va_args, string);
	vprintf(string, va_args);
	va_end (va_args);
	printf("\n");
}

#else

void clear() { printf("BUILD_TARGET not set or need to define clear() for a new platform."); }
void startup() {
	printf("BUILD_TARGET not set or need to define startup() for a new platform.");
}
void done() {
	printf("BUILD_TARGET not set or need to define done() for a new platform.");
}
void text_color(char color) {
	printf("BUILD_TARGET not set or need to define text_color() for a new platform.");
}
void get_string(char *str, int max) {
	_t_index = 0;
	while (_t_temp = getchar()) {
		if (_t_temp == '\n') break;
		if (_t_index < max - 1)
			str[_t_index] = _t_temp;
		_t_index++;
	}
}
char get_char() {
	while (_t_temp = getchar()) {
		if (_t_temp == '\n')
			return _t_result;
		else _t_result = _t_temp;
	}
	return _t_temp;
}
void center(unsigned char length, const char *string, ...) {
	length = (COLUMNS - length) / 2;
	for (_t_index = 0; _t_index < length; _t_index++)
		printf(" ");
	va_start (va_args, string);
	vprintf(string, va_args);
	va_end (va_args);
	printf("\n");
}

#endif
#endif

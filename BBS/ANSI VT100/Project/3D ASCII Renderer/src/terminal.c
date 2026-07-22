#include "terminal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
static HANDLE hConsole;
static DWORD originalMode;
#else
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
static struct termios original_termios;
#endif

static int initialized = 0;

void term_init(void) {
    if (initialized) return;
    
#ifdef _WIN32
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleMode(hConsole, &originalMode);
    SetConsoleMode(hConsole, originalMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
#else
    tcgetattr(STDIN_FILENO, &original_termios);
    struct termios new_termios = original_termios;
    new_termios.c_lflag &= ~(ICANON | ECHO);
    new_termios.c_cc[VMIN] = 0;
    new_termios.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
#endif
    
    printf("\x1b[?25l");
    term_clear();
    initialized = 1;
}

void term_restore(void) {
    if (!initialized) return;
    
    printf("\x1b[?25h");
    printf("\x1b[0m");
    term_clear();
    term_move(1, 1);
    term_flush();
    
#ifdef _WIN32
    SetConsoleMode(hConsole, originalMode);
#else
    tcsetattr(STDIN_FILENO, TCSANOW, &original_termios);
#endif
    
    initialized = 0;
}

void term_clear(void) {
    printf("\x1b[2J");
}

void term_move(int row, int col) {
    printf("\x1b[%d;%dH", row, col);
}

void term_hide_cursor(void) {
    printf("\x1b[?25l");
}

void term_show_cursor(void) {
    printf("\x1b[?25h");
}

void term_fg(int color) {
    printf("\x1b[%dm", 30 + color);
}

void term_bg(int color) {
    printf("\x1b[%dm", 40 + color);
}

void term_reset(void) {
    printf("\x1b[0m");
}

void term_bold(void) {
    printf("\x1b[1m");
}

void term_underline(void) {
    printf("\x1b[4m");
}

void term_putchar_at(int row, int col, char c) {
    term_move(row, col);
    putchar(c);
}

void term_puts_at(int row, int col, const char *s) {
    term_move(row, col);
    printf("%s", s);
}

TerminalSize term_get_size(void) {
    TerminalSize size = {80, 24};
    
#ifdef _WIN32
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(h, &csbi)) {
        size.width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        size.height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    }
#else
    struct winsize ws;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == 0) {
        size.width = ws.ws_col;
        size.height = ws.ws_row;
    }
#endif
    
    return size;
}

void term_flush(void) {
    fflush(stdout);
}

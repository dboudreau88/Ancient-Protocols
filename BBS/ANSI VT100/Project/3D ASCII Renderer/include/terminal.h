#ifndef TERMINAL_H
#define TERMINAL_H

#include <stdio.h>

typedef struct {
    int width;
    int height;
} TerminalSize;

// Initialize terminal for raw mode
void term_init(void);

// Restore terminal to original state
void term_restore(void);

// Clear the entire screen
void term_clear(void);

// Move cursor to position (1-indexed)
void term_move(int row, int col);

// Hide cursor
void term_hide_cursor(void);

// Show cursor
void term_show_cursor(void);

// Set foreground color (0-7)
void term_fg(int color);

// Set background color (0-7)
void term_bg(int color);

// Reset all attributes
void term_reset(void);

// Enable bold
void term_bold(void);

// Enable underline
void term_underline(void);

// Print character at position
void term_putchar_at(int row, int col, char c);

// Print string at position
void term_puts_at(int row, int col, const char *s);

// Get terminal size
TerminalSize term_get_size(void);

// Flush output buffer
void term_flush(void);

#endif

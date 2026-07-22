#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

typedef struct {
    char *chars;
    int *colors;
    int *bgcolors;
    int width;
    int height;
} FrameBuffer;

// Create a new framebuffer
FrameBuffer *fb_create(int width, int height);

// Free framebuffer
void fb_free(FrameBuffer *fb);

// Clear framebuffer to defaults
void fb_clear(FrameBuffer *fb);

// Set character at position
void fb_set_char(FrameBuffer *fb, int x, int y, char c);

// Set foreground color at position
void fb_set_color(FrameBuffer *fb, int x, int y, int color);

// Set background color at position
void fb_set_bgcolor(FrameBuffer *fb, int x, int y, int bgcolor);

// Get character at position
char fb_get_char(FrameBuffer *fb, int x, int y);

// Get foreground color at position
int fb_get_color(FrameBuffer *fb, int x, int y);

// Render framebuffer to terminal
void fb_render(FrameBuffer *fb);

// Compare two framebuffers (for dirty region tracking)
int fb_compare(FrameBuffer *a, FrameBuffer *b);

// Copy framebuffer b to a
void fb_copy(FrameBuffer *a, FrameBuffer *b);

#endif

#ifndef RENDERER_H
#define RENDERER_H

#include "framebuffer.h"

// ASCII shading characters from darkest to brightest
static const char SHADE_CHARS[] = " .:-=+oO#@";
static const int SHADE_COUNT = 10;

// Get character for intensity (0.0 to 1.0)
char renderer_shade_char(float intensity);

// Get color for intensity (maps to VT100 colors)
int renderer_shade_color(float intensity);

// Draw a line on the framebuffer
void renderer_line(FrameBuffer *fb, int x0, int y0, int x1, int y1, char c, int color);

// Draw a filled triangle
void renderer_triangle(FrameBuffer *fb, 
                       int x0, int y0, 
                       int x1, int y1, 
                       int x2, int y2, 
                       char c, int color);

// Draw a shaded triangle with per-pixel intensity
void renderer_triangle_shaded(FrameBuffer *fb,
                              int x0, int y0, float i0,
                              int x1, int y1, float i1,
                              int x2, int y2, float i2);

// Draw a rectangle outline
void renderer_rect(FrameBuffer *fb, int x, int y, int w, int h, char c, int color);

// Draw a filled rectangle
void renderer_rect_filled(FrameBuffer *fb, int x, int y, int w, int h, char c, int color);

// Draw a circle (midpoint algorithm)
void renderer_circle(FrameBuffer *fb, int cx, int cy, int r, char c, int color);

#endif

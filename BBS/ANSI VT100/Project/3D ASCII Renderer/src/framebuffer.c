#include "framebuffer.h"
#include "terminal.h"
#include <stdlib.h>
#include <string.h>

FrameBuffer *fb_create(int width, int height) {
    FrameBuffer *fb = (FrameBuffer *)malloc(sizeof(FrameBuffer));
    if (!fb) return NULL;
    
    fb->width = width;
    fb->height = height;
    fb->chars = (char *)calloc(width * height, sizeof(char));
    fb->colors = (int *)calloc(width * height, sizeof(int));
    fb->bgcolors = (int *)calloc(width * height, sizeof(int));
    
    if (!fb->chars || !fb->colors || !fb->bgcolors) {
        free(fb->chars);
        free(fb->colors);
        free(fb->bgcolors);
        free(fb);
        return NULL;
    }
    
    fb_clear(fb);
    return fb;
}

void fb_free(FrameBuffer *fb) {
    if (!fb) return;
    free(fb->chars);
    free(fb->colors);
    free(fb->bgcolors);
    free(fb);
}

void fb_clear(FrameBuffer *fb) {
    if (!fb) return;
    memset(fb->chars, ' ', fb->width * fb->height);
    memset(fb->colors, 7, fb->width * fb->height);
    memset(fb->bgcolors, 0, fb->width * fb->height);
}

static inline int fb_index(FrameBuffer *fb, int x, int y) {
    return y * fb->width + x;
}

void fb_set_char(FrameBuffer *fb, int x, int y, char c) {
    if (!fb || x < 0 || x >= fb->width || y < 0 || y >= fb->height) return;
    fb->chars[fb_index(fb, x, y)] = c;
}

void fb_set_color(FrameBuffer *fb, int x, int y, int color) {
    if (!fb || x < 0 || x >= fb->width || y < 0 || y >= fb->height) return;
    fb->colors[fb_index(fb, x, y)] = color;
}

void fb_set_bgcolor(FrameBuffer *fb, int x, int y, int bgcolor) {
    if (!fb || x < 0 || x >= fb->width || y < 0 || y >= fb->height) return;
    fb->bgcolors[fb_index(fb, x, y)] = bgcolor;
}

char fb_get_char(FrameBuffer *fb, int x, int y) {
    if (!fb || x < 0 || x >= fb->width || y < 0 || y >= fb->height) return ' ';
    return fb->chars[fb_index(fb, x, y)];
}

int fb_get_color(FrameBuffer *fb, int x, int y) {
    if (!fb || x < 0 || x >= fb->width || y < 0 || y >= fb->height) return 7;
    return fb->colors[fb_index(fb, x, y)];
}

void fb_render(FrameBuffer *fb) {
    if (!fb) return;
    
    term_move(1, 1);
    
    int last_color = -1;
    int last_bg = -1;
    
    for (int y = 0; y < fb->height; y++) {
        for (int x = 0; x < fb->width; x++) {
            int idx = fb_index(fb, x, y);
            int color = fb->colors[idx];
            int bg = fb->bgcolors[idx];
            char c = fb->chars[idx];
            
            if (color != last_color) {
                term_fg(color);
                last_color = color;
            }
            if (bg != last_bg) {
                term_bg(bg);
                last_bg = bg;
            }
            
            putchar(c);
        }
        if (y < fb->height - 1) {
            putchar('\n');
        }
    }
    
    term_flush();
}

int fb_compare(FrameBuffer *a, FrameBuffer *b) {
    if (!a || !b) return 0;
    if (a->width != b->width || a->height != b->height) return 0;
    
    int size = a->width * a->height;
    int diff = 0;
    
    for (int i = 0; i < size; i++) {
        if (a->chars[i] != b->chars[i] ||
            a->colors[i] != b->colors[i] ||
            a->bgcolors[i] != b->bgcolors[i]) {
            diff++;
        }
    }
    
    return diff;
}

void fb_copy(FrameBuffer *a, FrameBuffer *b) {
    if (!a || !b) return;
    if (a->width != b->width || a->height != b->height) return;
    
    int size = a->width * a->height;
    memcpy(a->chars, b->chars, size * sizeof(char));
    memcpy(a->colors, b->colors, size * sizeof(int));
    memcpy(a->bgcolors, b->bgcolors, size * sizeof(int));
}

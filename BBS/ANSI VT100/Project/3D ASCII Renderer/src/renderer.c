#include "renderer.h"
#include <stdlib.h>
#include <math.h>

char renderer_shade_char(float intensity) {
    if (intensity < 0.0f) intensity = 0.0f;
    if (intensity > 1.0f) intensity = 1.0f;
    
    int index = (int)(intensity * (SHADE_COUNT - 1));
    return SHADE_CHARS[index];
}

int renderer_shade_color(float intensity) {
    if (intensity < 0.0f) intensity = 0.0f;
    if (intensity > 1.0f) intensity = 1.0f;
    
    if (intensity < 0.2f) return 0;
    if (intensity < 0.4f) return 1;
    if (intensity < 0.6f) return 3;
    if (intensity < 0.8f) return 6;
    return 7;
}

void renderer_line(FrameBuffer *fb, int x0, int y0, int x1, int y1, char c, int color) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;
    
    while (1) {
        fb_set_char(fb, x0, y0, c);
        fb_set_color(fb, x0, y0, color);
        
        if (x0 == x1 && y0 == y1) break;
        
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

void renderer_triangle(FrameBuffer *fb, 
                       int x0, int y0, 
                       int x1, int y1, 
                       int x2, int y2, 
                       char c, int color) {
    int bbox_min_x = x0, bbox_min_y = y0;
    int bbox_max_x = x0, bbox_max_y = y0;
    
    if (x1 < bbox_min_x) bbox_min_x = x1;
    if (x2 < bbox_min_x) bbox_min_x = x2;
    if (x1 > bbox_max_x) bbox_max_x = x1;
    if (x2 > bbox_max_x) bbox_max_x = x2;
    
    if (y1 < bbox_min_y) bbox_min_y = y1;
    if (y2 < bbox_min_y) bbox_min_y = y2;
    if (y1 > bbox_max_y) bbox_max_y = y1;
    if (y2 > bbox_max_y) bbox_max_y = y2;
    
    for (int y = bbox_min_y; y <= bbox_max_y; y++) {
        for (int x = bbox_min_x; x <= bbox_max_x; x++) {
            int d0x = x1 - x0, d0y = y1 - y0;
            int d1x = x2 - x1, d1y = y2 - y1;
            int d2x = x0 - x2, d2y = y0 - y2;
            
            int s0 = (x - x0) * d0y - (y - y0) * d0x;
            int s1 = (x - x1) * d1y - (y - y1) * d1x;
            int s2 = (x - x2) * d2y - (y - y2) * d2x;
            
            int has_neg = (s0 < 0) || (s1 < 0) || (s2 < 0);
            int has_pos = (s0 > 0) || (s1 > 0) || (s2 > 0);
            
            if (!(has_neg && has_pos)) {
                fb_set_char(fb, x, y, c);
                fb_set_color(fb, x, y, color);
            }
        }
    }
}

void renderer_triangle_shaded(FrameBuffer *fb,
                              int x0, int y0, float i0,
                              int x1, int y1, float i1,
                              int x2, int y2, float i2) {
    int bbox_min_x = x0, bbox_min_y = y0;
    int bbox_max_x = x0, bbox_max_y = y0;
    
    if (x1 < bbox_min_x) bbox_min_x = x1;
    if (x2 < bbox_min_x) bbox_min_x = x2;
    if (x1 > bbox_max_x) bbox_max_x = x1;
    if (x2 > bbox_max_x) bbox_max_x = x2;
    
    if (y1 < bbox_min_y) bbox_min_y = y1;
    if (y2 < bbox_min_y) bbox_min_y = y2;
    if (y1 > bbox_max_y) bbox_max_y = y1;
    if (y2 > bbox_max_y) bbox_max_y = y2;
    
    for (int y = bbox_min_y; y <= bbox_max_y; y++) {
        for (int x = bbox_min_x; x <= bbox_max_x; x++) {
            int d0x = x1 - x0, d0y = y1 - y0;
            int d1x = x2 - x1, d1y = y2 - y1;
            int d2x = x0 - x2, d2y = y0 - y2;
            
            int s0 = (x - x0) * d0y - (y - y0) * d0x;
            int s1 = (x - x1) * d1y - (y - y1) * d1x;
            int s2 = (x - x2) * d2y - (y - y2) * d2x;
            
            int has_neg = (s0 < 0) || (s1 < 0) || (s2 < 0);
            int has_pos = (s0 > 0) || (s1 > 0) || (s2 > 0);
            
            if (!(has_neg && has_pos)) {
                float area = (float)abs(d0x * d1y - d0y * d1x);
                if (area < 1.0f) area = 1.0f;
                
                float w0 = (float)abs((x - x1) * (y2 - y1) - (x2 - x1) * (y - y1)) / area;
                float w1 = (float)abs((x - x2) * (y0 - y2) - (x0 - x2) * (y - y2)) / area;
                float w2 = 1.0f - w0 - w1;
                
                if (w0 < 0) w0 = 0;
                if (w1 < 0) w1 = 0;
                if (w2 < 0) w2 = 0;
                
                float intensity = w0 * i0 + w1 * i1 + w2 * i2;
                char c = renderer_shade_char(intensity);
                int color = renderer_shade_color(intensity);
                
                fb_set_char(fb, x, y, c);
                fb_set_color(fb, x, y, color);
            }
        }
    }
}

void renderer_rect(FrameBuffer *fb, int x, int y, int w, int h, char c, int color) {
    renderer_line(fb, x, y, x + w - 1, y, c, color);
    renderer_line(fb, x + w - 1, y, x + w - 1, y + h - 1, c, color);
    renderer_line(fb, x + w - 1, y + h - 1, x, y + h - 1, c, color);
    renderer_line(fb, x, y + h - 1, x, y, c, color);
}

void renderer_rect_filled(FrameBuffer *fb, int x, int y, int w, int h, char c, int color) {
    for (int j = y; j < y + h; j++) {
        for (int i = x; i < x + w; i++) {
            fb_set_char(fb, i, j, c);
            fb_set_color(fb, i, j, color);
        }
    }
}

void renderer_circle(FrameBuffer *fb, int cx, int cy, int r, char c, int color) {
    int x = r;
    int y = 0;
    int err = 0;
    
    while (x >= y) {
        fb_set_char(fb, cx + x, cy + y, c);
        fb_set_char(fb, cx + y, cy + x, c);
        fb_set_char(fb, cx - y, cy + x, c);
        fb_set_char(fb, cx - x, cy + y, c);
        fb_set_char(fb, cx - x, cy - y, c);
        fb_set_char(fb, cx - y, cy - x, c);
        fb_set_char(fb, cx + y, cy - x, c);
        fb_set_char(fb, cx + x, cy - y, c);
        
        fb_set_color(fb, cx + x, cy + y, color);
        fb_set_color(fb, cx + y, cy + x, color);
        fb_set_color(fb, cx - y, cy + x, color);
        fb_set_color(fb, cx - x, cy + y, color);
        fb_set_color(fb, cx - x, cy - y, color);
        fb_set_color(fb, cx - y, cy - x, color);
        fb_set_color(fb, cx + y, cy - x, color);
        fb_set_color(fb, cx + x, cy - y, color);
        
        y++;
        if (err <= 0) {
            err += 2 * y + 1;
        }
        if (err > 0) {
            x--;
            err -= 2 * x + 1;
        }
    }
}

#include "terminal.h"
#include "framebuffer.h"
#include "renderer.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#define SLEEP_MS(ms) Sleep(ms)
#else
#include <unistd.h>
#include <sys/select.h>
#define SLEEP_MS(ms) usleep((ms) * 1000)
#endif

static int key_pressed(void) {
#ifdef _WIN32
    return _kbhit();
#else
    fd_set fds;
    struct timeval tv = {0, 0};
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    return select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv) > 0;
#endif
}

static char get_key(void) {
#ifdef _WIN32
    return _getch();
#else
    char c;
    read(STDIN_FILENO, &c, 1);
    return c;
#endif
}

int main(void) {
    TerminalSize size = term_get_size();
    
    term_init();
    term_hide_cursor();
    
    FrameBuffer *fb = fb_create(size.width, size.height);
    if (!fb) {
        term_restore();
        fprintf(stderr, "Failed to create framebuffer\n");
        return 1;
    }
    
    float rotation = 0.0f;
    int running = 1;
    
    while (running) {
        fb_clear(fb);
        
        float cx = size.width / 2.0f;
        float cy = size.height / 2.0f;
        
        float cos_r = cosf(rotation);
        float sin_r = sinf(rotation);
        
        float cube_size = 8.0f;
        
        float verts[8][3] = {
            {-1, -1, -1}, { 1, -1, -1}, { 1,  1, -1}, {-1,  1, -1},
            {-1, -1,  1}, { 1, -1,  1}, { 1,  1,  1}, {-1,  1,  1}
        };
        
        int edges[12][2] = {
            {0,1}, {1,2}, {2,3}, {3,0},
            {4,5}, {5,6}, {6,7}, {7,4},
            {0,4}, {1,5}, {2,6}, {3,7}
        };
        
        for (int i = 0; i < 12; i++) {
            int v0 = edges[i][0];
            int v1 = edges[i][1];
            
            float x0 = verts[v0][0] * cube_size;
            float y0 = verts[v0][1] * cube_size;
            float z0 = verts[v0][2] * cube_size;
            
            float x1 = verts[v1][0] * cube_size;
            float y1 = verts[v1][1] * cube_size;
            float z1 = verts[v1][2] * cube_size;
            
            float rx0 = x0 * cos_r - z0 * sin_r;
            float rz0 = x0 * sin_r + z0 * cos_r;
            
            float rx1 = x1 * cos_r - z1 * sin_r;
            float rz1 = x1 * sin_r + z1 * cos_r;
            
            float depth0 = rz0 + 20.0f;
            float depth1 = rz1 + 20.0f;
            
            float sx0 = cx + rx0 * 4.0f / depth0 * 10.0f;
            float sy0 = cy + y0 * 2.0f / depth0 * 10.0f;
            float sx1 = cx + rx1 * 4.0f / depth1 * 10.0f;
            float sy1 = cy + y1 * 2.0f / depth1 * 10.0f;
            
            float brightness0 = 1.0f - (depth0 - 10.0f) / 20.0f;
            float brightness1 = 1.0f - (depth1 - 10.0f) / 20.0f;
            if (brightness0 < 0.1f) brightness0 = 0.1f;
            if (brightness1 < 0.1f) brightness1 = 0.1f;
            
            int color = renderer_shade_color((brightness0 + brightness1) / 2.0f);
            char c = renderer_shade_char((brightness0 + brightness1) / 2.0f);
            
            renderer_line(fb, (int)sx0, (int)sy0, (int)sx1, (int)sy1, c, color);
        }
        
        char status[64];
        snprintf(status, sizeof(status), "3D ASCII Renderer | Rotation: %.1f | Press Q to quit", 
                 rotation * 180.0f / 3.14159f);
        fb_set_color(fb, 0, 0, 2);
        for (int i = 0; status[i]; i++) {
            fb_set_char(fb, i, 0, status[i]);
            fb_set_color(fb, i, 0, 2);
        }
        
        fb_render(fb);
        
        SLEEP_MS(50);
        
        rotation += 0.05f;
        
        if (key_pressed()) {
            char key = get_key();
            if (key == 'q' || key == 'Q' || key == 27) {
                running = 0;
            }
        }
    }
    
    fb_free(fb);
    term_restore();
    
    printf("Goodbye!\n");
#ifdef _WIN32
    system("pause");
#else
    printf("Press any key to exit...\n");
    getchar();
#endif
    return 0;
}

#include "sense.h"
#include "display.h"
/* to get NULL definition */
#include <stddef.h>
#include <stdio.h>

#define BLACK 0x0000
#define WHITE 0xFFFF
pi_framebuffer_t *fb = NULL;


void allocate_fb(void) {
    if(fb==NULL) { 
        fb=getFrameBuffer();
    }
}

void free_fb(void) { 
    if(fb) {
        clearFrameBuffer(fb,BLACK);
	sleep(1);
        freeFrameBuffer(fb);
        fb=NULL;
    }
}

void display_dot(char x, char y) { 
    if(fb == NULL) {
	fprintf(stderr,"Tried to draw (%d,%d) to a non-existent frame buffer!\n",x,y);
	return;
    }
    sense_fb_bitmap_t *bm=fb->bitmap;
    clearFrameBuffer(fb,BLACK);
    fb->bitmap->pixel[y][x] = WHITE;
}

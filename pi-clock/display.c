#include <stdio.h>
#include "display.h"

#define WHITE 0xFFFF
#define DIM_WHITE 0x7BEF
#define BLACK 0x0000
#define BLUE 0x001F
#define DIM_BLUE 0x000F
#define GREEN 0x07E0
#define DIM_GREEN 0x0400
#define RED 0xF000
#define DIM_RED 0x7000

pi_framebuffer_t *fb = NULL;

int open_display() {
    fb = getFrameBuffer();
	if (fb == NULL) {
		return 0;
	}
	return 1;
}

void display_time(int hours, int minutes, int seconds, int hour_mode, int is_dim) {
	clearFrameBuffer(fb, BLACK);
	display_colons( hour_mode, is_dim );
    display_hours( hours, hour_mode, is_dim );
    display_minutes( minutes, hour_mode, is_dim );
    display_seconds( seconds, hour_mode, is_dim );

}

void display_colons(int hour_mode, int is_dim) {
    sense_fb_bitmap_t *bm=fb->bitmap;

	if (is_dim == 0) {

    	// Left Colons
	    bm->pixel[2][2]=WHITE;
    	bm->pixel[3][2]=WHITE;
	    bm->pixel[2][3]=WHITE;
    	bm->pixel[3][3]=WHITE;
    
    	bm->pixel[5][2]=WHITE;
    	bm->pixel[6][2]=WHITE;
    	bm->pixel[5][3]=WHITE;
    	bm->pixel[6][3]=WHITE;

    	// Right Colons
    	bm->pixel[2][5]=WHITE;
    	bm->pixel[3][5]=WHITE;
    	bm->pixel[2][6]=WHITE;
    	bm->pixel[3][6]=WHITE;
    
	    bm->pixel[5][5]=WHITE;
   	 	bm->pixel[6][5]=WHITE;
    	bm->pixel[5][6]=WHITE;
   		bm->pixel[6][6]=WHITE;
	}
	else {
    	// Left Colons
	    bm->pixel[2][2]=DIM_WHITE;
    	bm->pixel[3][2]=DIM_WHITE;
	    bm->pixel[2][3]=DIM_WHITE;
    	bm->pixel[3][3]=DIM_WHITE;
    
    	bm->pixel[5][2]=DIM_WHITE;
    	bm->pixel[6][2]=DIM_WHITE;
    	bm->pixel[5][3]=DIM_WHITE;
    	bm->pixel[6][3]=DIM_WHITE;

    	// Right Colons
    	bm->pixel[2][5]=DIM_WHITE;
    	bm->pixel[3][5]=DIM_WHITE;
    	bm->pixel[2][6]=DIM_WHITE;
    	bm->pixel[3][6]=DIM_WHITE;
    
	    bm->pixel[5][5]=DIM_WHITE;
   	 	bm->pixel[6][5]=DIM_WHITE;
    	bm->pixel[5][6]=DIM_WHITE;
   		bm->pixel[6][6]=DIM_WHITE;
		
	}
}

void display_hours(int hours, int hour_mode, int is_dim) {
    sense_fb_bitmap_t *bm=fb->bitmap;
    int i = 7;
    while (i > 1) {
        if (hours % 2) {
			if (is_dim == 0) {
				bm->pixel[7][i]=BLUE;
			}
			else {
            	bm->pixel[7][i]=DIM_BLUE;
			}
        }
        hours = hours / 2;
        i--;
    }
}

void display_minutes(int minutes, int hour_mode, int is_dim) {
    sense_fb_bitmap_t *bm=fb->bitmap;
    int i = 7;
    while (i > 1) {
        if (minutes % 2) {
            if (is_dim == 0) {
				bm->pixel[4][i]=GREEN;
			}
			else {
				bm->pixel[4][i]=DIM_GREEN;
			}
        }
        minutes = minutes / 2;
        i--;
    }
    
}

void display_seconds(int seconds, int hour_mode, int is_dim) {
    sense_fb_bitmap_t *bm=fb->bitmap;
    int i = 7;
    while (i > 1) {
        if (seconds % 2) {
            if (is_dim == 0) {
				bm->pixel[1][i]=RED;
			}
			else {
				bm->pixel[1][i]=DIM_RED;
			}
        }
        seconds = seconds / 2;
        i--;
    }
    
}

void close_display() {
    clearFrameBuffer(fb, BLACK);
    freeFrameBuffer(fb);
}


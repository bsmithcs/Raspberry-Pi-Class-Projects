#include "project.h"

pi_framebuffer_t *fb=NULL;

void open_display() {
	fb = getFrameBuffer();	
}

void close_display() {
	if (fb!=NULL) {
		clearFrameBuffer(fb, BLACK);	
		fb=NULL;
		freeFrameBuffer(fb);
	}
}

void display_dot(int xOffset, int yOffset, int COLOR, int orientation) {
	sense_fb_bitmap_t *bm=fb->bitmap;

	orientation = orientation % 360;

	if(orientation==90 || orientation == -270) {
		int temp = xOffset;
		xOffset = yOffset;
		yOffset = temp;
	}
	else if(orientation==180 || orientation == -180) {
		xOffset = -1 * xOffset - 1;
		yOffset = -1 * yOffset - 1;
	}
	else if(orientation==270 || orientation == -90) {
		int temp = xOffset;
		xOffset = -1 * yOffset - 1;
		yOffset = -1 * temp - 1;
	}

	xOffset = (xOffset % 8); 
	yOffset = (yOffset % 8); 

	if (xOffset < 0) {
		xOffset = xOffset + 8;
	}

	if (yOffset < 0) { 
		yOffset = yOffset + 8; 
	}

	// Make it so that y values match pi orientation starting at bottom
	yOffset = 7 - yOffset;

	bm->pixel[yOffset][xOffset]=COLOR;
}


void display_compass(int orientation) {
	clearFrameBuffer(fb, BLACK);

	display_dot(3, 7, RED, orientation);
	display_dot(4, 7, RED, orientation);

	display_dot(3, 3, DARK_BLUE, orientation);
	display_dot(3, 4, DARK_BLUE, orientation);
	display_dot(4, 3, DARK_BLUE, orientation);
	display_dot(4, 4, DARK_BLUE, orientation);

	display_dot(3, 5, DARK_BLUE, orientation);
	display_dot(4, 5, DARK_BLUE, orientation);
	display_dot(3, 6, DARK_BLUE, orientation);
	display_dot(4, 6, DARK_BLUE, orientation);

	display_dot(4, 2, DARK_BLUE, orientation);
	display_dot(3, 2, DARK_BLUE, orientation);
	display_dot(4, 1, DARK_BLUE, orientation);
	display_dot(3, 1, DARK_BLUE, orientation);

	display_dot(3, 0, WHITE, orientation);
	display_dot(4, 0, WHITE, orientation);
}


void clear_display() {
	clearFrameBuffer(fb, BLACK);
}

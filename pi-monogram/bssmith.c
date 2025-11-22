#include <stdio.h>
#include <unistd.h>
#include "sense.h"

#define WHITE 0xFFFF
#define BLACK 0x0000
#define GREEN 0x9E60 

int main(void) {
    // getFrameBuffer should only get called once/program
    pi_framebuffer_t *fb=getFrameBuffer();
    sense_fb_bitmap_t *bm=fb->bitmap;

    // Left of B
    bm->pixel[1][0]=WHITE;
    bm->pixel[2][0]=WHITE;
    bm->pixel[3][0]=WHITE;
    bm->pixel[4][0]=WHITE;
    bm->pixel[5][0]=WHITE;
    bm->pixel[6][0]=WHITE;
    bm->pixel[7][0]=WHITE;

    // Middle of B
    bm->pixel[1][1]=WHITE;
    bm->pixel[1][2]=WHITE;
    bm->pixel[1][3]=WHITE;

    bm->pixel[4][1]=WHITE;
    bm->pixel[4][2]=WHITE;
    bm->pixel[4][3]=WHITE;

    bm->pixel[7][1]=WHITE;
    bm->pixel[7][2]=WHITE;
    bm->pixel[7][3]=WHITE;
    // Right of B
    bm->pixel[2][4]=WHITE;
    bm->pixel[3][4]=WHITE;

    bm->pixel[5][4]=WHITE;
    bm->pixel[6][4]=WHITE;
   
    sleep(1);
    clearFrameBuffer(fb,BLACK);

    // Top of S
    bm->pixel[1][1]=WHITE;
    bm->pixel[1][2]=WHITE;
    bm->pixel[1][3]=WHITE;
    bm->pixel[1][4]=WHITE;

    // Middle of S
    bm->pixel[2][0]=WHITE;
    bm->pixel[3][0]=WHITE;
    bm->pixel[4][1]=WHITE;
    bm->pixel[4][2]=WHITE;
    bm->pixel[4][3]=WHITE;
    bm->pixel[5][4]=WHITE;
    bm->pixel[6][4]=WHITE;

    // Bottom of S
    bm->pixel[7][0]=WHITE;
    bm->pixel[7][1]=WHITE;
    bm->pixel[7][2]=WHITE;
    bm->pixel[7][3]=WHITE;

    sleep(1);
    clearFrameBuffer(fb,BLACK);

    // Green Clover
    bm->pixel[1][1]=GREEN;
    bm->pixel[1][2]=GREEN;
    bm->pixel[1][4]=GREEN;
    bm->pixel[1][5]=GREEN;

    bm->pixel[2][0]=GREEN;
    bm->pixel[2][1]=GREEN;
    bm->pixel[2][2]=GREEN;
    bm->pixel[2][4]=GREEN;
    bm->pixel[2][5]=GREEN;
    bm->pixel[2][6]=GREEN;

    bm->pixel[3][0]=GREEN;
    bm->pixel[3][1]=GREEN;
    bm->pixel[3][2]=GREEN;
    bm->pixel[3][3]=GREEN;
    bm->pixel[3][4]=GREEN;
    bm->pixel[3][5]=GREEN;
    bm->pixel[3][6]=GREEN;

    bm->pixel[4][3]=GREEN;
    bm->pixel[4][4]=GREEN;

    bm->pixel[5][2]=GREEN;
    bm->pixel[5][4]=GREEN;
    bm->pixel[5][5]=GREEN;
    bm->pixel[5][6]=GREEN;

    bm->pixel[6][2]=GREEN;
    bm->pixel[6][4]=GREEN;
    bm->pixel[6][5]=GREEN;
    bm->pixel[6][6]=GREEN;

    bm->pixel[7][3]=GREEN;
    bm->pixel[7][5]=GREEN;


    // see: "man 3 sleep"
    sleep(1);
    // freeFrameBuffer() should only be called once/program
    // may or may not clear the screen. See "clear" example.
    clearFrameBuffer(fb,BLACK);
    freeFrameBuffer(fb);
    return 0;
}

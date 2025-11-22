#include <stdio.h>
#include <unistd.h>
#include "sense.h"

#define WHITE 0xFFFF

int main(void) {
    // getFrameBuffer should only get called once/program
    pi_framebuffer_t *fb=getFrameBuffer();
    sense_fb_bitmap_t *bm=fb->bitmap;


    // Top of sigma
    bm->pixel[7][0]=WHITE;
    bm->pixel[6][0]=WHITE;
    bm->pixel[5][0]=WHITE;
    bm->pixel[4][0]=WHITE;
    bm->pixel[3][0]=WHITE;

    // Middle
    bm->pixel[6][1]=WHITE;
    bm->pixel[5][2]=WHITE;
    bm->pixel[4][3]=WHITE;
    bm->pixel[5][4]=WHITE;
    bm->pixel[6][5]=WHITE;

    // Bottom of sigma
    bm->pixel[7][6]=WHITE;
    bm->pixel[6][6]=WHITE;
    bm->pixel[5][6]=WHITE;
    bm->pixel[4][6]=WHITE;
    bm->pixel[3][6]=WHITE;

    // see: "man 3 sleep"
    sleep(2);
    // freeFrameBuffer() should only be called once/program
    // may or may not clear the screen. See "clear" example.
    freeFrameBuffer(fb);
    return 0;
}

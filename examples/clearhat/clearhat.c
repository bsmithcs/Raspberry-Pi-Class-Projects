#include <stdio.h>
#include <unistd.h> // for sleep()
#include "sense.h"

#define BLACK 0x0000

int main(void) {
    pi_framebuffer_t *fb=getFrameBuffer();
    clearFrameBuffer(fb,BLACK);
    // If the free happens too quickly, the fb writes may not "take"
    sleep(1);
    freeFrameBuffer(fb);
    return 0;
}

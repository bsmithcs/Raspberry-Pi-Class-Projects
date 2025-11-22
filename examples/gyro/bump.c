#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "sense.h"

/* Bump detector. When the total acceleration is above
 * the threshold, prints the components out.
 * When this is run, nothing will appear except when the Pi
 * is bumped.
 */

int run=1;
void interrupt_handler(int sig){
    run=0;
}

int main(){
    float threshold=1;
    pi_i2c_t* device;
    coordinate_t data;
    signal(SIGINT, interrupt_handler);
    device=geti2cDevice();
    if (device){
        configureAccelGyro(device);
        /*
        printf("Please leave the Pi flat on the table for calibration\n");
        while(run && getAccelData(device,&data) && data.x!=0.0) {
            usleep(100);
        }
        printf("You may pick up the pi.\n");
        */
        float x=0,y=0,z=0;
        float maxx=0,maxy=0,maxz=0;
        while (run && getAccelData(device,&data)){
            float dx=data.x-x,dy=data.y-y,dz=data.z-z;
            if(dx>maxx) maxx=dx;
            if(dy>maxy) maxy=dy;
            if(dz>maxz) maxz=dz;
            if(dx*dx+dy*dy+dz*dz > threshold) {
                printf("bumped: %f %f %f\n",dx,dy,dz);
            }
            x=data.x; y=data.y; z=data.z;
        }
        printf("Max bump: %f %f %f\n",maxx,maxy,maxz);
        printf("\nExiting...\n");
        freei2cDevice(device);
    }
}

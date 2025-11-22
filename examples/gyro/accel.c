#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "sense.h"

/* Averages the acceleration and prints the result about 
 * one/second. Note that you'll be mostly seeing gravity.
 */

int run=1;
void interrupt_handler(int sig){
    run=0;
}

int main(){
    int cnt=0,delay=109;
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
        while (run && getAccelData(device,&data)){
            x+=data.x; y+=data.y; z+=data.z;
            cnt++;
            if(cnt==delay) {
                printf("Avg Accel: %f %f %f\n",
                        x/delay,y/delay,z/delay);
                x=0; y=0; z=0; cnt=0;
            }
        }
        printf("\nExiting...\n");
        freei2cDevice(device);
    }
}

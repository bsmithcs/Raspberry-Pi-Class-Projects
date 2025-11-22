#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "sense.h"

int run=1;
void interrupt_handler(int sig){
    run=0;
}
int main(){
    int cnt=0;
    pi_i2c_t* device;
    coordinate_t data = {0,0,0};
    signal(SIGINT, interrupt_handler);
    device=geti2cDevice();
    if (device){
        configureAccelGyro(device);
        printf("Please leave the Pi flat on the table for calibration\n");
        while(run && getGyroPosition(device,&data) && data.x==0.0) {
            usleep(100);
        }
        printf("You may pick up the pi.\n");
        while (run && getGyroPosition(device,&data)){
            if (cnt==109){ //sample rate, display once per second
                cnt=0;
                printf("Gyro: %f %f %f\n",data.x,data.y,data.z);
            }
            cnt++;
        }
        printf("\nExiting...\n");
        freei2cDevice(device);
    }
}

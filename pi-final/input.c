#include "project.h"

pi_joystick_t* joystick=NULL;
//pi_i2c_t* magnet=NULL;

void open_input() {
	joystick=getJoystickDevice();
//	magnet=geti2cDevice();
}

void close_input() {
	freeJoystick(joystick);
	joystick = NULL;
}

void check_input(void (*callback)(unsigned int code), int delay) {
	open_input();
	pollJoystick(joystick, handler, 1000);
	close_input();
}

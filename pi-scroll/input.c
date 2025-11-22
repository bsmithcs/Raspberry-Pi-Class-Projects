#include "scroll.h"

pi_joystick_t* joystick=NULL;

void open_input() {
	joystick = getJoystickDevice();	
}

void close_input() {
	if (joystick!=NULL) {
		freeJoystick(joystick);
		joystick = NULL;
	}
}

void check_input(void (*callback)(unsigned int code), int delay) {
	open_input();
	pollJoystick(joystick, handler, delay);
	close_input();
}

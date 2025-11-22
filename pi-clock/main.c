#include "display.h"

int hour_mode = 0;
void callbackFunc(unsigned int code);
int main(void) {
    open_display();

    int hours;
    int minutes;
    int seconds;

	int is_dim = 0;

	pi_joystick_t* joystick=getJoystickDevice();

    int input = scanf("%d:%d:%d", &hours, &minutes, &seconds);
    while (input == 3) {
		pollJoystick(joystick, callbackFunc, 1000);
		input = scanf("%d:%d:%d", &hours, &minutes, &seconds);
		is_dim = 0;	

		if (hour_mode == 0) {
        	display_time(hours, minutes, seconds, hour_mode, is_dim);
		}
		else if (hour_mode == 1) {
			if (hours == 0) {
				hours = 12;
			}
			else if (hours > 12) {
				is_dim = 1;
				hours = hours - 12;
			}
        	display_time(hours, minutes, seconds, hour_mode, is_dim);
		}
    }
    
    close_display();
	return 0;
}

void callbackFunc(unsigned int code) {
	if (hour_mode == 0) {
		hour_mode = 1;
	}
	else {
		hour_mode = 0;
	}
}

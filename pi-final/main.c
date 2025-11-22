#include "project.h"

pi_i2c_t* magnet=NULL;

int orientation=0;
float x_diff;
float held_x;

void animate_compass() {
	int running = 1;
	orientation = 0;
	magnet=geti2cDevice(magnet);
	configureMag(magnet);

	while (running) {                                                                         
	fprintf(stderr, "orientation: %d\n", orientation);
		display_compass(orientation);
		check_input(handler, 1000);
		magnet_handler();
	}
}

void magnet_handler() {
	coordinate_t data;
	getMagData(magnet, &data);

	if (!held_x) {
		float held_x = data.x;
	}

	x_diff = data.x - held_x;
	fprintf(stderr, "x_diff: %f\n", x_diff);

	if (x_diff > 30) {
		orientation -= 270;
		held_x = data.x;
	}
	else if (x_diff > 20) {
		orientation -= 180;
		held_x = data.x;
	}
	else if (x_diff > 10) {
		orientation -= 90;
		held_x = data.x;
	}
	else if (x_diff < -30) {
		orientation += 270;
		held_x = data.x;
	}
	else if (x_diff < -20) {
		orientation += 180;
		held_x = data.x;
	}
	else if (x_diff < -10) {
		orientation += 90;
		held_x = data.x;
	}

}

void handler(unsigned int code) {
	if(code==106) {
		orientation += 90;
		fprintf(stderr, "%d\n", orientation);
	}
	else if(code==105) {
		orientation -= 90;
		fprintf(stderr, "%d\n", orientation);
	}
}

void main() {
	open_display();

	animate_compass();

	close_display();
}

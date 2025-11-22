#include "scroll.h"

int running = 0;
int vx = 0;
int vy = 0;
int COLOR = WHITE;
int DEGREES = 0;

void dot_roll(void) {
	
	printf("Enter a value from -10 to 10 for vx and vy seperated by a space:\t");
	scanf("%d %d", &vx, &vy);

	running = 1;
	float x = 0;
	float y = 0;
	float max;
	if (vx*vx >= vy*vy) {
		max = vx;
	}
	else {
		max = vy;
	}
	if (max < 0) {
		max = -1 * max;
	}

	float dx = vx / max;
	float dy = vy / max;

	while (running) {
		x = x + dx;
		y = y + dy;

		display_letter('.', (int)x, (int)y, COLOR, DEGREES);
		if (max != 0) {
			usleep((int)2000000/max);
		}
	}
}

void animate_letter() {
	running = 1;
	float x = 0.0;
	float y = 0.0;
	float max;
	float dx = 0.0;
	float dy = 0.0;

	while (running) {
		if (vx*vx >= vy*vy) {
			max = vx;
		}
		else {
			max = vy;
		}
		if (max < 0) {
			max = -1 * max;
		}

		if (max == 0) {
			dx = 0.0;
			dy = 0.0;
		}
		else {
			dx = vx / max;
			dy = vy / max;
		}
			
		x = x + dx;
		y = y + dy;

		display_letter('B', (int)x, (int)y, COLOR, DEGREES);

		check_input(handler, (int)(1000/max));
	}


}

void handler(unsigned int code) {
	if(code == 28) {
		running = 0;
	}
	else if(code == 103) {
		vy++;
	}
	else if(code == 108) {
		vy--;
	}
	else if(code == 106) {
		vx++;
	}
	else if(code == 105) {
		vx--;
	}
}

void main(int argc, char *argv[]) {
	if(!strcmp(argv[1], "-h")) {
		printf("This is the Raspberry Pi Monogram Scroller\n\nTo begin call scroll\nTo change the direction of the letter, use the joystick\n\nFlags:\n\t-h\t\thelp\n\t-c\t\tcolor\n\t-r\t\tdegrees\n\t--secret\t[redacted]\nEnjoy!\n");
	}
	else if(!strcmp(argv[1], "-c")) {
		if(!strcmp(argv[2], "white")) {
			COLOR = WHITE;
		}
		if(!strcmp(argv[2], "red")) {
			COLOR = RED;
		}
		if(!strcmp(argv[2], "green")) {
			COLOR = GREEN;
		}
		if(!strcmp(argv[2], "blue")) {
			COLOR = BLUE;
		}
	}
	else if(!strcmp(argv[1], "-r")) {
		printf("in");
		if(!strcmp(argv[2], "0")) {
			DEGREES = NONE;
		}
		if(!strcmp(argv[2], "90")) {
			DEGREES = QUARTER;
		}
		if(!strcmp(argv[2], "180")) {
			DEGREES = HALF;
		}
		if(!strcmp(argv[2], "270")) {
			DEGREES = TQUARTER;
		}
		if(!strcmp(argv[2], "360")) {
			DEGREES = FULL;
		}
	}
	else if(!strcmp(argv[1], "--secret")) {
		printf("Congrats, you found the secret!\n");
	}
	open_display();
	animate_letter(); 
	close_display();

}

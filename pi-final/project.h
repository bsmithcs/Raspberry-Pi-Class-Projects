#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <linux/input.h>
#include "sense.h"


/* COLORS */
#define WHITE getColor(200, 200, 200)
#define BLACK 0x0000
#define RED getColor(200, 0, 0) 
#define BLUE 0x001F
#define DARK_BLUE getColor(50, 50, 200)
#define GREEN 0x07E0 


/* DISPLAY */
void open_display(void);

void close_display(void);
void display_dot(int xOffset, int yOffset, int COLOR, int orientation);
void display_compass(int orientation);
void animate_compass();

void clear_display(void);


/* INPUT */
void open_input(void);
void close_input(void);
void check_input(void (*handler)(unsigned int code), int delay);

void handler(unsigned int code);
void magnet_handler();

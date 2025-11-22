#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "sense.h"

#define WHITE 0xFFFF
#define BLACK 0x0000
#define RED 0xF000 
#define BLUE 0x001F
#define GREEN 0x07E0 
#define NONE 0 
#define QUARTER 90 
#define HALF 180 
#define TQUARTER 270 
#define FULL 360 


void open_display(void);
void close_display(void);
void display_letter(char letter, int xOffset, int yOffset, int COLOR, int DEGREES);
void clear_display(void);

void open_input(void);
void close_input(void);
void check_input(void (*callback)(unsigned int code), int delay);

void handler(unsigned int code);

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sense.h"

int open_display(void);
void display_time(int hours, int minutes, int seconds, int hour_mode, int is_dim);
void display_colons(int hour_mode, int is_dim);
void display_hours(int hours, int hour_mode, int is_dim);
void display_minutes(int minutes, int hour_mode, int is_dim);
void display_seconds(int seconds, int hour_mode, int is_dim);
void close_display(void);


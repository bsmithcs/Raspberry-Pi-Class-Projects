# Set a variable LDFLAGS. Use the variable as $(LDFLAGS)
LDFLAGS := -L ~/lib -lsense -lm

all: joystick
joystick: joystick.o display.o
	cc -o joystick joystick.o display.o $(LDFLAGS)

%.o: %.c display.h
	cc -g -c $< -I ~/include

clean:
	rm -f *.o joystick

CFLAGS := -g
INCLUDE := -I ~/include
LDFLAGS := -L ~/lib -lsense -lm

all: accel gyro bump
%.o: %.c
	cc -c $(CFLAGS) $< $(INCLUDE)

gyro: gyro.o
	cc -o gyro $(INCLUDE) gyro.o $(LDFLAGS)
accel: accel.o
	cc -o accel $(INCLUDE) accel.o $(LDFLAGS)
bump: bump.o
	cc -o bump $(INCLUDE) bump.o $(LDFLAGS)
clean:
	rm -f *.o gyro accel bump

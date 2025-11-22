INCLUDE := -I ~/include
LDFLAGS := -L ~/lib -lsense -lm

all: scroll
scroll: input.o main.o display.o
	cc -o scroll input.o main.o display.o $(LDFLAGS)

clean:
	rm -f *.o scroll
main.o: main.c scroll.h
	cc -c main.c -I ~/include
display.o: display.c scroll.h
	cc -c display.c -I ~/include
input.o: input.c scroll.h
	cc -c input.c -I ~/include

run: scroll
	./scroll

debug: input.o main.o display.o
	cc -g -o scroll input.o main.o display.o $(LDFLAGS)

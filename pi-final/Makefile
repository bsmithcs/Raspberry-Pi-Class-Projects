INCLUDE := -I ~/include
LDFLAGS := -L ~/lib -lsense -lm

all: main
main: input.o main.o output.o 
	cc -o main input.o main.o output.o $(LDFLAGS)

main.o: main.c project.h
	cc -c main.c -I ~/include
input.o: input.c project.h
	cc -c input.c -I ~/include
output.o: output.c project.h
	cc -c output.c -I ~/include


clean:
	rm -f *.o main
run: main
	./main

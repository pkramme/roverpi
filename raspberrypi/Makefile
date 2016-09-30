all:
	gcc -Wall -pedantic -Wshadow -Wpointer-arith -Wcast-qual -Wcast-align -Wstrict-prototypes -Wmissing-prototypes -Wconversion -O3 -ansi src/main.c src/init.c src/getch.c src/light.c src/move.c src/argument.c src/directinput.c src/test.c src/headless.c src/headlessinput.c -o roverpi-v.3.2.0 -l bcm2835
debug:
	gcc -Wall -pedantic -Wshadow -Wpointer-arith -Wcast-qual -Wcast-align -Wstrict-prototypes -Wmissing-prototypes -Wconversion -O3 -ansi -D DEBUG src/main.c src/init.c src/getch.c src/light.c src/move.c src/argument.c src/directinput.c src/test.c src/headless.c src/headlessinput.c -o roverpi-DEBUG -l bcm2835
clean:
	rm roverpi-*

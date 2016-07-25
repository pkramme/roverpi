all:
	gcc -Wall -pedantic -Wshadow -Wpointer-arith -Wcast-qual -Wcast-align -Wstrict-prototypes -Wmissing-prototypes -Wconversion -O3 -ansi src/main.c src/api/init.c src/api/getch.c src/api/light.c src/api/move.c src/api/argument.c src/directinput.c src/test.c src/headless.c src/api/headlessinput.c -o roverpi-v.3.1.3 -l bcm2835
debug:
	gcc -Wall -pedantic -Wshadow -Wpointer-arith -Wcast-qual -Wcast-align -Wstrict-prototypes -Wmissing-prototypes -Wconversion -O3 -ansi -D DEBUG src/main.c src/api/init.c src/api/getch.c src/api/light.c src/api/move.c src/api/argument.c src/directinput.c src/test.c src/headless.c src/api/headlessinput.c -o roverpi-DEBUG -l bcm2835
unittest:
	clang -Weverything -std=c11 -D BCM2835_DEBUG_MODE_SWITCH=1 src/unittest.c src/api/move.c src/api/init.c -o unittest_move -l bcm2835
clean:
	rm roverpi-*

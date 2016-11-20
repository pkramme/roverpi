all:
	gcc -Wall -pedantic -Wshadow -Wpointer-arith -Wcast-qual -Wcast-align -Wstrict-prototypes -Wmissing-prototypes -Wconversion -O3 -ansi src/main.c src/init.c src/getch.c src/light.c src/move.c src/argument.c src/directinput.c src/test.c src/headless.c src/headlessinput.c -o roverpi-v.3.2.0 -l src/bcm2835/
debug:
	gcc -Wall -pedantic -Wshadow -Wpointer-arith -Wcast-qual -Wcast-align -Wstrict-prototypes -Wmissing-prototypes -Wconversion -O3 -ansi -D DEBUG src/main.c src/init.c src/getch.c src/light.c src/move.c src/argument.c src/directinput.c src/test.c src/headless.c src/headlessinput.c src/bcm2835/src/bcm2835.c -o roverpi-DEBUG
clean:
	rm roverpi-*
debugnew:
	gcc -O3 -D DEBUG src/main.c src/init.c src/getch.c src/light.c src/move.c src/argument.c src/directinput.c src/test.c src/headless.c src/headlessinput.c src/bcm2835/src/bcm2835.c -o roverpi-DEBUG
allnew:
	gcc -O3 src/main.c src/init.c src/getch.c src/light.c src/move.c src/argument.c src/directinput.c src/test.c src/headless.c src/headlessinput.c src/bcm2835/src/bcm2835.c -o roverpi-v.3.2.0
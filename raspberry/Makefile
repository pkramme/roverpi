all:
	gcc -O3 src/main.c src/init.c src/getch.c src/light.c src/move.c src/argument.c src/directinput.c src/test.c src/headless.c src/headlessinput.c src/bcm2835/src/bcm2835.c -o roverpi-v.3.3.0
debug:
	gcc -O3 -D DEBUG src/main.c src/init.c src/getch.c src/light.c src/move.c src/argument.c src/directinput.c src/test.c src/headless.c src/headlessinput.c src/bcm2835/src/bcm2835.c -o roverpi-DEBUG
clean:
	rm roverpi-*

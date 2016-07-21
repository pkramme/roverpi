all:
	clang -Weverything -std=c11 -D BCM2835_DEBUG_MODE_SWITCH=0 src/main.c src/api/init.c src/api/getch.c src/api/light.c src/api/move.c src/api/argument.c src/directinput.c src/test.c src/headless.c src/api/headlessinput.c -o roverpi-v.3.1.3 -l bcm2835
debug:
	clang -Weverything -std=c11 -D BCM2835_DEBUG_MODE_SWITCH=1 src/main.c src/api/init.c src/api/getch.c src/api/light.c src/api/move.c src/api/argument.c src/directinput.c src/test.c src/headless.c src/api/headlessinput.c -o roverpi-DEBUG -l bcm2835
utest_move:
	clang -Weverything -std=c11 -D BCM2835_DEBUG_MODE_SWITCH=1 src/unittest_move.c src/api/move.c src/api/init.c -o unittest_move -l bcm2835
clean:
	rm roverpi-*

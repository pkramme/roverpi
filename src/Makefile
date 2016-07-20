all:
	clang -Weverything -std=c11 -D BCM2835_DEBUG_MODE_SWITCH=0 main.c init.c getch.c light.c move.c argument.c directinput.c test.c headless.c headlessinput.c -o roverpi-v.3.1.3 -l bcm2835
debug:
	clang -Weverything -std=c11 -D BCM2835_DEBUG_MODE_SWITCH=1 main.c init.c getch.c light.c move.c argument.c directinput.c test.c headless.c headlessinput.c -o roverpi-DEBUG -l bcm2835
utest_move:
	clang -Weverything -std=c11 -D BCM2835_DEBUG_MODE_SWITCH=1 utest_move.c move.c -l bcm2835
clean:
	rm roverpi-*

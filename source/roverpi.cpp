#include"input.h"

int main()
{
	std::thread input_module(input);
	std::cout << "INPUT MODULE THREAD LAUNCHED" << std::endl;
	std::thread x_move_module(x_move);
	std::cout << "X MOVE MODULE LAUNCHED" << std::endl;

	input_module.join();
	x_move_module.join();

	std::cout << "ROVERPI SOFTWARE by Paul Kramme" << std::endl;
	return 0;
}

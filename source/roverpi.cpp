#include"input.h"
#include"version.h"

int main(int argc, char *argv[])
{
	if(argc == 1)
	{
		input();
	}
	else
	{
		std::string argument1 = argv[1];
		if(argument1 == "-v")
		{
			version();
		}
		else if(argument1 == "-h")
		{
			std::cout << "---HELPMESSAGE---" << std::endl;
			std::cout << "Movekeys" << std::endl;
			std::cout << "w - forward" << std::endl;
			std::cout << "a - left" << std::endl;
			std::cout << "s - backward" << std::endl;
			std::cout << "d - right" << std::endl;
			std::cout << "e - killall" << std::endl;
			std::cout << "Lightkeys" << std::endl;
			std::cout << "r - front light" << std::endl;
			std::cout << "t - ground light" << std::endl;
			std::cout << "Camera Movekeys" << std::endl;
			std::cout << "u - cam up" << std::endl;
			std::cout << "h - cam left" << std::endl;
			std::cout << "j - cam down" << std::endl;
			std::cout << "k - cam right" << std::endl;
		}
	}
	return 0;
}

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
	}
	return 0;
}

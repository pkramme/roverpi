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
		switch((*argv)[1])
		{
			case '--version':
				version();
		}
	}
	return 0;
}

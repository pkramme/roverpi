#include"input.h"

int main()
{
	boost::thread_group tgroup;

	tgroup.create_thread(boost::bind(&x_move));
	tgroup.create_thread(boost::bind(&input));

	tgroup.join_all();
	std::cout << "ROVERPI SOFTWARE by Paul Kramme" << std::endl;
	return 0;
}

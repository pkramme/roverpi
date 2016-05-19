#include"input.h"

int main()
{
	boost::thread_group tgroup;

	tgroup.create_thread(boost::bind(&x_move));
	std::cout << "LAUNCHED X_MOVE THREAD" << std::endl;
	tgroup.create_thread(boost::bind(&input));
	std::cout << "LAUNCHED INPUT THREAD" << std::endl;
	tgroup.join_all();
	std::cout << "ROVERPI SOFTWARE by Paul Kramme" << std::endl;
	return 0;
}

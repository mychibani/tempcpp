#include "easyfind.hpp"

int
main (__attribute__((unused)) int ac, __attribute__((unused)) char **av)
{
	std::vector<int> lst;

	lst.push_back(42);
	lst.push_back(2);
	lst.push_back(521);
	lst.push_back(12);
	lst.push_back(982);
	lst.push_back(1242);

	try
	{
		easyfind(lst, 521);
		std::cout << "the value has been found" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		easyfind(lst, 0);
		std::cout << "the value has been found" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

		try
	{
		easyfind(lst, 12);
		std::cout << "the value has been found" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
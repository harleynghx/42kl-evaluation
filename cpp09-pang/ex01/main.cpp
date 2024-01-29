#include <iostream>
#include "RPN.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Usage:\n" << argv[0] << " <rpn>" << std::endl;
		return 1;
	}

	RPN polish(argv[1]);
	int result = polish.CalculateNumbers();
	if (!polish.GetStatus())
		return 1;

	std::cout << result << std::endl;
	return 0;
}
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <ctime>
#include "PmergeMe.hpp"

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec)
{
	os << "[ ";
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++)
	{
		os << *it << " ";
	}
	os << "]";

	return os;
}

std::ostream& operator<<(std::ostream& os, const std::list<int>& vec)
{
	os << "[ ";
	for (std::list<int>::const_iterator it = vec.begin(); it != vec.end(); it++)
	{
		os << *it << " ";
	}
	os << "]";

	return os;
}

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage:\n" << argv[0] << " <array>" << std::endl;
		return 1;
	}

	PmergeMe me(argv + 1, argc - 1);
	if (!me.GetStatus())
		return 1;

	clock_t vstart, vfinish, lstart, lfinish;

	std::cout << "Before: " << me.GetVectorArray() << "\n";

	vstart = clock();
	PmergeMe vme(argv + 1, argc - 1);
	vme.VectorSort();
	vfinish = clock();

	lstart = clock();
	PmergeMe lme(argv + 1, argc - 1);
	lme.ListSort();
	lfinish = clock();

	std::cout << "After:  " << vme.GetVectorArray() << "\n";
	// std::cout << "After:  " << lme.GetListArray() << "\n";
	std::cout << "Time to process a range of " << vme.GetVectorArray().size() << " elements with std::vector : " << std::fixed << std::setprecision(14) << double(vfinish - vstart) / double(CLOCKS_PER_SEC) << " second(s)\n";
	std::cout << "Time to process a range of " << lme.GetListArray().size() << " elements with std::list   : " << std::fixed << std::setprecision(14) << double(lfinish - lstart) / double(CLOCKS_PER_SEC) << " second(s)\n";

	return 0;
}
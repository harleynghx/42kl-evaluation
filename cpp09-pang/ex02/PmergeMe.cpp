#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <limits>
#include <algorithm>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char** array, int size) : _Status(true)
{
	for (int i = 0; i < size; i++)
	{
		std::string num(array[i]);
		for (std::string::iterator it = num.begin(); it < num.end(); it++)
		{
			if (*it < '0' || *it > '9')
			{
				ThrowError("Bad input");
				return;
			}
		}

		long tmp = 0;
		std::stringstream ss(num);
		ss >> tmp;
		if (tmp > std::numeric_limits<int>::max() || tmp < std::numeric_limits<int>::min())
		{
			ThrowError("Input overflows/underflows");
			return;
		}

		_VArray.push_back(tmp);
		_LArray.push_back(tmp);
	}

	// std::cout << "[debug] _VArray.size() = " << _VArray.size() << " | _LArray.size() = " << _LArray.size() << std::endl;
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& pmerge) { (void)pmerge; }

PmergeMe& PmergeMe::operator=(const PmergeMe& pmerge) { (void)pmerge; return *this; }

const std::vector<int>& PmergeMe::GetVectorArray() const
{
	return _VArray;
}

const std::list<int>& PmergeMe::GetListArray() const
{
	return _LArray;
}

bool PmergeMe::GetStatus() const
{
	return _Status;
}

void PmergeMe::ThrowError(std::string msg)
{
	std::cerr << "Error: " << msg << std::endl;
	_Status = false;
}


// ==============
// Vector sorting
// --------------

void PmergeMe::VectorSort()
{
	std::vector<size_t> fixedDists;
	for (size_t i = _VArray.size() / 2; i > 0; i /= 2)
	{
		fixedDists.push_back(i);
	}

	FordJohnsonVectorSort(_VArray.begin(), _VArray.end(), fixedDists);
}

void PmergeMe::FordJohnsonVectorSort(vIterator begin, vIterator end, const std::vector<size_t>& fixedDists)
{
	const size_t size = std::distance(begin, end); // size of the iterator, not array
	if (size < 2)
		return;

	const size_t pairDistance = size / 2; // [n/2]
	// std::cout << "[debug] size: " << size << "\n";
	if (size % 2 != 0)
		++begin;

	// Step 1: Pair two elements together, such that there will be [n/2] pairs.
	// Then swap each pair depending on their size, the larger value will be placed on the right side.
	// Each pair will be identified through their pairDistance between each element.
	// By the end of this for loop, all the elements that were the largest in each pair should be on the right side of the array.
	// Those elements shall be considered the "main chain".
	// std::cout << "[debug] step 1 (" << pairDistance << ")\n";
	for (size_t i = 0; i < pairDistance; i++)
	{
		vIterator leftPair = begin + i;
		vIterator rightPair = leftPair + pairDistance;

	// 	DisplayArray(_VArray, leftPair, rightPair);
		if (*leftPair > *rightPair)
			VectorSwap(leftPair, rightPair, fixedDists, pairDistance);
	}

	// Step 2: Recursively sort the "main chain" using the Ford-Johnson Algorithm
	// (yes this is what the paper said to do, it apparently works)
	// std::cout << "[debug] step 2 (" << pairDistance << ")\n";
	FordJohnsonVectorSort(begin + pairDistance, end, fixedDists);

	// Step 3: Insertion (ever heard of insertion sort? basically that)
	// std::cout << "[debug] step 3 (" << pairDistance << ")\n";
	size_t newDistance = pairDistance;
	for (size_t i = 0; i < pairDistance; i++)
	{
		vIterator leftPair = begin;
		vIterator rightPair = leftPair + newDistance;
	// 	DisplayArray(_VArray, leftPair, rightPair);

		// Given that the rightPair is always larger than the left pair, we only have to compare the left side
	// 	std::cout << "[debug] step 3 (" << pairDistance << "): comparing\n";
		vIterator mainChainFront = end - newDistance;
		vIterator it = std::lower_bound(mainChainFront, rightPair, *leftPair);

	// 	DisplayArray(_VArray, leftPair, it);
		vIterator middle = leftPair + 1;
		if (middle != it)
			VectorRotate(leftPair, middle, it, fixedDists, pairDistance);

	// 	DisplayArray(_VArray, leftPair, it);

	// 	std::cout << "[debug] step 3 (" << pairDistance << "): end of comparing\n";
	// 	DisplayArray(_VArray, leftPair, rightPair);
		++newDistance;
		// break;
	}

	// insert leftover into the "main chain"
	if (size % 2 != 0)
	{
		vIterator leftover = begin - 1;
		vIterator it = std::lower_bound(begin, end, *leftover);

	// 	DisplayArray(_VArray, leftover, it);
		vIterator middle = begin;
		if (middle != it)
			VectorRotate(leftover, middle, it, fixedDists, pairDistance);

	// 	DisplayArray(_VArray, leftover, it);
	}

	// std::cout << "[debug] exiting (" << pairDistance << ")\n";
}

void PmergeMe::VectorRotate(vIterator first, vIterator middle, vIterator last, const std::vector<size_t>& fixedDists, size_t pairDistance)
{
	if (first < _VArray.begin())
		return;

	for (std::vector<size_t>::const_iterator it = fixedDists.begin(); *it > pairDistance; it++)
	{
		vIterator prevFirst = first - *it;
		vIterator prevLast = last - *it;
		vIterator prevMiddle = middle - *it;

		if (prevFirst < _VArray.begin())
			break;

	// 	std::cout << "[debug]" << *it << " deeper...\n";
		VectorRotate(prevFirst, prevMiddle, prevLast, fixedDists, *it);
	// 	std::cout << "[debug] up...\n";
	}

	std::rotate(first, middle, last);
	// DisplayArray(_VArray, first, last);
}

void PmergeMe::VectorSwap(vIterator leftPair, vIterator rightPair, const std::vector<size_t>& fixedDists, size_t pairDistance)
{
	if (leftPair < _VArray.begin() || rightPair >= _VArray.end())
		return;

	// DisplayArray(_VArray, leftPair, rightPair);
	for (std::vector<size_t>::const_iterator it = fixedDists.begin(); *it > pairDistance; it++)
	{
		vIterator prevLeft = leftPair - *it;
		vIterator prevRight = rightPair - *it;

		if (prevLeft < _VArray.begin())
			break;

	// 	std::cout << "[debug]" << *it << " deeper...\n";
		VectorSwap(prevLeft, prevRight, fixedDists, *it);
	// 	std::cout << "[debug] up...\n";
	}

	std::swap(*leftPair, *rightPair);
	// DisplayArray(_VArray, leftPair, rightPair);
}


// ============
// List sorting
// ------------

void PmergeMe::ListSort()
{
	std::list<size_t> fixedDists;
	for (size_t i = _LArray.size() / 2; i > 0; i /= 2)
	{
		fixedDists.push_back(i);
	}

	FordJohnsonListSort(_LArray.begin(), _LArray.end(), fixedDists);
}

void PmergeMe::FordJohnsonListSort(lIterator begin, lIterator end, const std::list<size_t>& fixedDists)
{
	const size_t size = std::distance(begin, end); // size of the iterator, not array
	if (size < 2)
		return;

	const size_t pairDistance = size / 2; // [n/2]
	// std::cout << "[debug] size: " << size << "\n";
	if (size % 2 != 0)
		++begin;

	// Step 1: Pair two elements together, such that there will be [n/2] pairs.
	// Then swap each pair depending on their size, the larger value will be placed on the right side.
	// Each pair will be identified through their pairDistance between each element.
	// By the end of this for loop, all the elements that were the largest in each pair should be on the right side of the array.
	// Those elements shall be considered the "main chain".
	// std::cout << "[debug] step 1 (" << pairDistance << ")\n";

	lIterator leftPair = begin;
	lIterator rightPair = leftPair;
	std::advance(rightPair, pairDistance);
	// lIterator mainChainFront = rightPair;

	for (size_t i = 0; i < pairDistance; i++)
	{
	// 	DisplayArray(_LArray, leftPair, rightPair);
		if (*leftPair > *rightPair)
			ListSwap(leftPair, rightPair, fixedDists, pairDistance);

		std::advance(leftPair, 1);
		std::advance(rightPair, 1);
	}

	// Step 2: Recursively sort the "main chain" using the Ford-Johnson Algorithm
	// (yes this is what the paper said to do, it apparently works)
	// std::cout << "[debug] step 2 (" << pairDistance << ")\n";
	lIterator newBegin = begin;
	std::advance(newBegin, pairDistance);
	FordJohnsonListSort(newBegin, end, fixedDists);

	// Step 3: Insertion (ever heard of insertion sort? basically that)
	// std::cout << "[debug] step 3 (" << pairDistance << ")\n";
	size_t newDistance = pairDistance;
	for (size_t i = 0; i < pairDistance; i++)
	{
		lIterator leftPair = begin;
		lIterator rightPair = leftPair;
		std::advance(rightPair, newDistance);
	// 	DisplayArray(_LArray, leftPair, rightPair);

		// Given that the rightPair is always larger than the left pair, we only have to compare the left side
	// 	std::cout << "[debug] step 3 (" << pairDistance << "): comparing\n";
		lIterator mainChainFront = end;
		std::advance(mainChainFront, -newDistance);
		lIterator it = std::lower_bound(mainChainFront, rightPair, *leftPair);

	// 	DisplayArray(_LArray, leftPair, it);
		lIterator middle = leftPair;
		std::advance(middle, 1);
		if (middle != it)
			ListRotate(leftPair, middle, it, fixedDists, pairDistance);

	// 	DisplayArray(_LArray, leftPair, it);

	// 	std::cout << "[debug] step 3 (" << pairDistance << "): end of comparing\n";
	// 	DisplayArray(_LArray, leftPair, rightPair);
		++newDistance;
		// break;
	}

	// insert leftover into the "main chain"
	if (size % 2 != 0)
	{
		lIterator leftover = begin;
		std::advance(leftover, -1);
		lIterator it = std::lower_bound(begin, end, *leftover);

	// 	DisplayArray(_LArray, leftover, it);
		lIterator middle = begin;
		if (middle != it)
			ListRotate(leftover, middle, it, fixedDists, pairDistance);

	// 	DisplayArray(_LArray, leftover, it);
	}

	// std::cout << "[debug] exiting (" << pairDistance << ")\n";
}

void PmergeMe::ListRotate(lIterator first, lIterator middle, lIterator last, const std::list<size_t>& fixedDists, size_t pairDistance)
{
	for (std::list<size_t>::const_iterator it = fixedDists.begin(); *it > pairDistance; it++)
	{
		lIterator prevFirst = first;
		lIterator prevLast = last;
		lIterator prevMiddle = middle;
		std::advance(prevFirst, -(*it));
		std::advance(prevLast, -(*it));
		std::advance(prevMiddle, -(*it));

	// 	std::cout << "[debug]" << *it << " deeper...\n";
		ListRotate(prevFirst, prevMiddle, prevLast, fixedDists, *it);
	// 	std::cout << "[debug] up...\n";
	}

	// _LArray.insert(last, *first);
	// _LArray.erase(first);
	std::rotate(first, middle, last);
	// DisplayArray(_LArray, first, last);
}

void PmergeMe::ListSwap(lIterator leftPair, lIterator rightPair, const std::list<size_t>& fixedDists, size_t pairDistance)
{
	// DisplayArray(_LArray, leftPair, rightPair);
	for (std::list<size_t>::const_iterator it = fixedDists.begin(); *it > pairDistance; it++)
	{
		lIterator prevLeft = leftPair;
		lIterator prevRight = rightPair;
		std::advance(prevLeft, -(*it));
		std::advance(prevRight, -(*it));

	// 	std::cout << "[debug]" << *it << " deeper...\n";
		ListSwap(prevLeft, prevRight, fixedDists, *it);
	// 	std::cout << "[debug] up...\n";
	}

	std::swap(*leftPair, *rightPair);
	// DisplayArray(_LArray, leftPair, rightPair);
}

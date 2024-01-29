#pragma once
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <string>
#include <iostream>

class PmergeMe
{
public:
	typedef std::vector<int>::iterator vIterator;
	typedef std::vector<int>::const_iterator vConstIterator;
	typedef std::list<int>::iterator lIterator;
	typedef std::list<int>::const_iterator lConstIterator;

	PmergeMe();
	// PmergeMe(std::string array);
	PmergeMe(char** array, int size);
	~PmergeMe();
	PmergeMe(const PmergeMe& pmerge);
	PmergeMe& operator=(const PmergeMe& pmerge);

	const std::vector<int>& GetVectorArray() const;
	const std::list<int>& GetListArray() const;
	bool GetStatus() const;

	void VectorSort();
	void FordJohnsonVectorSort(vIterator begin, vIterator end, const std::vector<size_t>& fixedDists);

	void ListSort();
	void FordJohnsonListSort(lIterator begin, lIterator end, const std::list<size_t>& fixedDists);

private:
	std::vector<int> _VArray;
	std::list<int> _LArray;
	bool _Status;

	void ThrowError(std::string msg);
	void VectorSwap(vIterator leftPair, vIterator rightPair, const std::vector<size_t>& fixedDists, size_t pairDistance);
	void VectorRotate(vIterator first, vIterator middle, vIterator last, const std::vector<size_t>& fixedDists, size_t pairDistance);
	void ListSwap(lIterator leftPair, lIterator rightPair, const std::list<size_t>& fixedDists, size_t pairDistance);
	void ListRotate(lIterator first, lIterator middle, lIterator last, const std::list<size_t>& fixedDists, size_t pairDistance);

	template <typename TCon, typename TIter>
	void DisplayArray(TCon& container, TIter& left, TIter& right) const
	{
		std::cout << "\n[ ";
		for (TIter it = container.begin(); it != container.end(); it++)
		{
			if (it == left)
				std::cout << "\033[32m\033[4m" << *it << "\033[24m\033[39m ";
			else if (it == right)
				std::cout << "\033[31m\033[4m" << *it << "\033[24m\033[39m ";
			else
				std::cout << *it << " ";
		}
		std::cout << "]\n";
	}
};

#endif

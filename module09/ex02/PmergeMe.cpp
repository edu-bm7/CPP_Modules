#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	return;
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	if (this != &other) {
		*this = other;
	}
	return;
}

PmergeMe::~PmergeMe()
{
	return;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
	// Guard Self-Assignment
	if (this == &rhs) {
		return *this;
	}

	return *this;
}

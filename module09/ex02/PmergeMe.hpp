#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <ctime>
#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <vector>

// Define uint64_t for C++98
typedef unsigned long long uint64_t;
typedef unsigned long long size_type;

class PmergeMe {
public:
	PmergeMe();                      // Canonical Default Constructor
	PmergeMe(const PmergeMe& other); // Canonical Copy Constructor
	~PmergeMe();                     // Canonical Default Destructor

	PmergeMe& operator=(const PmergeMe& rhs); // Canonical Assignment Operator

	template< typename T >
	void sortVector(typename std::vector< T >::iterator first,
					typename std::vector< T >::iterator last);

	template< typename T >
	void sortDeque(typename std::deque< T >::iterator first,
				   typename std::deque< T >::iterator last);

private:
	template< typename T >
	void sortVectorImp(typename std::vector< T >::iterator first, typename std::vector< T >::iterator last, std::size_t itSize);

	template< typename T >
	void sortDequeImp(typename std::deque< T >::iterator first, typename std::deque< T >::iterator last, std::size_t itSize);
};

template< typename T >
struct CompareIterators {
	// Compare a value with an iterator (dereference the iterator)
	bool operator()(const T& lhs, typename std::deque< T >::iterator& rhs) const
	{
		return lhs < *rhs;
	}

	// Compare a value with an iterator (dereference the iterator)
	bool operator()(const T& lhs, typename std::vector< T >::iterator& rhs) const
	{
		return lhs < *rhs;
	}
};

template< typename Iterator, typename T, typename Container, typename ContainerIterator, typename Compare >
Iterator custom_upper_bound(Iterator first, Iterator last, const T& value, const Container& container, ContainerIterator containerIterator, std::size_t& itSize, Compare comp)
{
	Iterator first_reference = first;
	std::size_t len;
	if (last != container.end()) {
		//	// Find the true last element base on itSize
		while (**first_reference != **last) {
			std::advance(first_reference, 1);
		}
		len = std::distance(first, first_reference);
	} else {
		len = std::distance(first, last);
	}

	// Result to return the correct iterator position
	Iterator result = first;

	while (len > 0) {
		std::size_t half = len >> 1;
		Iterator middle = result;
		std::advance(middle, (half));
		containerIterator = *middle + itSize - 1;
		if (comp(value, containerIterator)) {
			len = half;
		} else {
			len = len - half - 1;
			std::advance(result, (half));
			result++;
		}
	}
	return result;
}

template< typename T >
void PmergeMe::sortVector(typename std::vector< T >::iterator first, typename std::vector< T >::iterator last)
{
	sortVectorImp< T >(first, last, 1);
}

template< typename T >
void PmergeMe::sortDeque(typename std::deque< T >::iterator first, typename std::deque< T >::iterator last)
{
	sortDequeImp< T >(first, last, 1);
}


template< typename T >
void PmergeMe::sortVectorImp(typename std::vector< T >::iterator first, typename std::vector< T >::iterator last, std::size_t itSize)
{
	// Cache all the differences between a Jacobsthal number and its
	// predecessor that fit in 64 bits, starting with the difference
	// between the Jacobsthal numbers 4 and 3 (the previous ones are
	// unneeded)
	static const uint64_t jacobsthal_diff[] = {
			2u, 2u, 6u, 10u, 22u, 42u, 86u, 170u, 342u, 682u, 1366u,
			2730u, 5462u, 10922u, 21846u, 43690u, 87382u, 174762u, 349526u, 699050u,
			1398102u, 2796202u, 5592406u, 11184810u, 22369622u, 44739242u, 89478486u,
			178956970u, 357913942u, 715827882u, 1431655766u, 2863311530u, 5726623062u,
			11453246122u, 22906492246u, 45812984490u, 91625968982u, 183251937962u,
			366503875926u, 733007751850u, 1466015503702u, 2932031007402u, 5864062014806u,
			11728124029610u, 23456248059222u, 46912496118442u, 93824992236886u, 187649984473770u,
			375299968947542u, 750599937895082u, 1501199875790165u, 3002399751580331u,
			6004799503160661u, 12009599006321322u, 24019198012642644u, 48038396025285288u,
			96076792050570576u, 192153584101141152u, 384307168202282304u, 768614336404564608u,
			1537228672809129216u, 3074457345618258432u, 6148914691236516864u};
	typedef typename std::vector< T >::iterator VectorIterator;

	std::size_t size = std::distance(first, last) / itSize;

	if (size < 2) {
		return;
	}

	// Whether there is a stray element not in a pair
	bool has_stray = (size % 2 != 0);

	////////////////////////////////////////////////////////////
	// Group elements by pairs and sort each pair
	VectorIterator end = has_stray ? last - (1 * itSize) : last;
	for (VectorIterator it = first; it != end; it += 2 * itSize) {
		T value1 = *(it + (1 * itSize + itSize - 1));
		T value2 = *(it + itSize - 1);
		if (value1 < value2) {
			std::iter_swap(it, it + (1 * itSize));
			if (itSize > 1) {
				std::size_t i = itSize;
				std::size_t n = 1;
				while (i != itSize * 2 - 1 && n != itSize) {
					std::iter_swap(it + n, it + i + 1);
					++i;
					++n;
				}
			}
		}
	}

	////////////////////////////////////////////////////////////
	// Recursively sort the main chain
	sortVectorImp< T >(first, end, 2 * itSize);

	////////////////////////////////////////////////////////////
	// Separate the main chain and the pending elements
	std::vector< VectorIterator > main_chain;

	// main chain will hold maximum of size elements so we can reserve it size to avoid resizing
	// b1, a1 are already part of the main chain, so we can just push the first 2 elements
	main_chain.reserve(size + 1);
	main_chain.push_back(first);
	main_chain.push_back(first + (1 * itSize));

	// Vector to store iterators pointing to the pending elements bi:bj
	// The pend_chain will hold a maximum of ((size + 1) / 2) - 1 elements, so we can also reserve it
	std::vector< VectorIterator > pend_chain;
	pend_chain.reserve(((size + 1) / 2) - 1);

	// Iterate through the remaining elements, adding them to the pending chain
	for (VectorIterator it = first + (2 * itSize); it != end; it += (2 * itSize)) {
		typename std::vector< VectorIterator >::iterator tmp;
		tmp = main_chain.insert(main_chain.end(), it + (1 * itSize));
		pend_chain.push_back(*tmp);
	}

	// Add the last element to pend if it exists; when it
	// exists, it always has to be inserted in the full chain,
	// so giving it chain.end() as end insertion point is ok
	if (has_stray) {
		pend_chain.push_back(*(--main_chain.end()));
	}

	////////////////////////////////////////////////////////////
	// Binary insertion into the main chain
	VectorIterator current_it = first + (2 * itSize);
	typename std::vector< VectorIterator >::iterator current_pend = pend_chain.begin();
	VectorIterator biggest_of_the_pair;
	VectorIterator containerIterator;
	typename std::vector< VectorIterator >::iterator insertion_point;
	for (int k = 0;; k++) {
		// Find next index
		uint64_t dist = jacobsthal_diff[k];

		// Checks for overflow
		if (dist > static_cast< size_type >(std::distance(
						   current_pend,
						   pend_chain.end()))) {
			break;
		}

		VectorIterator it = current_it;
		std::advance(it, dist * 2 * itSize);

		typename std::vector< VectorIterator >::iterator pe = current_pend;
		std::advance(pe, dist);

		// Compare values in the original deque
		do {
			--pe;
			it -= (2 * itSize);
			biggest_of_the_pair = it + itSize - 1;
			if (pe == --pend_chain.end()) {
				insertion_point = custom_upper_bound(
						main_chain.begin(), main_chain.end(),
						*biggest_of_the_pair, main_chain, containerIterator, itSize, CompareIterators< T >());
			} else {
				insertion_point = custom_upper_bound(
						main_chain.begin(), pe,
						*biggest_of_the_pair, main_chain, containerIterator, itSize, CompareIterators< T >());
			}
			main_chain.insert(insertion_point, it);
		} while (pe != current_pend);
		std::advance(current_it, dist * 2 * itSize);
		std::advance(current_pend, dist);
	}


	// If there are pend elements left, insert them into
	// the main chain, the order of insertion does not
	// matter so forward traversal is ok
	while (current_pend != pend_chain.end()) {
		biggest_of_the_pair = current_it + itSize - 1;
		if (current_pend == --pend_chain.end()) {
			insertion_point = custom_upper_bound(
					main_chain.begin(), main_chain.end(), *biggest_of_the_pair,
					main_chain, containerIterator, itSize, CompareIterators< T >());
		} else {
			insertion_point = custom_upper_bound(
					main_chain.begin(), current_pend, *biggest_of_the_pair,
					main_chain, containerIterator, itSize, CompareIterators< T >());
		}
		main_chain.insert(insertion_point, current_it);
		current_it += (2 * itSize);
		++current_pend;
	}

	////////////////////////////////////////////////////////////
	// Move values in order to a cache then back to origin
	std::vector< T > cache;
	typename std::vector< VectorIterator >::iterator it;
	for (it = main_chain.begin(); it != main_chain.end(); it++) {
		VectorIterator cacheBegin = *it;
		VectorIterator cacheEnd = cacheBegin + itSize;

		cache.insert(cache.end(), cacheBegin, cacheEnd);
	}
	// Copy the values back from the cache to the original sequence
	std::copy(cache.begin(), cache.end(), first);
}


template< typename T >
void PmergeMe::sortDequeImp(typename std::deque< T >::iterator first, typename std::deque< T >::iterator last, std::size_t itSize)
{
	// Cache all the differences between a Jacobsthal number and its
	// predecessor that fit in 64 bits, starting with the difference
	// between the Jacobsthal numbers 4 and 3 (the previous ones are
	// unneeded)
	static const uint64_t jacobsthal_diff[] = {
			2u, 2u, 6u, 10u, 22u, 42u, 86u, 170u, 342u, 682u, 1366u,
			2730u, 5462u, 10922u, 21846u, 43690u, 87382u, 174762u, 349526u, 699050u,
			1398102u, 2796202u, 5592406u, 11184810u, 22369622u, 44739242u, 89478486u,
			178956970u, 357913942u, 715827882u, 1431655766u, 2863311530u, 5726623062u,
			11453246122u, 22906492246u, 45812984490u, 91625968982u, 183251937962u,
			366503875926u, 733007751850u, 1466015503702u, 2932031007402u, 5864062014806u,
			11728124029610u, 23456248059222u, 46912496118442u, 93824992236886u, 187649984473770u,
			375299968947542u, 750599937895082u, 1501199875790165u, 3002399751580331u,
			6004799503160661u, 12009599006321322u, 24019198012642644u, 48038396025285288u,
			96076792050570576u, 192153584101141152u, 384307168202282304u, 768614336404564608u,
			1537228672809129216u, 3074457345618258432u, 6148914691236516864u};
	typedef typename std::deque< T >::iterator DequeIterator;
	std::size_t size = std::distance(first, last) / itSize;
	if (size < 2) {
		return;
	}

	// Whether there is a stray element not in a pair
	bool has_stray = (size % 2 != 0);

	////////////////////////////////////////////////////////////
	// Group elements by pairs and sort each pair

	DequeIterator end = has_stray ? last - (1 * itSize) : last;
	for (DequeIterator it = first; it != end; it += 2 * itSize) {
		T value1 = *(it + (1 * itSize + itSize - 1));
		T value2 = *(it + itSize - 1);
		if (value1 < value2) {
			std::iter_swap(it, it + (1 * itSize));
			if (itSize > 1) {
				std::size_t i = itSize;
				std::size_t n = 1;
				while (i != itSize * 2 - 1 && n != itSize) {
					std::iter_swap(it + n, it + i + 1);
					++i;
					++n;
				}
			}
		}
	}
	////////////////////////////////////////////////////////////
	// Recursively sort the main chain
	sortDequeImp< T >(first, end, 2 * itSize); // Sort the first pair


	////////////////////////////////////////////////////////////
	// Separate the main chain and the pending elements
	std::deque< DequeIterator > main_chain;
	main_chain.push_back(first);
	main_chain.push_back((first + (1 * itSize)));


	// Deque to store iterators pointing to the pending elements
	std::deque< DequeIterator > pend_chain;


	// Iterate through the remaining elements, adding them to the pending chain
	for (DequeIterator it = first + (2 * itSize); it != end; it += (2 * itSize)) {
		typename std::deque< DequeIterator >::iterator tmp;
		tmp = main_chain.insert(main_chain.end(), (it + 1 * itSize));
		pend_chain.push_back(*tmp);
	}

	// Add the last element to pend if it exists; when it
	// exists, it always has to be inserted in the full chain,
	// so giving it main_chain.end() as end insertion point is ok
	if (has_stray) {
		pend_chain.push_back(*(--main_chain.end()));
	}

	////////////////////////////////////////////////////////////
	// Binary insertion into the main chain
	DequeIterator current_it = first + (2 * itSize);
	typename std::deque< DequeIterator >::iterator current_pend = pend_chain.begin();
	DequeIterator biggest_of_pair;
	DequeIterator containerIterator;
	for (int k = 0;; ++k) {
		// Find next index
		uint64_t dist = jacobsthal_diff[k];
		// Checks for overflow
		if (dist > static_cast< size_type >(std::distance(current_pend, pend_chain.end()))) {
			break;
		}

		DequeIterator it = current_it;
		std::advance(it, dist * 2 * itSize);

		typename std::deque< DequeIterator >::iterator pe = current_pend;
		std::advance(pe, dist);

		do {
			it -= (2 * itSize);
			--pe;
			// Compare values in the original deque
			biggest_of_pair = it + itSize - 1;
			typename std::deque< DequeIterator >::iterator insertion_point;
			if (pe == --pend_chain.end()) {
				insertion_point = custom_upper_bound(
						main_chain.begin(), main_chain.end(),
						*biggest_of_pair, main_chain, containerIterator, itSize, CompareIterators< T >());
			} else {
				insertion_point = custom_upper_bound(
						main_chain.begin(), pe,
						*biggest_of_pair, main_chain, containerIterator, itSize, CompareIterators< T >());
			}
			main_chain.insert(insertion_point, it);
		} while (pe != current_pend);

		std::advance(current_it, dist * 2 * itSize);
		std::advance(current_pend, dist);
	}

	// If there are pend elements left, insert them into
	// the main chain, the order of insertion does not
	// matter so forward traversal is ok
	while (current_pend != pend_chain.end()) {
		biggest_of_pair = current_it + itSize - 1;
		typename std::deque< DequeIterator >::iterator insertion_point;
		if (current_pend == --pend_chain.end()) {
			insertion_point = custom_upper_bound(
					main_chain.begin(), main_chain.end(),
					*biggest_of_pair, main_chain, containerIterator,
					itSize, CompareIterators< T >());
		} else {
			insertion_point = custom_upper_bound(
					main_chain.begin(), current_pend,
					*biggest_of_pair, main_chain, containerIterator,
					itSize, CompareIterators< T >());
		}
		main_chain.insert(insertion_point, current_it);
		current_it += (2 * itSize);
		++current_pend;
	}

	////////////////////////////////////////////////////////////
	// Move values in order to a cache then back to origin
	std::deque< T > cache;
	typename std::deque< DequeIterator >::iterator it;
	for (it = main_chain.begin(); it != main_chain.end(); it++) {
		DequeIterator cacheBegin = *it;
		DequeIterator cacheEnd = cacheBegin + itSize;

		cache.insert(cache.end(), cacheBegin, cacheEnd);
	}

	// Copy the values back from the cache to the original sequence
	std::copy(cache.begin(), cache.end(), first);
}

#endif // PMERGEME_HPP

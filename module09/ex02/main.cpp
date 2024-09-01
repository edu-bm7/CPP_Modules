#include "PmergeMe.hpp"
#include <limits>

template< typename Container >
bool is_sorted(const Container& deq)
{
	if (deq.empty()) {
		return true;
	}

	typename Container::const_iterator it = deq.begin();
	typename Container::const_iterator next = it;

	++next;
	while (next != deq.end()) {
		if (*next < *it) {
			return false; // The deque is not sorted.
		}
		++it;
		++next;
	}
	return true; // The deque is sorted.
}

int main(int argc, char* argv[])
{
	if (argc < 2) {
		std::cerr << "Error: No input provided" << std::endl;
		return 1;
	}

	// Deque Initialization
	std::deque< long > deq; // Change this to std::deque<int> or long, etc
	// Vector initialization
	std::vector< long > vec; // Change this to std::vector<int> or std::vector<unsigned long> as needed
	try {
		for (int i = 1; i < argc; ++i) {
			long num = std::atol(argv[i]);
			if (num > static_cast< long >(std::numeric_limits< int >::max())) {
				throw std::invalid_argument("Too big of a number.");
			}
			if (num < 0) {
				throw std::invalid_argument("Negative number.");
			}
			vec.push_back(num);
			deq.push_back(num);
		}
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}


	std::cout << "Before: ";
	for (std::size_t i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	PmergeMe Ford_Johnson;
	// Start the Vector timer
	std::clock_t start_time_vector = std::clock();

	// Sort the vector
	Ford_Johnson.sortVector< long >(vec.begin(), vec.end());

	// Stop the Vector timer
	std::clock_t end_time_vector = std::clock();

	// Calculate the elapsed Vector time in milliseconds
	double elapsed_time_vector = static_cast< double >(end_time_vector - start_time_vector) / CLOCKS_PER_SEC * 1000;


	std::cout << "After(std::vector<T>):\t";
	for (std::size_t i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	// Start the Deque Timer
	std::clock_t start_time_list = std::clock();

	// Sort the Deque
	Ford_Johnson.sortDeque< long >(deq.begin(), deq.end());

	// Stop the Deque timer
	std::clock_t end_time_list = std::clock();

	// Calculate the elapsed time in milliseconds
	double elapsed_time_list = static_cast< double >(end_time_list - start_time_list) / CLOCKS_PER_SEC * 1000;


	std::cout << "After(std::deque<T>):\t";
	std::deque< long >::iterator it; // Change this to your list type
	int i = 0;
	for (it = deq.begin(); it != deq.end(); ++it, ++i) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	if (is_sorted(vec)) {
		std::cout << "VECTOR SORTED!" << std::endl;
	} else {
		std::cerr << "VECTOR NOT SORTED!" << std::endl;
	}
	if (!is_sorted(deq)) {
		std::cerr << "DEQUE NOT SORTED!" << std::endl;
	} else {
		std::cout << "DEQUE SORTED!" << std::endl;
	}

	std::cout << "Time to process a range of: " << argc - 1 << " elements with std::vector<T> : " << elapsed_time_vector << " milliseconds" << std::endl;
	std::cout << "Time to process a range of: " << argc - 1 << " elements with std::deque<T> : " << elapsed_time_list << " milliseconds" << std::endl;

	return 0;
}

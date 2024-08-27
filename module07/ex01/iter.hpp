#ifndef ITER_HPP
#define ITER_HPP

#include <cstdlib>

template< typename T, typename F >
void iter(T* arr, std::size_t len, F function)
{
	for (std::size_t i = 0; i < len; ++i) {
		function(arr[i]);
	}
}

#endif // ITER_HPP

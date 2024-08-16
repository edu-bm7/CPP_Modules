#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <limits>
#include <ostream>
#include <vector>

class Span {
public:
	Span();                  // Canonical Default Constructor
	Span(const Span& other); // Canonical Copy Constructor
	~Span();                 // Canonical Default Destructor

	Span(unsigned int n);
	Span& operator=(const Span& rhs); // Canonical Assignment Operator

	// Exception Nested Classes
	class SpanFullException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class SpanNotPossibleException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	// Member Functions
	void addNumber(int number);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	template< typename InputIterator >
	void addNumbers(InputIterator first, InputIterator last);

	// Getters
	unsigned int getSize() const;
	std::vector< int > getNumbers() const;

private:
	std::vector< int > mNumbers;
	unsigned int mSize;
};

// Templates
template< typename InputIterator >
void Span::addNumbers(InputIterator first, InputIterator last)
{
	if (std::distance(first, last) > static_cast< long >(mSize - mNumbers.size())) {
		throw SpanFullException();
	}

	mNumbers.insert(mNumbers.end(), first, last);
}

std::ostream& operator<<(std::ostream& os, const Span& span);

#endif // SPAN_HPP

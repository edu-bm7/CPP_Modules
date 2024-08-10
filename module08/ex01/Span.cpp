#include "Span.hpp"

/*-------------------------------CONSTRUCTORS---------------------------------*/

Span::Span() : mNumbers(), mSize(0)
{
	return;
}

Span::Span(const Span& other) : mNumbers(other.mNumbers),
								mSize(other.mSize)
{
	return;
}

Span::Span(unsigned int n) : mSize(n)
{
	return;
}

/*--------------------------------DESTRUCTOR----------------------------------*/

Span::~Span()
{
	return;
}

/*--------------------------------OVERLOADS-----------------------------------*/

Span& Span::operator=(const Span& rhs)
{
	// Guard Self-Assignment
	if (this == &rhs) {
		return *this;
	}

	mSize = rhs.mSize;
	mNumbers = rhs.mNumbers;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Span& span)
{
	std::vector<int>::iterator it;
	std::vector<int> vec = span.getNumbers();

	os << "Span Max Capacity: " << span.getSize() << std::endl;
	os << "Span Elements:";

	for (it = vec.begin(); it != vec.end(); ++it) {
		os << " " << *it;
	}
	return os;
}

/*---------------------------------GETTERS------------------------------------*/

unsigned int Span::getSize() const
{
	return mSize;
}

std::vector<int> Span::getNumbers() const
{
	return mNumbers;
}

/*-------------------------------EXCEPTIONS-----------------------------------*/

const char* Span::SpanFullException::what() const throw()
{
	return "Maximum Capacity reached. Cannot add new elements.";
}

const char* Span::SpanNotPossibleException::what() const throw()
{
	return "Too few elements. Cannot calculate the span.";
}

/*----------------------------MEMBER FUNCTIONS--------------------------------*/

void Span::addNumber(int number)
{
	if (mNumbers.size() < mSize) {
		mNumbers.push_back(number);
	} else {
		throw SpanFullException();
	}
}

unsigned int Span::shortestSpan() const
{
	if (mNumbers.size() < 2) {
		throw SpanNotPossibleException();
	}

	unsigned int shortest_span = std::numeric_limits<unsigned int>::max();
	std::vector<int> vec = mNumbers;
	std::sort(vec.begin(), vec.end());

	for (std::vector<int>::iterator it = vec.begin(); it != vec.end() - 1; ++it) {
		unsigned int span = static_cast<unsigned int>(*(it + 1) - *it);
		if (span < shortest_span) {
			shortest_span = span;
		}
	}

	return shortest_span;
}

unsigned int Span::longestSpan() const
{
	return *std::max_element(mNumbers.begin(), mNumbers.end()) - *std::min_element(mNumbers.begin(), mNumbers.end());
}

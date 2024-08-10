#include "Span.hpp"
#include <cstdlib>
#include <ctime>

static void testInvalidSpan();
static void testNegativeSpan();
static void testSmallSpan();
static void testBigSpan();

int main()
{
	std::srand(static_cast<unsigned int>(std::time(0)));

	testInvalidSpan();
	testNegativeSpan();
	testSmallSpan();
	testBigSpan();

	return 0;
}

static void testInvalidSpan()
{
	std::cout << "--------------- INVALID SPAN TESTS ---------------\n";
	try {
		Span invalid;
		std::cout << "Invalid Span: " << invalid << std::endl;
		invalid.addNumber(6);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Span invalid(1);
		invalid.addNumber(2);
		std::cout << "Invalid Span: " << invalid << std::endl;
		invalid.shortestSpan();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Span invalid(1);
		invalid.addNumber(2);
		std::cout << "Invalid Span: " << invalid << std::endl;
		invalid.longestSpan();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Span invalid(2);
		invalid.addNumber(2);
		invalid.addNumber(3);
		std::cout << "Invalid Span: " << invalid << std::endl;
		invalid.addNumber(4);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Span invalid(3);
		std::vector<int> nums(5, 2);
		std::cout << "Invalid Span: " << invalid << std::endl;
		invalid.addNumbers(nums.begin(), nums.end());
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

static void testNegativeSpan()
{
	std::cout << "---------------- NEGATIVE SPAN TESTS ----------------\n";

	{
		Span negative_span(5);

		negative_span.addNumber(-6);
		negative_span.addNumber(3);
		negative_span.addNumber(-17);
		negative_span.addNumber(9);
		negative_span.addNumber(-11);
		std::cout << "Negative Span: " << negative_span << std::endl;
		std::cout << "shortest span: " << negative_span.shortestSpan() << std::endl;
		std::cout << "longest span: " << negative_span.longestSpan() << std::endl;
	}
	std::cout << std::endl;
	{
		Span negative_span(5);
		std::vector<int> nums(4, -6);
		nums.push_back(-10);

		negative_span.addNumbers(nums.begin(), nums.end());
		std::cout << "Negative Span: " << negative_span << std::endl;
		std::cout << "shortest span: " << negative_span.shortestSpan() << std::endl;
		std::cout << "longest span: " << negative_span.longestSpan() << std::endl;
	}
}

static void testSmallSpan()
{
	std::cout << "---------------- SMALL SPAN TESTS ----------------\n";

	{
		Span small_span(5);

		small_span.addNumber(6);
		small_span.addNumber(3);
		small_span.addNumber(17);
		small_span.addNumber(9);
		small_span.addNumber(11);
		std::cout << "Small Span: " << small_span << std::endl;
		std::cout << "shortest span: " << small_span.shortestSpan() << std::endl;
		std::cout << "longest span: " << small_span.longestSpan() << std::endl;
	}
	std::cout << std::endl;
	{
		Span small_span(5);
		std::vector<int> nums(4, 6);
		nums.push_back(10);

		small_span.addNumbers(nums.begin(), nums.end());
		std::cout << "Small Span: " << small_span << std::endl;
		std::cout << "shortest span: " << small_span.shortestSpan() << std::endl;
		std::cout << "longest span: " << small_span.longestSpan() << std::endl;
	}
}

static void testBigSpan()
{
	std::cout << "------------------ BIG SPAN TESTS ------------------\n";

	{

		std::cout << "------------------ addNumber() TESTS ------------------\n";
		Span big_span(2000);

		for (unsigned int i = 0; i < big_span.getSize(); ++i) {
			big_span.addNumber(std::rand() % 200000000);
		}

		std::vector<int> vec = big_span.getNumbers();

		// Uncomment this line only and it'll print all elements of big_span,
		// please change the big_span size first (around 2000 and we can see it in our terminal) :)
		// std::cout << "Big Span: " << big_span << std::endl;

		std::cout << "MAX_NUMBER: " << *std::max_element(vec.begin(), vec.end()) << std::endl;
		std::cout << "MIN_NUMBER: " << *std::min_element(vec.begin(), vec.end()) << std::endl;

		std::cout << "shortest span: " << big_span.shortestSpan() << std::endl;
		std::cout << "longest span: " << big_span.longestSpan() << std::endl;
	}
	{
		std::cout << "------------------ addNumbers(range) TESTS ------------------\n";

		Span big_span(200000);

		std::vector<int> nums(199999, 542);
		nums.push_back(500);

		big_span.addNumbers(nums.begin(), nums.end());
		std::vector<int> vec = big_span.getNumbers();

		// Uncomment this line only and it'll print all elements of big_span,
		// please change the big_span size first (around 2000 and we can see it in our terminal) :)
		// std::cout << "Big Span: " << big_span << std::endl;
		std::cout << "MAX_NUMBER: " << *std::max_element(vec.begin(), vec.end()) << std::endl;
		std::cout << "MIN_NUMBER: " << *std::min_element(vec.begin(), vec.end()) << std::endl;

		std::cout << "shortest span: " << big_span.shortestSpan() << std::endl;
		std::cout << "longest span: " << big_span.longestSpan() << std::endl;
	}
}

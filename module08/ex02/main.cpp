#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	std::cout << "/* ******************************* PDF TESTS "
				 "******************************** *\\\n";
	{
		MutantStack< int > mstack;

		std::cout << "=== MUTANT STACK OUTPUT ===\n";
		mstack.push(5);
		mstack.push(17);
		std::cout << "top (equivalent to back): " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "total size: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack< int >::iterator it = mstack.begin();
		MutantStack< int >::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << "mstack MutantStack content:";
		while (it != ite) {
			std::cout << ' ' << *it;
			++it;
			std::stack< int > s(mstack);
		}
	}
	std::cout << "\n\n";
	{
		std::list< int > lst;

		std::cout << "=== STANDARD LIST OUTPUT ===\n";
		lst.push_back(5);
		lst.push_back(17);
		std::cout << "back (equivalent to top): " << lst.back() << std::endl;
		lst.pop_back();
		std::cout << "total size: " << lst.size() << std::endl;
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(0);
		std::list< int >::iterator it = lst.begin();
		std::list< int >::iterator ite = lst.end();
		++it;
		--it;
		std::cout << "lst std::list content:";
		while (it != ite) {
			std::cout << ' ' << *it;
			++it;
		}
	}
	std::cout << "\n\\* *************************************"
			  << "************************************* */\n\n";

	MutantStack< int > ms1, ms_tmp;

	std::cout << "=== STACK MEMBER FUNCTIONS ===\n"
			  << "ms1.empty():  " << (ms1.empty() ? "true" : "false") << '\n'
			  << "ms1.size():   " << ms1.size() << '\n'
			  << "ms1.push(42)" << '\n'
			  << "ms1.push(21)" << '\n';
	ms1.push(42);
	ms1.push(21);

	std::cout << "\nms1.empty():  " << (ms1.empty() ? "true" : "false") << '\n'
			  << "ms1.size():   " << ms1.size() << '\n'
			  << "ms1.top():    " << ms1.top() << '\n'
			  << "ms1.pop()" << '\n';
	ms1.pop();

	std::cout << "\nms1.empty():  " << (ms1.empty() ? "true" : "false") << '\n'
			  << "ms1.size():   " << ms1.size() << '\n'
			  << "ms1.top():    " << ms1.top() << '\n';

	std::cout << "\n=== MUTANTSTACK ITERATORS ===\n";
	ms1.push(1337);
	ms1.push(19);
	ms1.push(123);
	std::cout << "ms1 MutantStack iterator:              ";
	for (MutantStack< int >::iterator it = ms1.begin(); it != ms1.end(); ++it) {
		std::cout << ' ' << *it;
	}

	std::cout << "\nms1 MutantStack const iterator:        ";
	for (MutantStack< int >::const_iterator it = ms1.begin(); it != ms1.end();
		 ++it) {
		std::cout << ' ' << *it;
	}
	std::cout << "\nms1 MutantStack reverse iterator:      ";

	for (MutantStack< int >::reverse_iterator it = ms1.rbegin(); it != ms1.rend();
		 ++it) {
		std::cout << ' ' << *it;
	}

	std::cout << "\nms1 MutantStack const reverse iterator:";
	for (MutantStack< int >::const_reverse_iterator it = ms1.rbegin();
		 it != ms1.rend();
		 ++it) {
		std::cout << ' ' << *it;
	}

	std::cout << "\n\n=== MUTANTSTACK COPY CONSTRUCTOR & ASSIGNMENT ===\n";

	MutantStack< int > ms2(ms1);
	std::cout << "MutantStack<int> ms2(ms1)\n"
			  << "ms2 content (iterator):         ";
	for (MutantStack< int >::iterator it = ms2.begin(); it != ms2.end(); ++it) {
		std::cout << ' ' << *it;
	}

	std::cout << "\nms2 content (reverse iterator): ";
	for (MutantStack< int >::reverse_iterator it = ms2.rbegin(); it != ms2.rend();
		 ++it) {
		std::cout << ' ' << *it;
	}

	MutantStack< int > ms3;
	ms3 = ms1;
	std::cout << "\n\nMutantStack<int> ms3\n"
			  << "ms3 = ms1\n"
			  << "ms3 content (iterator):         ";
	for (MutantStack< int >::iterator it = ms3.begin(); it != ms3.end(); ++it) {
		std::cout << ' ' << *it;
	}

	std::cout << "\nms3 content (reverse iterator): ";
	for (MutantStack< int >::reverse_iterator it = ms3.rbegin(); it != ms3.rend();
		 ++it) {
		std::cout << ' ' << *it;
	}

	std::cout << std::endl;

	return 0;
}

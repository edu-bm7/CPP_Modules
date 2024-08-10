#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <stack>

template< class T, class Container = std::deque< T > >
class MutantStack : public std::stack< T, Container > {
public:
	// Canonical Default Constructor
	MutantStack() {}

	// Canonical Copy Constructor
	MutantStack(const MutantStack& other) : std::stack< T, Container >(other) {}

	// Canonicap Default Destructor
	virtual ~MutantStack() {}

	// Canonical Assignment Operator
	MutantStack& operator=(const MutantStack& rhs)
	{
		if (this == &rhs) {
			return *this;
		}
		std::stack< T, Container >::operator=(rhs);
		return *this;
	}

	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;
	typedef typename Container::reverse_iterator reverse_iterator;
	typedef typename Container::const_reverse_iterator const_reverse_iterator;

	// Non-Constant Methods
	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
	reverse_iterator rbegin() { return this->c.rbegin(); }
	reverse_iterator rend() { return this->c.rend(); }

	// Constant Methods
	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }
	const_reverse_iterator rbegin() const { return this->c.rbegin(); }
	const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif // MUTANTSTACK_HPP

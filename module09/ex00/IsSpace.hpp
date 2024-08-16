#ifndef ISSPACE_HPP
#define ISSPACE_HPP

#include <cctype>

struct IsSpace {
	bool operator()(char c) const;
};

#endif // ISSPACE_HPP

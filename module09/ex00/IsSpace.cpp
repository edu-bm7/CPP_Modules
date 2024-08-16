#include "IsSpace.hpp"

bool IsSpace::operator()(char c) const
{
	return std::isspace(static_cast< unsigned char >(c));
}

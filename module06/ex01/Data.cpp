#include "Data.hpp"


/*-------------------------------CONSTRUCTORS---------------------------------*/

Data::Data() : mValue(42)
{
	std::cout << "Data created with Default Constructor." << std::endl;
}

Data::Data(int value) : mValue(value)
{
	std::cout << "Data created with Parameterized Constructor." << std::endl;
}

Data::Data(const Data& other) : mValue(other.getValue())
{
	std::cout << "Data created with Copy Constructor." << std::endl;
}

/*--------------------------------DESTRUCTOR----------------------------------*/

Data::~Data()
{
	std::cout << "Data Destructor called." << std::endl;
}

/*--------------------------------OVERLOADS-----------------------------------*/

Data& Data::operator=(const Data& rhs)
{
	std::cout << "Data has been attributed." << std::endl;

	// Guard Self-Assignment
	if (this == &rhs) {
		return *this;
	}

	mValue = rhs.getValue();
	return *this;
}

/*----------------------------MEMBER FUNCTIONS--------------------------------*/

int Data::getValue() const
{
	return mValue;
}

void Data::setValue(int value)
{
	mValue = value;
}

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data {
public:
	Data();                  // Canonical Default Constructor
	Data(const Data& other); // Canonical Copy Constructor
	~Data();                 // Canonical Default Destructor

	Data(int Value);

	Data& operator=(const Data& rhs); // Canonical Assignment Operator

	// Getters
	int getValue() const;
	// Setters
	void setValue(int value);

private:
	int mValue;
};

#endif // DATA_HPP

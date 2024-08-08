#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>
#include <sstream>

int main()
{
	Data dataObject(77);

	uintptr_t serializedData = Serializer::serialize(&dataObject);

	Data* deserializedData = Serializer::deserialize(serializedData);

	std::cout << "Original data value:\t\t "
			  << dataObject.getValue() << std::endl;
	std::cout << "Deserialized data value:\t "
			  << deserializedData->getValue() << std::endl
			  << std::endl;
	std::cout << "Serialized data value(long int): "
			  << serializedData << std::endl
			  << std::endl;

	// Convert a uintptr_t(long int) into Hexadecimal String
	std::ostringstream oss;
	oss << std::hex << serializedData;
	std::string hexStr = oss.str();

	std::cout << "Serialized data value in hex:\t 0x"
			  << hexStr << std::endl;
	std::cout << "Original data address:\t\t "
			  << &dataObject << std::endl;
	std::cout << "Deserialized data address:\t "
			  << deserializedData << std::endl;

	return 0;
}

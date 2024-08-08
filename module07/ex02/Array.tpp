/*-------------------------------CONSTRUCTORS---------------------------------*/

#include <stdexcept>
template<typename T>
Array<T>::Array() : mElements(NULL), mSize(0)
{
	std::cout << "Empty Array Created." << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int n) : mElements(NULL), mSize(n)
{
	if (!n) {
		return;
	}

	mElements = new T[mSize]();
	std::cout << "Array with " << mSize
			  << " elements has been created and initialized." << std::endl;
}

template<typename T>
Array<T>::Array(const Array<T>& other) : mElements(NULL), mSize(other.mSize)
{
	if (!mSize) {
		return;
	}

	mElements = new T[mSize];
	for (unsigned int i = 0; i < mSize; ++i) {
		mElements[i] = other.mElements[i];
	}
	std::cout << "Elements of array deep copied via Copy Constructor." << std::endl;
}

/*--------------------------------DESTRUCTOR----------------------------------*/

template<typename T>
Array<T>::~Array()
{
	if (mElements) {
		delete[] mElements;
	}
	std::cout << "Array Destructor called." << std::endl;
}

/*--------------------------------OVERLOADS-----------------------------------*/

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& rhs)
{
	// Guard Self-Assignment
	if (this == &rhs) {
		return *this;
	}

	if (mElements || !rhs.mSize) {
		delete[] mElements;
		if (!rhs.mSize) {
			mSize = 0;
			return *this;
		}
	}
	mSize = rhs.mSize;
	mElements = new T[mSize];
	for (unsigned int i = 0; i < mSize; ++i) {
		mElements[i] = rhs.mElements[i];
	}
	std::cout << "Array Construction done by Assignment Operator." << std::endl;
}

template<typename T>
T& Array<T>::operator[](const unsigned int index) const
{
	if (index >= mSize) {
		throw std::out_of_range("Array Index out of bounds");
	}
	return mElements[index];
}

/*------------------------------MEMBER FUNCTION-------------------------------*/

template<typename T>
unsigned int Array<T>::size() const
{
	return mSize;
}

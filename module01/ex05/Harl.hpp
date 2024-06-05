#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
public:
	void complain(std::string level);
private:
	void debug();
	void info();
	void warning();
	void error();
};

/*
 * How can I avoid syntax errors when creating pointers to members?
 * https://isocpp.org/wiki/faq/pointers-to-members#typedef-for-ptr-to-memfn
 * How can I avoid syntax errors when calling a member function 
 * using a pointer-to-member-function?
 * https://isocpp.org/wiki/faq/pointers-to-members#macro-for-ptr-to-memfn
 * How do I create and use an array of pointer-to-member-function?
 * https://isocpp.org/wiki/faq/pointers-to-members#array-memfnptrs
 *
 * How would it look like without typedef and macros for this simple usecase ?
 *
 * void (Harl::*funcs[4])(void)
 * (this->*funcs[i])();
 *
 * We can see that it can get really messy and hard to read
 * */

typedef  void (Harl::*HarlMemFn)(void);

#define CALL_MEMBER_FN(object,ptrToMember) ((object).*(ptrToMember))

#endif

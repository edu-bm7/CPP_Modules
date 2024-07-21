#include "ShrubberyCreationForm.hpp"

/*-------------------------------CONSTRUCTORS---------------------------------*/

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), mTarget("undefined")
{
	std::cout << "ShrubberyCreationForm created with Default Constructor."
			  << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", SCF_SIGN_GRADE, SCF_EXEC_GRADE), mTarget(target)
{
	std::cout << "ShrubberyCreationForm created with Parameterized Constructor."
			  << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), mTarget(other.getTarget())
{
	std::cout << "ShrubberyCreationForm created with Copy Constructor."
			  << std::endl;
}

/*--------------------------------DESTRUCTOR----------------------------------*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor called."
			  << std::endl;
}

/*--------------------------------OVERLOADS-----------------------------------*/

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	// Guard Self-Assigment
	if (this == &rhs) {
		return *this;
	}
	throw UnassignableException();
}

/*-------------------------------EXCEPTIONS-----------------------------------*/

const char* ShrubberyCreationForm::FileCreateErrorException::what() const throw()
{
	return "Could not create Shrubbery File";
}


const char* ShrubberyCreationForm::FileWriteErrorException::what() const throw()
{
	return "Could not write into Shrubbery File";
}

/*----------------------------MEMBER FUNCTIONS--------------------------------*/

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream outputFile;
	outputFile.open((mTarget + "_shrubbery").c_str(), std::fstream::out | std::fstream::trunc);
	if (outputFile.fail()) {
		throw FileCreateErrorException();
	}
	outputFile
			<< "             # #### ####\n"
			<< "           ### \\/#|### |/####\n"
			<< "          ##\\/#/ \\||/##/_/##/_#\n"
			<< "        ###  \\/###|/ \\/ # ###\n"
			<< "      ##_\\_#\\_\\## | #/###_/_####\n"
			<< "     ## #### # \\ #| /  #### ##/##\n"
			<< "      __#_--###`  |{,###---###-~\n"
			<< "                \\ }{\n"
			<< "                 }}{\n"
			<< "                 }}{\n"
			<< "                 {{}\n"
			<< "           , -=-~{ .-^- _\n";
	if (outputFile.bad()) {
		throw FileWriteErrorException();
	}
	outputFile.close();
}

/*---------------------------------GETTERS------------------------------------*/

std::string ShrubberyCreationForm::getTarget() const
{
	return mTarget;
}

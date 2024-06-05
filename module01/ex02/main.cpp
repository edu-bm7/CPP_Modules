#include <iostream>
#include <string>

int main()
{
    std::string brain = "HI THIS IS BRAIN";
    std::string* stringPTR = &brain;
    std::string& stringREF = brain;

    std::cout << "Memory address of variable : \t" <<  &brain << std::endl;
    std::cout << "Memory address of stringPTR: \t" <<  stringPTR << std::endl;
    std::cout << "Memory address of stringREF: \t" <<  &stringREF << std::endl;
    std::cout << "Value of variable: \t\t" <<  brain << std::endl;
    std::cout << "Value pointed by stringPTR: \t" <<  *stringPTR << std::endl;
    std::cout << "Value pointed by stringREF: \t" <<  stringREF << std::endl;

}
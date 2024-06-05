#include "replaceAll.hpp"
#include <fstream>
#include <iostream>
#include <string>

static bool isValidInputFile(std::ifstream& ifs, std::string const& filename);
static bool isValidOutputFile(std::ofstream& ofs,
			      std::string const& outFilename);

bool replaceAll(std::string const& filename,
		std::string const& s1,
		std::string const& s2)
{
	std::ifstream ifs(filename.c_str(), std::ifstream::in);

	if (!isValidInputFile(ifs, filename)) {
		return false;
	}

	if (s1.empty()) {
		std::cerr << "String to be replaced(Str1) can't be empty." << std::endl;
		return false;
	}

	std::string outFilename = filename + ".replace";
	std::ofstream ofs(outFilename.c_str());

	if (!isValidOutputFile(ofs, outFilename)) {
		return false;
	}

	std::string line;
	while (std::getline(ifs, line)) {
		std::size_t found = line.find(s1);
		while (found != std::string::npos) {
			line.erase(found, s1.length());
			line.insert(found, s2);
			found = line.find(s1, found + s2.length());
		}
		ofs << line << std::endl;
	}
	ifs.close();
	ofs.close();

	return true;
}

static bool isValidInputFile(std::ifstream& ifs, std::string const& filename)
{
    if (!ifs) {
		std::cerr << "Error: Cannot open file '" << filename << "'" << std::endl;
		return false;
	} else if (ifs.peek() == std::ifstream::traits_type::eof()) {
		std::cerr << "Error: File '" << filename << "'" << " is empty" << std::endl;
		return false;
	}
	return true;
}

static bool isValidOutputFile(std::ofstream& ofs,
			      std::string const& outFilename)
{
	if (!ofs) {
		std::cerr << "Error: Cannot open file '" << outFilename << "'" << std::endl;
		return false;
	}
	return true;
}

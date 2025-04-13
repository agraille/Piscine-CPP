#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery Creation", 145, 137), _target(target) {}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target){}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
    if (this != &other) {
		AForm::operator=(other);
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
    AForm::execute(executor);
    std::ofstream file((_target + "_shrubbery").c_str());
    if (file.is_open()) {
		file << "       *\n";
		file << "      ***\n";
		file << "     *****\n";
		file << "    *******\n";
		file << "   *********\n";
		file << "  ***********\n";
		file << " *************\n";
		file << "***************\n";
		file << "      |||\n";
		file.close();
	}
    else
        throw std::runtime_error("Error: unable to create file");
}

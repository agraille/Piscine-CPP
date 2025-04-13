#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern& other){
	(void)other;
}

Intern::~Intern(){}

Intern& Intern::operator=(const Intern& other){
	(void)other;
    return *this;
}

static AForm*	newPresident(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

static AForm*	newRobot(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

static AForm*	newShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const{
	AForm* (*formCreator[])(const std::string&) = {
		&newShrubbery,
		&newRobot,
		&newPresident
	};
	const std::string	forms[] = { "shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 3; ++i){
		if (formName == forms[i]){
			std::cout << "Intern creates " << formName << "\n";
			return formCreator[i](target);
		}
	}
	std::ostringstream buffer;
	buffer << formName << " doesn't exist, try with shrubbery creation / robotomy request / presidential pardon";
	throw FormNotExistExeption(buffer.str());
}

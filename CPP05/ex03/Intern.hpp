#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <sstream>

class AForm;

class Intern{

	public:
		Intern();
    	Intern(const Intern& other);
    	~Intern();
		Intern& operator=(const Intern& other);

		AForm*	makeForm(const std::string& formName, const std::string& target) const;

		class FormNotExistExeption : public std::exception{
			public:
				FormNotExistExeption(const std::string& message) : _message(message){};
				virtual ~FormNotExistExeption()  throw(){};
				const char* what() const throw(){
					return _message.c_str();
				}
			private:
				const std::string _message;
		};
};

#endif

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <ostream>
#include <exception>
#include "AForm.hpp"

class AForm;
class Bureaucrat{

	public:
		Bureaucrat(const std::string& name, int grade);
    	Bureaucrat(const Bureaucrat& other);
    	~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& other);

		const std::string& getName() const;
		int	getGrade() const;
		void decrementGrade();
		void incrementGrade();
		void signForm(AForm& form);
		void executeForm(AForm const& form) const;

		class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw(){
				return "Grade too high";
			}
	};
	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw(){
				return "Grade too low";
			}
	};

	private:
		const std::string _name;
		int	_grade;
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& bureaucrat);

#endif

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <ostream>

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

	private:
		const std::string _name;
		int	_grade;

	class GradeTooHighException : public std::exception {
		const char* what() const throw(){
			return "Grade too high";
		}
	};
	class GradeTooLowException : public std::exception {
		const char* what() const throw(){
			return "Grade too low";
		}
	};
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& bureaucrat);

#endif

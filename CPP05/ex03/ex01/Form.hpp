#ifndef FORM_HPP
#define FORM_HPP

#include <Bureaucrat.hpp>
class Bureaucrat;

class Form{

	public:
		Form(const std::string& name, const int& gradeToSign, const int gradeToExecute);
    	Form(const Form& other);
    	~Form();
		Form& operator=(const Form& other);

		void	beSigned(const Bureaucrat& agent);
		const std::string& getName() const;
		const int& getGradeToSign() const;
		const int& getGradeToExecute() const;
		bool       getIsSigned() const;
		void	   setIsSigned(bool value);

	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw(){
				return "(form) Grade too high";
			}
	};
	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw(){
				return "(form) Grade too low";
			}
	};
	private:
		const std::string _name;
		bool	_isSigned;
		const int	_gradeToSign;
		const int	_gradeToExecute;
};

std::ostream& operator<<(std::ostream& o, const Form& form);

#endif

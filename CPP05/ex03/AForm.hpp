#ifndef AFORM_HPP
#define AFORM_HPP

#include <Bureaucrat.hpp>

class Bureaucrat;

class AForm{

	public:
		AForm(const std::string& name, const int& gradeToSign, const int gradeToExecute);
    	AForm(const AForm& other);
    	virtual ~AForm() = 0;
		AForm& operator=(const AForm& other);

		void	beSigned(const Bureaucrat& agent);
		const std::string& getName() const;
		const int& getGradeToSign() const;
		const int& getGradeToExecute() const;
		bool       getIsSigned() const;
		void	   setIsSigned(bool value);
		virtual void execute(Bureaucrat const& executor) const;

	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw(){
				return "(Aform) Grade too high";
			}
	};
	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw(){
				return "(Aform) Grade too low";
			}
	};
	class FormNotSignedException : public std::exception {
		public:
			const char* what() const throw() {
				return "Form is not signed!";
			}
	};
	private:
		const std::string _name;
		bool	_isSigned;
		const int	_gradeToSign;
		const int	_gradeToExecute;
};

std::ostream& operator<<(std::ostream& o, const AForm& Aform);

#endif

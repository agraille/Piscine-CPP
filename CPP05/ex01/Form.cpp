#include "Form.hpp"

Form::Form(const std::string& name, const int& gradeToSign, const int gradeToExecute) 
: _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
	if (_gradeToExecute < 1 || _gradeToSign < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw GradeTooLowException();
	_isSigned = false;

}

Form::Form(const Form& other)
: _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute){
	this->_isSigned = other._isSigned;
}

Form::~Form(){
}

Form& Form::operator=(const Form& other){
    if (this != &other) {
		this->_isSigned = other._isSigned;
    }
    return *this;	
}

std::ostream& operator<<(std::ostream& o, const Form& form){
	o << "Form name is : " << form.getName() << "\nStatus is signed : " << form.getIsSigned() \
	<< "\nGrade to sign is : " << form.getGradeToSign() << "\nGrade to execute is : " << form.getGradeToExecute();
	return o;
}

const std::string& Form::getName() const{
	return _name;
}

const int& Form::getGradeToSign() const{
	return _gradeToSign;
}

const int& Form::getGradeToExecute() const{
	return _gradeToExecute;
}

bool       Form::getIsSigned() const{
	return _isSigned;
}

void	Form::setIsSigned(bool value){
	_isSigned = value;
}

void	Form::beSigned(const Bureaucrat& agent){
	if (agent.getGrade() <= getGradeToSign()){
		std::cout << agent.getName() << " signed " << this->getName() << "\n";
		setIsSigned(true);
	}
	else{
		std::cout << agent.getName() << " couldn’t sign " << this->getName() << " because ";
		throw GradeTooLowException();
	}
 }

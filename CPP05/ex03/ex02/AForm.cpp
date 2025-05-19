#include "AForm.hpp"

AForm::AForm(const std::string& name, const int& gradeToSign, const int gradeToExecute) 
: _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
	if (_gradeToExecute < 1 || _gradeToSign < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw GradeTooLowException();
	_isSigned = false;

}

AForm::AForm(const AForm& other)
: _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute){
	this->_isSigned = other._isSigned;
}

AForm::~AForm(){}

AForm& AForm::operator=(const AForm& other){
    if (this != &other) {
		this->_isSigned = other._isSigned;
    }
    return *this;	
}

std::ostream& operator<<(std::ostream& o, const AForm& Aform){
	o << "AForm name is : " << Aform.getName() << "\nStatus is signed : " << Aform.getIsSigned() \
	<< "\nGrade to sign is : " << Aform.getGradeToSign() << "\nGrade to execute is : " << Aform.getGradeToExecute();
	return o;
}

const std::string& AForm::getName() const{
	return _name;
}

const int& AForm::getGradeToSign() const{
	return _gradeToSign;
}

const int& AForm::getGradeToExecute() const{
	return _gradeToExecute;
}

bool       AForm::getIsSigned() const{
	return _isSigned;
}

void	AForm::setIsSigned(bool value){
	_isSigned = value;
}

void	AForm::beSigned(const Bureaucrat& agent){
	if (agent.getGrade() <= getGradeToSign()){
		std::cout << agent.getName() << " signed " << this->getName() << "\n";
		setIsSigned(true);
	}
	else{
		std::cout << agent.getName() << " couldn’t sign " << this->getName() << " because ";
		throw GradeTooLowException();
	}
 }

 void AForm::execute(Bureaucrat const& executor) const {
    if (!_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException();
}

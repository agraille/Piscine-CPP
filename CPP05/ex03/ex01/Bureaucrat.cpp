#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade){
	if (_grade < 1)
        throw GradeTooHighException();
    if (_grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade){
}

Bureaucrat::~Bureaucrat(){
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
    if (this != &other)
        _grade = other._grade;
    return *this;
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& bureaucrat){
	o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return o;
}

int	Bureaucrat::getGrade() const{
	return _grade;
}

const std::string& Bureaucrat::getName() const{
	return _name;
}

void Bureaucrat::incrementGrade() {
    if (_grade <= 1) {
        throw GradeTooHighException();
    }
    --_grade;
}

void Bureaucrat::decrementGrade() {
    if (_grade >= 150) {
        throw GradeTooLowException();
    }
    ++_grade;
}

void Bureaucrat::signForm(Form& form){
	form.beSigned(*this);
}

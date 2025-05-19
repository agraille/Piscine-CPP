#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy Request", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target){}

RobotomyRequestForm::~RobotomyRequestForm(){
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
    AForm::execute(executor);
    std::cout << "Drilling noises...\n";
	std::srand(time(0));
    if (rand() % 2 == 0) { 
        std::cout << _target << " has been robotomized successfully\n";
    }
	else
        std::cout << "The robotomy failed on " << _target << "\n";
}

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm{

	public:
		RobotomyRequestForm(const std::string& target);
    	RobotomyRequestForm(const RobotomyRequestForm& other);
    	~RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

		virtual void execute(Bureaucrat const& executor) const;

	private:
	const std::string _target;
};

#endif

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm{

	public:
		ShrubberyCreationForm(const std::string& target);
    	ShrubberyCreationForm(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

		virtual void execute(Bureaucrat const& executor) const;

	private:
		const std::string _target;
};

#endif

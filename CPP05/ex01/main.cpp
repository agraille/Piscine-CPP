#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(){

	try {
		Bureaucrat	bob("bob", 150);
		Form	A("test", 1, 150);
		// std::cout << A << "\n";
		bob.signForm(A);

	}
	catch(const Bureaucrat::GradeTooHighException& e){
		std::cout << e.what() << "\n";
	}
	catch(const Bureaucrat::GradeTooLowException& e){
		std::cout << e.what() << "\n";
	}
	catch(const Form::GradeTooLowException& e){
		std::cout << e.what() << "\n";
	}
	catch(const Form::GradeTooHighException& e){
		std::cout << e.what() << "\n";
	}
	catch(const std::exception& e){
		std::cout << e.what() << "\n";
	}
	return 0;
}

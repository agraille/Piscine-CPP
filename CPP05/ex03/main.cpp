#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 1);
		Intern	random;
		AForm*	test;

		test = random.makeForm("shrubbery creation", "shrub");
	
        bob.signForm(*test);
        bob.executeForm(*test);

		delete test;

		AForm*	test2;
		test2 = random.makeForm("robotomy request", "shrub");
	
        bob.signForm(*test2);
        bob.executeForm(*test2);

		delete test2;

		AForm*	test3;
		test3 = random.makeForm("presidential pardon", "shrub");
	
        bob.executeForm(*test3);

		delete test3;
    }
    catch (const std::exception& e) {
        std::cout << e.what() << "\n";
	}
    return 0;
}

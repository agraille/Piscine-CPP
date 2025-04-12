#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 30);
        ShrubberyCreationForm shrub("Home");
        RobotomyRequestForm robot("Alice");
        PresidentialPardonForm pardon("John");

        bob.signForm(shrub);
        bob.executeForm(shrub);

        bob.signForm(robot);
        bob.executeForm(robot);

		// while (bob.getGrade() != 1)
		// 	bob.incrementGrade();

        bob.signForm(pardon);
        bob.executeForm(pardon);
    }
    catch (const std::exception& e) {
        std::cout << e.what() << "\n";
    }

    return 0;
}

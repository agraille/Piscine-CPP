#include "Bureaucrat.hpp"

int	main(){
	try{
		Bureaucrat	jagaan("JAGAAN", 150);
		std::cout << jagaan << std::endl;
		jagaan.incrementGrade();
		std::cout << jagaan << std::endl;
		jagaan.decrementGrade();
		std::cout << jagaan << std::endl;
		Bureaucrat	bis("bis", 1);
		std::cout << bis << "\n";
		bis = jagaan;
		std::cout << bis << "\n";
		jagaan.decrementGrade();
	}
	catch(const std::exception& e){
		std::cout << e.what() << "\n";
	}
	try{
		Bureaucrat fail("fail", -1);
		std::cout << fail << "\n";
	}
	catch (const std::exception& e){
		std::cout << e.what() << "\n";
	}
	return 0;
}

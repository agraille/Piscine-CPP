#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	Span random(1000);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	// try{
	// 	sp.addNumber(42);
	// }catch (const std::exception& e){
	// 	std::cout << e.what() << std::endl;
	// }
	try{
		std::cout << sp.shortestSpan() << "\n";
		std::cout << sp.longestSpan() << "\n";
	}
	catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	try{
		random.addRandomNumbers(1000);
		std::cout << random.shortestSpan() << "\n";
		std::cout << random.longestSpan() << "\n";
	}
	catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	return 0;
}

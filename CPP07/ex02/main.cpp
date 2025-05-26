#include <Array.hpp>

int main()
{
	try{
		Array<std::string> strings(3);
		strings[0] = "Hello";
		strings[1] = "World";
		strings[2] = "!";
		std::cout << "Array content: " << strings << "\n";
		std::cout << "Array size: " << strings.size() << "\n";
		std::cout << "Array 0: " << strings[0] << "\n";

		const Array<std::string> copy(strings);
		copy[1] = "C++";
		std::cout << "Original: " << strings << "\n";
		std::cout << "Copy: " << copy << "\n";

		Array<int> test(3);
		test[0] = 1;
		test[1] = 2;
		test[2] = 3;
		std::cout << "Array content: " << test << "\n";
		std::cout << "Array size: " << test.size() << "\n";
		std::cout << "Array size: " << test[1] << "\n";
	}
	catch (const std::bad_alloc& e){
		std::cout << e.what() << std::endl;
	}
	catch (const std::exception& e) {
			std::cout << "Exception: " << e.what() << std::endl;
	}
}


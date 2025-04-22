#include "RPN.hpp"

int	main(int argc, char** argv){
	if (argc != 2 || !parse_arg(argv[1])){
		std::cout << "Error: invalid arguments.\n";
		return 1;
	}
	return 0;
}

#include "BitcoinExchange.hpp"

int	main(int argc, char** argv){
	if (argc != 2){
		std::cout << "Error: invalid arguments. Please read the subject instructions.\n";
		return 1;
	}
	std::ifstream	data("data.csv");
	if (!data.is_open()){
		std::cout << "Cannot open data.csv\n";
		return 1;
	}
	if (!addDataToMap(data)){
		std::cout << "Invalid file content\n";
		data.close();
		return 1;
	}
	static_cast<void>(argv);
	return 0;
}

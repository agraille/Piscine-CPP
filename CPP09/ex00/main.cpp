#include "BitcoinExchange.hpp"

int	main(int argc, char** argv){
	if (argc != 2){
		std::cout << "Error: could not open file.\n";
		return 1;
	}
	std::ifstream	data("data.csv");
	if (!data.is_open()){
		std::cout << "Cannot open data.csv\n";
		return 1;
	}
	if (!addDataToMap(data, argv[1])){
		std::cout << "Invalid data file content\n";
		data.close();
		return 1;
	}
	return 0;
}

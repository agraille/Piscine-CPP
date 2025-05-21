#include "PmergeMe.hpp"

static bool	check_arg(const std::string& arg){
	for(int i = 0; arg[i]; ++i){
		if (!isdigit(arg[i]))
			return false;
	}
	return true;
}

static int	str_to_int(const std::string& str){
	std::stringstream	value(str);
	int	result;
	value >> result;
	if (value.fail())
		throw	std::out_of_range("Value to BIG: ");
	return result;
}

int	main (int argc, char **argv){
	if (argc < 3){
		std::cout << "Error: add more arguments\n";
		return 1;
	}
	std::vector<int> jacob;
	std::deque<int>	 jacob2;
	for (int i = 1; argv[i]; ++i){
		if (!check_arg(argv[i])){
			std::cout << "Invalid value: " << argv[i] << std::endl;
			return 2;
		}
		try{
			jacob.push_back(str_to_int(argv[i]));
			jacob2.push_back(str_to_int(argv[i]));
		}catch (const std::exception& e){
			std::cout << e.what() << argv[i] << std::endl;
			return 1;
		}

	}
	make_pairs(jacob);
	make_pairs(jacob2);
	return 0;
}

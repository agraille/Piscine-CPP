#include "ScalarConverter.hpp"
#include <climits>

void	is_impossible(){
	std::cout << "Invalid input can't convert, read the subject for example . . .\n";
	std::exit(127);
}

static void stringToInt(const std::string& str){
	std::stringstream ss(str);
	int result;
	ss >> result;
	if (ss.fail() || !ss.eof())
		is_impossible();
	std::cout << "STRING TO INT:\n";
	char	c = static_cast<char>(result);
	float	f = static_cast<float>(result);
	double	d = static_cast<double>(result);
	std::cout << "int: " << result << "\n";
	if (result >= 32 && result < 127)
		std::cout << "char: " << c << "\n";
	else
		std::cout << "Character not in the printable ASCII set"<< "\n";
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " <<  f << "f" << "\n";
	std::cout << "double: " << d << "\n";
}

static void stringToDouble(const std::string& str){
	std::stringstream ss(str);
	double result;
	ss >> result;
	if (ss.fail())
		is_impossible();
	std::cout << "STRING TO DOUBLE:\n";
	if (result > 2147483647 || result < -2147483648){
		std::cout << "int: " << "impossible" << "\n";
		std::cout << "Character not in the printable ASCII set"<< "\n";
	}
	else {
		int		i = static_cast<int>(result);
		char	c = static_cast<char>(i);
		std::cout << "int: " << i << "\n";
		if (i >= 32 && i < 127)
			std::cout << "char: " << c << "\n";
		else
			std::cout << "Character not in the printable ASCII set"<< "\n";
	}
	float	f = static_cast<float>(result);
	std::cout << "float: " <<  f << "f" << "\n";
	std::cout << "double: " << result << "\n";
}

static void stringToChar(const std::string& str){
	char	c = str[0];
	int		i = static_cast<int>(c);
	float	f = static_cast<float>(c);
	double	d = static_cast<double>(c);
	std::cout << "STRING TO CHAR:\n";
	std::cout << "int: " << i << "\n";
	std::cout << "char: " << c << "\n";
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " <<  f << "f" << "\n";
	std::cout << "double: " << d << "\n";
}

static void	parse_type(const std::string& param){
	unsigned short	point = 0;
	unsigned short	k = 0;

	for(int i = 0; param[i]; ++i){
		if (param[i] == '+' || param[i] == '-')
			continue;
		if (param[i] == '.')
			++point;
		if (!isdigit(param[i]))
			k++;
	}
	if (point > 1 || k > 2)
		is_impossible();
	if (param[param.length() - 1] == 'f' && point == 1)
		stringToDouble(param);
	else if (point == 1 && k == 1)
		stringToDouble(param);
	else if (param.length() == 1 && isalpha(param[0]))
		stringToChar(param);
	else if (k == 0)
		stringToInt(param);
	else
		is_impossible();
}

static void	print_is_impossible(const std::string& param){
	std::cout << "int: " << "impossible" << "\n";
	std::cout << "char: " << "impossible"  << "\n";
	if (param[0] == 'n'){
		std::cout << "float: " <<  "nanf" << "\n";
		std::cout << "double: " << "nan"  << "\n";
	}
	else if (param[0] == '+'){
		std::cout << "float: " <<  "+inff" << "\n";
		std::cout << "double: " << "+inf"  << "\n";
	}
	else{
		std::cout << "float: " <<  "-inff" << "\n";
		std::cout << "double: " << "-inf"  << "\n";
	}
}

static bool	parse_arg(const std::string& param){
	if (param.length() == 0)
		is_impossible();
	if (param == "+inf" || param == "+inff" || param == "nan" || param == "nanf" \
		|| param == "-inf" || param == "-inff")
		return true;
	return false;
}

void	ScalarConverter::convert(const std::string& param){
	if (parse_arg(param)){
		print_is_impossible(param);
		return ;
	}
	parse_type(param);
}

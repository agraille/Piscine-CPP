#include "ScalarConverter.hpp"

int stringToInt(const std::string& str) {
	std::stringstream ss(str);
	int result;
	ss >> result;
	return result;
}

void	ScalarConverter::convert(const std::string& param){
	int		i = stringToInt(param);
	char	c = static_cast<char>(i);
	float	f = static_cast<float>(i);
	double	d = static_cast<double>(i);

	std::cout << i << "\n";
	std::cout << c << "\n";
	std::cout << f << "\n";
	std::cout << d << "\n";
}

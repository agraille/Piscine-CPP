#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <limits>

class ScalarConverter{

	public:
		static void	convert(const std::string& param);

	private:
		ScalarConverter();
    	ScalarConverter(const ScalarConverter& other);
    	virtual ~ScalarConverter() = 0;
		virtual ScalarConverter& operator=(const ScalarConverter& other) = 0;
};

#endif

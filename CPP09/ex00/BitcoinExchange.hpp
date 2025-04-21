#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip>

typedef	const std::string& STRING_CR;

bool	addDataToMap(std::ifstream& data, STRING_CR input);

#endif

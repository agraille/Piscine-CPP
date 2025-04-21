#include "BitcoinExchange.hpp"

static int stringToInt(const std::string& str){
	std::stringstream	key(str);
		int	result;
		key >> result;
	if (key.fail())
		return -1;
	return	result;
}

static bool	check_date(const std::string& line_read){
	if (line_read[4] != '-' || line_read[7] !=  '-' || line_read[10] != ',' || !isdigit(line_read[11]))
		return false;
	short 			years = stringToInt(line_read.substr(0, 4));
	short 			month = stringToInt(line_read.substr(5, 2));
	short 			day = stringToInt(line_read.substr(8, 2));
	if ((years < 2009 || years > 2025) || (month < 1 || month > 12) || (day < 1 || day > 31))
		return false;
	if ((day > 28 && month == 2) || (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11)))
		return false;
	return true;
}

static bool	is_valid_data(const std::string& line_read){
	if (line_read[10] != ',' || !isdigit(line_read[11]) || !check_date(line_read))
		return false;

	std::string 	value = line_read.substr(11);
	short			point = 0;
	for (int i = 0; value[i]; i++){
		if (value[i] != '.' && !isdigit(value[i]))
			return false;
		if (value[i] == '.')
			++point;
	}
	if (point > 1)
		return false;
	return true;
}

bool	addDataToMap(std::ifstream& data){
	std::map<int, std::string>	dataBase;
	std::string				line_read;
	getline(data, line_read);
	if (line_read != "date,exchange_rate")
		return false;
	while (getline(data, line_read)){
		if (is_valid_data(line_read) == false)
			return false;
		line_read.erase(std::remove(line_read.begin(), line_read.end(), '-'), line_read.end());
		int	key = stringToInt(line_read.substr(0, 8));
		dataBase.insert(std::make_pair(key, line_read.substr(9)));
	}
	for (std::map<int, std::string>::iterator it = dataBase.begin(); it != dataBase.end(); ++it) {
		std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
	}
	data.close();
	return true;
}

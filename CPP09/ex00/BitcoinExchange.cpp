#include "BitcoinExchange.hpp"

static int stringToInt(const std::string& str){
	std::stringstream	key(str);
		int	result;
		key >> result;
	if (key.fail())
		return -1;
	return	result;
}

static bool	is_valid_file(const std::string& line_read){
	if (line_read[4] != '-' && line_read[7] !=  '-' && line_read[10] != ',' && !isdigit(line_read[11]))
		return false;
	//verifier la date,
	//verifier le float
	return true;
}

bool	addDataToMap(std::ifstream& data){
	std::map<int, std::string>	dataBase;
	std::string				line_read;
	getline(data, line_read);
	if (line_read != "date,exchange_rate"){
		return false;
	}
	while (getline(data, line_read)){
		if (is_valid_file(line_read) == false)
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

#include "BitcoinExchange.hpp"

static int stringToInt(STRING_CR str){
	std::stringstream	key(str);
		int	result;
		key >> result;
	if (key.fail())
		return -1;
	return	result;
}

static bool	check_date(STRING_CR line_read){
	if (line_read[4] != '-' || line_read[7] !=  '-')
		return false;
	short 			years = stringToInt(line_read.substr(0, 4));
	short 			month = stringToInt(line_read.substr(5, 2));
	short 			day = stringToInt(line_read.substr(8, 2));
	if ((years < 2009 || years > 2025) || (month < 1 || month > 12) || (day < 1 || day > 31))
		return false;
	if ((day > 28 && month == 2 && !(years % 4 == 0 && (years % 100 != 0 || years % 400 == 0))) ||
		(day > 29 && month == 2) ||
		(day > 30 && (month == 4 || month == 6 || month == 9 || month == 11)))
		return false;
	return true;
}

static bool	check_value(STRING_CR value){
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

static void	check_base(std::map<int, std::string>& dataBase, STRING_CR line_read, STRING_CR value){
	std::string date_str = line_read.substr(0, 10);
	std::string clean_date = date_str;

	clean_date.erase(std::remove(clean_date.begin(), clean_date.end(), '-'), clean_date.end());
	int date_key = stringToInt(clean_date);	
	std::map<int, std::string>::iterator it = dataBase.lower_bound(date_key);
	if (it == dataBase.end())
		--it;
	else if (it->first != date_key) {
		if (it != dataBase.begin())
			--it;
		else {
			std::cout << "Error: no earlier date available for " << date_str << "\n";
			return;
		}
	}
	std::stringstream ss(it->second);
	float exchange_rate;
	ss >> exchange_rate;

	std::stringstream vs(value);
	float input_value;
	vs >> input_value;	

	float result = input_value * exchange_rate;
	if (result > 1000000)
		std::cout << std::fixed << std::setprecision(2);
	std::cout << date_str << " => " << value << " = " << result << "\n";
}

static void	check_infile(std::map<int, std::string>& dataBase, std::string input){
	std::ifstream	infile(input.c_str());
	if (!infile.is_open()){
		std::cout << "Cannot open "<< input << "\n";
		std::exit(1);
	}
	std::string	line_read;
	while(getline(infile, line_read)){
		if (line_read == "date | value")
			continue;
		if (!check_date(line_read) || line_read[10] != ' ' || line_read[11] != '|' \
			|| line_read[12] != ' '){
			std::cout << "Error: bad input => " << line_read << "\n";
			continue;
		}
		std::string 	value = line_read.substr(13);
		if (value[0] == '-'){
			std::cout << "Error: not a positive number.\n";
			continue;
		}
		if (value.length() > 4){
			std::cout << "Error: too large a number.\n";
			continue;
		}
		if (check_value(value) == false || value.length() == 0){
			std::cout << "Error: bad input => " << line_read << "\n";
			continue;
		}
		check_base(dataBase, line_read, value);
	}
	infile.close();
}

bool	addDataToMap(std::ifstream& data, STRING_CR input){
	std::map<int, std::string>	dataBase;
	std::string				line_read;
	getline(data, line_read);
	if (line_read != "date,exchange_rate")
		return false;
	while (getline(data, line_read)){
		if (line_read[10] != ',' || !isdigit(line_read[11]) || !check_date(line_read))
			return false;
		std::string 	value = line_read.substr(11);
		if (check_value(value) == false)
			return false;
		line_read.erase(std::remove(line_read.begin(), line_read.end(), '-'), line_read.end());
		int	key = stringToInt(line_read.substr(0, 8));
		dataBase.insert(std::make_pair(key, line_read.substr(9)));
	}
	data.close();
	check_infile(dataBase, input);
	return true;
}

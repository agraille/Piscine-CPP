#include "RPN.hpp"

static bool	check_sign(char c){
	std::string	sign = "+-*/ 0123456789";
	return sign.find(c) != std::string::npos;
}

static bool	calc_sign(std::stack<int>& pile, char sign){
	int temp = pile.top();
	pile.pop();
	int temp2 = pile.top();
	pile.pop();
	if (sign == '/'){
		if (temp == 0){
			std::cout << "Why you try to break my program :( ?\n";
			return false;
		}
		temp2 /= temp;
	}
	else if (sign == '+')
		temp2 += temp;
	else if (sign == '-')
		temp2 -= temp;
	else if (sign == '*')
		temp2 *= temp;
	pile.push(temp2);
	return true;
	// std::cout << "TOP PILE = " << pile.top() << std::endl;
}

bool	parse_arg(const std::string& arg){
	short				count_numbers = 0;
	short				count_sign = 0;
	std::stack<int>		pile;

	for(int i = 0; arg[i]; ++i){
		if (!check_sign(arg[i]))
			return false;
	}
	if (isdigit(arg[0]) && arg[1] == ' ' && isdigit(arg[2])){
		count_numbers = 2;
		pile.push(arg[0] - '0');
		pile.push(arg[2] - '0');
	}
	else
		return false;
	short	is_space = 1;
	for (int i = 3; arg[i]; ++i){
		if (is_space == 1 && arg[i] == ' ')
			is_space = 0;
		else if (is_space == 0 && isdigit(arg[i])){
			pile.push(arg[i] - '0');
			is_space = 1;
			++count_numbers;
		}
		else if (is_space == 0 && (arg[i] == '+' || arg[i] == '-' \
				|| arg[i] == '/' || arg[i] == '*')){
			is_space = 1;
			++count_sign;
			if (calc_sign(pile, arg[i]) == false)
				return false;
		}
		else
			return false;
	}
	if (count_sign + 1 == count_numbers)
		std::cout <<  pile.top() << "\n";
	else
		return false;
	return true;
}

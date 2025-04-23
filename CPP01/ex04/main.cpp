/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:32:03 by agraille          #+#    #+#             */
/*   Updated: 2025/03/27 11:18:33 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

void	replace_file(std::string& filename, std::string& s1, std::string& s2){
	std::ifstream	input(filename.c_str());
	if (!input.is_open())
	{
		std::cout << "Error opening file: " << filename << std::endl;
        exit(EXIT_FAILURE);
	}
	std::ofstream	output((filename + ".replace").c_str());
	if (!output.is_open())
	{
		std::cout << "Error creating file: " << filename << ".replace" <<std::endl;
		input.close();
        exit(EXIT_FAILURE);
	}
	std::string	line_read;
	while (getline(input, line_read)){
		size_t pos = 0;
		while ((pos = line_read.find(s1, pos)) != std::string::npos){
			output << line_read.substr(0, pos);
			output << s2;
			pos += s1.length();
			line_read = line_read.substr(pos);
			pos = 0;
		}
		output << line_read << std::endl;
	}
	input.close();
	output.close();
}

int main(int argc, char **argv){
	if (argc != 4)
		exit(EXIT_FAILURE);

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (s1.length() == 0)
		return 1;
	replace_file(filename, s1, s2);

	return 0;
}

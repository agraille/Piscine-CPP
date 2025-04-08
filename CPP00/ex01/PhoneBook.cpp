/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:03:47 by agraille          #+#    #+#             */
/*   Updated: 2025/04/08 16:45:27 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0), contact_count(0){
	std::cout << "PhoneBook is built\n";
}

PhoneBook::~PhoneBook(){
	std::cout << "PhoneBook is destroy" << std::endl;
}

void PhoneBook::add_contact(){
	if (index == 8)
		index = 0;
	contacts[index].setContact();
	index++;
	contact_count++;
}

void PhoneBook::search_contact(){
	std::string input;
	
	if (contact_count == 0){
		std::cout << "PhoneBook is empty !" << std::endl;
		return;
	}
	std::cout << std::setw(10) << "index" << "|" << std::setw(10) << "first name" \
	<< "|" << std::setw(10) << "last name" << "|" << std::setw(10) << "nickname\n";
	for (int i = 0; i < contact_count && i < 8; i++)
		contacts[i].getDisplayall(i);
	std::cout << "Enter an existing index:\n";
	while (1)
	{
		getline(std::cin, input);
		if (std::cin.eof())
			exit(0);
		std::cout << "Enter an existing index:\n";
		int number = input[0] - '0';
		if (input.length() != 1 || number < 0 || number > 7)
			continue;
		if (number < contact_count && number >= 0 && number <= 7)
		{
			if (number <= contact_count)
				contacts[number].getDisplayIndex();
			break;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:03:37 by agraille          #+#    #+#             */
/*   Updated: 2025/03/24 16:13:41 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){
	std::cout << "Contact is built\n";
}

Contact::~Contact(){
	std::cout << "Contact is destroy" << std::endl;
}

static void no_empty_line(const std::string &message, std::string &variable) {
    std::cout << message;
    while (std::getline(std::cin, variable) && variable.empty())
		std::cout << "Error: " << message << " cannot be empty. Try again: ";
}

void Contact::setContact() {
    no_empty_line("Enter First Name: ", FirstName);
    no_empty_line("Enter Last Name: ", LastName);
    no_empty_line("Enter Nickname: ", NickName);
    no_empty_line("Enter Phone Number: ", PhoneNumber);
    no_empty_line("Enter Darkest Secret: ", DarkestSecret);
}

void Contact::getDisplayall(int index) const {
	std::cout << std::setw(10) << index << "|";
	if (FirstName.length() > 9)
		std::cout  << std::setw(9) << FirstName.substr(0, 9) << "." << "|";
	else
		std::cout  << std::setw(10) << FirstName << "|";
	if (LastName.length() > 9)
		std::cout  << std::setw(9) << LastName.substr(0, 9) << "." << "|";
	else
		std::cout  << std::setw(10) << LastName << "|";
	if (NickName.length() > 9)
		std::cout << std::setw(9) << NickName.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << NickName;
	std::cout << "\n";
}

void Contact::getDisplayIndex() const {
    std::cout << "First name: " << FirstName << std::endl;
    std::cout << "Last name: " << LastName << std::endl;
    std::cout << "Nickname: " << NickName << std::endl;
    std::cout << "Phone number: " << PhoneNumber << std::endl;
    std::cout << "Darkest secret: " << DarkestSecret << std::endl;
}

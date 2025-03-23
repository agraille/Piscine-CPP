/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:03:37 by agraille          #+#    #+#             */
/*   Updated: 2025/03/23 22:13:09 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact(){
	std::cout << "Contact is built\n";
}

Contact::~Contact(){
	std::cout << "Contact is destroy" << std::endl;
}

void Contact::no_empty_line(const std::string &message, std::string &variable) {
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

void Contact::DisplayIndex() const {
    std::cout << "First name: " << FirstName << std::endl;
    std::cout << "Last name: " << LastName << std::endl;
    std::cout << "Nickname: " << NickName << std::endl;
    std::cout << "Phone number: " << PhoneNumber << std::endl;
    std::cout << "Darkest secret: " << DarkestSecret << std::endl;
}

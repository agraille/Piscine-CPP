/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:03:47 by agraille          #+#    #+#             */
/*   Updated: 2025/03/23 22:13:23 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook() : index(0), contact_count(0){
	std::cout << "PhoneBook is built\n";
}

PhoneBook::~PhoneBook(){
	std::cout << "PhoneBook is destroy" << std::endl;
}

void PhoneBook::add_contact()
{
	if (index == 7)
		index = 0;
	contacts[index].setContact();
	index++;
	contact_count++;
}

void PhoneBook::search_contact() const
{
	if (contact_count == 0){
		std::cout << "PhoneBook is empty !" << std::endl;
		return;
	}
}

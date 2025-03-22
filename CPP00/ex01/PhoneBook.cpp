/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:03:47 by agraille          #+#    #+#             */
/*   Updated: 2025/03/22 22:32:13 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook() : index(0){
	std::cout << "PhoneBook is built\n";
}

PhoneBook::~PhoneBook(){
	std::cout << "PhoneBook is destroy" << std::endl;
}

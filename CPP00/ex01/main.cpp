/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:27:34 by agraille          #+#    #+#             */
/*   Updated: 2025/03/24 09:35:40 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <signal.h>

int	main()
{
	PhoneBook		phonebook;
	std::string 	input;
	
	while(1)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): " << std::endl;
		getline(std::cin, input);

		if (input == "ADD") 
			phonebook.add_contact();
        else if (input == "SEARCH")
			phonebook.search_contact();
        else if (input == "EXIT" || std::cin.eof())
            break;
	}
	return 0;
}

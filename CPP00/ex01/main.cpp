/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:27:34 by agraille          #+#    #+#             */
/*   Updated: 2025/03/23 21:18:46 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main()
{
	PhoneBook		phonebook;
	std::string 	input;

	while(1)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		getline(std::cin, input);

		if (input == "ADD") 
			phonebook.add_contact();
        else if (input == "SEARCH")
			phonebook.search_contact();
        else if (input == "EXIT")
            break;
	}
	return 0;
}

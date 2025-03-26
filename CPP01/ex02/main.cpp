/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:59:46 by agraille          #+#    #+#             */
/*   Updated: 2025/03/26 14:29:15 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>

int	main()
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << &str << "\n";
	std::cout << &stringPTR << "\n";
	std::cout << &stringREF << "\n";

	std::cout << str << "\n";
	std::cout << *stringPTR << "\n";
	std::cout << stringREF << "\n";
}

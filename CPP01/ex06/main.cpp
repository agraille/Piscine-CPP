/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:21:16 by agraille          #+#    #+#             */
/*   Updated: 2025/03/27 12:29:20 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(int argc, char **argv){
	Harl	harl;

	if (argc != 2)
	{
		std::cout << "Need only one argument\n";
		return 1;
	}
	std::string	s1 = argv[1];
    harl.complain(s1);
	return 0;
}

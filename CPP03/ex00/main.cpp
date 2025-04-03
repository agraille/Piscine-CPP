/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:02:41 by agraille          #+#    #+#             */
/*   Updated: 2025/04/03 11:42:08 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap clap1("BOO");
	ClapTrap clap2("GOHAN");

    clap1.attack("Enemy");
    clap1.takeDamage(3);
    clap1.beRepaired(5);
    clap1.attack("Enemy");
    clap1.takeDamage(12);
    clap1.beRepaired(5);
	std::endl(std::cout);
	
	// clap2 = clap1;
	
	clap2.attack("Enemy");
    clap2.takeDamage(3);
    clap2.beRepaired(5);
    clap2.attack("Enemy");
    clap2.takeDamage(12);
    clap2.beRepaired(5);

	return 0;
}

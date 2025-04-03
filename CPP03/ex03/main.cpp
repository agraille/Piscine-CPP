/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:02:41 by agraille          #+#    #+#             */
/*   Updated: 2025/04/03 15:11:48 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ClapTrap clap1("BOO");
	ClapTrap clap2("GOHAN");
	ScavTrap slap1("bob");
	ScavTrap slap2("bobi");

    clap1.attack("Enemy");
    clap1.takeDamage(3);
    clap1.beRepaired(5);
    clap1.attack("Enemy");
    clap1.takeDamage(12);
    clap1.beRepaired(5);
	std::endl(std::cout);
	
	// clap2 = clap1;
	slap1 = slap2;
	
	slap1.attack("Enemy");
    slap1.takeDamage(3);
    slap1.beRepaired(5);
    slap1.attack("Enemy");
    slap1.takeDamage(12);
    slap1.beRepaired(5);
    slap1.guardGate();

	return 0;
}

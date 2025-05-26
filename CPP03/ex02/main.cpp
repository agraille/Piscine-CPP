/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:02:41 by agraille          #+#    #+#             */
/*   Updated: 2025/04/04 12:17:01 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	ClapTrap clap1("BOO");
	ClapTrap clap2("GOHAN");
	// ScavTrap slap1("LUFFY");
	// ScavTrap slap2("ZORO");
	// FragTrap frag1("GUTS");
	// FragTrap frag2("GRIFFITH");


	// clap1 = clap2;

    clap1.attack("Enemy");
    clap1.takeDamage(3);
    clap1.beRepaired(-5);
    clap1.attack("Enemy");
    clap1.takeDamage(12);
    clap1.beRepaired(-5);
	std::endl(std::cout);
	
	// slap1 = slap2;
	
	// slap1.attack("Enemy");
    // slap1.takeDamage(3);
    // slap1.beRepaired(5);
    // slap1.attack("Enemy");
    // slap1.takeDamage(12);
    // slap1.beRepaired(5);
    // slap1.guardGate();
	// std::endl(std::cout);

	// // frag1 = frag2;
	// frag1.attack("Enemy");
    // frag1.takeDamage(3);
    // frag1.beRepaired(5);
    // frag1.attack("Enemy");
    // frag1.takeDamage(12);
    // frag1.beRepaired(5);
    // frag1.highFivesGuys();
	return 0;
}

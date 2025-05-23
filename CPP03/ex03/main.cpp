/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:02:41 by agraille          #+#    #+#             */
/*   Updated: 2025/04/04 13:55:11 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap slap1("LUFFY");
	// DiamondTrap slap2("ZORO");
	std::endl(std::cout);

	// slap1 = slap2;
	
	slap1.attack("Enemy");
    slap1.takeDamage(3);
    slap1.beRepaired(5);
    slap1.attack("Enemy");
    slap1.takeDamage(12);
    slap1.beRepaired(5);
    slap1.whoAmI();
	std::endl(std::cout);

	return 0;
}

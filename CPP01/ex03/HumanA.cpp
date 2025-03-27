/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:31:54 by agraille          #+#    #+#             */
/*   Updated: 2025/03/27 08:41:09 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon){
}

HumanA::~HumanA(){
}

void	HumanA::attack() const{
	std::cout << name << " attacks with their " << weapon.getType() << "\n";
}

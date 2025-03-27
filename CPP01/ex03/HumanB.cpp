/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:32:00 by agraille          #+#    #+#             */
/*   Updated: 2025/03/27 09:52:47 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL){
}

HumanB::~HumanB(){
}

void	HumanB::setWeapon(Weapon& club){
		this->weapon = &club;
}

void HumanB::attack() const {
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << "\n";
    else
        std::cout << name << " has no weapon to attack!\n";
}

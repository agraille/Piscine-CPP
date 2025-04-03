/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:44:40 by agraille          #+#    #+#             */
/*   Updated: 2025/04/03 15:17:34 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    _hitpoints = 100;
    _energy = 50;
    _attack_damage = 20;
    std::cout << "ScavTrap " << _name << " is created!\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {  
    std::cout << "ScavTrap " << _name << " is copied!\n";
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap " << _name << " is destroy!\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other){
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

void ScavTrap::attack(const std::string& target) {
    if (_energy > 0 && _hitpoints > 0) {
        _energy--;
        std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!\n";
    } else {
        std::cout << "ScavTrap " << _name << " is too weak to attack!\n";
    }
}

void ScavTrap::guardGate() const{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!\n";
}

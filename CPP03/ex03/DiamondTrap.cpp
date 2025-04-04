/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:19:19 by agraille          #+#    #+#             */
/*   Updated: 2025/04/04 14:00:08 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name) 
: ClapTrap(name + "_clap_name"),  ScavTrap(name), FragTrap(name), _name(name) {
    _hitpoints= FragTrap::_hitpoints;
    _energy = ScavTrap::_energy;
	_attack_damage = FragTrap::_attack_damage;
    std::cout << "DiamondTrap " << name << " constructed!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) 
: ClapTrap(copy._name), ScavTrap(copy._name), FragTrap(copy._name), _name(copy._name)
{
	_hitpoints = copy._hitpoints;
	_energy = copy._energy;
	_attack_damage = copy._attack_damage;
	std::cout << "DiamondTrap " << _name << " is copied!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        _name = other._name;
        _hitpoints = other._hitpoints;
		_energy = other._energy;
        _attack_damage= other._attack_damage;
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << _name << " is destroyed!" << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name: " << _name << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

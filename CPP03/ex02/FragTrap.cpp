/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:14:07 by agraille          #+#    #+#             */
/*   Updated: 2025/04/04 12:12:33 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    _hitpoints = 100;
    _energy = 100;
    _attack_damage = 30;
    std::cout << "FragTrap " << _name << " is created!\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {  
    std::cout << "FragTrap " << _name << " is copied!\n";
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap " << _name << " is destroy!\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other){
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

void FragTrap::attack(const std::string& target) {
    if (_energy > 0 && _hitpoints > 0) {
        _energy--;
        std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!\n";
    } else {
        std::cout << "FragTrap " << _name << " is too weak to attack!\n";
    }
}

void FragTrap::highFivesGuys(){
	std::cout << "FragTrap " << _name << " call high fives GUYS!\n";
}

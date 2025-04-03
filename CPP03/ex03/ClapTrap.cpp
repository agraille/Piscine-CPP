/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:02:38 by agraille          #+#    #+#             */
/*   Updated: 2025/04/03 14:18:10 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitpoints(10), _energy(10), _attack_damage(0){
	std::cout << "ClapTrap " << _name << " is created!\n";
}

ClapTrap::ClapTrap(const ClapTrap& copy)
    : _name(copy._name), _hitpoints(copy._hitpoints), _energy(copy._energy), _attack_damage(copy._attack_damage){
	    std::cout << "ClapTrap " << _name << " is copied!\n";
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap " << _name << " is destroy!\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
	if (this != &other){
		_name = other._name;
		_hitpoints = other._hitpoints;
		_energy = other._energy;
		_attack_damage = other._attack_damage;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target) {
    if (_energy > 0 && _hitpoints > 0) {
        _energy--;
        std::cout << "ClapTrap " << _name << " attacks " << target
                  << ", causing " << _attack_damage << " points of damage!" << std::endl;
    } else
        std::cout << "ClapTrap " << _name << " is too weak to attack!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    _hitpoints -= amount;
    std::cout << "ClapTrap " << _name << " takes " << amount
              << " points of damage! Remaining HP: " << _hitpoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_energy > 0 && _hitpoints > 0) {
        _hitpoints += amount;
        _energy--;
        std::cout << "ClapTrap " << _name << " repairs itself for "
                  << amount << " hit points! Remaining HP: " << _hitpoints
                  << ", Energy: " << _energy << std::endl;
    }
	else
        std::cout << "ClapTrap " << _name << " is too weak to repair itself!" << std::endl;
}

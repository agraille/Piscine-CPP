/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:00:07 by agraille          #+#    #+#             */
/*   Updated: 2025/03/26 14:22:58 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce() const{
	std::cout << "Zombie: " << name << " was created\n";
}

Zombie::Zombie(){
}

void	Zombie::setName(std::string name){
	this->name = name;
	announce();
}

Zombie::~Zombie(){
	std::cout << "Zombie: " << name <<" is destroy\n";
}


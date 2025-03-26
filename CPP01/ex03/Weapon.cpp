/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:32:05 by agraille          #+#    #+#             */
/*   Updated: 2025/03/26 15:35:33 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type){
	this->type = type;
}

Weapon::~Weapon(){
}

const std::string&	Weapon::getType() const{
	return type;
}

void Weapon::setType(std::string type){
	this->type = type;
}

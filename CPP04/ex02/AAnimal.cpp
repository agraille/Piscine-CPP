/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:35:31 by agraille          #+#    #+#             */
/*   Updated: 2025/04/09 09:55:00 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal"){
    std::cout << "AAnimal constructor called\n";
}

AAnimal::AAnimal(const AAnimal& other){
    std::cout << "AAnimal copy constructor called\n";
    this->type = other.type;
}

AAnimal& AAnimal::operator=(const AAnimal& other){
    std::cout << "AAnimal assignment operator called\n";
    if (this != &other)
        type = other.type;
    return *this;
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal destructor called\n";
}

std::string AAnimal::getType() const{
    return type;
}

void AAnimal::makeSound() const{
    std::cout << "* Aanimal sound *\n";
}

const std::string&	AAnimal::getIdeas(int index) const{
	(void)index;
	return type;
}

void AAnimal::setIdea()const {}

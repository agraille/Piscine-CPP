/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:33:29 by agraille          #+#    #+#             */
/*   Updated: 2025/04/08 10:20:31 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal"){
    std::cout << "WrongAnimal constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other){
    std::cout << "WrongAnimal copy constructor called\n";
    this->type = other.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other){
    std::cout << "WrongAnimal assignment operator called\n";
    if (this != &other)
        type = other.type;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called\n";
}

std::string WrongAnimal::getType() const{
    return type;
}

void WrongAnimal::makeSound() const{
    std::cout << "* Wronganimal sound *\n";
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:35:31 by agraille          #+#    #+#             */
/*   Updated: 2025/04/08 10:21:38 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal"){
    std::cout << "Animal constructor called\n";
}

Animal::Animal(const Animal& other){
    std::cout << "Animal copy constructor called\n";
    this->type = other.type;
}

Animal& Animal::operator=(const Animal& other){
    std::cout << "Animal assignment operator called\n";
    if (this != &other)
        type = other.type;
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructor called\n";
}

std::string Animal::getType() const{
    return type;
}

void Animal::makeSound() const{
    std::cout << "* animal sound *\n";
}

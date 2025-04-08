/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:21:58 by agraille          #+#    #+#             */
/*   Updated: 2025/04/08 10:32:36 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
	brain = new Brain();
    std::cout << "Dog constructor called\n";
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain)){
    std::cout << "Dog copy constructor called\n";
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assignment operator called\n";
    if (this != &other){
		Animal::operator=(other);
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called\n";
	delete brain;
}

void Dog::makeSound() const {
    std::cout << "Wouf! Wouf!\n";
}

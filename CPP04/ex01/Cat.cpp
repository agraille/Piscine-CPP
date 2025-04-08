/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:36:24 by agraille          #+#    #+#             */
/*   Updated: 2025/04/08 10:32:29 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
	brain = new Brain();
    std::cout << "Cat constructor called\n";
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain)){
    std::cout << "Cat copy constructor called\n";
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignment operator called\n";
    if (this != &other){
		Animal::operator=(other);
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called\n";
	delete brain;
}

void Cat::makeSound() const {
    std::cout << "Miaaaaaaaaaaaaaaaaaaaoooouuuuuu\n";
}

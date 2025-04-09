/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:21:58 by agraille          #+#    #+#             */
/*   Updated: 2025/04/09 11:05:29 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
	brain = new Brain();
    std::cout << "Dog constructor called\n";
}

Dog::Dog(const Dog& other) : AAnimal(other), brain(new Brain(*other.brain)){
    std::cout << "Dog copy constructor called\n";
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assignment operator called\n";
    if (this != &other){
		AAnimal::operator=(other);
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

void Dog::setIdea() const{
	for(int i = 0; i < 100; i++){
		std::ostringstream buffer;
		buffer << "My DOG idea number " << i;
		brain->setIdeas(i, buffer.str());
	}
}

const std::string&	Dog::getIdeas(int index) const{
	return brain->getIdeas(index);
}

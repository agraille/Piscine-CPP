/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:36:24 by agraille          #+#    #+#             */
/*   Updated: 2025/04/09 11:04:17 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
	brain = new Brain();
    std::cout << "Cat constructor called\n";
}

Cat::Cat(const Cat& other) : AAnimal(other), brain(new Brain(*other.brain)){
    std::cout << "Cat copy constructor called\n";
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignment operator called\n";
    if (this != &other){
		AAnimal::operator=(other);
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

void Cat::setIdea() const{
	for(int i = 0; i < 100; i++){
		std::ostringstream buffer;
		buffer << "My CAT idea number " << i;
		brain->setIdeas(i, buffer.str());
	}
}

const std::string&	Cat::getIdeas(int index) const{
	return brain->getIdeas(index);
}

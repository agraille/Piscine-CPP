/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:37:09 by agraille          #+#    #+#             */
/*   Updated: 2025/04/07 21:37:10 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
    type = "WrongCat";
    std::cout << "WrongCat constructor called\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other){
    std::cout << "WrongCat copy constructor called\n";
    *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << "WrongCat assignment operator called\n";
    if (this != &other)
        this->type = other.type;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called\n";
}

void WrongCat::makeSound() const {
    std::cout << "Miarrrrrraaarrrraaaaaaaaarroroorourrrurururruu\n";
}

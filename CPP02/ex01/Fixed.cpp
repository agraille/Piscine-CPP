/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:32:30 by agraille          #+#    #+#             */
/*   Updated: 2025/03/31 13:27:54 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : nbr(0){
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& copy){
	std::cout << "Copy constructor called\n";
	*this = copy;
}

Fixed::~Fixed() {
    std::cout << "Destructor called\n";
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called\n";
    if (this != &other)
	   this->nbr = other.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called\n";
    return this->nbr;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:32:30 by agraille          #+#    #+#             */
/*   Updated: 2025/04/01 22:23:59 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed() : nbr(0){
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& copy){
	std::cout << "Copy constructor called\n";
	*this = copy;
}

Fixed::Fixed(const int& value){
	std::cout << "Int constructor called\n";
	nbr = value << fractionalBits;
}

Fixed::Fixed(const float& value){
	std::cout << "Float constructor called\n";
	nbr = roundf(value * (1 << fractionalBits)); 
}

Fixed::~Fixed() {
    std::cout << "Destructor called\n";
}

float Fixed::toFloat(void) const {
	return (float)nbr / (1 << fractionalBits);
}

int Fixed::toInt(void) const {
	return nbr >> fractionalBits;
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

void Fixed::setRawBits(int const raw) {
    this->nbr = raw;
}

std::ostream& operator<<(std::ostream& o, const Fixed& fixed){
	o << fixed.toFloat();
	return o;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:09:16 by agraille          #+#    #+#             */
/*   Updated: 2025/04/09 15:02:33 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type){
}

AMateria::AMateria(const AMateria& copy) : type(copy.type){
}

AMateria::~AMateria(){
}

AMateria&	AMateria::operator=(const AMateria& other){
	if (this != &other)
		this->type = other.type;
	return *this;
}

std::string const & AMateria::getType() const {
    return type;
}

void AMateria::use(ICharacter& target) {
    (void)target;
}

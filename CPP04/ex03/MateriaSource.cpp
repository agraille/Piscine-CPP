/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:10:26 by agraille          #+#    #+#             */
/*   Updated: 2025/04/09 16:19:23 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	for (int i = 0; i < 4; ++i) 
            materiaInventory[i] = NULL;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        if (materiaInventory[i]) {
            delete materiaInventory[i];
        }
    }
}

MateriaSource::MateriaSource(const MateriaSource& copy) : IMateriaSource(copy){
	for (int i = 0; i < 4; ++i) {
		materiaInventory[i] = copy.materiaInventory[i];
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other){
	if (this != &other){
		for (int i = 0; i < 4; ++i) {
			materiaInventory[i] = other.materiaInventory[i];
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; ++i) {
        if (!materiaInventory[i]) {
            materiaInventory[i] = m;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; ++i) {
        if (materiaInventory[i] && materiaInventory[i]->getType() == type) {
            return materiaInventory[i]->clone();
        }
    }
    return NULL;
}

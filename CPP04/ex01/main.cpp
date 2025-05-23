/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:34:39 by agraille          #+#    #+#             */
/*   Updated: 2025/04/09 09:54:32 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

#define TOTALANIMALS 4

int main(){
	const Animal* animals[TOTALANIMALS];
	
	for (int i = 0; i < TOTALANIMALS / 2; ++i){
        animals[i] = new Dog();
		animals[i]->setIdea();
		std::cout << animals[i]->getIdeas(i) << std::endl;
	}

    for (int i = TOTALANIMALS / 2; i < TOTALANIMALS; ++i){
        animals[i] = new Cat();
		animals[i]->setIdea();
		std::cout << animals[i]->getIdeas(i) << std::endl;
	}

    for (int i = 0; i < TOTALANIMALS; ++i){
		
        delete animals[i];
	}
	return 0;
}

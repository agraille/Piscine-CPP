/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:34:39 by agraille          #+#    #+#             */
/*   Updated: 2025/04/08 16:35:11 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(){
	const Animal* animals[10];
	
	for (int i = 0; i < 10 / 2; ++i){
        animals[i] = new Dog();
	}
		
    for (int i = 10 / 2; i < 10; ++i){
        animals[i] = new Cat();
	}	
    for (int i = 0; i < 10; ++i){
        delete animals[i];
	}
	return 0;
}

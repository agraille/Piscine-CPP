/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:01:06 by agraille          #+#    #+#             */
/*   Updated: 2025/04/09 09:46:44 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain constructor called\n";
}

Brain::Brain(const Brain& other){
	std::cout << "Brain copy constructor called\n";
	for (int i = 0; i < 100; ++i)
        ideas[i] = other.ideas[i];;
}

Brain::~Brain(){
	std::cout << "Brain destructor called\n";
}

Brain&	Brain::operator=(const Brain& other){
    std::cout << "Brain assignment operator called\n";
	if (this != &other){
		for (int i = 0; i < 100; ++i)
        	ideas[i] = other.ideas[i];
	}
	return *this;
}

const std::string&	Brain::getIdeas(int index) const{
	if (index >= 0 && index < 100)
		return ideas[index];
	else{
		std::cout << "Enter valid index ! like this index 1 ";
		return ideas[1];
	}
}

void	Brain::setIdeas(int index, const std::string& idea){
	ideas[index] = idea;
}

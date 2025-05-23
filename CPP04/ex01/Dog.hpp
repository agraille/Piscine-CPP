/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:36:42 by agraille          #+#    #+#             */
/*   Updated: 2025/04/09 11:04:57 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	public:
		Dog();
		Dog(const Dog& other);
		~Dog();

		Dog& operator=(const Dog& other);

		void makeSound() const;
		void setIdea() const;
		const std::string&	getIdeas(int index) const;
	private:
		Brain *brain;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:35:29 by agraille          #+#    #+#             */
/*   Updated: 2025/04/09 09:54:53 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <sstream>

class	Animal{

	public:
		Animal();
		Animal(const Animal& copy);
		virtual ~Animal();

		Animal& operator=(const Animal& other);

		virtual	void makeSound() const;
		std::string	 getType() const;
		virtual void setIdea() const;
		virtual const std::string&	getIdeas(int index) const;
	protected:
		std::string type;
};

#endif

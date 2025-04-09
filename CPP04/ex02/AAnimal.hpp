/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:35:29 by agraille          #+#    #+#             */
/*   Updated: 2025/04/09 10:15:11 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <sstream>

class	AAnimal{

	public:
		AAnimal();
		AAnimal(const AAnimal& copy);
		virtual ~AAnimal() = 0;

		AAnimal& operator=(const AAnimal& other);

		virtual	void makeSound() const;
		std::string	 getType() const;
		virtual void setIdea() const;
		virtual const std::string&	getIdeas(int index) const;
	protected:
		std::string type;
};

#endif

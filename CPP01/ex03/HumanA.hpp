/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:31:58 by agraille          #+#    #+#             */
/*   Updated: 2025/03/27 08:53:14 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include "iostream"

class	HumanA{

	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();
		void	attack() const;
	private:
		std::string name;
		const Weapon&	   weapon;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:31:58 by agraille          #+#    #+#             */
/*   Updated: 2025/03/26 15:56:12 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "iostream"

class	HumanA{

	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();
	private:
		const std::string& name;
		Weapon&			   weapon;
};

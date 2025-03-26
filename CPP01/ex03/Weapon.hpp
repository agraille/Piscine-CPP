/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:32:07 by agraille          #+#    #+#             */
/*   Updated: 2025/03/26 15:32:46 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class	Weapon{

	public:
		Weapon(std::string type);
		~Weapon();
		const std::string&	getType() const;
		void				setType(std::string type);
	private:
		std::string type;
};

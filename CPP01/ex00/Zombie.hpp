/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:13:00 by agraille          #+#    #+#             */
/*   Updated: 2025/03/27 08:53:46 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class	Zombie{
	public:
		Zombie(std::string name);
		~Zombie();
		void 	announce(void) const;
	private:
		std::string name;
};

Zombie* newZombie( std::string name );
void 	randomChump( std::string name );

#endif

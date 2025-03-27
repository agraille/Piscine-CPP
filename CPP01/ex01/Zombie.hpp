/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:59:58 by agraille          #+#    #+#             */
/*   Updated: 2025/03/27 08:53:38 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <cstdlib>

class Zombie{
	public:
		Zombie(void);
		void	setName(std::string name);
		void	announce() const;
		~Zombie();
	private:
		std::string name;
};

Zombie* zombieHorde( int N, std::string name );

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:59:58 by agraille          #+#    #+#             */
/*   Updated: 2025/03/26 13:55:29 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

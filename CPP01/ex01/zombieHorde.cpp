/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:00:21 by agraille          #+#    #+#             */
/*   Updated: 2025/03/26 13:56:12 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ){
	if (N < 1){
		std::cout << "Set minimun 1 zombie...bye\n";
		exit(EXIT_FAILURE);
	}
	Zombie* Horde = new Zombie[N];

	for (int i = 0; i < N; i++)
		Horde[i].setName(name);
	return Horde;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:32:03 by agraille          #+#    #+#             */
/*   Updated: 2025/03/27 09:54:47 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main(){
	{
		Weapon club = Weapon("shotgun");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("desert eagle");
		bob.attack();
	}
	{
		Weapon club = Weapon("grenade");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("bottle of water");
		jim.attack();
	}
return 0;
}

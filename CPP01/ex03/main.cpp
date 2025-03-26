/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:32:03 by agraille          #+#    #+#             */
/*   Updated: 2025/03/26 15:36:21 by agraille         ###   ########.fr       */
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
		club.setType("botlle of water");
		jim.attack();
	}
return 0;
}

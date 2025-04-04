/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:14:02 by agraille          #+#    #+#             */
/*   Updated: 2025/04/04 13:00:14 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap{

	public:
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& copy);
		~FragTrap();

		void	highFivesGuys(void);
		void	attack(const std::string& target);
		FragTrap& operator=(const FragTrap& other);
};

#endif

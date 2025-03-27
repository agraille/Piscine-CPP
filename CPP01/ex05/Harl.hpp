/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:21:15 by agraille          #+#    #+#             */
/*   Updated: 2025/03/27 11:41:10 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl{
	public:
		Harl();
		~Harl();
		void complain( std::string level );
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
};

#endif

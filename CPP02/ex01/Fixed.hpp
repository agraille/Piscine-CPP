/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:32:31 by agraille          #+#    #+#             */
/*   Updated: 2025/03/29 23:34:22 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class	Fixed{
	public:
		Fixed();
		Fixed(const Fixed& copy);
		~Fixed();
		Fixed& operator=(const Fixed& other);
		int	getRawBits(void) const;
	private:
		int	nbr;
	
};
#endif

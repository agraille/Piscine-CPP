/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:32:31 by agraille          #+#    #+#             */
/*   Updated: 2025/04/01 22:17:36 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed{
	public:
		Fixed();
		Fixed(const int& value);
		Fixed(const float& value);
		Fixed(const Fixed& copy);
		~Fixed();

		Fixed& operator=(const Fixed& other);

		float 	toFloat(void) const;
		int 	toInt(void) const;
		int		getRawBits(void) const;
		void 	setRawBits(int const raw);

	private:
		int	nbr;
		static const int fractionalBits;
	
};

std::ostream& operator<<(std::ostream& o, const Fixed& fixed);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:32:31 by agraille          #+#    #+#             */
/*   Updated: 2025/04/07 08:09:34 by agraille         ###   ########.fr       */
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

		int		getRawBits(void) const;
		void 	setRawBits(int const raw);

	private:
		int	nbr;
		static const int fractionalBits;
	
};
#endif

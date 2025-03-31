/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:32:32 by agraille          #+#    #+#             */
/*   Updated: 2025/03/31 13:31:44 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(){
	Fixed a;
	Fixed b( a );
	Fixed c;
	
	c = a;
	std::cout << a.getRawBits() << "\n";
	std::cout << b.getRawBits() << "\n";
	std::cout << c.getRawBits() << "\n";
	return 0;
}

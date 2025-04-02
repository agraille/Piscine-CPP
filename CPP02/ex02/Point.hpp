/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 21:33:48 by agraille          #+#    #+#             */
/*   Updated: 2025/04/02 22:12:08 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

class	Point{
	
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& copy);
		~Point();

		Point& 	operator=(const Point& other);
		Fixed 	getX() const;
    	Fixed 	getY() const;
	private:
		const Fixed x;
		const Fixed y;
	
};

std::ostream& operator<<(std::ostream& o,const Point& fixed);

bool bsp(Point const a, Point const b, Point const c, Point const point);

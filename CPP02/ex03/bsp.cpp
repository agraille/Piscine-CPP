/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 21:31:56 by agraille          #+#    #+#             */
/*   Updated: 2025/04/03 00:05:57 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed area(Point const a, Point const b, Point const c) {
    return (a.getX() * (b.getY() - c.getY()) + 
            b.getX() * (c.getY() - a.getY()) + 
            c.getX() * (a.getY() - b.getY())) / Fixed(2.0f);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed areaABC(area(a, b, c));
    Fixed areaPAB(area(point, a, b));
    Fixed areaPBC(area(point, b, c));
    Fixed areaPCA(area(point, c, a));

	if (areaPAB == Fixed(0) || areaPBC == Fixed(0) || areaPCA == Fixed(0))
		return false;
	else if (abs(areaPAB.toInt()) + abs(areaPBC.toInt()) + abs(areaPCA.toInt()) == abs(areaABC.toInt()))
		return true;
	else
		return false;
}




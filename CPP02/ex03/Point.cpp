/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 21:33:46 by agraille          #+#    #+#             */
/*   Updated: 2025/04/02 23:49:44 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0){
}

Point::Point(const float x, const float y) : x(x), y(y){
}

Point::~Point(){
}

Point::Point(const Point& copy) : x(copy.getX()), y(copy.getY()){
}

Point& Point::operator=(const Point& other){
	if (this == &other)
		return *this;
	return *this;
}

Fixed Point::getX() const{
	return x;
}

Fixed Point::getY() const{
	return y;
}

std::ostream& operator<<(std::ostream& o,const Point& fixed){
	o << "X : " << fixed.getX() << "\nY: " << fixed.getY();
	return o;
}

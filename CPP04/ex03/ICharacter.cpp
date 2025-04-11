/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:11:23 by agraille          #+#    #+#             */
/*   Updated: 2025/04/09 15:38:30 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

ICharacter::ICharacter(){
}

ICharacter::ICharacter(const ICharacter& copy){
	(void)copy;
}

ICharacter::~ICharacter(){
}

ICharacter&	ICharacter::operator=(const ICharacter& copy){
	(void)copy;
	return *this;
}

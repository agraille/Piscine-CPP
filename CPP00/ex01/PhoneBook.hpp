/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:19:01 by agraille          #+#    #+#             */
/*   Updated: 2025/03/22 22:33:10 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
	private:
		Contact contacts[8];
		int		index;
};
#endif        

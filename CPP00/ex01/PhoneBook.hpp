/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:19:01 by agraille          #+#    #+#             */
/*   Updated: 2025/03/23 21:35:02 by agraille         ###   ########.fr       */
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
		void add_contact();
		void search_contact() const;
		~PhoneBook();
	private:
		Contact contacts[8];
		unsigned short	index;
		unsigned short	contact_count;
};
#endif

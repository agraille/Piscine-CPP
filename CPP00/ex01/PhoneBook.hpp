/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:19:01 by agraille          #+#    #+#             */
/*   Updated: 2025/03/24 15:43:18 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <stdlib.h>
#include <string>
class PhoneBook
{
	public:
		PhoneBook();
		void add_contact();
		void search_contact();
		~PhoneBook();
	private:
		Contact contacts[8];
		unsigned short	index;
		unsigned short	contact_count;
};
#endif

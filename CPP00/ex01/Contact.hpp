/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:18:33 by agraille          #+#    #+#             */
/*   Updated: 2025/04/21 09:43:54 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iomanip> 
#include <iostream>
#include <stdlib.h>
#include <string>

class	Contact
{
	public:
		Contact();
		void getDisplayIndex() const;
		void getDisplayall(int index) const;
		void setContact();
		~Contact();
	private:
		std::string FirstName;
		std::string LastName;
		std::string NickName;
		std::string PhoneNumber;
		std::string DarkestSecret;
};

#endif

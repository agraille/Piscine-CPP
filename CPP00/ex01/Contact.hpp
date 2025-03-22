/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:18:33 by agraille          #+#    #+#             */
/*   Updated: 2025/03/22 21:58:21 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class	Contact
{
	public:
		Contact();
		~Contact();
	private:
		std::string FirstName;
		std::string LastName;
		std::string NickName;
		std::string Phone_Number;
		std::string Darkest_Secret;
};

#endif

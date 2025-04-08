/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:01:14 by agraille          #+#    #+#             */
/*   Updated: 2025/04/08 10:15:37 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

class Brain{
	
	public:
		Brain();
		Brain(const Brain& copy);
		~Brain();

		Brain& operator=(const Brain& other);
		void	getIdeas(int index) const;
	private:
		std::string	ideas[100];
};

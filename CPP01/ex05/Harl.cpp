/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:21:13 by agraille          #+#    #+#             */
/*   Updated: 2025/03/27 12:30:55 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){
}

Harl::~Harl(){
}

void Harl::debug(void){
    std::cout << "[DEBUG]\nI love having extra bacon for my \
	7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n" << std::endl;
}

void Harl::info(void){
    std::cout << "INFO]\nI cannot believe adding extra bacon costs more money. \
	You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning(void){
    std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free. \
	I’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error(void){
    std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::complain(std::string level){
    void (Harl::*functions[])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++)
        if (levels[i] == level)
        {
            (this->*functions[i])();
            return;
        }
    std::cout << "Probably complaining about insignificant problems" << std::endl;
}

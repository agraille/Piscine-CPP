/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:21:13 by agraille          #+#    #+#             */
/*   Updated: 2025/03/31 08:04:59 by agraille         ###   ########.fr       */
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
    std::cout << "[INFO]\nI cannot believe adding extra bacon costs more money. \
	You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning(void){
    std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free. \
	I’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error(void){
    std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

Level stringToLevel(const std::string& level) {
    if (level == "DEBUG") return DEBUG;
    if (level == "INFO") return INFO;
    if (level == "WARNING") return WARNING;
    if (level == "ERROR") return ERROR;
    return UNKNOW;
}

void Harl::complain(std::string level){

	Level enumlvl= stringToLevel(level);
	
	switch (enumlvl) {
        case DEBUG:
            this->debug();
        case INFO:
            this->info();
        case WARNING:
            this->warning();
        case ERROR:
            this->error();
			break; 
        default:
            std::cout << "[Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
}

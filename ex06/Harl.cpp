/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:03:28 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/12 16:23:34 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Something called \"Harl\" began making some noise" << std::endl;
}

Harl::~Harl()
{
	std::cout << "The misterious \"Harl\" stopped making noise" << std::endl;
}

void	Harl::debug()
{
	std::cout << GRAY << "[DEBUG]	" << DEFAULT << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}	

void	Harl::info()
{
	std::cout << MAGENTA << "[INFO]	" << DEFAULT << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning()
{
	std::cout << YELLOW << "[WARNING] " << DEFAULT << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::error()
{
	std::cout << RED << "[ERROR]	" << DEFAULT << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	void	(Harl::*complaints[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i = 0;
	
	while (i < 4)
	{
		if (level == levels[i])
			break ;
		i++;
	}
	switch(i)
	{
		case 0:
			(this->*complaints[0])();
			[[fallthrough]];
		case 1:
			(this->*complaints[1])();
			[[fallthrough]];
		case 2:
			(this->*complaints[2])();
			[[fallthrough]];
		case 3:
			(this->*complaints[3])();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
	}
}
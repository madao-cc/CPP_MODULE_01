/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:47:29 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/11 19:13:56 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie(std::string zombie_name)
{
	this->name = zombie_name;
	std::cout << "Zombie " << this->name << " is born" << std::endl; 
	return ;
}

Zombie::~Zombie()
{
	std::cout << this->name << " destroyed" << std::endl;
	return ;
}

void	Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}
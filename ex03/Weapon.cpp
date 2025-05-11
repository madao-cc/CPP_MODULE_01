/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 08:52:14 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/04/29 17:24:41 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
	std::cout << "👶 Weapon " << this->type << " created" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "💀 Weapon " << this->type << " destroyed" << std::endl;
}

void	Weapon::setType(std::string type)
{	
	this->type = type;
	std::cout << "⚔️  Weapon type set to " << this->type << std::endl;
}

const std::string &Weapon::getType()
{
	return (this->type);
}
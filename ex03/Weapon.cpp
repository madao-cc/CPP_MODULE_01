/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 08:52:14 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/12 08:56:02 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
	std::cout << "Weapon " << this->type << " created" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Weapon " << this->type << " destroyed" << std::endl;
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}

const std::string &Weapon::getType()
{
	return (this->type);
}
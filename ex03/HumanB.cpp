/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 09:00:34 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/04/29 17:26:33 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : my_weapon(NULL)
{
	this->name = name;
	std::cout << "👶 HumanB " << this->name << " is born, but without a weapon" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "💀 HumanB " << this->name << " destroyed" << std::endl;
}

void	HumanB::attack()
{
	std::cout << RED << this->name << " attacks with his " << this->my_weapon->getType() << RESET << std::endl;
}

void	HumanB::setWeapon(Weapon &my_weapon)
{
	this->my_weapon = &my_weapon;
	std::cout << "⚔️  HumanB " << this->name << " got a " << my_weapon.getType() << std::endl;
}
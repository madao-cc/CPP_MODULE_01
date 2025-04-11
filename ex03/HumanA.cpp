/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 08:58:11 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/12 09:17:05 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &my_weapon) : name(name), my_weapon(my_weapon)
{
	std::cout << "HumanA " << this->name << " with " << my_weapon.getType() << " is born" << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA " << this->name << " destroyed" << std::endl;
}

void	HumanA::attack()
{
	std::cout << this->name << " attacks with his " << this->my_weapon.getType() << std::endl;
}
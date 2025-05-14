/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:47:25 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/05/13 16:26:03 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie *newZombie(std::string name)
{
	Zombie *my_zombie;

	name = name.empty() ? "Unknown" : name;
	my_zombie = new Zombie(name);
	return (my_zombie);
}
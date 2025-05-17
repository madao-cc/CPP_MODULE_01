/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:47:38 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/05/17 16:08:56 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int	main(void)
{
	Zombie	*zombie;

	zombie = newZombie("John");
	zombie->announce();
	delete zombie;
	
	zombie = newZombie("");
	zombie->announce();
	delete zombie;

	randomChump("Paul");
	
	return (0);
}

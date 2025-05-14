/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:47:38 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/05/13 16:35:43 by mikelitoris      ###   ########.fr       */
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

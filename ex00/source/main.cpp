/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:47:38 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/11 19:03:36 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int	main(void)
{
	Zombie	*zombie;

	zombie = newZombie("John");
	zombie->announce();
	randomChump("Paul");
	delete zombie;
	return (0);
}

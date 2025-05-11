/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:18:37 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/05/10 17:56:51 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	if (name.empty())
	{
		std::cout << "Zombie needs a name" << std::endl;
		return (NULL);
	}
	if (N < 1)
	{
		std::cout << "Stop playing around... C'mon" << std::endl;
		return (NULL);
	}
	else if (N == 1)
	{
		std::cout << "1 zombie is not a horde, its just a sad zombie" << std::endl;
		return (NULL);
	}
	Zombie *new_horde = new Zombie[N];
	if (!new_horde)
	{
		std::cout << "Memory allocation failed" << std::endl;
		return (NULL);
	}
	for (int i = 0; i < N; i++)
	{
		new_horde[i].set_name(name);
	}
	return (new_horde);
}
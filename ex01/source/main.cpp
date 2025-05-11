/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:28:10 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/05/10 17:59:01 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int	main(void)
{
	// Test 1: Horde of 5 zombies named "Jonny"
	std::cout << "Test 1: Horde of 5 zombies named Jonny" << std::endl;
	int N = 5;
	Zombie *horde = zombieHorde(N, "Jonny");
	if (horde)
	{
		for (int i = 0; i < N; i++)
		{
			horde[i].announce();
		}
		delete [] horde;
	}
	std::cout << std::endl << "----------------" << std::endl << std::endl;
	
	// Test 2: Horde of 1 zombies named "Susane"
	std::cout << "Test 2: Horde of 1 zombies named Susane" << std::endl;
	N = 1;
	horde = zombieHorde(N, "Susane");
	if (horde)
	{
		for (int i = 0; i < N; i++)
		{
			horde[i].announce();
		}
		delete [] horde;
	}
	std::cout << std::endl << "----------------" << std::endl << std::endl;

	//Test 3: Horde of 5 unnamed zombies
	std::cout << "Test 3: Horde of 5 unnamed zombies" << std::endl;
	N = 5;
	horde = zombieHorde(N, "");
	if (horde)
	{
		for (int i = 0; i < N; i++)
		{
			horde[i].announce();
		}
		delete [] horde;
	}
	std::cout << std::endl << "----------------" << std::endl << std::endl;

	// Test 4: Horde of 0 zombies
	std::cout << "Test 4: Horde of 0 zombies" << std::endl;
	N = 0;
	horde = zombieHorde(N, "George");
	if (horde)
	{
		for (int i = 0; i < N; i++)
		{
			horde[i].announce();
		}
		delete [] horde;
	}
	std::cout << std::endl << "----------------" << std::endl << std::endl;

	// Test 5: Horde of 10 zombies named "Pauline"
	std::cout << "Test 5: Horde of 10 zombies named Pauline" << std::endl;
	N = 10;
	horde = zombieHorde(N, "Pauline");
	if (horde)
	{
		for (int i = 0; i < N; i++)
		{
			horde[i].announce();
		}
		delete [] horde;
	}
	std::cout << std::endl << "----------------" << std::endl << std::endl;
	
	return (0);
}

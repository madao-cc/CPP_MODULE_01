/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 08:49:38 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/05/10 18:12:02 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}

/*****************************************************
 * ********** OUTPUT OF THE SUBJECT'S MAIN: ********
 * *********************************************
 * 👶 Weapon crude spiked club created
 * 👶 HumanA Bob with crude spiked club is born
 * Bob attacks with his crude spiked club
 * ⚔️  Weapon type set to some other type of club
 * Bob attacks with his some other type of club
 * 💀 HumanA Bob destroyed
 * 💀 Weapon some other type of club destroyed
 * 👶 Weapon crude spiked club created
 * 👶 HumanB Jim is born, but without a weapon
 * ⚔️  HumanB Jim got a crude spiked club
 * Jim attacks with his crude spiked club
 * ⚔️  Weapon type set to some other type of club
 * Jim attacks with his some other type of club
 * 💀 HumanB Jim destroyed
 * 💀 Weapon some other type of club destroyed
 * **********************************************
 * **********************************************
 * Because the Human goes to grab a Weapon in it's lifetime
 * it is safe to first delete that data fromm the Human and 
 * only then delete the the Weapon.
 *****************************************************/
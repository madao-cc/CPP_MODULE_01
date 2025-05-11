/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:07:03 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/05/10 17:51:17 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	private:
		std::string	name;
	public:
		Zombie();
		~Zombie();
		void	announce();
		void	set_name(std::string name);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);
Zombie	*zombieHorde(int N, std::string name);

#endif

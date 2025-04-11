/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:47:32 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/11 18:51:06 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
private:
	std::string	name;
public:
	Zombie(std::string zombie_name);
	~Zombie();
	void	announce();
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

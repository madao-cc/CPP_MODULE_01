/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 08:45:14 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/05/10 18:17:11 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"


# define RED "\033[31m"
# define RESET "\033[0m"

class HumanA
{
	private:
		std::string name;
		Weapon &my_weapon;
	public:
		HumanA(std::string name, Weapon &my_weapon);
		~HumanA();
		void attack();
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:14:39 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/05/05 12:18:35 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main()
{
	Harl	my_harl;
	
	std::cout << "Harl complains about DEBUG:" << std::endl;
	my_harl.complain("DEBUG");
	std::cout << std::endl;
	std::cout << "Harl complains about INFO:" << std::endl;
	my_harl.complain("INFO");
	std::cout << std::endl;
	std::cout << "Harl complains about WARNING:" << std::endl;
	my_harl.complain("WARNING");
	std::cout << std::endl;
	std::cout << "Harl complains about ERROR:" << std::endl;
	my_harl.complain("ERROR");
	return (0);
}
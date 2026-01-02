/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:33:57 by enchevri          #+#    #+#             */
/*   Updated: 2026/01/02 08:46:12 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Claptrap.hpp"

int	main(void)
{
	Claptrap c("Enchevri");
	Claptrap c2("Faoriol");
	c.setAttackPoints(9);
	c2.setAttackPoints(53);
	c.attack("Faoriol");
	c2.takeDamage(c.getAttackPoints());
	c2.beRepaired(2);
	c2.attack("Enchevri");
	c.takeDamage(c2.getAttackPoints());
	c.attack("Faoriol");
	c.beRepaired(99);
	return (0);
}

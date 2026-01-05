/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:33:57 by enchevri          #+#    #+#             */
/*   Updated: 2026/01/02 12:37:51 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap c("Enchevri");
	ScavTrap c2("Faoriol");
	c.attack("Faoriol");
	c2.takeDamage(c.getAttackPoints());
	c2.attack("Enchevri");
	c.takeDamage(c2.getAttackPoints());
	c.attack("Faoriol");
	c.beRepaired(1);
	c2.beRepaired(1);
	FragTrap c3("Jweber");
	c3.attack("Faoriol");
	c2.takeDamage(c3.getAttackPoints());
	c2.guardGate();
	c3.highFivesGuys();
	return (0);
}

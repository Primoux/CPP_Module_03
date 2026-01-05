/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:33:57 by enchevri          #+#    #+#             */
/*   Updated: 2026/01/05 14:45:15 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap c2("Faoriol");
	FragTrap c3("Jweber");
	ClapTrap c1("Enchevri");
	ClapTrap c4;
	c4.attack("Maximart");
	c1.attack("Faoriol");
	c2.takeDamage(c1.getAttackPoints());
	c2.attack("Enchevri");
	c1.takeDamage(c2.getAttackPoints());
	c1.attack("Faoriol");
	c1.beRepaired(1);
	c2.beRepaired(1);
	c3.attack("Faoriol");
	c2.takeDamage(c3.getAttackPoints());
	c2.guardGate();
	c3.highFivesGuys();
	return (0);
}

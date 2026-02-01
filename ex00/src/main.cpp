/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:33:57 by enchevri          #+#    #+#             */
/*   Updated: 2026/02/01 13:54:07 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "Color.h"
#include <iostream>

using std::endl;

void title(std::string name)
{
	std::cout << BRED "------------------------------------" RESET<< endl;
	std::cout << BYELLOW << name << RESET << std::endl;
	std::cout << BRED "------------------------------------\n" RESET << endl;
}

int	main(void)
{
	// ========== CONSTRUCTORS TESTS ==========
	title("DEFAULT CONSTRUCTOR");
	ClapTrap claptrap;

	title("PARAMETERIZED CONSTRUCTOR");
	ClapTrap clap("CL4P-TP");

	title("COPY CONSTRUCTOR");
	ClapTrap clapCopy(clap);

	// ========== CLAPTRAP COMBAT TESTS ==========
	title("CLAPTRAP BASIC COMBAT");
	ClapTrap hero("Hero");
	ClapTrap enemy("Enemy");
	
	hero.attack("Enemy");
	enemy.takeDamage(hero.getAttackPoints());
	enemy.attack("Hero");
	hero.takeDamage(enemy.getAttackPoints());
	hero.beRepaired(5);
	enemy.beRepaired(3);

	// ========== ENERGY DEPLETION TEST ==========
	title("ENERGY DEPLETION TEST");
	ClapTrap tired("Tired");
	tired.setAttackPoints(1);
	
	std::cout << BMAGENTA "Attempting 12 attacks (max is 10)..." RESET << endl;
	for (int i = 1; i < 13; i++)
	{ 
		std::cout << i << " "; tired.attack("TargetDummy"); 
	}
	
	std::cout << BMAGENTA "\nTrying to repair with no energy..." RESET << endl;
	tired.beRepaired(5);

	// ========== DEATH TEST ==========
	title("DEATH TEST");
	ClapTrap victim("Victim");
	ClapTrap killer("Killer");
	
	std::cout << BMAGENTA "Victim takes 15 damage (10 HP total)..." RESET << endl;
	victim.takeDamage(15);
	
	std::cout << BMAGENTA "\nDead victim tries to act..." RESET << endl;
	victim.attack("Killer");
	victim.beRepaired(10);

	title("DESTRUCTORS");
	return (0);
}

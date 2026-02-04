/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:33:57 by enchevri          #+#    #+#             */
/*   Updated: 2026/02/04 16:50:58 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
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
	{ClapTrap claptrap;
	ScavTrap scavtrap;
	FragTrap fragtrap;}

	title("PARAMETERIZED CONSTRUCTOR");
	ClapTrap clap("CL4P-TP");
	ScavTrap scav("SC4V-TP");
	FragTrap frag("FR4G-TP");

	title("COPY CONSTRUCTOR");
	ClapTrap clapCopy(clap);
	ScavTrap scavCopy(scav);
	FragTrap fragCopy(frag);


	// ========== FRAGTRAP COMBAT TESTS ==========
	title("FRAGTRAP BASIC COMBAT");
	FragTrap berserker("Berserker");
	FragTrap target("Target");
	
	berserker.attack("Target");
	target.takeDamage(berserker.getAttackPoints());
	target.beRepaired(20);
	target.attack("Berserker");
	berserker.takeDamage(target.getAttackPoints());
	berserker.beRepaired(25);

	// ========== FRAGTRAP SPECIAL ABILITY ==========
	title("HIGH FIVE MODE");
	berserker.highFive();
	target.highFive();

	// ========== ENERGY DEPLETION TEST ==========
	title("ENERGY DEPLETION TEST");
	FragTrap tiredFrag("Tired Clap");
	
	std::cout << BWHITE "Attempting 6 attacks (max is 5)..." RESET << endl;
	tiredFrag.setEnergyPoints(5);
	for (int i = 0; i < 6; i++)
	{
		tiredFrag.attack("TargetDummy");
		tiredFrag.highFive();

	}
	
	std::cout << BWHITE "\nTrying to repair with no energy..." RESET << endl;
	tiredFrag.beRepaired(5);
	
	std::cout << BWHITE "\nTrying to repair with no energy..." RESET << endl;
	tiredFrag.beRepaired(5);

	// ========== DEATH TEST ==========
	title("DEATH TEST");
	FragTrap victim("Victim");
	
	std::cout << BWHITE "Victim takes 500 damage..." RESET << endl;
	victim.takeDamage(500);

	std::cout << BWHITE "\nDead victim tries to act..." RESET << endl;
	victim.attack("Killer");
	victim.beRepaired(10);
	victim.beRepaired(10);
	victim.highFive();


	title("Test gate keeper mode");
	ScavTrap guard("Guard");
	std::cout << BWHITE "\nTry to put guard in gate keeper mode" RESET << endl;
	
	guard.guardGate();
	std::cout << BWHITE "\nTry to take damage in gate keeper mode" RESET << endl;
	guard.takeDamage(500);
	std::cout << BWHITE "\nTry to take damage again after loosing the gatekeeper mode" RESET << endl;
	guard.takeDamage(500);

	title("Test high five mode");
	FragTrap highFive("I just wanted someone");

	highFive.highFive();

	title("DESTRUCTORS");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:33:57 by enchevri          #+#    #+#             */
/*   Updated: 2026/02/02 16:14:22 by enchevri         ###   ########lyon.fr   */
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
	ClapTrap claptrap;
	std::cout << "------------" << endl;
	ScavTrap scavtrap;
	std::cout << "------------" << endl;
	FragTrap fragtrap;

	title("PARAMETERIZED CONSTRUCTOR");
	ClapTrap clap("CL4P-TP");
	std::cout << "------------" << endl;
	ScavTrap scav("SC4V-TP");
	std::cout << "------------" << endl;
	FragTrap frag("FR4G-TP");

	title("COPY CONSTRUCTOR");
	ClapTrap clapCopy(clap);
	ScavTrap scavCopy(scav);
	FragTrap fragCopy(frag);

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

	// ========== SCAVTRAP COMBAT TESTS ==========
	title("SCAVTRAP BASIC COMBAT");
	ScavTrap warrior("Warrior");
	ScavTrap opponent("Opponent");
	
	warrior.attack("Opponent");
	opponent.takeDamage(warrior.getAttackPoints());
	opponent.beRepaired(10);
	opponent.attack("Warrior");
	warrior.takeDamage(opponent.getAttackPoints());
	warrior.beRepaired(15);

	// ========== SCAVTRAP SPECIAL ABILITY ==========
	title("GATE KEEPER MODE");
	warrior.guardGate();
	opponent.guardGate();

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
	berserker.highFivesGuys();
	target.highFivesGuys();

	// ========== ENERGY DEPLETION TEST ==========
	title("ENERGY DEPLETION TEST");
	ClapTrap tired("Tired");
	
	std::cout << BWHITE "Attempting 12 attacks (max is 10)..." RESET << endl;
	for (int i = 0; i < 12; i++)
		tired.attack("TargetDummy");
	
	std::cout << BWHITE "\nTrying to repair with no energy..." RESET << endl;
	tired.beRepaired(5);

	// ========== DEATH TEST ==========
	title("DEATH TEST");
	ClapTrap victim("Victim");
	ScavTrap killer("Killer");
	FragTrap destroyer("Destroyer");
	
	std::cout << BWHITE "Victim takes 15 damage (10 HP total)..." RESET << endl;
	victim.takeDamage(15);
	
	std::cout << BWHITE "\nDead victim tries to act..." RESET << endl;
	victim.attack("Killer");
	victim.beRepaired(10);

	std::cout << BWHITE "\nKiller tries gate keeper mode..." RESET << endl;
	killer.guardGate();

	std::cout << BWHITE "\nDestroyer takes lethal damage and tries high five..." RESET << endl;
	destroyer.takeDamage(150);
	destroyer.highFivesGuys();

	title("DESTRUCTORS");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 06:56:29 by enchevri          #+#    #+#             */
/*   Updated: 2026/02/04 16:47:10 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "Color.h"
#include <iostream>
#include <ostream>

using std::endl;
using std::string;


ScavTrap::ScavTrap() : _guardMod(false)
{
	this->_name = "DefaultScavTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackPoints = 20;
	std::cout << SCAVTRAP << this->_name << BGREEN <<  " created" RESET<< endl;
}

ScavTrap::ScavTrap(const string &name) : ClapTrap(name) , _guardMod(false)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackPoints = 20;
	std::cout << SCAVTRAP << name << BGREEN << " created" RESET << endl;
}

ScavTrap::ScavTrap(ScavTrap const &original) : ClapTrap(original) , _guardMod(false)
{
	std::cout << SCAVTRAP << BGREEN "Created " RESET "a copy of " << SCAVCOLOR << original << RESET << endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << SCAVTRAP << this->_name << BRED << " destroyed" RESET << endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackPoints = other._attackPoints;
		this->_guardMod = other._guardMod;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &o, const ScavTrap &obj)
{
	return (o << obj.getName());
}

void ScavTrap::attack(const string &target)
{
	if (this->_energyPoints == 0)
	{
		std::cout	<< SCAVTRAP << *this << RESET " can't attack "
					<< target << " no energy points left" RESET << endl;
		return;
	}
	else if (this->_hitPoints == 0)
	{
		std::cout	<< SCAVTRAP << *this << RESET " can't attack "
					<< target << " because he's dead" RESET << endl;
		return;
	}
	std::cout	<< SCAVTRAP << *this << RESET " attacked "
				<< target << " and dealt "
				<< this->_attackPoints << RESET<< endl;
	
	--this->_energyPoints;
}

// void ScavTrap::takeDamage(unsigned int amount)
// {
// 	if (_hitPoints == 0)
// 	{
// 		std::cout << "Chill bro, " << *this << " is dead" << std::endl;
// 		return ;
// 	}
// 	if (this->_guardMod)
// 	{
// 		std::cout	<< SCAVTRAP << *this << RESET 
// 					<< " didn't took " << amount 
// 					<< " damage cause he's in gate keeper mode" << endl;
// 		this->guardGate();
// 		return;
// 	}

// 	std::cout << SCAVTRAP << *this << RESET << " took " << amount << " damage" << endl;
	
// 	if (amount >= this->_hitPoints)
// 		this->_hitPoints = 0;
// 	else
// 		this->_hitPoints = _hitPoints - amount;

// 	if (this->_hitPoints == 0)
// 		std::cout << SCAVTRAP << *this << RESET << " died " BRED "RIP" RESET << endl;
// }

void ScavTrap::guardGate(void)
{
	
	if (this->_hitPoints == 0)
	{
		std::cout	<< SCAVTRAP << *this << RESET
					<< " can't be in gate keeper mode because he's dead" << endl;
		return;
	}
	else if (this->_guardMod == true)
	{
		this->_guardMod = false;
		std::cout	<< SCAVTRAP << *this << RESET
					<< " is now no longer in gate keeper mode" << endl;
		return;
	}
	else if (this->_energyPoints == 0)
	{
		std::cout	<< SCAVTRAP << *this << RESET
					<< " can't be in gate keeper mode because he got 0 energy" << endl;
		return;
	}
	std::cout	<< SCAVTRAP << *this << RESET
				<< " is now in gate keeper mode" << endl;
	this->_guardMod = true;
}

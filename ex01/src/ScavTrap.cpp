/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 06:56:29 by enchevri          #+#    #+#             */
/*   Updated: 2026/02/01 14:24:01 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "Color.h"
#include <iostream>
#include <ostream>

using std::endl;
using std::string;


ScavTrap::ScavTrap() : ClapTrap()
{
	this->_name = "DefaultScavTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackPoints = 20;
	std::cout << SCAVTRAP << this->_name << BGREEN <<  " created" RESET<< endl;
}

ScavTrap::ScavTrap(const string &name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackPoints = 20;
	std::cout << SCAVTRAP << name << BGREEN << " created" RESET << endl;
}

ScavTrap::ScavTrap(ScavTrap const &original) : ClapTrap(original)
{
	std::cout << SCAVTRAP << BGREEN "Created " RESET "a copy of " << SCAVCOLOR << original << RESET << endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << SCAVTRAP << this->_name << BRED << " destroyed" RESET << endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other)
{
	this->_name = other.getName();
	this->_hitPoints = other.getHitPoints();
	this->_energyPoints = other.getEnergyPoints();
	this->_attackPoints = other.getAttackPoints();
	return (*this);
}

std::ostream &operator<<(std::ostream &o, const ScavTrap &obj)
{
	return (o << obj.getName());
}

void ScavTrap::guardGate(void)
{
	unsigned int currentHealth = this->getHitPoints();
	unsigned int currentEnergy = this->getEnergyPoints();
	if (currentEnergy == 0)
	{
		std::cout	<< *this
					<< " can't be in gate keeper mode because he got 0 energy" << endl;
		return;
	}
	else if (currentHealth == 0)
	{
		std::cout	<< *this
					<< " can't be in gate keeper mode because he's dead" << endl;
		return;
	}
	std::cout	<< *this
				<< " is now in gate keeper mode" << endl;
}

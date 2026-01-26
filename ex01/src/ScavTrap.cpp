/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 06:56:29 by enchevri          #+#    #+#             */
/*   Updated: 2026/01/26 21:51:45 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "Color.h"
#include <iostream>
#include <ostream>

using std::endl;
using std::string;


ScavTrap::ScavTrap()
{
	this->_name = "DefaultScavTrap";
	std::cout << SCAVTRAP << this->_name << RESET " created" << endl;
	this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackPoints = 20;
}

ScavTrap::ScavTrap(const string &name)
{
	string lastName = this->_name;
	this->_name = name;
	std::cout << SCAVTRAP << name << RESET << " created from->" << CLAPCOLOR << lastName << RESET << endl;
	this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackPoints = 20;
}

ScavTrap::ScavTrap(ScavTrap const &original) : ClapTrap(original)
{
	std::cout << SCAVTRAP << RESET "Created a copy of " << SCAVCOLOR << original << RESET << endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << SCAVTRAP << this->_name << RED << " destroyed" RESET << endl;
}

ScavTrap &ScavTrap::operator=(ClapTrap const &other)
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

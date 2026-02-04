/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 06:56:29 by enchevri          #+#    #+#             */
/*   Updated: 2026/02/04 13:37:24 by enchevri         ###   ########lyon.fr   */
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
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackPoints = other._attackPoints;
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
		std::cout	<< SCAVTRAP << *this << " can't attack "
					<< target << " no energy points left" RESET << endl;
		return;
	}
	else if (this->_hitPoints == 0)
	{
		std::cout	<< SCAVTRAP << *this << " can't attack "
					<< target << " because he's dead" RESET << endl;
		return;
	}
	std::cout	<< SCAVTRAP << *this << " attacked "
				<< target << " and dealt "
				<< this->_attackPoints << RESET<< endl;
	
	--this->_energyPoints;
}

void ScavTrap::guardGate(void)
{
	if (this->_energyPoints == 0)
	{
		std::cout	<< *this
					<< " can't be in gate keeper mode because he got 0 energy" << endl;
		return;
	}
	else if (this->_hitPoints == 0)
	{
		std::cout	<< *this
					<< " can't be in gate keeper mode because he's dead" << endl;
		return;
	}
	std::cout	<< *this
				<< " is now in gate keeper mode" << endl;
}

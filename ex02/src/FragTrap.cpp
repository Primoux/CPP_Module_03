/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 06:56:29 by enchevri          #+#    #+#             */
/*   Updated: 2026/02/02 15:58:58 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Color.h"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>
#include <ostream>

using std::endl;
using std::string;

FragTrap::FragTrap()
{
	this->_name = "DefaultFragTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackPoints = 30;
	std::cout << FRAGTRAP << this->_name << BGREEN <<  " created" RESET<< endl;
}

FragTrap::FragTrap(const string &name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackPoints = 30;
	std::cout << FRAGTRAP << name << BGREEN << " created" RESET << endl;
}

FragTrap::FragTrap(FragTrap const &original) : ClapTrap(original)
{
	std::cout << FRAGTRAP << BGREEN "Created " RESET "a copy of " << FRAGCOLOR << original << RESET << endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << FRAGTRAP << this->_name << BRED << " destroyed" << RESET << endl;
}

FragTrap &FragTrap::operator=(FragTrap const &other)
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

std::ostream &operator<<(std::ostream &o, const FragTrap &obj)
{
	return (o << obj.getName() << RESET);
}

void FragTrap::attack(const string &target)
{
	if (this->_energyPoints == 0)
	{
		std::cout	<< FRAGTRAP << *this << " can't attack "
					<< target << " no energy points left" RESET << endl;
		return;
	}
	else if (this->_hitPoints == 0)
	{
		std::cout	<< FRAGTRAP << *this << " can't attack "
					<< target << " because he's dead" RESET << endl;
		return;
	}
	std::cout	<< FRAGTRAP << *this << " attacked "
				<< target << " and dealt "
				<< this->getAttackPoints() << RESET<< endl;
	
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void FragTrap::highFivesGuys(void)
{
	unsigned int currentHealth = this->getHitPoints();
	unsigned int currentEnergy = this->getEnergyPoints();
	if (currentEnergy == 0)
	{
		std::cout	<< *this
					<< " can't request a positive high-five because he got 0 energy" << endl;
		return;
	}
	else if (currentHealth == 0)
	{
		std::cout	<< *this
					<< " can't request a positive high-five because he's dead" << endl;
		return;
	}
	std::cout	<< *this
				<< " is now requesting a positive high-five" << endl;
}

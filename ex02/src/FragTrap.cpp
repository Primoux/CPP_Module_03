/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 06:56:29 by enchevri          #+#    #+#             */
/*   Updated: 2026/01/05 14:19:44 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "trap.h"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>
#include <ostream>

using std::endl;
using std::string;

FragTrap::FragTrap(const string &name)
{
	string lastName = this->_name;
	this->setName(name);
	std::cout << FRAGTRAP << name << BGREEN " created " RESET "from->" << CLAPCOLOR << lastName << RESET << endl;
	this->setAttackPoints(30);
	this->setEnergyPoints(100);
	this->setHitPoints(100);
}

FragTrap::~FragTrap(void)
{
	std::cout << FRAGTRAP << this->_name << RED << " destroyed" << RESET << endl;
}

FragTrap &FragTrap::operator=(ClapTrap const &other)
{
	this->_name = other.getName();
	this->_hitPoints = other.getHitPoints();
	this->_energyPoints = other.getEnergyPoints();
	this->_attackPoints = other.getAttackPoints();
	return (*this);
}

std::ostream &operator<<(std::ostream &o, const FragTrap &obj)
{
	return (o << FRAGTRAP << obj.getName() << RESET);
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

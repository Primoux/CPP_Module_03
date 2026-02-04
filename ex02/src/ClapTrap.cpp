/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 06:56:29 by enchevri          #+#    #+#             */
/*   Updated: 2026/02/04 16:21:29 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "Color.h"
#include <iostream>
#include <ostream>

using std::endl;
using std::string;

ClapTrap::ClapTrap(): 
_name("DefaultClapTrap"), _hitPoints(10), _energyPoints(10), _attackPoints(0)
{
	std::cout	<< CLAPTRAP << this->_name << BGREEN " created" RESET << endl;
}

ClapTrap::ClapTrap(const string &name) : 
_name(name), _hitPoints(10), _energyPoints(10), _attackPoints(0)
{
	std::cout	<< CLAPTRAP << this->_name << BGREEN " created" RESET << endl;
}

ClapTrap::ClapTrap(ClapTrap const &original) :
_name(original._name), _hitPoints(original._hitPoints), _energyPoints(original._energyPoints), _attackPoints(original._attackPoints)
{
	std::cout	<< CLAPTRAP << BGREEN "Created" RESET " a copy of " CLAPCOLOR << original << RESET << endl;
}

ClapTrap::~ClapTrap()
{
	std::cout	<< CLAPTRAP << this->_name << BRED " destroyed" RESET << endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other)
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

std::ostream &operator<<(std::ostream &o, const ClapTrap &obj)
{
	return (o << obj.getName());
}

const string &ClapTrap::getName(void) const
{
	return (this->_name);
}

unsigned int ClapTrap::getHitPoints(void) const
{
	return (this->_hitPoints);
}

unsigned int ClapTrap::getEnergyPoints(void) const
{
	return (this->_energyPoints);
}

unsigned int ClapTrap::getAttackPoints(void) const
{
	return (this->_attackPoints);
}

void ClapTrap::setEnergyPoints(unsigned int points)
{
	this->_energyPoints = points;
}

void ClapTrap::setAttackPoints(unsigned int points)
{
	this->_attackPoints = points;
}

void ClapTrap::setHitPoints(unsigned int points)
{
	this->_hitPoints = points;
}

void ClapTrap::setName(const string &name)
{
	this->_name = name;
}

void ClapTrap::attack(const string &target)
{
	if (this->_energyPoints == 0)
	{
		std::cout	<< CLAPTRAP << *this << RESET " can't attack "
					<< target << " no energy points left" << endl;
		return;
	}
	else if (this->_hitPoints == 0)
	{
		std::cout	<< CLAPTRAP << *this << RESET " can't attack "
					<< target << " because he's dead" << endl;
		return;
	}
	std::cout	<< CLAPTRAP << *this << RESET " attacked "
				<< target << " and dealt "
				<< this->_attackPoints << endl;
	
	--this->_energyPoints;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "Chill bro, " << *this << " is dead" << std::endl;
		return ;
	}
	std::cout << *this << " took " << amount << " damage" << endl;
	
	if (amount >= this->_hitPoints)
		this->_hitPoints = 0;
	else
		this->_hitPoints = _hitPoints - amount;

	if (this->_hitPoints == 0)
		std::cout << *this << " died " BRED "RIP" RESET << endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints == 0)
	{
		std::cout	<< *this << " can't repair himself no energy points left" << endl;
		return ;
	}
	else if (this->_hitPoints == 0)
	{
		std::cout	<< *this << " can't repair himself because he's dead" << endl;
		return ;
	}
	std::cout	<< *this << " healed " << amount << " hit points" << endl;
	this->_hitPoints = _hitPoints + amount;
	--this->_energyPoints;
}

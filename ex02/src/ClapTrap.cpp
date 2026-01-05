/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 06:56:29 by enchevri          #+#    #+#             */
/*   Updated: 2026/01/05 14:05:54 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "iostream"
#include "trap.h"
#include <ostream>

using std::endl;
using std::string;

ClapTrap::ClapTrap() : 
_name("DefaultClapTrap"), _hitPoints(10), _energyPoints(10), _attackPoints(0) 
{	
	std::cout << CLAPTRAP "DefaultClapTrap" RESET " created" << endl;
}

ClapTrap::ClapTrap(string name) : 
_name(name), _hitPoints(10), _energyPoints(10), _attackPoints(0)
{
	std::cout << CLAPTRAP << name << RESET " created" << endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << CLAPTRAP << this->_name << RESET << RED << " destroyed" << RESET << endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other)
{
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackPoints = other._attackPoints;
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
		std::cout	<< *this << " can't attack "
					<< target << " no energy points left" << endl;
		return;
	}
	else if (this->_hitPoints == 0)
	{
		std::cout	<< *this << " can't attack "
					<< target << " because he's dead" << endl;
		return;
	}
	std::cout	<< *this << " attacked "
				<< target << " and dealt "
				<< this->getAttackPoints() << endl;
	
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void ClapTrap::takeDamage(unsigned int amount)
{
	unsigned int currentHealth = this->getHitPoints();

	if (currentHealth == 0)
	{
		std::cout << "Chill bro, " << *this << " is dead" << endl;
		return;
	}

	std::cout << *this << " took " << amount << " damage" << endl;

	unsigned int newHealth;
	if (amount >= currentHealth)
		newHealth = 0;
	else
		newHealth = currentHealth - amount;

	this->setHitPoints(newHealth);
	if (newHealth == 0)
		std::cout << *this << " died RIP" << endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	unsigned int currentEnergyPoints = getEnergyPoints();
	unsigned int currentHealth = this->getHitPoints();
	if (currentEnergyPoints == 0)
	{
		std::cout << *this << " can't repair himself no energy points left" << endl;
		return;
	}
	else if (currentHealth == 0)
	{
		std::cout << *this << " can't repair himself because he's dead" << endl;
		return;
	}

	std::cout << *this << " healed " << amount << " hit points" << endl;
	
	unsigned int newHealth = currentHealth + amount;
	unsigned int newEnergyPoints = currentEnergyPoints - 1;
	this->setHitPoints(newHealth);
	this->setEnergyPoints(newEnergyPoints);
}

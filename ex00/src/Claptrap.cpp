/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Claptrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 06:56:29 by enchevri          #+#    #+#             */
/*   Updated: 2026/01/02 09:03:18 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Claptrap.hpp"
#include "iostream"
#include <ostream>

using std::endl;
using std::string;

Claptrap::Claptrap(string name) : 
_name(name), _hitPoints(10), _energyPoints(10), _attackPoints(0)
{
	std::cout << name << " created" << endl;
}

Claptrap::~Claptrap()
{
	std::cout << this->_name << " destroyed" << endl;
}

Claptrap &Claptrap::operator=(Claptrap const &other)
{
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackPoints = other._attackPoints;
	return (*this);
}

std::ostream &operator<<(std::ostream &o, const Claptrap &obj)
{
	return (o << obj.getName());
}

const string &Claptrap::getName(void) const
{
	return (this->_name);
}

unsigned int Claptrap::getHitPoints(void) const
{
	return (this->_hitPoints);
}

unsigned int Claptrap::getEnergyPoints(void) const
{
	return (this->_energyPoints);
}

unsigned int Claptrap::getAttackPoints(void) const
{
	return (this->_attackPoints);
}

void Claptrap::setEnergyPoints(unsigned int points)
{
	this->_energyPoints = points;
}

void Claptrap::setAttackPoints(unsigned int points)
{
	this->_attackPoints = points;
}

void Claptrap::setHitPoints(unsigned int points)
{
	this->_hitPoints = points;
}

void Claptrap::attack(const string &target)
{
	if (this->_energyPoints == 0)
	{
		std::cout	<< *this << " can't attacked "
					<< target << " no energy points left" << endl;
		return;
	}
	else if (this->_hitPoints == 0)
	{
		std::cout	<< *this << " can't attack "
					<< target << " cause he's dead" << endl;
		return;
	}
	std::cout	<< *this << " attacked "
				<< target << " and dealed "
				<< this->getAttackPoints() << endl;
	
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void Claptrap::takeDamage(unsigned int amount)
{
	unsigned int currentHealth = this->getHitPoints();

	if (currentHealth == 0)
	{
		std::cout	<< "Chill bro, " << *this << " is dead" << std::endl;
		return;
	}

	std::cout	<< *this << " took " << amount << " damage" << endl;

	unsigned int newHealth;
	if (amount >= currentHealth)
		newHealth = 0;
	else
		newHealth = currentHealth - amount;

	this->setHitPoints(newHealth);
	if (newHealth == 0)
		std::cout << *this << " died RIP" << endl;
}

void Claptrap::beRepaired(unsigned int amount)
{
	unsigned int currentEnergyPoints = getEnergyPoints();
	unsigned int currentHealth = this->getHitPoints();
	if (currentEnergyPoints == 0)
	{
		std::cout	<< *this << " can't repair himself no energy points left" << endl;
		return;
	}
	else if (currentHealth == 0)
	{
		std::cout	<< *this << " can't repair himself cause he's dead" << endl;
		return;
	}

	std::cout	<< *this << " healed " << amount << " hit points" << endl;
	
	unsigned int newHealth = currentHealth + amount;
	unsigned int newEnergyPoints = currentEnergyPoints - 1;
	this->setHitPoints(newHealth);
	this->setEnergyPoints(newEnergyPoints);
}

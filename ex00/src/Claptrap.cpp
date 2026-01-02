/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Claptrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 06:56:29 by enchevri          #+#    #+#             */
/*   Updated: 2026/01/02 07:57:24 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Claptrap.hpp"
#include "iostream"
#include <ostream>

using std::endl;
using std::string;

Claptrap::Claptrap(string name) : _name(name), _hitPoints(10),
	_energyPoints(10), _attackPoints(0)
{
	std::cout << name << " created" << endl;
	return ;
}

Claptrap::~Claptrap()
{
	std::cout << "Bye bye " << this->_name << endl;
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

int Claptrap::getHitPoints(void) const
{
	return (this->_hitPoints);
}

int Claptrap::getEnergyPoints(void) const
{
	return (this->_energyPoints);
}

int Claptrap::getAttackPoints(void) const
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
	if (this->_energyPoints > 0)
	{
		std::cout << *this << " attacked " << target << " and dealed " << this->getAttackPoints() << endl;
		this->setEnergyPoints(this->getEnergyPoints() - 1);
		return;
	}
	
	std::cout << *this << " can't attacked " << target << " no energy points left" << endl;
}

void Claptrap::takeDamage(unsigned int amount)
{
	unsigned int currentHealth = this->getHitPoints();

	if (currentHealth == 0)
	{
		std::cout << "Chill bro, " << *this << " is allready dead" << std::endl;
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
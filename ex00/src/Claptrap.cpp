/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Claptrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 06:56:29 by enchevri          #+#    #+#             */
/*   Updated: 2026/01/02 07:06:54 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Claptrap.hpp"
#include "iostream"
using std::string;
using std::endl;

Claptrap::Claptrap(string name) :
_name(name) , _hitPoints(10), _energyPoints(10), _attackPoints(0)
{
	std::cout << name << " created" << endl;
	return;
}

Claptrap::~Claptrap()
{
	std::cout << "Bye bye " << this->_name << endl;
}

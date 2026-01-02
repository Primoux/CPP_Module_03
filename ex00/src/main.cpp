/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:33:57 by enchevri          #+#    #+#             */
/*   Updated: 2026/01/02 07:59:54 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Claptrap.hpp"

int	main(void)
{
	Claptrap c("Enchevri");
	Claptrap c2("Faoriol");
	c.setAttackPoints(5);
	c.attack("Faoriol");
	c2.takeDamage(c.getAttackPoints());
	c.attack("Faoriol");
	c2.takeDamage(c.getAttackPoints());
	return (0);
}

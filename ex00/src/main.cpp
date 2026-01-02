/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:33:57 by enchevri          #+#    #+#             */
/*   Updated: 2026/01/02 07:56:38 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Claptrap.hpp"

int	main(void)
{
	Claptrap c("Enzo");
	Claptrap c2("Paolo");
	c.setAttackPoints(10);
	c.attack("Paolo");
	c2.takeDamage(c.getAttackPoints());
	c2.takeDamage(c.getAttackPoints());
	return (0);
}

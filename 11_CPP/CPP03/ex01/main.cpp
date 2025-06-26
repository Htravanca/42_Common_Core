/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:02:31 by hepereir          #+#    #+#             */
/*   Updated: 2025/06/14 15:38:27 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap a("toze");

    a.attack("outro zezinho");
    a.beRepaired(10);
    a.takeDamage(2);

    std::cout << "----------" << std::endl;

    ScavTrap b("Serena");
    b.attack("outro serenaaa");
    b.takeDamage(20);
    b.beRepaired(15);
    b.guardGate();

    std::cout << "----------" << std::endl;

    ScavTrap c;
    c.attack("outro serenaaa");
    c.takeDamage(20);

    std::cout << "----------" << std::endl;

}
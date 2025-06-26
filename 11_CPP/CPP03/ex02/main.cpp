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
#include "FragTrap.hpp"

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
    FragTrap c("Juca");
    c.attack("Bad Guy");
    c.takeDamage(50);
    c.beRepaired(30);
    c.highFivesGuys();

    return 0;
}
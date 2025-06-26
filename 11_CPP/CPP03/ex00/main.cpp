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

int main()
{
    ClapTrap a("toze");
    ClapTrap b = a;
    ClapTrap c("Zezito");
    c = a;

    a.attack("outro zezinho");
    a.beRepaired(2);
    a.takeDamage(2);

    for (int i = 0; i < 10; ++i)
    {
        std::cout << i << ": ";
        a.attack("Monster");
    }

    a.beRepaired(1);
    a.takeDamage(100);
    a.attack("outro zezinho");

}
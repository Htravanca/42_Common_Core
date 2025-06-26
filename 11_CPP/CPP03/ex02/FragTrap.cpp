/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:01:20 by hepereir          #+#    #+#             */
/*   Updated: 2025/06/14 17:03:44 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("DefaultFrag")
{
    _name = "DefaultFrag";
    _hitpoints = 100;
    _energypoints = 100;
    _attackdamage = 30;
    std::cout << "FragTrap " << this->_name << " constructed!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _hitpoints = 100;
    _energypoints = 100;
    _attackdamage = 30;
    std::cout << "FragTrap " << _name << " constructed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called for " << other._name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << _name << " destructed!" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << _name << " requested a high five!" << std::endl;
}

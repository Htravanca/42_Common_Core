/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:01:20 by hepereir          #+#    #+#             */
/*   Updated: 2025/06/14 17:03:44 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    _name = "DefaultScav";
    _hitpoints = 100;
    _energypoints = 50;
    _attackdamage = 20;
    std::cout << "ScavTrap " << this->_name << " constructed!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _hitpoints = 100;
    _energypoints = 50;
    _attackdamage = 20;
    std::cout << "ScavTrap " << _name << " constructed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called for " << other._name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " destructed!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (_energypoints > 0 && _hitpoints > 0)
    {
        _energypoints--;
        std::cout << "ScavTrap " << _name << " attacks " << target
                  << ", causing " << _attackdamage << " points of damage!" << std::endl;
    }
    else
    {
        std::cout << "ScavTrap " << _name << " has no energy or is destroyed and cannot attack!" << std::endl;
    }
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is now in Gate Keeper mode!" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:59:36 by hepereir          #+#    #+#             */
/*   Updated: 2025/06/14 18:31:30 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : _name("Default"), _hitpoints(10), _energypoints(10), _attackdamage(0)
{
    std::cout << "ClapTrap " << this->_name << " constructed!" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : _name(name), _hitpoints(10), _energypoints(10), _attackdamage(0)
{
    std::cout << "ClapTrap " << this->_name << " constructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : _name(other._name),
	  _hitpoints(other._hitpoints),
	  _energypoints(other._energypoints),
	  _attackdamage(other._attackdamage)
{
	std::cout << "Copy Constructor called\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitpoints = other._hitpoints;
        this->_energypoints = other._energypoints;
        this->_attackdamage = other._attackdamage;
    }
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destructed!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->_energypoints > 0 && this->_hitpoints > 0)
    {
        this->_energypoints--;
        std::cout << "ClapTrap " << this->_name << " attacks " << target
                    << ", causing "  << this->_attackdamage << " points of damage!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << this->_name << " cannot attack — no energy or is destroyed!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitpoints <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " is already destroyed!" << std::endl;
        return;
    }

    this->_hitpoints -= amount;
    if (this->_hitpoints < 0)
        this->_hitpoints = 0;

    std::cout << "ClapTrap " << this->_name << " takes " << amount 
              << " points of damage! Remaining hit points: "  << this->_hitpoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energypoints <= 0 || this->_hitpoints <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " cannot repair because it is out of energy or destroyed!" << std::endl;
        return;
    }
    if (amount > 0)
    {
        this->_energypoints--;
        this->_hitpoints += amount;
        std::cout << "ClapTrap " << this->_name << " repairs itself for " << amount << " of HitPoints!" << std::endl;
    }
    else
        std::cout << "Not a valid amount to Repair!" << std::endl;
    
}


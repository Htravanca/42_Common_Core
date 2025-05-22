/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:53:55 by hepereir          #+#    #+#             */
/*   Updated: 2025/05/08 17:36:53 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    this->type = type;
}

Weapon::~Weapon()
{
    std::cout << "Weapon destroyed" << std::endl;
}

const std::string& Weapon::getType() const
{
    return (type);
}

void Weapon::setType(std::string value)
{
    type = value;
}

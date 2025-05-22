/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 18:30:34 by hepereir          #+#    #+#             */
/*   Updated: 2025/05/04 19:21:30 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// This memory is allocated in the Heap memory
Zombie* newZombie(std::string name)
{
    return (new Zombie(name));
}

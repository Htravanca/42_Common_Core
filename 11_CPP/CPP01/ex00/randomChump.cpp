/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 18:43:37 by hepereir          #+#    #+#             */
/*   Updated: 2025/05/04 19:35:02 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//Zombie is created on the stack. It will be destroyed automatically when the function ends.
void randomChump(std::string name)
{
    Zombie stack(name);
    stack.announce();
}
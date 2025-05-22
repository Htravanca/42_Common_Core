/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:03:19 by hepereir          #+#    #+#             */
/*   Updated: 2025/05/04 19:33:50 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie* carlos = newZombie("carlos");
    carlos->announce();
    delete (carlos);

    randomChump("toze");

    return (0);
}
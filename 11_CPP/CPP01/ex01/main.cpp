/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:03:19 by hepereir          #+#    #+#             */
/*   Updated: 2025/05/08 16:46:30 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int count = 10;
    Zombie* many = zombieHorde(count, "toino");
    
    for (int i = 0; i < count; i++)
    {
        std::cout << i << ": ";
        many[i].announce();
    }
    delete[] many;

    return (0);
}
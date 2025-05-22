/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:49:40 by hepereir          #+#    #+#             */
/*   Updated: 2025/05/16 12:49:42 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl toze;

    if (argc != 2)
        return (std::cout << "Example: ./harlFilter WARNING" << std::endl, 1);
    toze.complain(argv[1]);

    return (0);
}
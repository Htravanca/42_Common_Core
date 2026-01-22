/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 12:36:16 by hepereir          #+#    #+#             */
/*   Updated: 2025/08/08 09:54:38 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "This program only takes one parameter" << std::endl;
        return (1);
    }
    ScalarConvert::convert(argv[1]);
    return (0);
}

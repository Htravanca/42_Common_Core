/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 20:32:39 by hepereir          #+#    #+#             */
/*   Updated: 2025/12/16 19:53:14 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error, please provide a valid input, ex: ./RPN \"3 4 +\"" << std::endl;
        return 1;
    }
    
    try
    {
        RPN rpn(argv[1]);
        std::cout << rpn.getResult() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    
    return 0;
}
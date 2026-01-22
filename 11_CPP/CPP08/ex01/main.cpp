/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 21:55:36 by hepereir          #+#    #+#             */
/*   Updated: 2025/11/22 21:24:04 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "Span.hpp"    

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;


    std::vector<int> bigList;
    for (int i = 0; i < 10000; i++)
        bigList.push_back(i);
    Span spbig(10000);
    spbig.addNumber(bigList.begin(), bigList.end());
    std::cout << spbig.shortestSpan() << std::endl;
    std::cout << spbig.longestSpan() << std::endl;

    Span spEmpty(0);
    try
    {
        spEmpty.addNumber(1);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
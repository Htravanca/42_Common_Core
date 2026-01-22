/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 12:36:16 by hepereir          #+#    #+#             */
/*   Updated: 2025/10/26 15:10:35 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void multiTen(int &i)
{
    i *= 10;
}

void printInt(const int &i)
{
    std::cout << i << " ";
}

void toUpper(std::string &s)
{
    for (size_t i = 0; i < s.size(); i++)
        s[i] = std::toupper(s[i]);
}

void printString(const std::string &s)
{
    std::cout << s << " ";
}

int main()
{
    std::cout << "=== INT ARRAY ===" << std::endl;
    int arrayint[] = {0, 1, 2, 3, 4, 5};
    size_t len = sizeof(arrayint) / sizeof(arrayint[0]);

    std::cout << "Before: ";
    iter(arrayint, len, printInt);
    std::cout << std::endl;
    iter(arrayint, len, multiTen);
    std::cout << "After:  ";
    iter(arrayint, len, printInt);
    std::cout << std::endl;

    std::cout << "\n\n=== STRING ARRAY ===" << std::endl;
    std::string strs[] = {"hello", "world", "iter", "test", "C++", "42", "?"};
    size_t slen = sizeof(strs) / sizeof(strs[0]);

    std::cout << "Before: ";
    iter(strs, slen, printString);
    std::cout << std::endl;
    iter(strs, slen, toUpper);
    std::cout << "After:  ";
    iter(strs, slen, printString);
    std::cout << std::endl;

    std::cout << "\n\n=== CONST ARRAY ===" << std::endl;
    const int constArr[] = {10, 20, 30};
    size_t clen = sizeof(constArr) / sizeof(constArr[0]);
    iter(constArr, clen, printInt);
    std::cout << "\n";

    std::cout << "\n\n=== EDGE CASES ===" << std::endl;
    int emptyArr[] = {};
    iter(emptyArr, 0, printInt);

    int singleArr[] = {99};
    iter(singleArr, 1, printInt);
    std::cout << std::endl;

    return 0;
}

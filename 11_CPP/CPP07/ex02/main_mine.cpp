/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 12:36:16 by hepereir          #+#    #+#             */
/*   Updated: 2025/10/04 16:20:00 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main()
{
    try
    {
        std::cout << "*** STRING ARRAY TEST ***" << std::endl;
        Array<std::string> strArr(3);
        strArr[0] = "Hello";
        strArr[1] = "42";
        strArr[2] = "Lisboa";
        for (unsigned int i = 0; i < strArr.size(); i++)
            std::cout << strArr[i] << " ";
        std::cout << "\nSize: " << strArr.size() << "\n\n";
        
        std::cout << "*** INT ARRAY TEST ***" << std::endl;
        Array<int> a(5);
        for (unsigned int i = 0; i < a.size(); i++)
            a[i] = i * 10;

        Array<int> b = a;
        b[2] = 999;

        std::cout << "Array a: \t\t";
        for (unsigned int i = 0; i < a.size(); i++)
            std::cout << a[i] << " ";
        std::cout << std::endl;

        std::cout << "Array b (copy): \t";
        for (unsigned int i = 0; i < b.size(); i++)
            std::cout << b[i] << " ";
        std::cout << std::endl;

        Array<int> c;
        c = a;
        c[0] = 111;
        std::cout << "Array c (assigned): \t";
        for (unsigned int i = 0; i < c.size(); i++)
            std::cout << c[i] << " ";
        std::cout << std::endl;

        std::cout << "\n*** EMPTY ARRAY TEST ***" << std::endl;
        Array<int> empty;
        std::cout << "Size: " << empty.size() << std::endl;

        std::cout << "\n*** CONST ARRAY TEST ***" << std::endl;
        const Array<int> constArr(a);
        for (unsigned int i = 0; i < constArr.size(); i++)
            std::cout << constArr[i] << " ";
        std::cout << std::endl;

        // Out of range test
        std::cout << "Accessing invalid index:\n";
        std::cout << a[10] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }
}

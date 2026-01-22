/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 22:05:39 by hepereir          #+#    #+#             */
/*   Updated: 2026/01/08 12:07:59 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top element: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Size: " <<mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "\n--- Testing copy constructor ---" << std::endl;
    MutantStack<int> copy(mstack);
    std::cout << "Copy size: " << copy.size() << std::endl;
    std::cout << "Copy top: " << copy.top() << std::endl;

    std::cout << "\n--- Testing with strings ---" << std::endl;
    MutantStack<std::string> strStack;
    strStack.push("hello");
    strStack.push("world");
    strStack.push("42");
    
    for (MutantStack<std::string>::iterator str_it = strStack.begin(); 
         str_it != strStack.end(); ++str_it)
    {
        std::cout << *str_it << " ";
    }
    std::cout << std::endl;

    std::cout << "\n--- Testing empty stack ---" << std::endl;
    MutantStack<int> empty;
    std::cout << "Empty size: " << empty.size() << std::endl;

    std::cout << "\n--- Comparison: MutantStack vs std::list ---" << std::endl;
    std::cout << "MutantStack output:" << std::endl;
    MutantStack<int> mstack2;
    mstack2.push(42);
    mstack2.push(21);
    mstack2.push(84);
    for (MutantStack<int>::iterator it2 = mstack2.begin(); it2 != mstack2.end(); ++it2)
        std::cout << *it2 << std::endl;

    std::cout << "\nstd::list output:" << std::endl;
    std::list<int> list;
    list.push_back(42);
    list.push_back(21);
    list.push_back(84);
    for (std::list<int>::iterator it3 = list.begin(); it3 != list.end(); ++it3)
        std::cout << *it3 << std::endl;

    std::cout << "\n(Both should print the same values!)" << std::endl;

    return 0;
}

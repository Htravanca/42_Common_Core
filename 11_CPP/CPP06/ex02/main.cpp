/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 12:36:16 by hepereir          #+#    #+#             */
/*   Updated: 2025/08/15 12:12:38 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base* generate()
{
    int r = std::rand() % 3;

    if (r == 0)
        return new A();
    else if (r == 1)
        return new B();
    else
        return new C();
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base &p) {

	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return;
	} catch (std::exception &e) {}

	try {
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (std::exception &e) {}

	try {
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return;
	} catch (std::exception &e) {}

	std::cout << "Unknown type" << std::endl;
}

int main(void)
{
    std::srand(std::time(NULL)); 
    for (int i = 0; i < 10; i++)
    {
        Base* obj = generate();
        std::cout << "Test " << i + 1 << ": " << std::endl;
        identify(obj);
        identify(*obj);
        delete obj;
        std::cout << "------" << std::endl;
    }

    return (0);
}

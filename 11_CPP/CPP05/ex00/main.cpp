/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 12:36:16 by hepereir          #+#    #+#             */
/*   Updated: 2025/07/24 13:21:36 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "Bureaucrat grade: 23222" << std::endl;
    try
    {
        Bureaucrat a("Carlos", 23222);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------" << std::endl << std::endl;

    std::cout << "Bureaucrat grade: -1" << std::endl;
    try
    {
        Bureaucrat a("Toino", -1);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------" << std::endl << std::endl;
 
    std::cout << "Bureaucrat grade: 125" << std::endl;
    try
    {
        Bureaucrat a("kawasaki", 125);
        a.decrementGrade();
        a.incrementGrade();
        a.incrementGrade();
        std::cout << a.getName() << std::endl;
        std::cout << a.getGrade() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------" << std::endl << std::endl;

    std::cout << "Bureaucrat grade: 80" << std::endl;
    try
    {
        Bureaucrat a("Honda", 80);
        Bureaucrat b(a);
        Bureaucrat c;
        c = a;
        
        std::cout << b << std::endl;
        b.incrementGrade();
        b.incrementGrade();
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << c << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------" << std::endl << std::endl;
    

    std::cout << "Bureaucrat grade: 1" << std::endl;
    Bureaucrat k("Honda", 1);
    try
    {
        k.incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------" << std::endl << std::endl;

    std::cout << "Bureaucrat grade: 150" << std::endl;
    Bureaucrat j("Honda", 150);
    try
    {
        j.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------" << std::endl << std::endl;
}

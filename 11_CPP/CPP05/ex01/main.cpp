/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 12:36:16 by hepereir          #+#    #+#             */
/*   Updated: 2025/07/25 13:47:20 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    std::cout << "===== FORM CONSTRUCTOR EXCEPTIONS =====" << std::endl;
    try
    {
        Form f1("InvalidHigh", 0, 50);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Form f2("InvalidLow", 151, 140);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Form f3("InvalidExecHigh", 50, 0);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Form f4("InvalidExecLow", 50, 200);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== FORM SIGNING TESTS =====" << std::endl;

    Bureaucrat john("John", 150);
    Bureaucrat alice("Alice", 100);
    Bureaucrat bob("Bob", 1);

    Form taxForm("TaxForm", 100, 50);

    std::cout << taxForm;
    john.signForm(taxForm);
    alice.signForm(taxForm);
    bob.signForm(taxForm);

    std::cout << "\nFinal form status:\n" << taxForm << std::endl;

    return 0;
}
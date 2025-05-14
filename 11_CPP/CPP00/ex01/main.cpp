/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 19:31:48 by hepereir          #+#    #+#             */
/*   Updated: 2025/05/03 15:21:48 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
# include "phonebook.hpp"

// ANSI escape code to clear screen and move cursor to top-left
void clearScreen()
{
    std::cout << "\033[2J\033[1;1H";
}

int main()
{
    Phonebook phonebook;
    std::string op;

    while (true)
    {
        clearScreen();
        std::cout << "*********** My Awesome PhoneBook ***********" << std::endl << std::endl;
        std::cout << "ADD: save a new contact;" << std::endl;
        std::cout << "SEARCH: display a specific contact;" << std::endl;
        std::cout << "EXIT: close the program;" << std::endl << std::endl;
        std::cout << "********************************************" << std::endl;
        std::cout << "Chose an option: ";
        if (!std::getline(std::cin, op))
        {
            std::cout << "\nInput interrupted (EOF). Exiting.\n";
            exit(1);
        }
        
        clearScreen();
        if (op.empty())
            continue;
        else if (op == "EXIT")
            break ;
        else if (op == "ADD")
            phonebook.addContact();
        else if (op == "SEARCH")
            phonebook.searchContacts();
    }
    std::cout << "Program quited gracefully" << std::endl;
    return (0);
}


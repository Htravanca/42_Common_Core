/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 19:57:16 by hepereir          #+#    #+#             */
/*   Updated: 2025/05/07 20:24:34 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook() : count(0), old_index(0) {}

void Phonebook::addContact()
{
    contacts[old_index].setInfo();
    old_index = (old_index + 1) % 8;
    if (count < 8)
        count++;
}

std::string truncate(const std::string& str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void Phonebook::searchContacts() const
{
    std::string dummy;
    int index;

    if (count == 0)
    {
        std::cout << "PhoneBook is empty. Press ENTER to continue...\n";
        if (!std::getline(std::cin, dummy))
        {
            std::cout << "Input interrupted (EOF). Exiting.\n";
            exit(1);
        }
        return;
    }

    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "\n";

    for (int i = 0; i < count; i++)
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << truncate(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << truncate(contacts[i].getLastName()) << "|"
                  << std::setw(10) << truncate(contacts[i].getNickname()) << "\n";
    }

    std::cout << "\nEnter index to view full contact: ";
    if (!(std::cin >> index) || index < 0 || index >= count)
    {
        std::cin.clear(); //clears the error flags on std::cin
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discards everything left in the input buffer up to the next newline
        std::cout << "Invalid index. Press ENTER to continue..." << std::endl;
        if (!std::getline(std::cin, dummy))
        {
            std::cout << "\nInput interrupted (EOF). Exiting.\n";
            exit(1);
        }
        return;
    }
    std::cin.ignore(); // Clear newline
    std::cout << "\n******** Contact Info ********" << std::endl;
    contacts[index].displayContact();
}

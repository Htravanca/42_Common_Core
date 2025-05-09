/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:05:23 by hepereir          #+#    #+#             */
/*   Updated: 2025/05/03 15:21:34 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"


bool isprintable(std::string input)
{
    for (size_t i = 0; i < input.length(); i++)
    {
        if (!std::isprint(static_cast<unsigned char>(input[i])))
            return false;
    }
    return true;
}

void Contact::setInfo()
{
    std::string dummy;
    std::cout << "First name: ";
    while (true)
    {
        if (!std::getline(std::cin, firstName))
        {
            std::cout << "\nInput interrupted (EOF). Exiting.\n";
            exit(1);
        }
        if (!firstName.empty() && isprintable(firstName))
            break;
        std::cout << "First name cannot be empty or contain unprintable characters. Try again: ";
    }

    std::cout << "Last name: ";
    while (true)
    {
        if (!std::getline(std::cin, lastName))
        {
            std::cout << "\nInput interrupted (EOF). Exiting.\n";
            exit(1);
        }
        if (!lastName.empty() && isprintable(lastName))
            break;
        std::cout << "Last name cannot be empty or contain unprintable characters. Try again: ";
    }

    std::cout << "Nickname: ";
    while (true)
    {
        if (!std::getline(std::cin, nickname))
        {
            std::cout << "\nInput interrupted (EOF). Exiting.\n";
            exit(1);
        }
        if (!nickname.empty() && isprintable(nickname))
            break;
        std::cout << "Nickname cannot be empty or contain unprintable characters. Try again: ";
    }

    std::cout << "Phone number: ";
    while (true)
    {
        if (!std::getline(std::cin, phoneNumber))
        {
            std::cout << "\nInput interrupted (EOF). Exiting.\n";
            exit(1);
        }
        if (!phoneNumber.empty() && isprintable(phoneNumber))
            break;
        std::cout << "Phone number cannot be empty or contain unprintable characters. Try again: ";
    }

    std::cout << "Darkest secret: ";
    while (true)
    {
        if (!std::getline(std::cin, darkestSecret))
        {
            std::cout << "\nInput interrupted (EOF). Exiting.\n";
            exit(1);
        }
        if (!darkestSecret.empty() && isprintable(darkestSecret))
            break;
        std::cout << "Darkest secret cannot be empty or contain unprintable characters. Try again: ";
    }
    std::cout << "\n" << "Contact added! Press ENTER to continue...";
    if (!std::getline(std::cin, dummy))
    {
        std::cout << "\nInput interrupted (EOF). Exiting.\n";
        exit(1);
    }
}

std::string Contact::getFirstName() const
{
	return firstName;
}

std::string Contact::getLastName() const 
{
	return lastName;
}

std::string Contact::getNickname() const
{
	return nickname;
}

std::string Contact::getPhoneNumber() const
{
	return phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
	return darkestSecret;
}

void Contact::displayContact() const
{
    std::string dummy;
    std::cout << "First name: " << firstName << std::endl;
    std::cout << "Last name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone number: " << phoneNumber << std::endl;
    std::cout << "Darkest secret: " << darkestSecret << std::endl;
    std::cout << "\n" <<"Press ENTER to return to the menu...";
    if (!std::getline(std::cin, dummy))
    {
        std::cout << "\nInput interrupted (EOF). Exiting.\n";
        exit(1);
    }
}
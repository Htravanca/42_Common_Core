/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:03:19 by hepereir          #+#    #+#             */
/*   Updated: 2025/05/08 16:38:37 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string mystring = "HI THIS IS BRAIN";
    std::string* stringPTR = &mystring;
    std::string& stringREF = mystring;
    
    std::cout << "First part, print the memory address:" << std::endl;
    std::cout << "string variable: " << &mystring << std::endl;
    std::cout << "string pointer: " << stringPTR << std::endl;
    std::cout << "string reference: " << &stringREF << std::endl;
    
    std::cout << "\n\nSecond part, print the value:" << std::endl;
    std::cout << "string variable: " << mystring << std::endl;
    std::cout << "string pointer: " << *stringPTR << std::endl;
    std::cout << "string reference: " << stringREF << std::endl;

    return (0);
}
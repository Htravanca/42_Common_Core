/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 12:36:16 by hepereir          #+#    #+#             */
/*   Updated: 2025/08/29 14:31:13 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
    Data importante;

    importante.data_string = "Bank important code";
    importante.data_int = 1111;
    std::cout << "Inside original: " << importante.data_string << " " << importante.data_int << std::endl << std::endl;

    std::cout << "Point to Original data:" << std::endl;
    std::cout << &importante << std::endl << std::endl;

    uintptr_t i = Serializer::serialize(&importante);
    std::cout << "After Serialize:" << std::endl;
    std::cout << i << std::endl << std::endl;
    
    Data* copia = Serializer::deserialize(i);
    std::cout << "After Deserialize:" << std::endl;
    std::cout << copia << std::endl << std::endl;

    std::cout << "Inside copy: " << copia->data_string << " " << copia->data_int << std::endl;

    if (&importante == copia)
        std::cout << "Pointers are equal ✅" << std::endl;
    else
        std::cout << "Pointers are NOT equal ❌" << std::endl;

    return (0);
}

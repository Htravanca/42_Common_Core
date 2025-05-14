/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 19:16:12 by hepereir          #+#    #+#             */
/*   Updated: 2025/05/01 19:16:13 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        for (int i = 1; argv[i]; i++)
        {
            for (size_t j = 0; argv[i][j]; j++)
                std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(argv[i][j])));
        }
    }
    std::cout << std::endl;
    return (0);
}

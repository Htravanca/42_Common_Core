/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FindType.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 10:25:48 by hepereir          #+#    #+#             */
/*   Updated: 2025/08/08 10:37:21 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FindType.hpp"

int ft_dot(std::string input)
{
    int i = 0;

    while (input[i])
    {
        if (input[i] == '.')
            return (1);
        i++;
    }
    return (0);
}

int ft_f(std::string input)
{
    int i = input.length() - 1;

    if (input[i] == 'f')
        return (1);
    return (0);
}

int ft_isint(std::string input)
{
    int i = 0;

    if (input[i] == '+' || input[i] == '-')
        i++;
    while (input[i])
    {
        if (!isdigit(input[i]))
            return (0);
        i++;
    }
    return (1);
}

std::string ft_findtype(std::string input)
{
    if (input.length() == 1 && isprint(input[0]) && !isdigit(input[0]))
        return ("CHAR");
    else if (input == "nanf" || input == "+inff" || input == "-inff")
        return ("FLOAT_PSEUDO");
    else if (input == "nan" || input == "+inf" || input == "-inf")
        return ("DOUBLE_PSEUDO");
    else if (ft_dot(input) == 1 && ft_f(input) == 1)
        return ("FLOAT");
    else if (ft_dot(input) == 1 && ft_f(input) == 0)
        return ("DOUBLE");
    else if(ft_isint(input) == 1)
        return ("INT");
    return ("NULL");
}

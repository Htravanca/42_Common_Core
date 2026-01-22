/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrintValues.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 10:26:46 by hepereir          #+#    #+#             */
/*   Updated: 2025/08/29 13:44:45 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PrintValues.hpp"

int stringToInt(const std::string& str)
{
    std::stringstream ss(str);
    int i;
    ss >> i;
    if (ss.fail() || !ss.eof())
        throw std::runtime_error("Invalid int conversion");
    return i;
}

float stringToFloat(const std::string& str)
{
    std::string s = str;
    if (!s.empty() && s[s.length() - 1] == 'f')
        s = s.substr(0, s.length() - 1);

    std::stringstream ss(s);
    float f;
    ss >> f;
    if (ss.fail())
        throw std::runtime_error("Invalid float conversion");
    return f;
}

double stringToDouble(const std::string& str)
{
    std::stringstream ss(str);
    double d;
    ss >> d;
    if (ss.fail() || !ss.eof())
        throw std::runtime_error("Invalid double conversion");
    return d;
}

void ft_print_char(std::string input)
{
    char c = input[0];
    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);

    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void ft_print_int(std::string input)
{
    try
    {
        int i = stringToInt(input);
        char c = static_cast<char>(i);
        float f = static_cast<float>(i);
        double d = static_cast<double>(i);

        if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
            std::cout << "char: impossible" << std::endl;
        else if (isprint(c))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << i << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}

void ft_print_float(std::string input)
{
    try
    {
        float f = stringToFloat(input);
        char c = static_cast<char>(f);
        int i = static_cast<int>(f);
        double d = static_cast<double>(f);

        if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
            std::cout << "char: impossible" << std::endl;
        else if (isprint(c))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        
        if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << i << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}

void ft_print_double(std::string input)
{
    try
    {
        double d = stringToDouble(input);
        char c = static_cast<char>(d);
        int i = static_cast<int>(d);
        float f = static_cast<float>(d);

        if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
            std::cout << "char: impossible" << std::endl;
        else if (isprint(c))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        
        if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << i << std::endl;

        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
    
    
}

void ft_print_floatpseudo(std::string input)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << input << std::endl;
    std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
}

void ft_print_doublepseudo(std::string input)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << input << "f" << std::endl;
    std::cout << "double: " << input << std::endl;
}

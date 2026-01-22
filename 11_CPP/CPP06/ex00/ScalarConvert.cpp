/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 23:58:25 by hepereir          #+#    #+#             */
/*   Updated: 2025/08/08 10:39:25 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"
#include "FindType.hpp"
#include "PrintValues.hpp"

ScalarConvert::ScalarConvert() {}

ScalarConvert::ScalarConvert(const ScalarConvert &other) {(void) other;}

ScalarConvert& ScalarConvert::operator=(const ScalarConvert &other) {(void) other; return *this;}

ScalarConvert::~ScalarConvert() {}

void ScalarConvert::convert(std::string const &input)
{
    std::string type;

    type = ft_findtype(input);
    if (type == "NULL" || input.empty())
    {
        std::cout << "Please enter a valid type, a CHAR, a INT, a FLOAT or a DOUBLE" << std::endl;
        return ;
    }
    if (type == "CHAR")
        ft_print_char(input);
    else if (type == "INT")
        ft_print_int(input);
    else if (type == "FLOAT")
        ft_print_float(input);
    else if (type == "DOUBLE")
        ft_print_double(input);
    else if (type == "FLOAT_PSEUDO")
        ft_print_floatpseudo(input);
    else if (type == "DOUBLE_PSEUDO")
        ft_print_doublepseudo(input);
}
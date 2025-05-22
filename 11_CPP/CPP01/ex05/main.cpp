/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:49:14 by hepereir          #+#    #+#             */
/*   Updated: 2025/05/16 12:49:16 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl toze;

    toze.complain("DEBUG");
    toze.complain("INFO");
    toze.complain("WARNING");
    toze.complain("ERROR");
    toze.complain("NADA");

    return (0);
}
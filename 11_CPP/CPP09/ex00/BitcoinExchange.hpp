/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 20:36:12 by hepereir          #+#    #+#             */
/*   Updated: 2026/01/11 21:56:02 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <stdlib.h>
#include <iostream>
#include <map>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _map;
        float getClosestRate(const std::string &date) const;

    public:
        //ocf
        BitcoinExchange();
        BitcoinExchange(std::string file);
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange& operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        //getters
        std::string GetMapLine(const std::string &date) const;
        void processInputFile(const std::string &inputFile);
};

#endif
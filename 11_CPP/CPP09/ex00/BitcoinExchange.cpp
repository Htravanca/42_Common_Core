/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 20:45:47 by hepereir          #+#    #+#             */
/*   Updated: 2026/01/11 22:09:10 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <cctype>
#include <iomanip>

static std::string trim(const std::string &s)
{
    std::size_t start = 0;
    while (start < s.size() && std::isspace(static_cast<unsigned char>(s[start]))) ++start;
    std::size_t end = s.size();
    while (end > start && std::isspace(static_cast<unsigned char>(s[end - 1]))) --end;
    return s.substr(start, end - start);
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string file)
{
    std::ifstream ifs(file.c_str());
    if (!ifs.is_open())
        throw std::runtime_error("Error: could not open database file. Check if the data.csv file is present.");
    
    std::string line;
    if (!std::getline(ifs, line)) // Skip header line
        return;
    
    while (std::getline(ifs, line))
    {
        if (line.empty())
            continue;
        std::size_t pos = line.find(',');
        if (pos == std::string::npos)
            continue;

        std::string date = trim(line.substr(0, pos));
        std::string rate_str = trim(line.substr(pos + 1));
        if (date.empty() || rate_str.empty())
            continue;

        try
        {
            std::istringstream iss(rate_str);
            float rate;
            if (!(iss >> rate))
               continue;
            _map[date] = rate;
        }
        catch (const std::exception &)
        {
            continue;
        }
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    _map = other._map;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        _map = other._map;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::GetMapLine(const std::string &date) const
{
    std::map<std::string, float>::const_iterator it = _map.find(date);
    std::ostringstream oss;
    if (it == _map.end())
    {
        oss << date << " => (not found)";
        return oss.str();
    }
    oss << it->first << " => " << std::fixed << std::setprecision(2) << it->second;
    return oss.str();
}

float BitcoinExchange::getClosestRate(const std::string &date) const
{
    std::map<std::string, float>::const_iterator it = _map.lower_bound(date);
    
    if (it != _map.end() && it->first == date) // If exact match
        return it->second;
    
    // If no entry >= date, use the last one before it
    if (it == _map.begin())
        return -1; // no valid date found
    --it;
    
    return it->second;
}

static bool isValidDate(const std::string &dateStr)
{
    if (dateStr.length() != 10 || dateStr[4] != '-' || dateStr[7] != '-')
        return false;
    
    for (int i = 0; i < 10; ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(static_cast<unsigned char>(dateStr[i])))
            return false;
    }
    
    // Month: 01-12
    if (dateStr[5] == '0' && dateStr[6] == '0')
        return false;
    if ((dateStr[5] == '1' && dateStr[6] > '2') || dateStr[5] > '1')
        return false;
    
    // Day: 01-31
    if (dateStr[8] == '0' && dateStr[9] == '0')
        return false;
    if ((dateStr[8] == '3' && dateStr[9] > '1') || dateStr[8] > '3')
        return false;
    
    return true;
}

static std::string formatFloat(float f)
{
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << f;
    std::string s = oss.str();
    s.erase(s.find_last_not_of('0') + 1);
    if (s.length() > 0 && s[s.length() - 1] == '.')
        s.erase(s.length() - 1);
    return s;
}

void BitcoinExchange::processInputFile(const std::string &inputFile)
{
    std::ifstream ifs(inputFile.c_str());
    if (!ifs.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    
    std::string line;
    if (!std::getline(ifs, line))
        return;
    
    while (std::getline(ifs, line))
    {
        if (line.empty())
            continue;
        
        std::size_t pipePos = line.find('|');
        if (pipePos == std::string::npos)
        {
            std::cout << "Error: bad input => " << trim(line) << std::endl;
            continue;
        }
        
        std::string dateStr = trim(line.substr(0, pipePos));
        std::string valueStr = trim(line.substr(pipePos + 1));
        
        if (!isValidDate(dateStr))
        {
            std::cout << "Error: bad input => " << dateStr << std::endl;
            continue;
        }
        
        std::istringstream iss(valueStr);
        float value;
        if (!(iss >> value))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        if (value < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000)
        {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }
        
        float rate = getClosestRate(dateStr);
        if (rate < 0)
        {
            std::cout << "Error: bad input => " << dateStr << std::endl;
            continue;
        }
        
        float result = value * rate;
        std::cout << dateStr << " => " << formatFloat(value) 
                  << " = " << formatFloat(result) << std::endl;
    }
}
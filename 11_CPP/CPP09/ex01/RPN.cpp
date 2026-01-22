/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 21:00:00 by hepereir          #+#    #+#             */
/*   Updated: 2025/12/16 19:52:29 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <cctype>
#include <stdexcept>

RPN::RPN() {};

RPN::RPN(std::string input)
{
    std::istringstream iss(input);
    std::string token;
    
    while (iss >> token)
    {
        // digit or operator
        if (token.length() == 1 && std::isdigit(static_cast<unsigned char>(token[0])))
        {
            int num = token[0] - '0';
            _st.push(num);
        }
        else if (token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'))
        {
            if (_st.size() < 2)
                throw std::runtime_error("Error");
        
            int second = _st.top();
            _st.pop();
            int first = _st.top();
            _st.pop();
            
            int result;
            switch (token[0])
            {
                case '+':
                    result = first + second;
                    break;
                case '-':
                    result = first - second;
                    break;
                case '*':
                    result = first * second;
                    break;
                case '/':
                    if (second == 0)
                        throw std::runtime_error("Error");
                    result = first / second;
                    break;
            }
            
            _st.push(result);
        }
        else
        {
            throw std::runtime_error("Error");
        }
    }
    
    // At the end, stack should have exactly 1 element
    if (_st.size() != 1)
        throw std::runtime_error("Error");
};


RPN::RPN(const RPN &other)
{
    _st = other._st;
}

RPN& RPN::operator=(const RPN &other)
{
    if (this != &other)
        _st = other._st;
    return *this;
}

RPN::~RPN() {}

int RPN::getResult() const
{
    if (_st.empty())
        throw std::runtime_error("Error");
    return _st.top();
}
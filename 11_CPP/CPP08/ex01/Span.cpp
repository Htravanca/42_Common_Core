/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 20:40:43 by hepereir          #+#    #+#             */
/*   Updated: 2025/11/18 20:32:30 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): _span(), _maxSize(0) {}

Span::Span(unsigned int n): _span() 
{
    _maxSize = n;
    _span.reserve(n);
}

Span::Span(const Span &other): _span(other._span), _maxSize(other._maxSize) {}

Span& Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _span = other._span;
        _maxSize = other._maxSize;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
    if (_span.size() >= static_cast<size_t>(_maxSize))
        throw std::out_of_range("Span is full");
    _span.push_back(number);
}

int Span::getAt(size_t i) const
{
    if (i >= static_cast<size_t>(_maxSize) || i >= _span.size())
        throw std::runtime_error("Outside of limits");
    return (_span.at(i));
}

int Span::shortestSpan() const
{
    if (_span.size() <= 1)
        throw std::runtime_error("Span is too small");
    
    std::vector<int> sorted = _span;
    std::sort(sorted.begin(), sorted.end());
    int small = INT_MAX;
    for (size_t i = 1; i < sorted.size(); i++)
    {
        if (sorted[i] - sorted[i - 1] < small)
            small = sorted[i] - sorted[i - 1];
    }
    
    return (small);
}

int Span::longestSpan() const
{
    if (_span.size() <= 1)
        throw std::runtime_error("Span is too small");
    
    std::vector<int> sorted = _span;
    std::sort(sorted.begin(), sorted.end());
    int longest = sorted[sorted.size() - 1] - sorted[0];
    return (longest);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 20:40:51 by hepereir          #+#    #+#             */
/*   Updated: 2025/11/18 20:33:33 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <stdlib.h>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits.h>

class Span
{
    private:
        std::vector<int> _span;
        unsigned int _maxSize;
    
    public:
        Span();
        Span(unsigned int n);
        Span(const Span &other);
        Span& operator=(const Span &other);
        ~Span();
        
        int getAt(size_t i) const;
        void addNumber(int number);
        int shortestSpan() const;
        int longestSpan() const;
        template <typename InputIterator>
        void addNumber(InputIterator begin, InputIterator end);
};

template <typename InputIterator>
void Span::addNumber(InputIterator begin, InputIterator end)
{
    size_t distance = std::distance(begin, end);

    if (_span.size() + distance > _maxSize)
        throw std::runtime_error("Not enough space to add range of numbers");

    for (InputIterator it = begin; it != end; ++it)
        _span.push_back(*it);
}

#endif
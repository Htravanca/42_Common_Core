/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:05:06 by hepereir          #+#    #+#             */
/*   Updated: 2025/09/16 13:05:07 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

// Generic iter template
template <typename T, typename F>
void iter(T* array, unsigned int size, F func)
{
    for (size_t i = 0; i < size; i++)
    {
        func(array[i]);
    }
}

// Overload for plain function templates
template <typename T>
void iter(T* array, unsigned int size, void (*func)(T const&))
{
    for (size_t i = 0; i < size; i++)
    {
        func(array[i]);
    }
}

#endif

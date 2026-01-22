/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:05:24 by hepereir          #+#    #+#             */
/*   Updated: 2025/10/24 12:22:29 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
const T& min(const T &a, const T &b)
{
    if (a < b)
        return a;
    return b;
}

template <typename T>
const T& max(const T &a, const T &b)
{
    if (a > b)
        return a;
    return b;
}

#endif

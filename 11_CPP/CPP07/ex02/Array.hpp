/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:04:57 by hepereir          #+#    #+#             */
/*   Updated: 2025/10/04 12:30:29 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array
{
    private:
        T* _data;
        unsigned int _size;

    public:
        //ocf
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();

        // Access operator
        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;

        // Getter
        unsigned int size() const;
};

# include "Array.tpp"

#endif
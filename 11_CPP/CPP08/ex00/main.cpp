/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 21:55:43 by hepereir          #+#    #+#             */
/*   Updated: 2026/01/08 11:28:30 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <deque>
#include <vector>
#include "easyfind.hpp"

int main()
{
    int arr[] = {10, 20, 30, 40};
    std::vector<int> v(arr, arr + 4);
    std::list<int> l(arr, arr + 4);
    std::deque<int> d(arr, arr + 4);

    try {
        std::vector<int>::iterator it = easyfind(v, 30);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::list<int>::iterator it = easyfind(l, 20);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::deque<int>::iterator it = easyfind(d, 10);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        easyfind(v, 100);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
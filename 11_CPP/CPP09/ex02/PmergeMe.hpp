/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 19:00:00 by hepereir          #+#    #+#             */
/*   Updated: 2025/12/19 15:10:51 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <sys/time.h>

class PmergeMe
{
    private:
        std::vector<int> _vector;
        std::deque<int> _deque;
        
        void sortVector(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        void sortDeque(std::deque<int>::iterator begin, std::deque<int>::iterator end);
        
    public:
        PmergeMe();
        PmergeMe(int argc, char **argv);
        PmergeMe(const PmergeMe &other);
        PmergeMe& operator=(const PmergeMe &other);
        ~PmergeMe();
        
        void run();
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 19:00:00 by hepereir          #+#    #+#             */
/*   Updated: 2025/12/20 13:28:13 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <iomanip>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, char **argv)
{
    if (argc < 2)
        throw std::runtime_error("Error");
    
    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];
        
        if (arg.empty())
            throw std::runtime_error("Error");
        
        if (arg[0] == '-')
            throw std::runtime_error("Error");
        
        for (size_t j = 0; j < arg.length(); ++j)
        {
            if (!std::isdigit(static_cast<unsigned char>(arg[j])))
                throw std::runtime_error("Error");
        }
        
        int num = std::atoi(arg.c_str());
        _vector.push_back(num);
        _deque.push_back(num);
    }
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    _vector = other._vector;
    _deque = other._deque;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _vector = other._vector;
        _deque = other._deque;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::sortVector(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    int size = std::distance(begin, end);
    if (size <= 1)
        return ;
    if (size == 2)
    {
        if (*begin > *(begin + 1))
            std::swap(*begin, *(begin + 1));
        return;
    }
    
    // Step 1: Create pairs - each pair has smaller element first, larger second
    std::vector<std::pair<int, int> > pairs;
    std::vector<int> pending;
    
    for (int i = 0; i < size - 1; i += 2)
    {
        int a = *(begin + i);
        int b = *(begin + i + 1);
        if (a > b)
            pairs.push_back(std::make_pair(b, a));
        else
            pairs.push_back(std::make_pair(a, b));
    }
    // Handle odd element
    if (size % 2 == 1)
        pending.push_back(*(end - 1));
    
    // Step 2: larger elements pushed to main
    std::vector<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i)
        mainChain.push_back(pairs[i].second);
    
    // Step 3: Recursively sort the main chain using Ford-Johnson
    if (mainChain.size() > 1)
        sortVector(mainChain.begin(), mainChain.end());
    
    // Step 4: Insert smaller elements using Jacobsthal insertion order
    std::vector<int> result = mainChain;
    
    // Generate Jacobsthal sequence
    std::vector<size_t> jacobsthal;
    jacobsthal.push_back(1);
    if (pairs.size() > 1)
    {
        jacobsthal.push_back(3);
        size_t idx = 2;
        while (true)
        {
            size_t next = jacobsthal[idx - 1] + 2 * jacobsthal[idx - 2];
            if (next > pairs.size())
                break;
            jacobsthal.push_back(next);
            ++idx;
        }
    }
    
    // Build insertion order based on Jacobsthal sequence
    std::vector<size_t> insertionOrder;
    std::vector<bool> added(pairs.size(), false);
    
    for (size_t j = 0; j < jacobsthal.size(); ++j)
    {
        size_t jacobPos = jacobsthal[j] - 1; // Convert to 0-based
        
        // Add the Jacobsthal position
        if (jacobPos < pairs.size() && !added[jacobPos])
        {
            insertionOrder.push_back(jacobPos);
            added[jacobPos] = true;
        }
        
        // Fill gap: add positions between previous and current Jacobsthal in reverse
        size_t prevJacob = (j == 0) ? 0 : jacobsthal[j - 1];
        for (size_t k = jacobPos; k > prevJacob && k > 0; --k)
        {
            if (!added[k - 1])
            {
                insertionOrder.push_back(k - 1);
                added[k - 1] = true;
            }
        }
    }
    
    // Add any remaining positions not yet in the order
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        if (!added[i])
            insertionOrder.push_back(i);
    }
    
    // Insert smaller elements in the computed order
    for (size_t i = 0; i < insertionOrder.size(); ++i)
    {
        int toInsert = pairs[insertionOrder[i]].first;
        std::vector<int>::iterator it = std::lower_bound(result.begin(), result.end(), toInsert);
        result.insert(it, toInsert);
    }
    
    // Step 5: Insert pending odd element
    for (size_t i = 0; i < pending.size(); ++i)
    {
        std::vector<int>::iterator it = std::lower_bound(result.begin(), result.end(), pending[i]);
        result.insert(it, pending[i]);
    }
    
    // Step 6: Copy result back
    for (int i = 0; i < size; ++i)
        *(begin + i) = result[i];
}

// Ford-Johnson algorithm (merge-insert sort) for deque
void PmergeMe::sortDeque(std::deque<int>::iterator begin, std::deque<int>::iterator end)
{
    int size = std::distance(begin, end);
    
    if (size <= 1)
        return;
    
    if (size == 2)
    {
        if (*begin > *(begin + 1))
            std::swap(*begin, *(begin + 1));
        return;
    }
    
    // Step 1: Create pairs - each pair has smaller element first, larger second
    std::deque<std::pair<int, int> > pairs;
    std::deque<int> pending;
    
    for (int i = 0; i < size - 1; i += 2)
    {
        int a = *(begin + i);
        int b = *(begin + i + 1);
        if (a > b)
            pairs.push_back(std::make_pair(b, a));
        else
            pairs.push_back(std::make_pair(a, b));
    }
    
    // Handle odd element
    if (size % 2 == 1)
        pending.push_back(*(end - 1));
    
    // Step 2: Extract larger elements from pairs (main chain)
    std::deque<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i)
        mainChain.push_back(pairs[i].second);
    
    // Step 3: Recursively sort the main chain using Ford-Johnson
    if (mainChain.size() > 1)
        sortDeque(mainChain.begin(), mainChain.end());
    
    // Step 4: Insert smaller elements using Jacobsthal insertion order
    std::deque<int> result = mainChain;
    
    // Generate Jacobsthal sequence
    std::vector<size_t> jacobsthal;
    jacobsthal.push_back(1);
    if (pairs.size() > 1)
    {
        jacobsthal.push_back(3);
        size_t idx = 2;
        while (true)
        {
            size_t next = jacobsthal[idx - 1] + 2 * jacobsthal[idx - 2];
            if (next > pairs.size())
                break;
            jacobsthal.push_back(next);
            ++idx;
        }
    }
    
    // Build insertion order based on Jacobsthal sequence
    std::vector<size_t> insertionOrder;
    std::vector<bool> added(pairs.size(), false);
    
    for (size_t j = 0; j < jacobsthal.size(); ++j)
    {
        size_t jacobPos = jacobsthal[j] - 1; // Convert to 0-based
        
        // Add the Jacobsthal position
        if (jacobPos < pairs.size() && !added[jacobPos])
        {
            insertionOrder.push_back(jacobPos);
            added[jacobPos] = true;
        }
        
        // Fill gap: add positions between previous and current Jacobsthal in reverse
        size_t prevJacob = (j == 0) ? 0 : jacobsthal[j - 1];
        for (size_t k = jacobPos; k > prevJacob && k > 0; --k)
        {
            if (!added[k - 1])
            {
                insertionOrder.push_back(k - 1);
                added[k - 1] = true;
            }
        }
    }
    
    // Add any remaining positions not yet in the order
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        if (!added[i])
            insertionOrder.push_back(i);
    }
    
    // Insert smaller elements in the computed order
    for (size_t i = 0; i < insertionOrder.size(); ++i)
    {
        int toInsert = pairs[insertionOrder[i]].first;
        std::deque<int>::iterator it = std::lower_bound(result.begin(), result.end(), toInsert);
        result.insert(it, toInsert);
    }
    
    // Step 5: Insert pending odd element
    for (size_t i = 0; i < pending.size(); ++i)
    {
        std::deque<int>::iterator it = std::lower_bound(result.begin(), result.end(), pending[i]);
        result.insert(it, pending[i]);
    }
    
    // Step 6: Copy result back
    for (int i = 0; i < size; ++i)
        *(begin + i) = result[i];
}

void PmergeMe::run()
{
    std::cout << "Before: ";
    for (size_t i = 0; i < _vector.size(); ++i)
    {
        if (i > 0)
            std::cout << " ";
        std::cout << _vector[i];
    }
    std::cout << std::endl;
    
    struct timeval start, end;
    gettimeofday(&start, NULL);
    sortVector(_vector.begin(), _vector.end());
    gettimeofday(&end, NULL);  
    double timeVector = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
    
    gettimeofday(&start, NULL);
    sortDeque(_deque.begin(), _deque.end());
    gettimeofday(&end, NULL);
    double timeDeque = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
    
    std::cout << "After: ";
    for (size_t i = 0; i < _vector.size(); ++i)
    {
        if (i > 0)
            std::cout << " ";
        std::cout << _vector[i];
    }
    std::cout << std::endl;
    
    std::cout << "Time to process a range of " << _vector.size() 
              << " elements with std::vector : " 
              << std::fixed << std::setprecision(5) << timeVector << " us" << std::endl;
    
    std::cout << "Time to process a range of " << _deque.size() 
              << " elements with std::deque : " 
              << std::fixed << std::setprecision(5) << timeDeque << " us" << std::endl;
}

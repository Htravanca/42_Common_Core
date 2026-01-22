/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 21:00:03 by hepereir          #+#    #+#             */
/*   Updated: 2025/12/14 12:08:39 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>

class RPN
{
    private:
        std::stack<int> _st;

    public:
        //ocf
        RPN();
        RPN(std::string input);
        RPN(const RPN &other);
        RPN& operator=(const RPN &other);
        ~RPN();
        
        // getter
        int getResult() const;

};

#endif
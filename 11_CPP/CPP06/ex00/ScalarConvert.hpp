/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 23:31:34 by hepereir          #+#    #+#             */
/*   Updated: 2025/08/08 10:30:00 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERT_HPP
# define SCALARCONVERT_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

class ScalarConvert
{
    private:
        //ocf
        ScalarConvert();
        ScalarConvert(const ScalarConvert &other);
        ScalarConvert& operator=(const ScalarConvert &other);
        ~ScalarConvert();
    
    public:
        static void convert(std::string const &input);  
};

#endif
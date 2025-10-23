/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 21:52:15 by hepereir          #+#    #+#             */
/*   Updated: 2025/07/26 22:00:02 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern
{
    public:
        //ocf
        Intern();
        Intern(const Intern &other);
        Intern& operator=(const Intern &other);
        ~Intern();
        
        AForm* makeForm(std::string const &formname, std::string const &target);
};

#endif
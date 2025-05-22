/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:50:25 by hepereir          #+#    #+#             */
/*   Updated: 2025/05/08 17:57:31 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
    private:
        std::string name;
        Weapon& weapon;

    public:
        HumanA(std::string name, Weapon& weapon);
        ~HumanA();
        void attack();
};

#endif
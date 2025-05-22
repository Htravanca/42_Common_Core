/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 23:01:09 by hepereir          #+#    #+#             */
/*   Updated: 2025/05/08 23:01:31 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon* weapon;

    public:
        HumanB(std::string name);
        ~HumanB();
        void setWeapon(Weapon& weapon);
        void attack();
};

#endif

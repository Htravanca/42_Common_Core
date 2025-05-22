/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:50:34 by hepereir          #+#    #+#             */
/*   Updated: 2025/05/08 17:36:36 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
    private:
        std::string type;

    public:
        Weapon(std::string value);
        ~Weapon();
        const std::string& getType() const;
        void setType(std::string value);
};

#endif
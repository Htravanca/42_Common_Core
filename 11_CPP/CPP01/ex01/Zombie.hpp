/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:06:07 by hepereir          #+#    #+#             */
/*   Updated: 2025/05/08 15:26:17 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	private:
		std::string name;

	public:
		Zombie();
		~Zombie();
		void setName(std::string name);
		void announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif
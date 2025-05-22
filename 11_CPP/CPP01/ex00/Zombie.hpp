/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:06:07 by hepereir          #+#    #+#             */
/*   Updated: 2025/05/04 19:31:41 by hepereir         ###   ########.fr       */
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
		Zombie(std::string name);
		~Zombie ();
		void announce(void);
};
	
Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 11:45:28 by hepereir          #+#    #+#             */
/*   Updated: 2025/06/26 16:16:38 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	protected:
		std::string ideas[100];

	public:
		Brain();
    	Brain(const Brain& other);
    	Brain& operator=(const Brain& other);
    	~Brain();
		void setIdea(int index, const std::string& idea);
    	std::string getIdea(int index) const;
};

#endif
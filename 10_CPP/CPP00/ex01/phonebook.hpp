/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 19:57:16 by hepereir          #+#    #+#             */
/*   Updated: 2025/05/04 15:09:32 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iomanip>
# include <limits>
# include "contact.hpp"

class Phonebook
{
	private:
		Contact contacts[8];
		int count;
		int old_index;
	public:
		Phonebook();
		void addContact();
		void searchContacts() const;
};

#endif
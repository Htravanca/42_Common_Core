/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:45:51 by hepereir          #+#    #+#             */
/*   Updated: 2025/05/22 14:51:39 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

/*Orthodox Canonical Form
	-Default Constructor: Creates object with default values
	-Copy Constructor: Creates a new object as a copy of an existing one
	-Copy Assignment Operator: Assigns values from one object to another already existing one
	-Destructor: Cleans up when the object is destroyed*/
class Fixed
{
	private:
		int					_value;
		static const int	_fractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif

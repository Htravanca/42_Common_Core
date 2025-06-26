/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:08:41 by hepereir          #+#    #+#             */
/*   Updated: 2025/06/01 18:49:44 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int integer)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = integer << _fractionalBits;
}

Fixed::Fixed(const float floating)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(floating * (1 << _fractionalBits));
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) 
		this->_value = other.getRawBits();
	return (*this);
}

bool Fixed::operator>(const Fixed& other) const
{
	if (this->getRawBits() > other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed& other) const
{
	if (this->getRawBits() < other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed& other) const
{
	if (this->getRawBits() >= other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed& other) const
{
	if (this->getRawBits() <= other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed& other) const
{
	if (this->getRawBits() == other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed& other) const
{
	if (this->_value != other.getRawBits())
		return (true);
	return (false);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed& other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed& other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
	if (other.toFloat() == 0)
	{
		std::cerr << "Error: Division by zero" << std::endl;
		return Fixed(0);
	}
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() // pre-increment
{
	++this->_value;
	return *this;
}

Fixed Fixed::operator++(int) // post-increment
{
	Fixed temp = *this;
	++(*this);
	return temp;
}

Fixed& Fixed::operator--() // pre-decrement
{
	--this->_value;
	return *this;
}

Fixed Fixed::operator--(int) // post-decrement
{
	Fixed temp = *this;
	--(*this);
	return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return a;
	else
		return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return a;
	else
		return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	else
		return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return a;
	else
		return b;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
	return ((float)getRawBits() / (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
	return (getRawBits() >> _fractionalBits);
}

int Fixed::getRawBits(void) const
{
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}
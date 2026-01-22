/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 12:36:16 by hepereir          #+#    #+#             */
/*   Updated: 2025/10/24 12:25:49 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int main( void ) {

	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl << std::endl;
	
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl << std::endl;

	double e = 3.4;
	double f = 10.1;
	::swap( e, f );
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl << std::endl;

	float g = 10.1003;
	float h = 10.1002;
	::swap( g, h );
	std::cout << "g = " << g << ", h = " << h << std::endl;
	std::cout << "min( g, h ) = " << ::min( g, h ) << std::endl;
	std::cout << "max( g, h ) = " << ::max( g, h ) << std::endl << std::endl;

	char c1 = 'A';
	char c2 = 'Z';
	::swap(c1, c2);
	std::cout << "c1 = " << c1 << ", c2 = " << c2 << std::endl;
	std::cout << "min( c1, c2 ) = " << ::min(c1, c2) << std::endl;
	std::cout << "max( c1, c2 ) = " << ::max(c1, c2) << std::endl << std::endl;

	int i = 42;
	int j = 42;
	::swap( i, j );
	std::cout << "i = " << i << ", j = " << j << std::endl;
	std::cout << "min( i, j ) = " << ::min( i, j ) << std::endl;
	std::cout << "max( i, j ) = " << ::max( i, j ) << std::endl << std::endl;
	
	const int k = 100;
	const int l = 200;
	std::cout << "k = " << k << ", l = " << l << std::endl;
	std::cout << "min( k, l ) = " << ::min( k,	l ) << std::endl;				
	std::cout << "max( k, l ) = " << ::max( k, l ) << std::endl;	

	return 0;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:26:19 by taha              #+#    #+#             */
/*   Updated: 2025/02/17 12:52:50 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

Base* generate(void)
{
	srand(time(NULL));
	int random = rand() % 3;

	switch(random) {
		case 0: 
			return new A();
			break;
		case 1: 
			return new B();
			break;
		case 2:
			return new C();
			break;
		default:
			break;
	}
	return NULL;
}

void identify(Base* p)
{
	if (p == NULL) {
		std::cout << "NULL" << std::endl;
		return;
	}

	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p); // to avoid warning
		std::cout << "A" << std::endl;
		return;
	}
	catch(std::bad_cast&) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch(std::bad_cast&) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch(std::bad_cast&) {}
}
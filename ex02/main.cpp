/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:32:42 by taha              #+#    #+#             */
/*   Updated: 2025/02/17 12:57:41 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"



int main()
{
	Base* base = generate();
	Base *base2 = new(A);
	Base *base3 = new(B);
	Base *base4 = new(C);
	Base* base5 = NULL;

	if (base && base2 && base3 && base4)
	{
		std::cout << "\n==== Identify Test 1====" << std::endl;
		identify(base);
		identify(*base);

		std::cout << "\n==== Identify Test 2====" << std::endl;
		identify(base2);
		identify(*base2);

		std::cout << "\n==== Identify Test 3====" << std::endl;
		identify(base3);
		identify(*base3);

		std::cout << "\n==== Identify Test 4====" << std::endl;
		identify(base4);
		identify(*base4);
	}
	else
		std::cerr << "Error: Base is NULL" << std::endl;

	std::cout << "\n ==== Null Test ====" << std::endl;
	identify(base5);
	delete base;
	delete base2;
	delete base3;
	delete base4;

	return 0;
}
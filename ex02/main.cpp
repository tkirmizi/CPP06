/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:32:42 by taha              #+#    #+#             */
/*   Updated: 2025/02/16 13:35:19 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"
#include "ABase.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"



	int main() {
		ABase* base = generate();
		
		identify(base);
		identify(*base);
		
		delete base;
		return 0;
	}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:24:58 by taha              #+#    #+#             */
/*   Updated: 2025/02/16 13:35:28 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "ABase.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

ABase*	generate(void);
void	identify(ABase* p);
void	identify(ABase& p);
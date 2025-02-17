/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:38:45 by taha              #+#    #+#             */
/*   Updated: 2025/02/17 12:36:53 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <cmath>
#include "Convert.hpp"

class ScalarConverter{
private:
		static bool isDouble(std::string const &str);
		static bool isFloat(std::string const &str);
		static bool isInt(std::string const &str);
		static bool isChar(std::string const &str);
public:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &other);
		ScalarConverter &operator=(ScalarConverter const &other);
		~ScalarConverter();
		
		static void convert(std::string const &literal);
};

#endif
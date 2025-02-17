/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:44:56 by taha              #+#    #+#             */
/*   Updated: 2025/02/17 12:36:38 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(ScalarConverter const &other){(void) other;}
ScalarConverter::~ScalarConverter(){}
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other){(void) other; return *this;}

bool ScalarConverter::isChar(std::string const &str)
{
	if (str.length() != 3)
		return false;
	if (str[0] != '\'' || str[2] != '\'')
		return false;
	return true;
}

bool ScalarConverter::isInt(std::string const &str)
{
	int flag = 1;
	size_t sign = 0;

	if (str.empty())
		flag = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		sign = 1;
		if (str.length() == 1)
			flag = 0;
	}

	for (; sign < str.length(); sign++)
	{
		if (!std::isdigit(str[sign]))
			return false;
	}
	if (!flag)
		return false;
	long long value = stoll(str);
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		return false;
	return true;
}

bool ScalarConverter::isFloat(std::string const &str)
{
	size_t sign = 0;
	size_t dot = 0;

	if (str == "nanf" || str == "+inff" || str == "-inff")
		return true;
	if (!str[0])
		return false;

	if (str.empty())
		return false;

	if (str[str.length() - 1] != 'f')
		return false;

	if (str[0] == '-' || str[0] == '+')
	{
		sign = 1;
		if (str.length() == 1)
			return false;
	}

	for (; sign < str.length(); sign++)
	{
		if (!std::isdigit(str[sign]) && str[sign] != '.' && str[sign] != 'f')
			return false;
		if (str[sign] == '.')
			dot++;
	}

	if (dot != 1)
		return false;
	return true;
}


bool ScalarConverter::isDouble(std::string const &str)
{
	size_t sign = 0;
	size_t dot = 0;

	if (!str[0])
		return false;

	if (str == "nan" || str == "+inf" || str == "-inf")
		return true;

	if (str.empty())
		return false;
		
	if (str.length() < 3)
		return false;

	if (str[0] == '-' || str[0] == '+')
	{
		sign = 1;
		if (str.length() == 1)
			return false;
	}
	for (; sign < str.length(); sign++)
	{
		if (!std::isdigit(str[sign]) && str[sign] != '.')
			return false;
		if (str[sign] == '.')
			dot++;
	}
	if (dot == 1)
	{
		size_t pos = str.find('.');
		if (!str[pos+1] || str[pos+1] == 'f')
			return false;
		return true;
	}
	if (dot != 1)
		return false;
	return true;
}

void ScalarConverter::convert(std::string const &literal)
{
	bool isSpecial = false;
	if (literal == "nan" || literal == "nanf" || 
		literal == "+inf" || literal == "-inf" ||
		literal == "+inff" || literal == "-inff")
	{
		isSpecial = true;
	}
	bool ic = isChar(literal);
	bool ii = isInt(literal);
	bool iff = isFloat(literal);
	bool id = isDouble(literal);

	charWritter(literal, ic, ii, iff, id, isSpecial);
	intWritter(literal, ic, ii, iff, id, isSpecial);
	floatWritter(literal, ic, ii, iff, id, isSpecial);
	doubleWritter(literal, ic, ii, iff, id, isSpecial);
}



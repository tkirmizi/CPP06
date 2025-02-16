/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:44:56 by taha              #+#    #+#             */
/*   Updated: 2025/02/16 12:42:38 by taha             ###   ########.fr       */
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

	std::cout << "char: ";
	if (ic)
		std::cout << "'" << literal[1] << "'" << std::endl;
	else if (isSpecial)
		std::cout << "impossible" << std::endl;
	else if (id || iff || ii)
	{
		if (iff)
		{
			float f = std::stof(literal);
			char c = static_cast<char>(f);
			if (std::isprint(c))
				std::cout << "'" << c << "'" << std::endl;
			else 
				std::cout << "Non displayable" << std::endl;
		}
		else if (id)
		{
			double d = std::stod(literal);
			char c = static_cast<char>(d);
			if (std::isprint(c))
				std::cout << "'" << c << "'" << std::endl;
			else
				std::cout << "Non displayable" << std::endl;
		}
		else
		{
			int i = std::stoi(literal);
			char c = static_cast<char>(i);
			if (std::isprint(c))
				std::cout << "'" << c << "'" << std::endl;
			else
				std::cout << "Non displayable" << std::endl;
		}
	}
	else 
		std::cout << "impossible" << std::endl;
	std::cout << "int: ";
	if (isSpecial)
		std::cout << "impossible" << std::endl;
	else
	{
		try {
			int value = 0;
			if (ic)
				value = static_cast<int>(literal[1]);
			else if (ii)
				value = std::stoi(literal);
			else if (iff)
				value = static_cast<int>(std::stof(literal));
			else if (id)
				value = static_cast<int>(std::stod(literal));
			std::cout << value << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << "impossible" << std::endl;
		}
	}

	std::cout << "float: ";
	if (isSpecial)
	{
		if (literal == "nan" || literal == "nanf")
			std::cout << "nanf" << std::endl;
		else if (literal == "+inf" || literal == "+inff")
			std::cout << "+inff" << std::endl;
		else
			std::cout << "-inff" << std::endl;
	}
	else
	{
		try {
		float value = 0;
		if (ic)
			value = static_cast<float>(literal[1]);
		else if (ii)
			value = static_cast<float>(std::stoi(literal));
		else if (iff)
			value = std::stof(literal);
		else if (id)
			value = static_cast<float>(std::stod(literal));
		std::cout << std::fixed << std::setprecision(1) << value << "f" << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << "impossible" << std::endl;
		}
	}
	std::cout << "double: ";
	if (isSpecial)
	{

		if (literal == "nan" || literal == "nanf")
			std::cout << "nan" << std::endl;
		else if (literal == "+inf" || literal == "+inff")
			std::cout << "+inf" << std::endl;
		else
			std::cout << "-inf" << std::endl;
	}
	else
	{
		try 
		{
			double value = 0;
			if (ic)
				value = static_cast<double>(literal[1]);
			else if (ii)
				value = static_cast<double>(std::stoi(literal));
			else if (iff)
				value = static_cast<double>(std::stof(literal));
			else if (id)
				value = std::stod(literal);
		std::cout << std::fixed << std::setprecision(1) << value << std::endl;
		}
		catch (const std::exception& e) 
		{
			std::cout << "impossible" << std::endl;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:37:11 by tkirmizi          #+#    #+#             */
/*   Updated: 2025/02/17 12:37:28 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

void charWritter(std::string const &literal, bool ic, bool ii, bool iff, bool id, bool isSpecial)
{
	std::cout << "char: ";
	if (ic)
		std::cout << "'" << literal[1] << "'" << std::endl;
	else if (isSpecial)
		std::cout << "impossible" << std::endl;
	else if (id || iff || ii)
	{
		try
		{
			char value = 0;
			if (ii)
				value = static_cast<char>(std::stoi(literal));
			else if (iff)
				value = static_cast<char>(std::stof(literal));
			else if (id)
				value = static_cast<char>(std::stod(literal));
			if (value < 32 || value > 126)
				std::cout << "Non displayable" << std::endl;
			else
				std::cout << "'" << value << "'" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "impossible" << std::endl;
		}
	}
	else 
		std::cout << "impossible" << std::endl;
}


void intWritter(std::string const &literal, bool ic, bool ii, bool iff, bool id, bool isSpecial)
{
	std::cout << "int: ";
	if (isSpecial)
		std::cout << "impossible" << std::endl;
	else
	{
		try
		{
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
		catch (const std::exception& e)
		{
			std::cout << "impossible" << std::endl;
		}
	}
}

void floatWritter(std::string const &literal, bool ic, bool ii, bool iff, bool id, bool isSpecial)
{
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
		try
		{
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
		catch (const std::exception& e)
		{
			std::cout << "impossible" << std::endl;
		}
	}
}

void doubleWritter(std::string const &literal, bool ic, bool ii, bool iff, bool id, bool isSpecial)
{
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
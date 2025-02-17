/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:35:48 by tkirmizi          #+#    #+#             */
/*   Updated: 2025/02/17 12:37:51 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
#define CONVERT_HPP
#include "ScalarConverter.hpp"

class ScalarConverter;
void charWritter(std::string const &literal, bool ic, bool ii, bool iff, bool id, bool isSpecial);
void intWritter(std::string const &literal, bool ic, bool ii, bool iff, bool id, bool isSpecial);
void floatWritter(std::string const &literal, bool ic, bool ii, bool iff, bool id, bool isSpecial);
void doubleWritter(std::string const &literal, bool ic, bool ii, bool iff, bool id, bool isSpecial);

#endif
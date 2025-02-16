/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:50:18 by taha              #+#    #+#             */
/*   Updated: 2025/02/16 12:52:01 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// orthodox form
Serializer::Serializer(){};
Serializer::~Serializer(){};
Serializer::Serializer(const Serializer &other){(void)other;};
Serializer &Serializer::operator=(const Serializer &other){(void)other; return *this;};



uintptr_t Serializer::serialize(Data* ptr){
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw){
	return reinterpret_cast<Data*>(raw);
}
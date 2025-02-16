/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:32:42 by taha              #+#    #+#             */
/*   Updated: 2025/02/16 12:57:40 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Serializer.hpp"

int main(){
	Data data {15, "Bob"};
	
	Data *dataPtr = &data;

	std::cout << "\n====initial address====\n";
	std::cout << "dataPtr: " << dataPtr << std::endl;
	uintptr_t raw = Serializer::serialize(dataPtr);
	std::cout << "\n====function tests====\n";
	std::cout << "serialized: " << raw << std::endl;
	Data *dataPtr2 = Serializer::deserialize(raw);
	std::cout << "deserialized: " << dataPtr2 << std::endl;
	std::cout << "\n====deserialized values====\n";
	std::cout << "i: " << dataPtr2->i << "\n" << "name: " << dataPtr2->name << std::endl;
}
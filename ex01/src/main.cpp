/******************************************************************************/
/*                                                                            */
/*                                                         :::      ::::::::  */
/*    main.cpp                                           :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*    By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*    Created: 2023/02/09 23:27:23 by rokupin           #+#    #+#            */
/*                                                     ###   ########.fr      */
/*                                                                            */
/******************************************************************************/
/**
		Description

	In C++, reinterpret_cast is a type of casting operator that is used to
 convert a pointer from one type to another without changing the value of the
 pointer itself. In this case, reinterpret_cast<uintptr_t> is used to convert the
 address of the source object to an unsigned integer of the same size (i.e.,
 the size of a pointer).

	Serialization is the process of converting an object from its in-memory
 representation to a format that can be stored or transmitted, such as a file
 or a network message. In this example, Data::serialize is a static member
 function that takes a pointer to a Data object and returns an uintptr_t
 value that represents the address of the object. This is a simple form of
 serialization, where the object is simply converted to its raw memory
 representation. The Data::deserialize function takes the raw memory
 representation (as an uintptr_t value) and returns a pointer to the original
 Data object.
	When main is executed, an instance of the Data class is created, and its
 values are printed to the console. The Data::serialize function is called
 with a pointer to the source object, and the resulting uintptr_t value is
 passed to Data::deserialize. This function returns a pointer to a new Data
 object that is identical to the source object. Finally, the values of the
 sink_ptr object are printed to the console, demonstrating that the
 serialization and deserialization process was successful.
*/
#include <iostream>
#include "Data.h"

int main() {
	Data source(1, "The Great Old One");
	Data* sink_ptr;
	std::cout << source << std::endl;
	sink_ptr = Data::deserialize(Data::serialize(&source));
	std::cout << *sink_ptr << std::endl;
	return 0;
}
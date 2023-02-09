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
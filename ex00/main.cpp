/******************************************************************************/
/*                                                                            */
/*                                                         :::      ::::::::  */
/*    main.cpp                                           :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*    By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*    Created: 2023/02/04 15:56:06 by rokupin           #+#    #+#            */
/*                                                     ###   ########.fr      */
/*                                                                            */
/******************************************************************************/

#include <cassert>
#include <iostream>
#include "ScalarConversion.h"

int main(int ac, const char** av) {
	assert(ac == 2 && "There should be only 1 argument");
	try {
		ScalarConversion val(av[1]);
		std::cout << val << std::endl;
	} catch (const ScalarConversion::WrongInputException& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
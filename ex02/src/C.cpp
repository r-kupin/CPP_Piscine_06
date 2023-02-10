/******************************************************************************/
/*                                                                            */
/*                                                         :::      ::::::::  */
/*    C.cpp                                              :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*    By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*    Created: 2023/02/10 12:01:55 by rokupin           #+#    #+#            */
/*                                                     ###   ########.fr      */
/*                                                                            */
/******************************************************************************/

#include <iostream>
#include "C.h"


C::C() {}

C::C(const C &other) {(void)other;}

C &C::operator=(const C &other) {
	(void)other;
	return *this;
}

C::~C() {}

void C::reveal() {
	std::cout << "This is Class C" << std::endl;
}

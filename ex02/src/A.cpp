/******************************************************************************/
/*                                                                            */
/*                                                         :::      ::::::::  */
/*    A.cpp                                              :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*    By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*    Created: 2023/02/10 12:01:30 by rokupin           #+#    #+#            */
/*                                                     ###   ########.fr      */
/*                                                                            */
/******************************************************************************/

#include <iostream>
#include "A.h"


A::A() {}

A::A(const A &other) {(void)other;}

A &A::operator=(const A &other) {
	(void)other;
	return *this;
}

A::~A() {}

void A::reveal() {
	std::cout << "This is Class A" << std::endl;
}

/******************************************************************************/
/*                                                                            */
/*                                                         :::      ::::::::  */
/*    B.cpp                                              :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*    By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*    Created: 2023/02/10 12:01:43 by rokupin           #+#    #+#            */
/*                                                     ###   ########.fr      */
/*                                                                            */
/******************************************************************************/

#include <iostream>
#include "B.h"


B::B() {}

B::B(const B &other) {(void)other;}

B &B::operator=(const B &other) {
	(void)other;
	return *this;
}

B::~B() {}

void B::reveal() {
	std::cout << "This is Class B" << std::endl;
}

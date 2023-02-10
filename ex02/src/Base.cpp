/******************************************************************************/
/*                                                                            */
/*                                                         :::      ::::::::  */
/*    Base.cpp                                           :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*    By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*    Created: 2023/02/10 11:59:53 by rokupin           #+#    #+#            */
/*                                                     ###   ########.fr      */
/*                                                                            */
/******************************************************************************/

#include <cstdlib>
#include <iostream>
#include "Base.h"
#include "A.h"
#include "B.h"
#include "C.h"

Base *Base::generate(void) {
	switch (std::rand() % 3) {
		case 0	: return new A();
		case 1	: return new B();
		default	: return new C();
	}
}

void Base::identify(Base *p) {
	A* probably_a = dynamic_cast<A*>(p);
	B* probably_b = dynamic_cast<B*>(p);
	C* probably_c = dynamic_cast<C*>(p);
	if (probably_a)
		std::cout << " pointer p idetified as A!" << std::endl;
	else if (probably_b)
		std::cout << " pointer p idetified as B!" << std::endl;
	else if (probably_c)
		std::cout << " pointer p idetified as C!" << std::endl;
	else
		std::cout << " pointer p isn`t idetified...  " << std::endl;
}

void Base::identify(Base &p) {
	try {
		A probably_a = dynamic_cast<A&>(p);
		std::cout << " reference p idetified as A!" << std::endl;
		return;
	} catch (...) {
		try {
			B probably_b = dynamic_cast<B&>(p);
			std::cout << " reference p idetified as B!" << std::endl;
			return;
		} catch (...) {
			try {
				C probably_c = dynamic_cast<C&>(p);
				std::cout << " reference p idetified as C!" << std::endl;
				return;
			} catch (...) {
				std::cout << " reference isn't identifyed.." << std::endl;
			}
		}
	}
}

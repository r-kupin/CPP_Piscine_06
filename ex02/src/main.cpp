/******************************************************************************/
/*                                                                            */
/*                                                         :::      ::::::::  */
/*    main.cpp                                           :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*    By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*    Created: 2023/02/10 12:06:14 by rokupin           #+#    #+#            */
/*                                                     ###   ########.fr      */
/*                                                                            */
/******************************************************************************/
/**
		Description

 	The void Base::identify(Base *p) and void Base::identify(Base &p)
 functions are both used to identify the	type of an object that is derived
 from the Base class. The difference between them is in how they take the
 object as an argument: identify(Base *p) takes a pointer to the object,
 while identify(Base &p) takes a reference to the object.
	Both functions use dynamic_cast to check if the object pointed to or
 referred to by the argument is an instance of class A, B, or C. If the
 object's type can be identified, the function prints a message identifying
 the type.
	The reason for having two functions that do the same thing with different
 types of parameters is to allow for more flexibility in how the function is
 called. By taking a pointer, the first function allows for a NULL (nullptr)
 argument, while the second function requires a valid reference to be passed in.
 	Additionally, taking a reference can make the function more efficient in
 some cases, since it avoids the overhead of dereferencing a pointer.
*/
#include "Base.h"

int main() {
	Base* unknown[10];
	for (int i = 0; i < 10; ++i) {
		unknown[i] = Base::generate();
		Base::identify(unknown[i]);
		Base::identify(*(unknown[i]));
		unknown[i]->reveal();
		delete unknown[i];
	}
}
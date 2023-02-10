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
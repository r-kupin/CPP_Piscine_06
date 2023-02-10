/******************************************************************************/
/*                                                                            */
/*                                                         :::      ::::::::  */
/*    A.h                                                :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*    By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*    Created: 2023/02/10 12:01:30 by rokupin           #+#    #+#            */
/*                                                     ###   ########.fr      */
/*                                                                            */
/******************************************************************************/

#ifndef EX02_A_H
#define EX02_A_H


#include <string>
#include <ostream>
#include "Base.h"

class A : public Base {
public:
	A();
	A(const A &);
	A &operator=(const A &);

	~A();

	void reveal(); /* override */
};

#endif //EX02_A_H

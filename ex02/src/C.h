/******************************************************************************/
/*                                                                            */
/*                                                         :::      ::::::::  */
/*    C.h                                                :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*    By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*    Created: 2023/02/10 12:01:55 by rokupin           #+#    #+#            */
/*                                                     ###   ########.fr      */
/*                                                                            */
/******************************************************************************/

#ifndef EX02_C_H
#define EX02_C_H


#include <string>
#include <ostream>
#include "Base.h"

class C  : public Base {
public:
	C();
	C(const C &);
	C &operator=(const C &);

	~C();

	void reveal(); /* override */
};

#endif //EX02_C_H

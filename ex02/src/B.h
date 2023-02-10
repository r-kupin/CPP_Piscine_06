/******************************************************************************/
/*                                                                            */
/*                                                         :::      ::::::::  */
/*    B.h                                                :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*    By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*    Created: 2023/02/10 12:01:43 by rokupin           #+#    #+#            */
/*                                                     ###   ########.fr      */
/*                                                                            */
/******************************************************************************/

#ifndef EX02_B_H
#define EX02_B_H


#include <string>
#include <ostream>
#include "Base.h"

class B : public Base {
public:
	B();
	B(const B &);
	B &operator=(const B &);

	~B();

	void reveal(); /* override */
};

#endif //EX02_B_H

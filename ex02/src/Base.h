/******************************************************************************/
/*                                                                            */
/*                                                         :::      ::::::::  */
/*    Base.h                                             :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*    By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*    Created: 2023/02/10 11:59:53 by rokupin           #+#    #+#            */
/*                                                     ###   ########.fr      */
/*                                                                            */
/******************************************************************************/

#ifndef EX02_BASE_H
#define EX02_BASE_H

template <typename T>
void writeMessage(T& messServer){    // (1)

	messServer.writeMessage();

}

class Base {
public:
	virtual ~Base() {};

	virtual void reveal() = 0;

	static Base* generate(void);
	static void identify(Base* p);
	static void identify(Base& p);
};


#endif //EX02_BASE_H

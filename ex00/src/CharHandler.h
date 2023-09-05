/******************************************************************************/
/*                                                                            */
/*                                                         :::      ::::::::  */
/*    CharHandler.h                                      :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*    By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*    Created: 2023/02/05 14:50:52 by rokupin           #+#    #+#            */
/*                                                     ###   ########.fr      */
/*                                                                            */
/******************************************************************************/

#ifndef EX00_CHARHANDLER_H
#define EX00_CHARHANDLER_H

#include <string>

//	simple stateless "static class" that has a pure public function
struct CharHandler {
	static std::string GetCharRep(const std::string &value);
};


#endif //EX00_CHARHANDLER_H

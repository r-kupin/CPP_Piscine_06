/******************************************************************************/
/*                                                                            */
/*                                                         :::      ::::::::  */
/*    NumberHandler.h                                       :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*    By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*    Created: 2023/02/06 11:48:23 by rokupin           #+#    #+#            */
/*                                                     ###   ########.fr      */
/*                                                                            */
/******************************************************************************/

#ifndef EX00_LIB_NUMBERHANDLER_H
#define EX00_LIB_NUMBERHANDLER_H

#include <string>

struct NumberHandler {
	static std::string GetIntRep(const std::string &value);
	static std::string GetFloatRep(const std::string &value);
	static std::string GetDoubleRep(const std::string &value);
};


#endif //EX00_LIB_NUMBERHANDLER_H

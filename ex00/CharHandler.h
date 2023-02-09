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

#ifndef EX00_LIB_CHARHANDLER_H
#define EX00_LIB_CHARHANDLER_H

#include <string>

class CharHandler {
public:
	static std::string GetCharRep(const std::string &value);
};


#endif //EX00_LIB_CHARHANDLER_H

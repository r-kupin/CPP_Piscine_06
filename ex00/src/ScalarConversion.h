/******************************************************************************/
/*                                                                            */
/*                                                         :::      ::::::::  */
/*    ScalarConversion.h                                 :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*    By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*    Created: 2023/02/04 16:12:20 by rokupin           #+#    #+#            */
/*                                                     ###   ########.fr      */
/*                                                                            */
/******************************************************************************/

#ifndef EX00_SCALARCONVERSION_H
#define EX00_SCALARCONVERSION_H


#include <string>
#include <ostream>
#include "NumberHandler.h"

static const std::string kNAN = "nan";
static const std::string kInf = "inf";
static const std::string kNANF = "nanf";
static const std::string kInfF = "inff";

static const std::string kImpossible = "impossible";
static const std::string kNonDisplayable = "Non displayable";

class ScalarConversion {
public:
	class WrongInputException : public std::exception {
	public:
		const char *what() const throw() ; /* override */
	};

    static std::string convert(const std::string &val);
private:
    ScalarConversion();
};

#endif //EX00_SCALARCONVERSION_H

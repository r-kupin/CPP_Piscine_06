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

	ScalarConversion();
	ScalarConversion(const ScalarConversion &);
//	all logic here
	explicit ScalarConversion(const std::string &value);
	ScalarConversion &operator=(const ScalarConversion &);

	~ScalarConversion() {};

	const std::string &GetRepresentation() const;
private:
//	Handler instances. Kind of redudnant, cause handling methods can be
//	static - but I	had	to create an example of static_cast usage somehow
	IntHandler int_handler_;
	FloatHandler float_handler_;
	DoubleHandler double_handler_;

	std::string value_;
	std::string representation_;
};

std::ostream &operator<<(std::ostream &os, const ScalarConversion &c);


#endif //EX00_SCALARCONVERSION_H

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

static const std::string kNAN = "nan";
static const std::string kInf = "inf";
static const std::string kNANF = "nanf";
static const std::string kInfF = "inff";

class ScalarConversion {
public:
	class WrongInputException : public std::exception {
	public:
		const char *what() const throw() ; /* override */
	};

	ScalarConversion();
	ScalarConversion(const ScalarConversion &);
	explicit ScalarConversion(const std::string &value);
	ScalarConversion &operator=(const ScalarConversion &);

	~ScalarConversion() {};

	const std::string &GetRawValue() const;
private:
	std::string value_;
};

std::ostream &operator<<(std::ostream &os, const ScalarConversion &c);


#endif //EX00_SCALARCONVERSION_H

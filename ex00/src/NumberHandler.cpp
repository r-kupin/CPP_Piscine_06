/******************************************************************************/
/*                                                                            */
/*                                                         :::      ::::::::  */
/*    NumberHandler.cpp                                     :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*    By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*    Created: 2023/02/06 11:48:23 by rokupin           #+#    #+#            */
/*                                                     ###   ########.fr      */
/*                                                                            */
/******************************************************************************/

#include <cstdlib>
#include <sstream>
#include <limits>
#include "NumberHandler.h"
#include "ScalarConversion.h"

static const std::string kImpossible = "impossible";

std::string char_input(const std::string &value) {
	if (value.length() == 1 &&
			value.find_first_not_of("0123456789") != std::string::npos) {
		std::ostringstream s;
		s << static_cast<int>(value[0]);
		return s.str();
	}
	return value;
}

std::string NumberHandler::GetIntRep(const std::string &value) {
	std::string checked_value = char_input(value);
	if (checked_value.find_first_not_of(".0123456789+-f") != std::string::npos)
		return kImpossible;	/* impossible if anything non pseudo-numerical */
	else {
		double number = std::strtod(checked_value.c_str(), NULL);
		if (number > std::numeric_limits<int>::max() ||
				number < std::numeric_limits<int>::min())
			return kImpossible;
		std::ostringstream s;
		s << static_cast<int>(number);
		return s.str();
	}
}

std::string NumberHandler::GetFloatRep(const std::string &value) {
	std::string checked_value = char_input(value);
	if (checked_value == kNAN || checked_value == kNANF)
		return kNANF;
	if (checked_value == kInf || checked_value == kInfF)
		return kInfF;
	if (checked_value.find_first_not_of(".0123456789+-f") != std::string::npos)
		return kImpossible;	/* impossible if anything non pseudo-numerical */
	else {
		double number = std::strtod(checked_value.c_str(), NULL);
		std::ostringstream s;
		s << static_cast<float>(number);
		if (std::abs(number - static_cast<long>(number)) < 0.000001)
			return s.str() + ".0f";
		return s.str() + "f";
	}
}

std::string NumberHandler::GetDoubleRep(const std::string &value) {
	std::string checked_value = char_input(value);
	if (checked_value == kNAN || checked_value == kNANF)
		return kNAN;
	if (checked_value == kInf || checked_value == kInfF)
		return kInf;
	if (checked_value.find_first_not_of(".0123456789+-f") != std::string::npos)
		return kImpossible;	/* impossible if anything non pseudo-numerical */
	else {
		double number = std::strtod(checked_value.c_str(), NULL);
		std::ostringstream s;
		s << number;
		if (std::abs(number - static_cast<long>(number)) < 0.000001)
			return s.str() + ".0";
		return s.str();
	}
}

/******************************************************************************/
/*                                                                            */
/*                                                         :::      ::::::::  */
/*    NumberHandler.cpp                                  :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*    By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*    Created: 2023/02/06 11:48:23 by rokupin           #+#    #+#            */
/*                                                     ###   ########.fr      */
/*                                                                            */
/******************************************************************************/

#include <cstdlib>
#include <limits>
#include "NumberHandler.h"
#include "ScalarConversion.h"

DoubleHandler::DoubleHandler(const std::string &value) : NumberHandler(value) {}

IntHandler::IntHandler(const std::string &value) : NumberHandler(value) {}

FloatHandler::FloatHandler(const std::string &value) : NumberHandler(value) {}

std::string IntHandler::GetRep(const std::string &value) {
	if (value.find_first_not_of(".0123456789+-f") != std::string::npos)
		return kImpossible;	/* impossible if anything non pseudo-numerical */
	else {
		double number = std::strtod(value.c_str(), NULL);
		if (number > std::numeric_limits<int>::max() ||
			number < std::numeric_limits<int>::min())
			return kImpossible;
		std::ostringstream s;
		s << static_cast<int>(number);
		return s.str();
	}
}

std::string FloatHandler::GetRep(const std::string &value) {
	if (value == kNAN || value == kNANF)
		return kNANF;
	if (value == kInf || value == kInfF)
		return kInfF;
	if (value.find_first_not_of(".0123456789+-f") != std::string::npos)
		return kImpossible;	/* impossible if anything non pseudo-numerical */
	else {
		double number = std::strtod(value.c_str(), NULL);
		std::ostringstream s;
		s << static_cast<float>(number);
		if (std::abs(number - static_cast<long>(number)) < 0.000001)
			return s.str() + ".0f";
		return s.str() + "f";
	}
}

std::string DoubleHandler::GetRep(const std::string &value) {
	if (value == kNAN || value == kNANF)
		return kNAN;
	if (value == kInf || value == kInfF)
		return kInf;
	if (value.find_first_not_of(".0123456789+-f") != std::string::npos)
		return kImpossible;	/* impossible if anything non pseudo-numerical */
	else {
		double number = std::strtod(value.c_str(), NULL);
		std::ostringstream s;
		s << number;
		if (std::abs(number - static_cast<long>(number)) < 0.000001)
			return s.str() + ".0";
		return s.str();
	}
}


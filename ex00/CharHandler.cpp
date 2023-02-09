/******************************************************************************/
/*                                                                            */
/*                                                         :::      ::::::::  */
/*    CharHandler.cpp                                    :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*    By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*    Created: 2023/02/05 14:50:52 by rokupin           #+#    #+#            */
/*                                                     ###   ########.fr      */
/*                                                                            */
/******************************************************************************/

#include <cstdlib>
#include <sstream>
#include "CharHandler.h"
#include "ScalarConversion.h"

static const std::string kImpossible = "impossible";
static const std::string kNonDisplayable = "Non displayable";

std::string skip_plus(std::string val) {
	if (val[0] == '+') {
		return val.substr(1);
	} else {
		return val;
	}
}

bool handle_fractional(std::string &ch_value) {
	if (ch_value.find('f') == std::string::npos) {			/* it is float */
		float number = strtof(ch_value.c_str(), NULL);
		if ((number - static_cast<int>(number)) < 0.000001) {/* explicit cast */
			std::ostringstream s;	/* if fractional part isn't significant */
			s << static_cast<int>(number);						/* explicit */
			ch_value = s.str();			/* we can turn it to a whole number */
			return true;				/* and probably display it as a chr */
		}
	} else {												/* it is double */
		double number = strtod(ch_value.c_str(), NULL);
		if ((number - static_cast<int>(number)) < 0.000001) {	/* explicit */
			std::ostringstream s;
			s << static_cast<int>(number);						/* explicit */
			ch_value = s.str();
			return true;
		}
	}
	return false;
}

std::string CharHandler::GetCharRep(const std::string &value) {
	char final_value;

	if(value.length() == 1 &&
		value.find_first_not_of("0123456789") != std::string::npos) {
		return "'" + value + "'";
	} else if (value == "-0" || value == "-0.0" || value == "-0.0f") {
		return kNonDisplayable;
	} else if (value[0] == '-') {
		return kImpossible;
	}

	std::string ch_value = skip_plus(value);
	if (ch_value == kInf || ch_value == kInfF)
		return kImpossible;

	if (ch_value.find_first_not_of(".0123456789f") == std::string::npos &&
			!handle_fractional(ch_value))
		return kImpossible;

	if (ch_value.find_first_not_of("0123456789") == std::string::npos ) {
		int number = std::atoi(ch_value.c_str());
		if (number >= ' ' && number <= '~') {
			final_value = static_cast<char>(number);	/* explicit conversion */
			return "'" + std::string(1, final_value) + "'";			/* input is number */
		}
		if (number < ' ' || number == 127)
			return kNonDisplayable;
	}
	return kImpossible;
}

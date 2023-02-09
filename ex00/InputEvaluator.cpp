/******************************************************************************/
/*                                                                            */
/*                                                         :::      ::::::::  */
/*    InputEvaluator.cpp                                 :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*    By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*    Created: 2023/02/06 10:27:58 by rokupin           #+#    #+#            */
/*                                                     ###   ########.fr      */
/*                                                                            */
/******************************************************************************/

#include "InputEvaluator.h"
#include "ScalarConversion.h"

bool HasOnlyNumbers(const std::string& str) {
	if (str.find_first_not_of("0123456789") == std::string::npos)
		return true;						/* valid if only digits */
	if (str.find_first_not_of(".0123456789f") != std::string::npos)
		return false;						/* wrong if not only digits,dot,f */
	int count_dots = 0;
	int count_fs = 0;
	for (size_t i = 0; i < str.length(); ++i) {
		if (str[i] == '.') {				/* if encounter a '.' */
			++count_dots;
			if (i == 0 ||					/* Dot can't be first */
				i == (str.length() - 1) ||	/* Dot can't be last */
				count_dots > 1)				/* No multiple Dots */
				return false;
		}
		if (str[i] == 'f') {				/* if encounter a f */
			++count_fs;
			if (i != (str.length() - 1) ||	/* f should be last */
				count_fs > 1 ||				/* No Multiple f's */
				count_dots == 0 ||			/* There can't be f without a dot */
				!isdigit(str[i - 1]))		/* before the f must be digit */
				return false;
		}
	}
	return true;
}

bool InputEvaluator::input_is_correct(std::string input) {
	if (input == "inf" || input == "inff")	/* inf and inff can't be unsigned */
		return false;
	if (input[0] == '+' || input[0] == '-') {
		std::string substr = input.substr(1);
		if (HasOnlyNumbers(substr) ||
			substr == kInf ||
			substr == kInfF ||
			substr.empty()) {
			return true;
		}
		return false;
	}
	if (HasOnlyNumbers(input) ||
		input.length() == 1 ||
		input == kInf ||
		input == kInfF ||
		input == kNAN ||
		input == kNANF) {
		return true;
	}
	return false;
}

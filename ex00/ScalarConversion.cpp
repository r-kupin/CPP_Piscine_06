/******************************************************************************/
/*                                                                            */
/*                                                         :::      ::::::::  */
/*    ScalarConversion.cpp                               :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*    By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*    Created: 2023/02/04 16:12:20 by rokupin           #+#    #+#            */
/*                                                     ###   ########.fr      */
/*                                                                            */
/******************************************************************************/

#include "ScalarConversion.h"
#include "CharHandler.h"
#include "InputEvaluator.h"
#include "NumberHandler.h"

ScalarConversion::ScalarConversion() : value_("") {}

ScalarConversion::ScalarConversion(const ScalarConversion &other)
: value_(other.value_) {}

ScalarConversion::ScalarConversion(const std::string &value)
: value_(value) {
	if (value.empty() || !InputEvaluator::input_is_correct(value))
		throw WrongInputException();
}

ScalarConversion &ScalarConversion::operator=(const ScalarConversion &other) {
	if (this == &other)
		return *this;
	value_ = other.value_;
	return *this;
}

const std::string &ScalarConversion::GetRawValue() const {
	return value_;
}

std::ostream &operator<<(std::ostream &os, const ScalarConversion &c) {
	os << "Given string: " << c.GetRawValue() << std::endl;
	os << "As char: " <<
			CharHandler::GetCharRep(c.GetRawValue()) << std::endl;
	os << "As int: " <<
			NumberHandler::GetIntRep(c.GetRawValue()) << std::endl;
	os << "As float: " <<
			NumberHandler::GetFloatRep(c.GetRawValue()) << std::endl;
	os << "As double: " <<
			NumberHandler::GetDoubleRep(c.GetRawValue());
	return os;
}

const char *ScalarConversion::WrongInputException::what() const throw() {
	return "Wrong Input!";
}

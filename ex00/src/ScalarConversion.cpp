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

ScalarConversion::ScalarConversion()
: int_handler_(""), float_handler_(""), double_handler_("") {}

ScalarConversion::ScalarConversion(const ScalarConversion &other)
: int_handler_(other.int_handler_), float_handler_(other.float_handler_),
  double_handler_(other.double_handler_), value_(other.value_) {}

ScalarConversion::ScalarConversion(const std::string &value)
: int_handler_(value), float_handler_(value),
	double_handler_(value), value_(value) {
//	check for the wrong input that we shouldn't even try to cast
	if (value.empty() || !InputEvaluator::input_is_correct(value))
		throw WrongInputException();
	else {
		representation_ = "Given string: " + value_ + "\n" +
/* Just static method */  "char: " + CharHandler::GetCharRep(value_) + "\n" +
/* CRTP for numbers */    "int: " + int_handler_.Handle() + "\n" +
						  "float: " + float_handler_.Handle() + "\n" +
						  "double: " + double_handler_.Handle();
	}
}

ScalarConversion &ScalarConversion::operator=(const ScalarConversion &other) {
	if (this == &other)
		return *this;
	value_ = other.value_;
	return *this;
}

const std::string &ScalarConversion::GetRepresentation() const {
	return representation_;
}

std::ostream &operator<<(std::ostream &os, const ScalarConversion &c) {
	os << c.GetRepresentation();
	return os;
}

const char *ScalarConversion::WrongInputException::what() const throw() {
	return "Wrong Input!";
}

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

ScalarConversion::ScalarConversion() {}

std::string ScalarConversion::convert(const std::string &value) {
//	check for the wrong input that we shouldn't even try to cast
    if (value.empty() || !InputEvaluator::input_is_correct(value))
        throw WrongInputException();
    else {
        std::string representation;

        IntHandler i_handler(value);
        FloatHandler f_handler(value);
        DoubleHandler d_handler(value);
        representation = "Given string: " + value + "\n" +
        "char: " + CharHandler::GetCharRep(value) + "\n" +  /* Just static method */
        "int: " + i_handler.Handle() + "\n" +               /* CRTP for numbers */
        "float: " + f_handler.Handle() + "\n" +
        "double: " + d_handler.Handle();
        return representation;
    }
}

const char *ScalarConversion::WrongInputException::what() const throw() {
	return "Wrong Input!";
}

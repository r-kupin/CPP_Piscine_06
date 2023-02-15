/******************************************************************************/
/*                                                                            */
/*                                                         :::      ::::::::  */
/*    NumberHandler.h                                    :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*    By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*    Created: 2023/02/06 11:48:23 by rokupin           #+#    #+#            */
/*                                                     ###   ########.fr      */
/*                                                                            */
/******************************************************************************/
/*
		Description

 	So, here is the thing.
 	There is a Base class NumberHandler, and 3 Derived classes representing
 	each particular number.
 	Before each method will try to convert the input to the corresponding
 	type - we have to perform a check, that our input isn't a single
 	non-digit printable char - in this case we have to process its ascii number.

 	When such check gets performed - we can represent actually a converted
 	value using implementations from derived classes. But to get this
 	implementation we need a reference or pointer of a derived class. And as
 	far as Base class knows nothing about its derivatives - the only way to
 	access their methods is a self-down-cast.

 	It might seem unsafe - but actually - it is nothing wrong here, as far as
 	all derived classes share same interface that we will use in a base class.
 	The only cast that can perform such operation is a static_cast.

 	Here's what happening:
 	1. We simply create the instance of a derived class, like this:
 	 		IntHandler int_handler_(input);
	2. As far as IntHandler is derived - his base class gets created first.
 	Base class has a template parameter, and to get the job done we should
 	pass a derived class there, like that:
 			IntHandler : NumberHandler<IntHandler>
	3. This way we let the base class know: " You'll cast yourself to this
 	class" - because this particular NumberHandler is a part of IntHandler
 	and therefore can be safely downcast-ed, and methods from derived class
 	can be accessed:

		template<typename CRTP>
		struct NumberHandler {
			std::string Handle() const {
				CRTP handler = static_cast<const CRTP&>(*this);
				...
				return handler.GetRep(s.str());
				}
		}
	4. To finally get the IntHandler's representation ot the input string,
 	after instantiation we should call base-class method Handle, which will
 	call IntHandler's GetRep() with some required operations done before and
 	after the call:
 		int_handler_.Handle();

 	And as far as all NumberHandler's derivations share same interface - they
 	can be called interchangeably:
 		float_handler_.Handle();
		double_handler_.Handle();
*/
#ifndef EX00_LIB_NUMBERHANDLER_H
#define EX00_LIB_NUMBERHANDLER_H

#include <string>
#include <sstream>

template<typename CRTP>
struct NumberHandler {
	std::string Handle() const {
		CRTP handler = static_cast<const CRTP&>(*this);

		std::string un_charred;
		if (value_.length() == 1 &&
			value_.find_first_not_of("0123456789") != std::string::npos) {
			std::ostringstream s;
			s << static_cast<int>(value_[0]);
			return handler.GetRep(s.str());
		}
		return handler.GetRep(value_);
	}
protected:
	explicit NumberHandler(const std::string &value) : value_(value) {};
	std::string value_;
};

struct IntHandler : NumberHandler<IntHandler> {
	explicit IntHandler(const std::string &value);

	std::string GetRep(const std::string &value);
};

struct FloatHandler : NumberHandler<FloatHandler> {
	explicit FloatHandler(const std::string &value);

	std::string GetRep(const std::string &value);
};

struct DoubleHandler : NumberHandler<DoubleHandler> {
	explicit DoubleHandler(const std::string &value);

	std::string GetRep(const std::string &value);
};



#endif //EX00_LIB_NUMBERHANDLER_H

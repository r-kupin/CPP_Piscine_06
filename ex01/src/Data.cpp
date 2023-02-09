/******************************************************************************/
/*                                                                            */
/*                                                         :::      ::::::::  */
/*    Data.cpp                                     :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*    By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*    Created: 2023/02/09 20:27:42 by rokupin           #+#    #+#            */
/*                                                     ###   ########.fr      */
/*                                                                            */
/******************************************************************************/

#include "Data.h"

Data::Data()
: some_int_data_(123), some_string_data_("some_string_data") {}

Data::Data(const Data &other)
: some_int_data_(other.some_int_data_),
	some_string_data_(other.some_string_data_) {}

Data &Data::operator=(const Data &other) {
	if (this == &other)
		return *this;
	some_string_data_ = other.some_string_data_;
	some_int_data_ = other.some_int_data_;
	return *this;
}

Data::Data(int some_int_data, const std::string &some_string_data)
: some_int_data_(some_int_data),
	some_string_data_(some_string_data) {}

Data::~Data() {}

int Data::GetSomeIntData() const {
	return some_int_data_;
}

void Data::SetSomeIntData(int some_int_data) {
	some_int_data_ = some_int_data;
}

const std::string &Data::GetSomeStringData() const {
	return some_string_data_;
}

void Data::SetSomeStringData(const std::string &some_string_data) {
	some_string_data_ = some_string_data;
}

uintptr_t Data::serialize(Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Data::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}

std::ostream &operator<<(std::ostream &os, const Data &data) {
	os << "some_int_data_: " << data.GetSomeIntData()
	<< " some_string_data_: " << data.GetSomeStringData();
	return os;
}

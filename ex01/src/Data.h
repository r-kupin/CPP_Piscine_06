/******************************************************************************/
/*                                                                            */
/*                                                         :::      ::::::::  */
/*    Data.h                                       :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*    By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*    Created: 2023/02/09 20:27:42 by rokupin           #+#    #+#            */
/*                                                     ###   ########.fr      */
/*                                                                            */
/******************************************************************************/

#ifndef EX01_SERIALIZER_H
#define EX01_SERIALIZER_H


#include <stdint.h>
#include <string>
#include <ostream>

class Data {
public:
	Data();
	Data(const Data &);
	Data &operator=(const Data &);
	Data(int some_int_data, const std::string &some_string_data);
	~Data();

	int GetSomeIntData() const;
	void SetSomeIntData(int some_int_data);
	const std::string &GetSomeStringData() const;
	void SetSomeStringData(const std::string &some_string_data);

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
private:
	int some_int_data_;
	std::string some_string_data_;
};

std::ostream &operator<<(std::ostream &os, const Data &data);

#endif //EX01_SERIALIZER_H

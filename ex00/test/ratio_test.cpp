/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ratio_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 23:32:02 by  rokupin          #+#    #+#             */
/*   Updated: 2023/10/12 12:22:02 by rokupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtest/gtest.h"
#include "../src/NumberHandler.h"

TEST(FloatOutputTest_Normal, nan) {
	FloatHandler handler("nanf");
	EXPECT_EQ(handler.Handle(), "nanf");
}

TEST(FloatOutputTest_Normal, nanf) {
	FloatHandler handler("nanf");
	EXPECT_EQ(handler.Handle(), "nanf");
}

TEST(FloatOutputTest_Normal, SimpleNumberNoFraction) {
	FloatHandler handler("42.0f");
	EXPECT_EQ(handler.Handle(), "42.0f");
}

TEST(FloatOutputTest_Normal, DoubleWithFraction) {
	FloatHandler handler("42.1f");
	EXPECT_EQ(handler.Handle(), "42.1f");
}

TEST(FloatOutputTest_Normal, FloatWithFraction) {
	FloatHandler handler("42.1f");
	EXPECT_EQ(handler.Handle(), "42.1f");
}

TEST(FloatOutputTest_Normal, PlusSimpleNumberNoFraction) {
	FloatHandler handler("42.0f");
	EXPECT_EQ(handler.Handle(), "42.0f");
}

TEST(FloatOutputTest_Normal, PlusDoubleWithFraction) {
	FloatHandler handler("42.1f");
	EXPECT_EQ(handler.Handle(), "42.1f");
}

TEST(FloatOutputTest_Normal, PlusFloatWithFraction) {
	FloatHandler handler("42.1f");
	EXPECT_EQ(handler.Handle(), "42.1f");
}

TEST(FloatOutputTest_Normal, MinusSimpleNumberNoFraction) {
	FloatHandler handler("-42.0f");
	EXPECT_EQ(handler.Handle(), "-42.0f");
}

TEST(FloatOutputTest_Normal, MinusDoubleWithFraction) {
	FloatHandler handler("-42.1f");
	EXPECT_EQ(handler.Handle(), "-42.1f");
}

TEST(FloatOutputTest_Normal, MinusFloatWithFraction) {
	FloatHandler handler("-42.1f");
	EXPECT_EQ(handler.Handle(), "-42.1f");
}

TEST(DoubleOutputTest_Normal, nan) {
	DoubleHandler handler("nan");
	EXPECT_EQ(handler.Handle(), "nan");
}

TEST(DoubleOutputTest_Normal, nanf) {
	DoubleHandler handler("nan");
	EXPECT_EQ(handler.Handle(), "nan");
}

TEST(DoubleOutputTest_Normal, SimpleNumberNoFraction) {
	DoubleHandler handler("42.0");
	EXPECT_EQ(handler.Handle(), "42.0");
}

TEST(DoubleOutputTest_Normal, DoubleWithFraction) {
	DoubleHandler handler("42.1");
	EXPECT_EQ(handler.Handle(), "42.1");
}

TEST(DoubleOutputTest_Normal, DoubleFromFloatWithFraction) {
	DoubleHandler handler("42.1");
	EXPECT_EQ(handler.Handle(), "42.1");
}

TEST(DoubleOutputTest_Normal, PlusSimpleNumberNoFraction) {
	DoubleHandler handler("42.0");
	EXPECT_EQ(handler.Handle(), "42.0");
}

TEST(DoubleOutputTest_Normal, PlusDoubleWithFraction) {
	DoubleHandler handler("42.1");
	EXPECT_EQ(handler.Handle(), "42.1");
}

TEST(DoubleOutputTest_Normal, PlusDoubleFromFloatWithFraction) {
	DoubleHandler handler("42.1");
	EXPECT_EQ(handler.Handle(), "42.1");
}

TEST(DoubleOutputTest_Normal, MinusSimpleNumberNoFraction) {
	DoubleHandler handler("-42.0");
	EXPECT_EQ(handler.Handle(), "-42.0");
}

TEST(DoubleOutputTest_Normal, MinusDoubleWithFraction) {
	DoubleHandler handler("-42.1");
	EXPECT_EQ(handler.Handle(), "-42.1");
}

TEST(DoubleOutputTest_Normal, MinusDoubleFromFloatWithFraction) {
	DoubleHandler handler("-42.1");
	EXPECT_EQ(handler.Handle(), "-42.1");
}

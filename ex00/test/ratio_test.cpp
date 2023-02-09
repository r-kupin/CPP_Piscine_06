/******************************************************************************/
/*                                                                            */
/*                                                         :::      ::::::::  */
/*    ratio_test.cpp                                     :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*    By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*    Created: 2023/02/08 23:32:21 by rokupin           #+#    #+#            */
/*                                                     ###   ########.fr      */
/*                                                                            */
/******************************************************************************/

#include "gtest/gtest.h"
#include "../src/NumberHandler.h"

TEST(FloatOutputTest_Normal, nan) {
	EXPECT_EQ(NumberHandler::GetFloatRep("nan"), "nanf");
}

TEST(FloatOutputTest_Normal, nanf) {
	EXPECT_EQ(NumberHandler::GetFloatRep("nanf"), "nanf");
}

TEST(FloatOutputTest_Normal, SimpleNumberNoFraction) {
	EXPECT_EQ(NumberHandler::GetFloatRep("42"), "42.0f");
}

TEST(FloatOutputTest_Normal, DoubleWithFraction) {
	EXPECT_EQ(NumberHandler::GetFloatRep("42.1"), "42.1f");
}

TEST(FloatOutputTest_Normal, FloatWithFraction) {
	EXPECT_EQ(NumberHandler::GetFloatRep("42.1f"), "42.1f");
}

TEST(FloatOutputTest_Normal, PlusSimpleNumberNoFraction) {
	EXPECT_EQ(NumberHandler::GetFloatRep("+42"), "42.0f");
}

TEST(FloatOutputTest_Normal, PlusDoubleWithFraction) {
	EXPECT_EQ(NumberHandler::GetFloatRep("+42.1"), "42.1f");
}

TEST(FloatOutputTest_Normal, PlusFloatWithFraction) {
	EXPECT_EQ(NumberHandler::GetFloatRep("+42.1f"), "42.1f");
}

TEST(FloatOutputTest_Normal, MinusSimpleNumberNoFraction) {
	EXPECT_EQ(NumberHandler::GetFloatRep("-42"), "-42.0f");
}

TEST(FloatOutputTest_Normal, MinusDoubleWithFraction) {
	EXPECT_EQ(NumberHandler::GetFloatRep("-42.1"), "-42.1f");
}

TEST(FloatOutputTest_Normal, MinusFloatWithFraction) {
	EXPECT_EQ(NumberHandler::GetFloatRep("-42.1f"), "-42.1f");
}

TEST(DoubleOutputTest_Normal, nan) {
	EXPECT_EQ(NumberHandler::GetDoubleRep("nan"), "nan");
}

TEST(DoubleOutputTest_Normal, nanf) {
	EXPECT_EQ(NumberHandler::GetDoubleRep("nanf"), "nan");
}

TEST(DoubleOutputTest_Normal, SimpleNumberNoFraction) {
	EXPECT_EQ(NumberHandler::GetDoubleRep("42"), "42.0");
}

TEST(DoubleOutputTest_Normal, DoubleWithFraction) {
	EXPECT_EQ(NumberHandler::GetDoubleRep("42.1"), "42.1");
}

TEST(DoubleOutputTest_Normal, DoubleFromFloatWithFraction) {
	EXPECT_EQ(NumberHandler::GetDoubleRep("42.1f"), "42.1");
}

TEST(DoubleOutputTest_Normal, PlusSimpleNumberNoFraction) {
	EXPECT_EQ(NumberHandler::GetDoubleRep("+42"), "42.0");
}

TEST(DoubleOutputTest_Normal, PlusDoubleWithFraction) {
	EXPECT_EQ(NumberHandler::GetDoubleRep("+42.1"), "42.1");
}

TEST(DoubleOutputTest_Normal, PlusDoubleFromFloatWithFraction) {
	EXPECT_EQ(NumberHandler::GetDoubleRep("+42.1f"), "42.1");
}

TEST(DoubleOutputTest_Normal, MinusSimpleNumberNoFraction) {
	EXPECT_EQ(NumberHandler::GetDoubleRep("-42"), "-42.0");
}

TEST(DoubleOutputTest_Normal, MinusDoubleWithFraction) {
	EXPECT_EQ(NumberHandler::GetDoubleRep("-42.1"), "-42.1");
}

TEST(DoubleOutputTest_Normal, MinusDoubleFromFloatWithFraction) {
	EXPECT_EQ(NumberHandler::GetDoubleRep("-42.1f"), "-42.1");
}

/******************************************************************************/
/*                                                                            */
/*                                                         :::      ::::::::  */
/*    int_test.cpp                                       :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*    By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*    Created: 2023/02/07 23:38:38 by rokupin           #+#    #+#            */
/*                                                     ###   ########.fr      */
/*                                                                            */
/******************************************************************************/

#include "gtest/gtest.h"
#include "../src/NumberHandler.h"

TEST(IntOutputTest_Impossible, Positive_overflow) {
	EXPECT_EQ(NumberHandler::GetIntRep("99999999999"), "impossible");
}

TEST(IntOutputTest_Impossible, Negative_overflow) {
	EXPECT_EQ(NumberHandler::GetIntRep("-99999999999"), "impossible");
}

TEST(IntOutputTest_Impossible, light_Positive_overflow) {
	EXPECT_EQ(NumberHandler::GetIntRep("2147483648"), "impossible");
}

TEST(IntOutputTest_Impossible, light_Negative_overflow) {
	EXPECT_EQ(NumberHandler::GetIntRep("-2147483649"), "impossible");
}

TEST(IntOutputTest_Impossible, Nan) {
	EXPECT_EQ(NumberHandler::GetIntRep("nan"), "impossible");
}

TEST(IntOutputTest_Impossible, NanF) {
	EXPECT_EQ(NumberHandler::GetIntRep("nanf"), "impossible");
}

TEST(IntOutputTest_Normal, Positive) {
	EXPECT_EQ(NumberHandler::GetIntRep("+10"), "10");
}

TEST(IntOutputTest_Normal, ImplicitlyPositive) {
	EXPECT_EQ(NumberHandler::GetIntRep("10"), "10");
}

TEST(IntOutputTest_Normal, Negative) {
	EXPECT_EQ(NumberHandler::GetIntRep("-10"), "-10");
}

TEST(IntOutputTest_Normal, DoubleInRange) {
	EXPECT_EQ(NumberHandler::GetIntRep("-10.0"), "-10");
}

TEST(IntOutputTest_Normal, FloatInRange) {
	EXPECT_EQ(NumberHandler::GetIntRep("-10.0f"), "-10");
}

TEST(IntOutputTest_Normal, DoubleInRangeWiyhFractionalPart) {
	EXPECT_EQ(NumberHandler::GetIntRep("-10.1234567"), "-10");
}

TEST(IntOutputTest_Normal,MaxDouble) {
	EXPECT_EQ(NumberHandler::GetIntRep("999999999999999.999999999"), "impossible");
}

TEST(IntOutputTest_Normal, MaxFloat) {
	EXPECT_EQ(NumberHandler::GetIntRep("999999999999999.99999999f"), "impossible");
}

TEST(IntOutputTest_Normal, Nan) {
	EXPECT_EQ(NumberHandler::GetIntRep("nan"), "impossible");
}

TEST(IntOutputTest_Normal, NanF) {
	EXPECT_EQ(NumberHandler::GetIntRep("nanf"), "impossible");
}

TEST(IntOutputTest_Normal, PosInf) {
	EXPECT_EQ(NumberHandler::GetIntRep("+inf"), "impossible");
}

TEST(IntOutputTest_Normal, NegInfF) {
	EXPECT_EQ(NumberHandler::GetIntRep("-inff"), "impossible");
}

TEST(IntOutputTest_Impossible, Positive_bound) {
	EXPECT_EQ(NumberHandler::GetIntRep("2147483647"), "2147483647");
}

TEST(IntOutputTest_Impossible, Negative_bound) {
	EXPECT_EQ(NumberHandler::GetIntRep("-2147483648"), "-2147483648");
}

TEST(IntOutputTest_Impossible, PlusOneChar) {
	EXPECT_EQ(NumberHandler::GetIntRep("+"), "43");
}

TEST(IntOutputTest_Impossible, SpaceOneChar) {
	EXPECT_EQ(NumberHandler::GetIntRep(" "), "32");
}
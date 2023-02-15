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
	IntHandler handler("impossible");
	EXPECT_EQ(handler.Handle(), "impossible");
}

TEST(IntOutputTest_Impossible, Negative_overflow) {
	IntHandler handler("impossible");
	EXPECT_EQ(handler.Handle(), "impossible");
}

TEST(IntOutputTest_Impossible, light_Positive_overflow) {
	IntHandler handler("impossible");
	EXPECT_EQ(handler.Handle(), "impossible");
}

TEST(IntOutputTest_Impossible, light_Negative_overflow) {
	IntHandler handler("impossible");
	EXPECT_EQ(handler.Handle(), "impossible");
}

TEST(IntOutputTest_Impossible, Nan) {
	IntHandler handler("impossible");
	EXPECT_EQ(handler.Handle(), "impossible");
}

TEST(IntOutputTest_Impossible, NanF) {
	IntHandler handler("impossible");
	EXPECT_EQ(handler.Handle(), "impossible");
}

TEST(IntOutputTest_Normal, Positive) {
	IntHandler handler("10");
	EXPECT_EQ(handler.Handle(), "10");
}

TEST(IntOutputTest_Normal, ImplicitlyPositive) {
	IntHandler handler("10");
	EXPECT_EQ(handler.Handle(), "10");
}

TEST(IntOutputTest_Normal, Negative) {
	IntHandler handler("-10");
	EXPECT_EQ(handler.Handle(), "-10");
}

TEST(IntOutputTest_Normal, DoubleInRange) {
	IntHandler handler("-10");
	EXPECT_EQ(handler.Handle(), "-10");
}

TEST(IntOutputTest_Normal, FloatInRange) {
	IntHandler handler("-10");
	EXPECT_EQ(handler.Handle(), "-10");
}

TEST(IntOutputTest_Normal, DoubleInRangeWiyhFractionalPart) {
	IntHandler handler("-10");
	EXPECT_EQ(handler.Handle(), "-10");
}

TEST(IntOutputTest_Normal,MaxDouble) {
	IntHandler handler("impossible");
	EXPECT_EQ(handler.Handle(), "impossible");
}

TEST(IntOutputTest_Normal, MaxFloat) {
	IntHandler handler("impossible");
	EXPECT_EQ(handler.Handle(), "impossible");
}

TEST(IntOutputTest_Normal, Nan) {
	IntHandler handler("impossible");
	EXPECT_EQ(handler.Handle(), "impossible");
}

TEST(IntOutputTest_Normal, NanF) {
	IntHandler handler("impossible");
	EXPECT_EQ(handler.Handle(), "impossible");
}

TEST(IntOutputTest_Normal, PosInf) {
	IntHandler handler("impossible");
	EXPECT_EQ(handler.Handle(), "impossible");
}

TEST(IntOutputTest_Normal, NegInfF) {
	IntHandler handler("impossible");
	EXPECT_EQ(handler.Handle(), "impossible");
}

TEST(IntOutputTest_Impossible, Positive_bound) {
	IntHandler handler("2147483647");
	EXPECT_EQ(handler.Handle(), "2147483647");
}

TEST(IntOutputTest_Impossible, Negative_bound) {
	IntHandler handler("-2147483648");
	EXPECT_EQ(handler.Handle(), "-2147483648");
}

TEST(IntOutputTest_Impossible, PlusOneChar) {
	IntHandler handler("43");
	EXPECT_EQ(handler.Handle(), "43");
}

TEST(IntOutputTest_Impossible, SpaceOneChar) {
	IntHandler handler("32");
	EXPECT_EQ(handler.Handle(), "32");
}
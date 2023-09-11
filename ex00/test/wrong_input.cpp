/******************************************************************************/
/*                                                                            */
/*                                                         :::      ::::::::  */
/*    wrong_input.cpp                                    :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*    By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*    Created: 2023/02/05 15:11:26 by rokupin           #+#    #+#            */
/*                                                     ###   ########.fr      */
/*                                                                            */
/******************************************************************************/

#include "gtest/gtest.h"
#include "../src/ScalarConversion.h"

// Wrong input

TEST(WrongInput, PlusNumberAndBullshit) {
	EXPECT_ANY_THROW(ScalarConversion::convert("+1a"));
}

TEST(WrongInput, UnsignedInfinity) {
	EXPECT_ANY_THROW(ScalarConversion::convert("inf"));
}

TEST(WrongInput, UnsignedInfinityF) {
	EXPECT_ANY_THROW(ScalarConversion::convert("inff"));
}

TEST(WrongInput, PlusAndBullshit) {
	EXPECT_ANY_THROW(ScalarConversion::convert("+a"));
}

TEST(WrongInput, ZeroAndBullshit) {
	EXPECT_ANY_THROW(ScalarConversion::convert("0a"));
}

TEST(WrongInput, BullshitAndZero) {
	EXPECT_ANY_THROW(ScalarConversion::convert("a0"));
}

TEST(WrongInput, PlusMinus) {
	EXPECT_ANY_THROW(ScalarConversion::convert("+-"));
}

TEST(WrongInput, MinusPlus) {
	EXPECT_ANY_THROW(ScalarConversion::convert("-+"));
}

TEST(WrongInput, PlusNumMinus) {
	EXPECT_ANY_THROW(ScalarConversion::convert("+1-"));
}

TEST(WrongInput, MinusNumPlus) {
	EXPECT_ANY_THROW(ScalarConversion::convert("-1+"));
}

TEST(WrongInput, DotInFront) {
	EXPECT_ANY_THROW(ScalarConversion::convert(".01"));
}

TEST(WrongInput, DotAtTheEnd) {
	EXPECT_ANY_THROW(ScalarConversion::convert("01."));
}

TEST(WrongInput, PlusDot) {
	EXPECT_ANY_THROW(ScalarConversion::convert("+."));
}

TEST(WrongInput, DotMinus) {
	EXPECT_ANY_THROW(ScalarConversion::convert(".-"));
}

TEST(WrongInput, DotDouble) {
	EXPECT_ANY_THROW(ScalarConversion::convert("1.23.4"));
}

TEST(WrongInput, NegInfff) {
	EXPECT_ANY_THROW(ScalarConversion::convert("-infff"));
}

TEST(WrongInput, Nanfff) {
	EXPECT_ANY_THROW(ScalarConversion::convert("nanfff"));
}

TEST(WrongInput, FractionalLittleTooBigNumberFF) {
	EXPECT_ANY_THROW(ScalarConversion::convert("+12.8ff"));
}

TEST(WrongInput, FractionalWayTooBigNumberFF) {
	EXPECT_ANY_THROW(ScalarConversion::convert("+1.234ff"));
}

TEST(WrongInput, FractionalLitleNegativeNumberFF) {
	EXPECT_ANY_THROW(ScalarConversion::convert("-0.1ff"));
}

TEST(WrongInput, FractionalBiggerNegativeNumberFF) {
	EXPECT_ANY_THROW(ScalarConversion::convert("-12.3ff"));
}

TEST(WrongInput, ZeroFF) {
	EXPECT_ANY_THROW(ScalarConversion::convert("0ff"));
}

TEST(WrongInput, ZeroPointZeroFF) {
	EXPECT_ANY_THROW(ScalarConversion::convert("0.0ff"));
}

TEST(WrongInput, PlusZeroFF) {
	EXPECT_ANY_THROW(ScalarConversion::convert("+0ff"));
}

TEST(WrongInput, MinusZeroFF) {
	EXPECT_ANY_THROW(ScalarConversion::convert("-0ff"));
}

TEST(WrongInput, PlusZeroPointZeroFF) {
	EXPECT_ANY_THROW(ScalarConversion::convert("+0.0ff"));
}

TEST(WrongInput, MinusZeroPointZeroFF) {
	EXPECT_ANY_THROW(ScalarConversion::convert("-0.0ff"));
}

TEST(WrongInput, PointZeroF) {
	EXPECT_ANY_THROW(ScalarConversion::convert("0.f"));
}

TEST(WrongInput, PointPlusZeroF) {
	EXPECT_ANY_THROW(ScalarConversion::convert("+0.f"));
}

TEST(WrongInput, PointMinusZeroF) {
	EXPECT_ANY_THROW(ScalarConversion::convert("-0.f"));
}

TEST(WrongInput, FFractionalLittleTooBigNumber) {
	EXPECT_ANY_THROW(ScalarConversion::convert("+f12.8"));
}

TEST(WrongInput, FFractionalWayTooBigNumber) {
	EXPECT_ANY_THROW(ScalarConversion::convert("+f1.234"));
}

TEST(WrongInput, FFractionalLitleNegativeNumber) {
	EXPECT_ANY_THROW(ScalarConversion::convert("-f0.1"));
}

TEST(WrongInput, FFractionalBiggerNegativeNumber) {
	EXPECT_ANY_THROW(ScalarConversion::convert("-f12.3"));
}

TEST(WrongInput, FPlusZero) {
	EXPECT_ANY_THROW(ScalarConversion::convert("+f0"));
}

TEST(WrongInput, FMinusZero) {
	EXPECT_ANY_THROW(ScalarConversion::convert("-f0"));
}

TEST(WrongInput, PlusFWitoutDot) {
	EXPECT_ANY_THROW(ScalarConversion::convert("+0f"));
}

TEST(WrongInput, FWitoutDot) {
	EXPECT_ANY_THROW(ScalarConversion::convert("0f"));
}

TEST(WrongInput, FPlusZeroPointZero) {
	EXPECT_ANY_THROW(ScalarConversion::convert("+f0.0"));
}

TEST(WrongInput, FMinusZeroPointZero) {
	EXPECT_ANY_THROW(ScalarConversion::convert("-f0.0"));
}

TEST(WrongInput, PositiveNan) {
	EXPECT_ANY_THROW(ScalarConversion::convert("+nan"));
}

/******************************************************************************/
/*                                                                            */
/*                                                         :::      ::::::::  */
/*    chat_test.cpp                                      :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*    By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*    Created: 2023/02/05 00:02:34 by rokupin           #+#    #+#            */
/*                                                     ###   ########.fr      */
/*                                                                            */
/******************************************************************************/

#include "gtest/gtest.h"
#include "../src/ScalarConversion.h"


TEST(CorrectInputTest_CorrectCharInput, OnlyPlus){
	EXPECT_NO_THROW(ScalarConversion var("+"));
}

TEST(CorrectInputTest_CorrectCharInput, PlusAndNumber) {
	EXPECT_NO_THROW(ScalarConversion var("+100"));
}

TEST(CorrectInputTest_CorrectCharInput, Number) {
	EXPECT_NO_THROW(ScalarConversion var("100"));
}

TEST(CorrectInputTest_CorrectCharInput, PlusAndLongNumber) {
	EXPECT_NO_THROW(ScalarConversion var("+123"));
}

TEST(CorrectInputTest_CorrectCharInput, OnlyMinus){
	EXPECT_NO_THROW(ScalarConversion var("-"));
}

TEST(CorrectInputTest_NonDisplayableChar, PlusAndNonDisplayableNumber) {
	EXPECT_NO_THROW(ScalarConversion var("+1"));
}

TEST(CorrectInputTest_NonDisplayableChar, Zero) {
	EXPECT_NO_THROW(ScalarConversion var("0"));
}

TEST(CorrectInputTest_NonDisplayableChar, PlusZero) {
	EXPECT_NO_THROW(ScalarConversion var("+0"));
}

TEST(CorrectInputTest_NonDisplayableChar, MinusZero) {
	EXPECT_NO_THROW(ScalarConversion var("-0"));
}

TEST(CorrectInputTest_NonDisplayableChar, JustNonDisplayableNumber) {
	EXPECT_NO_THROW(ScalarConversion var("10"));
}

TEST(CorrectInputTest_NonDisplayableChar, OtherNonDisplayableNumber) {
	EXPECT_NO_THROW(ScalarConversion var("31"));
}

TEST(CorrectInputTest_NonDisplayableChar, BigNonDisplayableNumber) {
	EXPECT_NO_THROW(ScalarConversion var("127"));
}


TEST(CorrectInputTest_NumericNotChar, LittleTooBigNumber) {
	EXPECT_NO_THROW(ScalarConversion var("+128"));
}

TEST(CorrectInputTest_NumericNotChar, WayTooBigNumber) {
	EXPECT_NO_THROW(ScalarConversion var("+1234"));
}

TEST(CorrectInputTest_NumericNotChar, LitleNegativeNumber) {
	EXPECT_NO_THROW(ScalarConversion var("-1"));
}

TEST(CorrectInputTest_NumericNotChar, BiggerNegativeNumber) {
	EXPECT_NO_THROW(ScalarConversion var("-123"));
}


TEST(CorrectInputTest_NotNumericNotChar, Nan) {
	EXPECT_NO_THROW(ScalarConversion var("nan"));
}

TEST(CorrectInputTest_NotNumericNotChar, PosInf) {
	EXPECT_NO_THROW(ScalarConversion var("+inf"));
}

TEST(CorrectInputTest_NotNumericNotChar, NegInf) {
	EXPECT_NO_THROW(ScalarConversion var("-inf"));
}

TEST(CorrectInputTest_NotNumericNotChar, Nanf) {
	EXPECT_NO_THROW(ScalarConversion var("nanf"));
}

TEST(CorrectInputTest_NotNumericNotChar, PosInfF) {
	EXPECT_NO_THROW(ScalarConversion var("+inff"));
}

TEST(CorrectInputTest_NotNumericNotChar, NegInfF) {
	EXPECT_NO_THROW(ScalarConversion var("-inff"));
}

TEST(CorrectInputTest_Double, FractionalLittleTooBigNumber) {
	EXPECT_NO_THROW(ScalarConversion var("+12.8"));
}

TEST(CorrectInputTest_Double, FractionalWayTooBigNumber) {
	EXPECT_NO_THROW(ScalarConversion var("+1.234"));
}

TEST(CorrectInputTest_Double, FractionalLitleNegativeNumber) {
	EXPECT_NO_THROW(ScalarConversion var("-0.1"));
}

TEST(CorrectInputTest_Double, FractionalBiggerNegativeNumber) {
	EXPECT_NO_THROW(ScalarConversion var("-12.3"));
}

TEST(CorrectInputTest_Float, FractionalLittleTooBigNumberF) {
	EXPECT_NO_THROW(ScalarConversion var("+12.8f"));
}

TEST(CorrectInputTest_Float, FractionalWayTooBigNumberF) {
	EXPECT_NO_THROW(ScalarConversion var("+1.234f"));
}

TEST(CorrectInputTest_Float, FractionalLitleNegativeNumberF) {
	EXPECT_NO_THROW(ScalarConversion var("-0.1f"));
}

TEST(CorrectInputTest_Float, FractionalBiggerNegativeNumberF) {
	EXPECT_NO_THROW(ScalarConversion var("-12.3f"));
}

TEST(CorrectInputTest_Float, PlusZeroPointZeroF) {
	EXPECT_NO_THROW(ScalarConversion var("+0.0f"));
}

TEST(CorrectInputTest_Float, MinusZeroPointZeroF) {
	EXPECT_NO_THROW(ScalarConversion var("-0.0f"));
}

TEST(CorrectInputTest_Float, NoPlusFractionalLittleTooBigNumberF) {
	EXPECT_NO_THROW(ScalarConversion var("12.8f"));
}

TEST(CorrectInputTest_Float, FractionalLitleNumberF) {
	EXPECT_NO_THROW(ScalarConversion var("0.1f"));
}

TEST(CorrectInputTest_Float, FractionalBiggerNumberF) {
	EXPECT_NO_THROW(ScalarConversion var("12.3f"));
}

TEST(CorrectInputTest_Float, ZeroPointZeroF) {
	EXPECT_NO_THROW(ScalarConversion var("0.0f"));
}

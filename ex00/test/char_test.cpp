/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 00:33:02 by  rokupin          #+#    #+#             */
/*   Updated: 2023/10/12 12:21:52 by rokupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtest/gtest.h"
#include "../src/CharHandler.h"

// Valid Char

TEST(CharOutputTest_CorrectCharInput, CharOutputOnlyPlus){
	EXPECT_EQ(CharHandler::GetCharRep("+"), "'+'");
}

TEST(CharOutputTest_CorrectCharInput, CharOutputPlusAndNumber) {
	EXPECT_EQ(CharHandler::GetCharRep("+100"), "'d'");
}

TEST(CharOutputTest_CorrectCharInput, CharOutputNumber) {
	EXPECT_EQ(CharHandler::GetCharRep("100"), "'d'");
}

TEST(CharOutputTest_CorrectCharInput, CharOutputPlusAndLongNumber) {
	EXPECT_EQ(CharHandler::GetCharRep("+123"), "'{'");
}
TEST(CharOutputTest_CorrectCharInput, CharOutputOnlyMinus){
	EXPECT_EQ(CharHandler::GetCharRep("-"), "'-'");
}

// Valid Char But Not Displayable

TEST(CharOutputTest_NonDisplayableChar, CharOutputPlusAndNonDisplayableNumber) {
	EXPECT_EQ(CharHandler::GetCharRep("+1"), "Non displayable");
}

TEST(CharOutputTest_NonDisplayableChar, CharOutputZero) {
	EXPECT_EQ(CharHandler::GetCharRep("0"), "Non displayable");
}

TEST(CharOutputTest_NonDisplayableChar, CharOutputPlusZero) {
	EXPECT_EQ(CharHandler::GetCharRep("+0"), "Non displayable");
}

TEST(CharOutputTest_NonDisplayableChar, CharOutputMinusZero) {
	EXPECT_EQ(CharHandler::GetCharRep("-0"), "Non displayable");
}

TEST(CharOutputTest_NonDisplayableChar, CharOutputJustNonDisplayableNumber) {
	EXPECT_EQ(CharHandler::GetCharRep("10"), "Non displayable");
}

TEST(CharOutputTest_NonDisplayableChar, CharOutputOtherNonDisplayableNumber) {
	EXPECT_EQ(CharHandler::GetCharRep("31"), "Non displayable");
}

TEST(CharOutputTest_NonDisplayableChar, CharOutputBigNonDisplayableNumber) {
	EXPECT_EQ(CharHandler::GetCharRep("127"), "Non displayable");
}

// Valid Numeric Not Char

TEST(CharOutputTest_NumericNotChar, CharOutputLittleTooBigNumber) {
	EXPECT_EQ(CharHandler::GetCharRep("+128"), "impossible");
}

TEST(CharOutputTest_NumericNotChar, CharOutputWayTooBigNumber) {
	EXPECT_EQ(CharHandler::GetCharRep("+1234"), "impossible");
}

TEST(CharOutputTest_NumericNotChar, CharOutputLitleNegativeNumber) {
	EXPECT_EQ(CharHandler::GetCharRep("-1"), "impossible");
}

TEST(CharOutputTest_NumericNotChar, CharOutputBiggerNegativeNumber) {
	EXPECT_EQ(CharHandler::GetCharRep("-123"), "impossible");
}

// Valid Not Numeric Not Char

TEST(CharOutputTest_NotNumericNotChar, CharOutputNan) {
	EXPECT_EQ(CharHandler::GetCharRep("nan"), "impossible");
}

TEST(CharOutputTest_NotNumericNotChar, CharOutputPosInf) {
	EXPECT_EQ(CharHandler::GetCharRep("+inf"), "impossible");
}

TEST(CharOutputTest_NotNumericNotChar, CharOutputInf) {
	EXPECT_EQ(CharHandler::GetCharRep("inf"), "impossible");
}

TEST(CharOutputTest_NotNumericNotChar, CharOutputNegInf) {
	EXPECT_EQ(CharHandler::GetCharRep("-inf"), "impossible");
}

TEST(CharOutputTest_NotNumericNotChar, CharOutputNanf) {
	EXPECT_EQ(CharHandler::GetCharRep("nanf"), "impossible");
}

TEST(CharOutputTest_NotNumericNotChar, CharOutputPosInfF) {
	EXPECT_EQ(CharHandler::GetCharRep("+inff"), "impossible");
}

TEST(CharOutputTest_NotNumericNotChar, CharOutputNegInfF) {
	EXPECT_EQ(CharHandler::GetCharRep("-inff"), "impossible");
}

// Valid Fractional Numeric Not Char

TEST(CharOutputTest_DoubleNotChar, CharOutputFractionalLittleTooBigNumber) {
	EXPECT_EQ(CharHandler::GetCharRep("+12.8"), "impossible");
}

TEST(CharOutputTest_DoubleNotChar, CharOutputFractionalWayTooBigNumber) {
	EXPECT_EQ(CharHandler::GetCharRep("+1.234"), "impossible");
}

TEST(CharOutputTest_DoubleNotChar,
	 CharOutputFractionalLitleNegativeNumber) {
	EXPECT_EQ(CharHandler::GetCharRep("-0.1"), "impossible");
}

TEST(CharOutputTest_DoubleNotChar,
	 CharOutputFractionalBiggerNegativeNumber) {
	EXPECT_EQ(CharHandler::GetCharRep("-12.3"), "impossible");
}

TEST(CharOutputTest_Float, FractionalLittleTooBigNumberF) {
	EXPECT_EQ(CharHandler::GetCharRep("+12.8f"), "impossible");
}

TEST(CharOutputTest_Float, FractionalWayTooBigNumberF) {
	EXPECT_EQ(CharHandler::GetCharRep("+1.234f"), "impossible");
}

TEST(CharOutputTest_Float, FractionalLitleNegativeNumberF) {
	EXPECT_EQ(CharHandler::GetCharRep("-0.1f"), "impossible");
}

TEST(CharOutputTest_Float, FractionalBiggerNegativeNumberF) {
	EXPECT_EQ(CharHandler::GetCharRep("-12.3f"), "impossible");
}

TEST(CharOutputTest_Float, NoPlusFractionalLittleTooBigNumberF) {
	EXPECT_EQ(CharHandler::GetCharRep("12.8f"), "impossible");
}

TEST(CharOutputTest_Float, FractionalLitleNumberF) {
	EXPECT_EQ(CharHandler::GetCharRep("0.1f"), "impossible");
}

TEST(CharOutputTest_Float, FractionalBiggerNumberF) {
	EXPECT_EQ(CharHandler::GetCharRep("12.3f"), "impossible");
}

TEST(CharOutputTest_Float_NonPrintable, PlusZeroPointZeroF) {
	EXPECT_EQ(CharHandler::GetCharRep("+0.0f"), "Non displayable");
}

TEST(CharOutputTest_Float_NonPrintable, MinusZeroPointZeroF) {
	EXPECT_EQ(CharHandler::GetCharRep("-0.0f"), "Non displayable");
}

TEST(CharOutputTest_Float_NonPrintable, ZeroPointZeroF) {
	EXPECT_EQ(CharHandler::GetCharRep("0.0f"), "Non displayable");
}

TEST(CharOutputTest_Float_NonPrintable, TildaPointZeroF) {
	EXPECT_EQ(CharHandler::GetCharRep("127.0f"), "Non displayable");
}

TEST(CharOutputTest_Float_Printable, FloatStar) {
	EXPECT_EQ(CharHandler::GetCharRep("42.0f"), "'*'");
}

TEST(CharOutputTest_Float_Printable, FloatSpace) {
	EXPECT_EQ(CharHandler::GetCharRep("32.0000001f"), "' '");
}

TEST(CharOutputTest_Float_Printable, SimpleChar) {
	EXPECT_EQ(CharHandler::GetCharRep("a"), "'a'");
}

TEST(CharOutputTest_Float_Printable, Tilda) {
	EXPECT_EQ(CharHandler::GetCharRep("~"), "'~'");
}


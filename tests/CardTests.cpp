//****************************************************************************** 
// File name:		Card.cpp
// Author:			CS, Pacific University
// Class:				CS 250
//******************************************************************************

#include <gtest/gtest.h>

// interface to unit test
#include "../include/Card.h"

// testing parametrized constructor
TEST (CardTest, CardConstructor) {
  Card cCard ("H", "A");
  EXPECT_EQ ("H", cCard.getSuit ());
  EXPECT_EQ ("A", cCard.getDenomination ());
  EXPECT_EQ (1, cCard.getDenominationValue ());
  Card cCard2 ("D", "K");
  EXPECT_EQ ("D", cCard2.getSuit ());
  EXPECT_EQ ("K", cCard2.getDenomination ());
  EXPECT_EQ (13, cCard2.getDenominationValue ());
}

// Testing to see if the setters actually throw 
TEST (CardTest, CardConstructorExceptions) {
  EXPECT_THROW (Card cCard ("X", "30"), std::invalid_argument);
  EXPECT_THROW (Card cCard ("X", "A"), std::invalid_argument);
  EXPECT_THROW (Card cCard ("C", "30"), std::invalid_argument);

}

// Testing copy constructor
TEST (CardTest, CardCopyConstructor) {
  Card cCard1 ("H", "2");
  Card cCard2 (cCard1);

  EXPECT_EQ ("H", cCard2.getSuit ());
  EXPECT_EQ ("2", cCard2.getDenomination ());
  EXPECT_EQ (2, cCard2.getDenominationValue ());
}

// testing operator==
TEST (CardTest, operatorEquals) {
  Card cCard1 ("H", "A");
  Card cCard2 ("H", "A");
  EXPECT_TRUE (cCard1 == cCard2);

  Card cCard3 ("D", "K");
  Card cCard4 ("D", "K");
  Card cCard5 ("H", "Q");
  EXPECT_TRUE (cCard3 == cCard4);
  EXPECT_FALSE (cCard1 == cCard3);
  EXPECT_FALSE (cCard2 == cCard5);
}

// testing operator insertion
TEST (CardTest, operatorInsertion) {
  Card cCard1 ("H", "3");
  std::ostringstream ostring;
  ostring << cCard1;
  EXPECT_EQ ("3H", ostring.str ());
}
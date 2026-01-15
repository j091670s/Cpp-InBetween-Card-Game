//****************************************************************************** 
// File name:		InBetweenHandTests.cpp
// Author:			Gio Adaya
// Class:				CS 250
// Purpose:			This file is written to unit test all functions that are part
//              of the included interface. Specifically here, we are testing the
//              class InBetweenHand. We are to make sure that each function from
//              Hand is called in our tests to ensure we have no errors.
//******************************************************************************

#include <gtest/gtest.h>

// interface to unit test
#include "../include/Hand.h"
#include "../include/InBetweenHand.h"
#include <exception>
#include <iostream>


// testing default constructor
TEST (InBetweenHandTest, InBetweenHandDefault) {
  InBetweenHand cInBetweenHand;
  // making sure I call Hand methods, such as getCard and removeCard
  EXPECT_EQ (0, cInBetweenHand.size ());
  EXPECT_THROW (cInBetweenHand.getCard (1), std::out_of_range);
  EXPECT_THROW (cInBetweenHand.removeCard (1), std::out_of_range);
}

// testing copy constructor
TEST (InBetweenHandTest, InBetweenHandCopyConstructor) {
  InBetweenHand cInBetweenHand;
  Card cCard1 ("H", "A");
  Card cCard2 ("S", "K");

  // called virtual addCard from Hand here
  cInBetweenHand.addCard (cCard1);
  cInBetweenHand.addCard (cCard2);

  InBetweenHand cInBetweenHand2 (cInBetweenHand);

  EXPECT_EQ (2, cInBetweenHand2.size ());
  EXPECT_EQ (Card ("H", "A"), cInBetweenHand2.getCard (0));
  EXPECT_EQ (Card ("S", "K"), cInBetweenHand2.getCard (1));
}

// testing addCard
TEST (InBetweenHandTest, addCard) {
  InBetweenHand cHand;
  InBetweenHand cHand2;
  Card cCard1 ("H", "A");
  Card cCard2 ("S", "10");
  std::ostringstream oString;

  cHand.addCard (cCard1);
  cHand.addCard (cCard2);
  oString << cHand;
  EXPECT_EQ (2, cHand.size ());
  EXPECT_EQ (Card ("H", "A"), cHand.getCard (0));
  EXPECT_EQ (Card ("S", "10"), cHand.getCard (1));
  EXPECT_EQ ("AH 10S", oString.str ());

  cHand2.addCard (Card ("H", "A"));
  cHand2.addCard (Card ("S", "A"));
  oString.str ("");
  oString << cHand2;
  EXPECT_EQ (2, cHand2.size ());
  EXPECT_EQ (Card ("H", "A"), cHand2.getCard (0));
  EXPECT_EQ (Card ("S", "A"), cHand2.getCard (1));
  EXPECT_EQ ("AH AS", oString.str ());

  // checking to see if i can remove a card then add one with no exceptions
  cHand2.removeCard (1);
  cHand2.addCard (Card ("H", "3"));
  oString.str ("");
  oString << cHand2;
  EXPECT_EQ (2, cHand2.size ());
  EXPECT_EQ ("AH 3H", oString.str ());

}

// testing addCard exceptions
TEST (InBetweenHandTest, addCardExceptions) {
  InBetweenHand cInBetweenHand;
  cInBetweenHand.addCard (Card ("H", "A"));
  cInBetweenHand.addCard (Card ("S", "9"));

  EXPECT_THROW (cInBetweenHand.addCard (Card ("H", "A")), std::runtime_error);
  // checking below to see if the function will throw even if I remove a Card 
  // and try to add one more when Im at max capacity
  cInBetweenHand.removeCard (1);
  EXPECT_EQ (1, cInBetweenHand.size ());
  cInBetweenHand.addCard (Card ("S", "9"));
  EXPECT_THROW (cInBetweenHand.addCard (Card ("H", "A")), std::runtime_error);
}

// testing getDistance
TEST (InBetweenHandTest, getDistance) {
  InBetweenHand cInBetweenHand;
  InBetweenHand cInBetweenHand2;

  cInBetweenHand.addCard (Card ("H", "A"));
  cInBetweenHand.addCard (Card ("S", "7"));
  EXPECT_EQ (5, cInBetweenHand.getDistance ());

  cInBetweenHand2.addCard (Card ("H", "A"));
  cInBetweenHand2.addCard (Card ("H", "A"));
  EXPECT_EQ (0, cInBetweenHand2.getDistance ());
  cInBetweenHand2.clear ();

  cInBetweenHand2.addCard (Card ("H", "9"));
  cInBetweenHand2.addCard (Card ("D", "3"));
  EXPECT_EQ (5, cInBetweenHand2.getDistance ());
}

// testing getDistance exceptions
TEST (InBetweenHandTest, getDistanceException) {
  InBetweenHand cInBetweenHand;
  EXPECT_THROW (cInBetweenHand.getDistance (), std::runtime_error);

  cInBetweenHand.addCard (Card ("C", "5"));
  EXPECT_THROW (cInBetweenHand.getDistance (), std::runtime_error);
  cInBetweenHand.addCard (Card ("C", "7"));
  EXPECT_EQ (1, cInBetweenHand.getDistance ());

  cInBetweenHand.clear ();
  EXPECT_THROW (cInBetweenHand.getDistance (), std::runtime_error);

}
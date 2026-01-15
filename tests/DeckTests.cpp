//****************************************************************************** 
// File name:		DeckTests.cpp
// Author:			Gio Adaya
// Class:				CS 250
// Purpose:			This file is written to unit test all functions that are part
//              of the included interface. Specifically here, we are testing the
//              Deck class. As we test, we are making sure each edge case is 
//              handled, as well as testing for throws. We also need to ensure 
//              that each Card function is called somehow in our tests.
//******************************************************************************

#include <gtest/gtest.h>

// interface to unit test
#include "../include/Deck.h"
#include <exception>


// Default constructor testing
TEST (DeckTest, DeckDefault) {
  Deck cDeck;
  std::ostringstream outString;
  outString << cDeck;
  EXPECT_EQ (52, cDeck.size ());
  // the line of code below needs to go past the gray line to work, cant wrap.
  EXPECT_EQ ("10H 2H 3H 4H 5H 6H 7H 8H 9H AH JH KH QH 10C 2C 3C 4C 5C 6C 7C 8C 9C AC JC KC QC 10D 2D 3D 4D 5D 6D 7D 8D 9D AD JD KD QD 10S 2S 3S 4S 5S 6S 7S 8S 9S AS JS KS QS", outString.str ());
}

// Copy constructor testing
TEST (DeckTest, DeckCopyConstructor) {
  Deck cDeck1;
  Deck cDeck2 (cDeck1);
  std::ostringstream oString;
  oString << cDeck2;
  EXPECT_EQ (52, cDeck2.size ());
  // the line of code below needs to go past the gray line to work, cant wrap.
  EXPECT_EQ ("10H 2H 3H 4H 5H 6H 7H 8H 9H AH JH KH QH 10C 2C 3C 4C 5C 6C 7C 8C 9C AC JC KC QC 10D 2D 3D 4D 5D 6D 7D 8D 9D AD JD KD QD 10S 2S 3S 4S 5S 6S 7S 8S 9S AS JS KS QS", oString.str ());
}

// Testing addCard
TEST (DeckTest, addCard) {
  Deck cDeck;
  Card cCard ("H", "A");
  Card cCard2 = cCard;
  std::ostringstream oString;

  cDeck.addCard (cCard);
  EXPECT_EQ (53, cDeck.size ());
  oString << cDeck;
  EXPECT_EQ ("10H 2H 3H 4H 5H 6H 7H 8H 9H AH JH KH QH 10C 2C 3C 4C 5C 6C 7C 8C 9C AC JC KC QC 10D 2D 3D 4D 5D 6D 7D 8D 9D AD JD KD QD 10S 2S 3S 4S 5S 6S 7S 8S 9S AS JS KS QS AH", oString.str ());
  EXPECT_TRUE (cCard == cCard2);
}

// testing dealCard
TEST (DeckTest, dealCard) {
  Deck cDeck;
  Card cDealtCard1 = cDeck.dealCard ();
  Card cDealtCard2 = cDeck.dealCard ();
  Card cDealtCard3 = cDeck.dealCard ();
  Deck cDeck2;
  size_t sizeOfDeck2 = cDeck2.size ();

  std::vector <Card> cDeck2Cards;


  EXPECT_EQ ("S", cDealtCard1.getSuit ());
  EXPECT_EQ ("Q", cDealtCard1.getDenomination ());
  EXPECT_EQ (12, cDealtCard1.getDenominationValue ());

  EXPECT_EQ ("S", cDealtCard2.getSuit ());
  EXPECT_EQ ("K", cDealtCard2.getDenomination ());
  EXPECT_EQ (13, cDealtCard2.getDenominationValue ());

  EXPECT_FALSE (cDealtCard1 == cDealtCard2);

  EXPECT_EQ ("S", cDealtCard3.getSuit ());
  EXPECT_EQ ("J", cDealtCard3.getDenomination ());
  EXPECT_EQ (11, cDealtCard3.getDenominationValue ());

  EXPECT_FALSE (cDealtCard2 == cDealtCard3);

  // using loop to deal all the cards, then checking the size of the second Deck
  for (size_t i = 0; i < sizeOfDeck2; ++i) {
    Card dealAll = cDeck2.dealCard ();
    cDeck2Cards.push_back (dealAll);
  }

  EXPECT_EQ (0, cDeck2.size ());
}

// testing dealCard exceptions
TEST (DeckTest, dealCardExceptions) {
  Deck cDeck;
  size_t sizeOfDeck = cDeck.size ();

  for (size_t i = 0; i < sizeOfDeck; ++i) {
    Card cDealt = cDeck.dealCard ();
  }

  EXPECT_EQ (0, cDeck.size ());
  EXPECT_THROW (cDeck.dealCard (), std::out_of_range);
}

// testing size
TEST (DeckTest, size) {
  Deck cDeck;
  EXPECT_EQ (52, cDeck.size ());
}

// testing shuffle
TEST (DeckTest, shuffle) {
  Deck cDeck;
  std::ostringstream oString;
  srand (3);
  cDeck.shuffle ();

  oString << cDeck;

  EXPECT_EQ ("QS JS 10D 8D KD 3D 4C 9S 7D 2D AS 5S 10H KH 3C QC 2H 6D 3S 4D AC 7C 2C 9H 5C JH JD 4S 7H JC 7S QD 8H 10C 10S 9D AH 5D 9C 4H 5H 8S 6S 3H 2S QH 8C 6H KC KS AD 6C", oString.str ());

}

// testing clear 
TEST (DeckTest, clear) {
  Deck cDeck;
  Card cCard ("H", "A");
  cDeck.addCard (cCard);

  EXPECT_EQ (53, cDeck.size ());
  cDeck.clear ();
  EXPECT_EQ (0, cDeck.size ());
}

// testing operator<<
TEST (DeckTest, operatorInsertion) {
  Deck cDeck;
  std::ostringstream oString;
  oString << cDeck;
  EXPECT_EQ ("10H 2H 3H 4H 5H 6H 7H 8H 9H AH JH KH QH 10C 2C 3C 4C 5C 6C 7C 8C 9C AC JC KC QC 10D 2D 3D 4D 5D 6D 7D 8D 9D AD JD KD QD 10S 2S 3S 4S 5S 6S 7S 8S 9S AS JS KS QS", oString.str ());
  Card cDealt = cDeck.dealCard ();
  oString.str ("");
  oString << cDealt;
  EXPECT_EQ ("QS", oString.str ());
}
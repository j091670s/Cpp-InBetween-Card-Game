//****************************************************************************** 
// File name:		HandTests.cpp
// Author:			Gio Adaya		
// Class:				CS 250
//******************************************************************************

#include <gtest/gtest.h>

// interface to unit test
#include "../include/Hand.h"
#include <exception>

// testing the virtual addCard
TEST(HandTest, addCardVirtual) {
  Hand cHand;
  Card cCard1("H","A");
  Card cCard2("S","8");

  cHand.addCard(cCard1);
  EXPECT_EQ(1, cHand.size());
  EXPECT_EQ(Card("H","A"), cHand.getCard(0));
  cHand.addCard(cCard2);
  EXPECT_EQ(2, cHand.size());
  EXPECT_EQ(Card("S","8"), cHand.getCard(1));
}

// testing the two arguments addCard (getCard is tested too)
TEST(HandTest, addCard) {
  Hand cHand;
  Card cCard1("H", "A");
  Card cCard2("S", "8");
  Card cCard3("D", "3");

  cHand.addCard(cCard1, 0);
  EXPECT_EQ(1,cHand.size());
  EXPECT_EQ(Card("H","A"), cHand.getCard(0));

  cHand.addCard(cCard2, 1);
  EXPECT_EQ(2,cHand.size());
  EXPECT_EQ(Card("S","8"), cHand.getCard(1));

  cHand.addCard(cCard3, 0);
  EXPECT_EQ(3,cHand.size());
  EXPECT_EQ(Card("D","3"), cHand.getCard(0));
  EXPECT_EQ(Card("H","A"), cHand.getCard(1));
  EXPECT_EQ(Card("S","8"), cHand.getCard(2));

}

// testing addCard exceptions
TEST(HandTest, addCardExceptions) {
  Hand cHand;
  Card cCard("H", "A");
  EXPECT_THROW(cHand.addCard(cCard, 1), std::out_of_range);
}

// testing getCard exception
TEST(HandTest, getCardExceptions) {
  Hand cHand;
  EXPECT_THROW(cHand.getCard(0), std::out_of_range);
}

// testing removeCard
TEST(HandTest, removeCard) {
  Hand cHand;
  Card cCard1("H", "A");
  Card cCard2("S", "8");

  cHand.addCard(cCard1);
  cHand.addCard(cCard2);

  Card cRemoved = cHand.removeCard(0);
  EXPECT_EQ(Card("H", "A"), cRemoved);
  EXPECT_THROW(cHand.removeCard(5), std::out_of_range);

}

// testing operator<<
TEST(HandTest, operatorInsertion) {
  Hand cHand;
  Card cCard1("H", "A");
  Card cCard2("S", "8");

  cHand.addCard(cCard1);
  cHand.addCard(cCard2);
  std::ostringstream oString;
  oString << cHand;
  EXPECT_EQ("AH 8S", oString.str());
}

//****************************************************************************** 
// File name:		HumanInBetweePlayerTests.cpp
// Author:			Gio Adaya
// Class: CS250
//******************************************************************************

#include <gtest/gtest.h>

// interface to unit test
#include "../include/HumanInBetweenPlayer.h"
#include "../include/Card.h"
#include "../include/Bank.h"
#include "../include/InBetweenPlayer.h"




// default cosntructor
TEST(HumanInBetweenPlayerTest, HumanInBetweenPlayerDefault) {
  HumanInBetweenPlayer cHIBP;
  EXPECT_EQ("Player_0", cHIBP.getName());
  EXPECT_EQ(0, cHIBP.getBank().getBalance());
  EXPECT_EQ(0, cHIBP.getInBetweenHand().size());

}

// parameterized constructor, but also testing various methods
TEST(HumanInBetweenPlayerTest, HumanInBetweenPlayerParameterized) {
  HumanInBetweenPlayer cHIBP("Gio", Bank(1000), InBetweenHand());
  EXPECT_EQ("Gio", cHIBP.getName());
  EXPECT_EQ(1000, cHIBP.getBank().getBalance());
  cHIBP.addToInBetweenHand(Card("H", "A"));
  cHIBP.addToInBetweenHand(Card("S", "A"));
  EXPECT_EQ(2, cHIBP.getInBetweenHand().size());
  cHIBP.clearInBetweenHand();
  EXPECT_EQ(0, cHIBP.getInBetweenHand().size());

}

// testing addToBank and subtractFromBank and clearBank
TEST(HumanInBetweenPlayerTest, addToBank) {
  HumanInBetweenPlayer cHIBP("Gio", Bank(1000), InBetweenHand());
  cHIBP.addToBank(1000);
  EXPECT_EQ(2000, cHIBP.getBank().getBalance());
  cHIBP.subtractFromBank(100);
  EXPECT_EQ(1900, cHIBP.getBank().getBalance());
  cHIBP.clearBank();
  EXPECT_EQ(0, cHIBP.getBank().getBalance());
}

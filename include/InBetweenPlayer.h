//******************************************************************************
// File name:  InBetweenPlayer.h
// Author:     CS, Pacific University
// Date:       
// Class:      CS250
// Assignment: Card Games
// Purpose:    Interface for class InBetweenPlayer.
//******************************************************************************

#pragma once

#include <string>
#include "Bank.h"
#include "Hand.h"
#include "InBetweenHand.h"

class InBetweenPlayer {
public:
  InBetweenPlayer ();
  InBetweenPlayer (const std::string& rcName, const Bank& rcBank,
    const InBetweenHand& rcHand);
  InBetweenPlayer (const InBetweenPlayer& rcInBetweenPlayer);
  virtual ~InBetweenPlayer ();
  std::string getName () const;
  Bank getBank () const;
  Bank addToBank (int amount);
  Bank subtractFromBank (int amount);
  InBetweenHand getInBetweenHand () const;
  InBetweenHand addToInBetweenHand (const Card& rcCard);
  void clearInBetweenHand ();
  void clearBank ();

  virtual int getBet (int potSize) const = 0;

private:
  std::string mcName;
  Bank mcBank;
  InBetweenHand mcInBetweenHand;
  static std::string defaultName;
  static int counter;

  void setName (const std::string& rcName);
  void setBank (const Bank& rcBank);
  void setHand (const InBetweenHand& rcHand);
};
//******************************************************************************
// File name:  HumanInBetweenPlayer.h
// Author:     CS, Pacific University
// Date:       
// Class:      CS250
// Assignment: Card Games
// Purpose:    Interface for class HumanInBetweenPlayer.
//******************************************************************************

#pragma once

#include <string>
#include "Bank.h"
#include "InBetweenHand.h"
#include "InBetweenPlayer.h"

class HumanInBetweenPlayer : public InBetweenPlayer {
public:
  HumanInBetweenPlayer ();
  HumanInBetweenPlayer (const std::string& rcName, const Bank& rcBank,
    const InBetweenHand& rcInBetweenHand);
  HumanInBetweenPlayer (const HumanInBetweenPlayer& rcHumanInBetweenPlayer);
  virtual ~HumanInBetweenPlayer ();

  virtual int getBet (int potSize) const;
};
//******************************************************************************
// File name:  AIConservativeInBetweenPlayer.h
// Author:     CS, Pacific University
// Date:       
// Class:      CS250
// Assignment: Card Games
// Purpose:    Interface for class AIConservativeInBetweenPlayer.
//******************************************************************************

#pragma once

#include <string>
#include "Bank.h"
#include "InBetweenHand.h"
#include "InBetweenPlayer.h"

class AIConservativeInBetweenPlayer : public InBetweenPlayer {
public:
  AIConservativeInBetweenPlayer ();
  AIConservativeInBetweenPlayer (const std::string& rcName, const Bank& rcBank,
    const InBetweenHand& rcInBetweenHand);
  AIConservativeInBetweenPlayer (const AIConservativeInBetweenPlayer&
    rcConservativeInBetweenPlayer);
  virtual ~AIConservativeInBetweenPlayer ();

  virtual int getBet (int potSize) const;
};
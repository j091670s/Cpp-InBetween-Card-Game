//******************************************************************************
// File name:   AIConservativeInBetweenPlayer.cpp
// Author:      Gio Adaya
// Date:        4/18/2025
// Class:       CS250
// Assignment:  05 CardGamePart C
// Purpose:     The purpose of this class is to create a conservative AI player.
//              Its purpose is to have a conservative strategy pattern 
//              that can function without human intervention. This class is a 
//              subclass of InBetweenPlayer.
// Hours:       1.5
//******************************************************************************
#include <iostream>
#include "../include/Card.h"
#include "../include/Bank.h"
#include "../include/InBetweenPlayer.h"
#include "../include/HumanInBetweenPlayer.h"
#include "../include/AIConservativeInBetweenPlayer.h"
#include "../include/InBetweenGamePlay.h"
#include <exception>
#include <string>

const int HIGH_RISK = 3;

const int MID_RISK = 2;


/*******************************************************************************
Function:     AIConservativeInBetweenPlayer default

Description:  Initializes a AIConservativeInBetweenPlayer object with default
              values coming from InBetweenPlayer

Parameter:    None

Returned:     None
*******************************************************************************/
AIConservativeInBetweenPlayer::AIConservativeInBetweenPlayer ()
  : InBetweenPlayer () {
}

/*******************************************************************************
Function:     AIConservativeInBetweenPlayer parameterized

Description:  Initializes a AIConservativeInBetweenPlayer with a specified name,
              bank, and hand

Parameter:    rcName          - the specified name of the player (string)
              rcBank          - the initial Bank balance of the player (Bank)
              rcInBetweenHand - the initial Hand of of Cards for the player

Returned:     None
*******************************************************************************/
AIConservativeInBetweenPlayer::AIConservativeInBetweenPlayer (const std::string&
  rcName, const Bank& rcBank, const InBetweenHand& rcInBetweenHand)
  : InBetweenPlayer (rcName, rcBank, rcInBetweenHand) {
}

/*******************************************************************************
Function:     AIConservativeInBetweenPlayer copy constructor

Description:  Creates a copy of an existing AIConservativeInBetweenPlayer object
              by copying its name, bank, and hand from the passed in object.

Parameter:    rcConservativeInBetweenPlayer - the AIConservativeInBetweenPlayer
                                              object to be copied

Returned:     None
*******************************************************************************/
AIConservativeInBetweenPlayer::AIConservativeInBetweenPlayer (
  const AIConservativeInBetweenPlayer& rcConservativeInBetweenPlayer)
  :InBetweenPlayer (rcConservativeInBetweenPlayer) {
}

/*******************************************************************************
Function:     AIConservativeInBetweenPlayer destructor

Description:  Destroys a AIConservativeInBetweenPlayer object, however theres no
              dynamically allocated resources in this class, therefore the
              destructor does nothing.

Parameter:    None

Returned:     None
*******************************************************************************/
AIConservativeInBetweenPlayer::~AIConservativeInBetweenPlayer () {
}

/*******************************************************************************
Function:     getBet

Description:  A virtual function, getBet returns the AI players bet based
              on a couple factors. If the in between card distance is greater
              than 10, then the AI will bet a HIGH RISK amount, which is 3. If
              the AI player doesn't have enough chips to bet HIGH RISK, it'll
              bet the next highest amount. If this player cannot bet the next
              highest amount, then they'll bet 1 chip, which is a LOW RISK.

Parameter:    potSize -  the current size of the pot (int)

Returned:     Returns an int which represents the bet amount of the ai player
*******************************************************************************/
int AIConservativeInBetweenPlayer::getBet (int potSize) const {
  int betAmount;
  int cardDistance = getInBetweenHand ().getDistance ();

  if (cardDistance > 10) {
    if (getBank ().getBalance () >= HIGH_RISK && potSize >= HIGH_RISK) {
      betAmount = InBetweenGamePlay::HIGH;
    }
    else if (getBank ().getBalance () >= MID_RISK && potSize >= MID_RISK) {
      betAmount = InBetweenGamePlay::MEDIUM;
    }
    else {
      betAmount = InBetweenGamePlay::LOW;
    }
  }
  else if (cardDistance > 8) {
    if (getBank ().getBalance () >= MID_RISK && potSize >= MID_RISK) {
      betAmount = InBetweenGamePlay::MEDIUM;
    }
    else {
      betAmount = InBetweenGamePlay::LOW;
    }
  }
  else {
    betAmount = InBetweenGamePlay::LOW;
  }

  std::cout << "Place your bet: " << betAmount << std::endl;

  return betAmount;
}
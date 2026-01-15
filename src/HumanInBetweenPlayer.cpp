//******************************************************************************
// File name:   HumanInBetweenPlayer.cpp
// Author:      Gio Adaya
// Date:        4/18/2025
// Class:       CS250
// Assignment:  05 CardGamePart C
// Purpose:     The main purpose of this subclass is to override the getBet
//              method from its base class InBetweenPlayer. The class lets a 
//              human player enter their bet through the terminal, checks if the 
//              bet follows the game rules, and deals with errors if the bet 
//              isnt valid."
// Hours:       1.5
//******************************************************************************
#include <iostream>
#include "../include/Card.h"
#include "../include/Bank.h"
#include "../include/InBetweenPlayer.h"
#include "../include/HumanInBetweenPlayer.h"
#include <exception>
#include <string>


const int VALID_HAND_SIZE = 2;
const int MINIMUM_BET = 1;


/*******************************************************************************
Function:     HumanInBetweenPlayer default

Description:  Initializes a HumanInBetweenPlayer object with default values
              coming from InBetweenPlayer

Parameter:    None

Returned:     None
*******************************************************************************/
HumanInBetweenPlayer::HumanInBetweenPlayer () : InBetweenPlayer () {
}

/*******************************************************************************
Function:     HumanInBetweenPlayer parameterized

Description:  Initializes a HumanInBetweenPlayer with a specified name, bank,
              and hand

Parameter:    rcName          - the specified name of the player (string)
              rcBank          - the initial Bank balance of the player (Bank)
              rcInBetweenHand - the initial Hand of of Cards for the player

Returned:     None
*******************************************************************************/
HumanInBetweenPlayer::HumanInBetweenPlayer (const std::string& rcName,
  const Bank& rcBank, const InBetweenHand& rcInBetweenHand)
  : InBetweenPlayer (rcName, rcBank, rcInBetweenHand) {
}

/*******************************************************************************
Function:     HumanInBetweenPlayer copy constructor

Description:  Creates a copy of an existing HumanInBetweenPlayer object by
              copying its name, bank, and hand from the passed in object.

Parameter:    rcHumanInBetweenPlayer - the HumanInBetweenPlayer object to be
                                       copied

Returned:     None
*******************************************************************************/
HumanInBetweenPlayer::HumanInBetweenPlayer (const HumanInBetweenPlayer&
  rcHumanInBetweenPlayer) : InBetweenPlayer (rcHumanInBetweenPlayer) {
}

/*******************************************************************************
Function:     HumanInBetweenPlayer destructor

Description:  Destroys a HumanInBetweenPlayer object, however theres no
              dynamically allocated resources in this class, therefore the
              destructor does nothing.

Parameter:    None

Returned:     None
*******************************************************************************/
HumanInBetweenPlayer::~HumanInBetweenPlayer () {

}

/*******************************************************************************
Function:     getBet

Description:  Prompts the player to enter their bet based on the pot size and
              size of their hand. Validates the bet by making sure its < 0 or
              > their balance. The bet cant exceed the pot size. If any of this
              is attempted, the proper throw messages will be displayed.

Parameter:    potSize - the current size of the pot (int)

Returned:     Returns an int which is the bet amount of the player
*******************************************************************************/
int HumanInBetweenPlayer::getBet (int potSize) const {
  int betAmount;
  bool bisValidBet = false;

  if (getInBetweenHand ().size () != VALID_HAND_SIZE) {
    throw std::runtime_error
    ("HumanInBetweenPlayer Exception::getBet: Invalid hand size");
  }

  while (!bisValidBet) {
    std::cout << "Place your bet: ";
    std::cin >> betAmount;

    if (betAmount < MINIMUM_BET || betAmount > getBank ().getBalance ()) {
      throw std::runtime_error
      ("HumanInBetweenPlayer Exception::getBet:: Invalid bet amount");
    }

    if (betAmount > potSize) {
      throw std::runtime_error
      ("HumanInBetweenPlayer Exception::getBet:: Bet cannot exceed pot size");
    }

    bisValidBet = true;
  }
  return betAmount;

}
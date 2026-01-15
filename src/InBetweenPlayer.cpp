//******************************************************************************
// File name:   InBetweenPlayer.cpp
// Author:      Gio Adaya
// Date:        4/18/2025
// Class:       CS250
// Assignment:  05 CardGamePart C
// Purpose:     The purpose of the InBetweenPlayer abstract class is to serve as 
//              a base class that defines the common interface and 
//              functionality that the ai and human player class must 
//              implement.
// Hours:       1.2
//******************************************************************************
#include <iostream>
#include "../include/Card.h"
#include "../include/Bank.h"
#include "../include/InBetweenPlayer.h"
#include <exception>
#include <string>


// static string variable for the default name
std::string InBetweenPlayer::defaultName = "Player";

// static int variable for the counter
int InBetweenPlayer::counter = 0;

const std::string UNDERSCORE = "_";
const int EMPTY_AMOUNT = 0;




/*******************************************************************************
Function:     InBetweenPlayer default

Description:  Initializes the player name to be Player_0 and Player_1... Sets
              the bank value to 0 and also sets an empty Hand

Parameter:    None

Returned:     None
*******************************************************************************/
InBetweenPlayer::InBetweenPlayer ()
  :mcName (defaultName + UNDERSCORE + std::to_string (counter++)),
  mcBank (EMPTY_AMOUNT) {
}

/*******************************************************************************
Function:     InBetweenPlayer parameterized

Description:  Constructor for InBetweenPlayer that takes in arguments for the
              name, the Bank, and the hand. Ensures each argument is valid by
              utilizing the setters, which will throw exceptions if their
              arguments are invalid.

Parameter:    rcName - the string representing the player name
              rcBank - a constant reference to a Bank object that will be used
                       to set mcBank
              rcHand - a constant reference to a InBetweenHand object that will
                       be used to set mcInBetweenHand

Returned:     None
*******************************************************************************/
InBetweenPlayer::InBetweenPlayer (const std::string& rcName, const Bank& rcBank,
  const InBetweenHand& rcHand) {
  setName (rcName);
  setBank (rcBank);
  setHand (rcHand);
}

/*******************************************************************************
Function:     InBetweenPlayer copy constructor

Description:  Constructor that sets the current InBetweenPlayer object members
              to another InBetweenPlayer objects members

Parameter:    rcInBetweenPlayer - a constant reference to the InBetweenPlayer
                                  object that will be used to set the current
                                  InBetweenPlayer objects members.

Returned:     None
*******************************************************************************/
InBetweenPlayer::InBetweenPlayer (const InBetweenPlayer& rcInBetweenPlayer) :
  mcName (rcInBetweenPlayer.mcName), mcBank (rcInBetweenPlayer.mcBank),
  mcInBetweenHand (rcInBetweenPlayer.mcInBetweenHand) {

}

/*******************************************************************************
Function:     InBetweenPlayer destructor

Description:  Does nothing

Parameter:    None

Returned:     None
*******************************************************************************/
InBetweenPlayer::~InBetweenPlayer () {

}

/*******************************************************************************
Function:     getName

Description:  Returns the name of the human in between player (mcName)

Parameter:    None

Returned:     mcName - player name of type string
*******************************************************************************/
std::string InBetweenPlayer::getName () const {
  return mcName;
}

/*******************************************************************************
Function:     getBank

Description:  returns the current bank balance of the player (mcBank)

Parameter:    None

Returned:     returns the Bank balance, which is mcBank
*******************************************************************************/
Bank InBetweenPlayer::getBank () const {
  return mcBank;
}

/*******************************************************************************
Function:     addToBank

Description:  adds amount to the Bank balance, specifically the mcBank private
              member. If the amount added is negative, an invalid_argument
              exception is thrown.

Parameter:    amount - the amount (int) to be added to the mcBank private member

Returned:     Returns the current mcBank member
*******************************************************************************/
Bank InBetweenPlayer::addToBank (int amount) {
  if (amount < EMPTY_AMOUNT) {
    throw std::invalid_argument
    ("InBetweenPlayer Exception::addToBank:amount must be positive");
  }
  mcBank.add (amount);
  return mcBank;
}

/*******************************************************************************
Function:     subtractFromBank

Description:  Subtracts an amount from the mcBank private member balance. If the
              amount is negative, an invalid_argument exception is thrown. This
              function reuses the subtract method from the Bank class since
              InBetweenPlayer has a Bank

Parameter:    amount - the amount (int) to be subtracted from the mcBank balance

Returned:     The current mcBank balance
*******************************************************************************/
Bank InBetweenPlayer::subtractFromBank (int amount) {
  if (amount < EMPTY_AMOUNT) {
    throw std::invalid_argument
    ("InBetweenPlayer Exception::subtractFromBank:amount must be positive");
  }
  mcBank.subtract (amount);
  return mcBank;
}

/*******************************************************************************
Function:     getInBetweenHand

Description:  Returns the InBetweenHand mcInBetweenHand private member

Parameter:    None

Returned:     The current players InBetweenHand
*******************************************************************************/
InBetweenHand InBetweenPlayer::getInBetweenHand () const {
  return mcInBetweenHand;
}

/*******************************************************************************
Function:     addToInBetweenHand

Description:  Adds a Card object to the InBetweenHand mcInBetweenHand private
              member

Parameter:    rcCard - a constant reference to the Card object that will be
                       added to mcInBetweenHand

Returned:     InBetweenHand - the current updated hand after adding the Card
*******************************************************************************/
InBetweenHand InBetweenPlayer::addToInBetweenHand (const Card& rcCard) {
  mcInBetweenHand.addCard (rcCard);
  return mcInBetweenHand;
}

/*******************************************************************************
Function:     clearInBetweenHand

Description:  Clears all players cards from the hand

Parameter:    None

Returned:     None (void)
*******************************************************************************/
void InBetweenPlayer::clearInBetweenHand () {
  mcInBetweenHand.clear ();
}


/*******************************************************************************
Function:     clearBank

Description:  Resets the players balance back to 0

Parameter:    None

Returned:     None (void)
*******************************************************************************/
void InBetweenPlayer::clearBank () {
  mcBank.clear ();
}
/*******************************************************************************
Function:     setName

Description:  Sets the mcName private member to the argument passed in. If the
              argument passed in is an empty string, an invalid_argument
              exception is thrown

Parameter:    rcName - the name that mcName will be set to

Returned:     None (void)
*******************************************************************************/
void InBetweenPlayer::setName (const std::string& rcName) {
  if (rcName.empty ()) {
    throw std::invalid_argument
    ("InBetweenPlayer Exception::setName: name is empty");
  }
  mcName = rcName;
}

/*******************************************************************************
Function:     setBank

Description:  Sets the Bank object to the passed in Bank object. If the balance
              of the Bank argument is less than zero, an invalid exception will
              be thrown

Parameter:    rcBank - constant reference to the Bank object being passed in. If
                       its balance is positive, its value will be used to set
                       mcBank

Returned:     None (void)
*******************************************************************************/
void InBetweenPlayer::setBank (const Bank& rcBank) {
  if (rcBank.getBalance () < EMPTY_AMOUNT) {
    throw std::invalid_argument
    ("InBetweenPlayer Exception::setBank: amount must be positive");
  }
  mcBank = rcBank;
}

/*******************************************************************************
Function:     setHand

Description:  Sets the mcInBetweenHand private member to the passed in
              InBetweenHand object

Parameter:    rcHand - the InBetweenHand object passed in used to set
                       mcInBetweenHand

Returned:     None (void)
*******************************************************************************/
void InBetweenPlayer::setHand (const InBetweenHand& rcHand) {
  mcInBetweenHand = rcHand;
}
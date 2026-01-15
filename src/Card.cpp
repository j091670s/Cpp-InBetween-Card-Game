//******************************************************************************
// File name:   Card.cpp
// Author:      Gio Adaya
// Date:        4/7/2025
// Class:       CS250
// Assignment:  05 CardGamePart B
// Purpose:     Implement the Card class, which is very crucial to the rest of 
//              the classes. We are tasked to implement a variety of setters 
//              and getters, as well as to overload certain operators such as
//              the insertion and equality operators.
// Hours:       2.0
//******************************************************************************
#include <iostream>
#include "../include/Card.h"
#include <exception>
#include <string>
#include <vector>
#include <map>

// static variable representing the Card suits
const std::vector<std::string> Card::SUITS = {
  "H", "C", "D", "S"
};


// static variable representing the Card denomination
const std::map<std::string, int> Card::DENOMINATION_VALUES = {
  {"A", 1},{"2", 2},{"3", 3},{"4", 4},{"5", 5},{"6", 6}, {"7", 7},
  {"8", 8}, {"9", 9}, {"10", 10}, {"J", 11}, {"Q", 12}, {"K", 13}
};




/*******************************************************************************
Function:     setSuit

Description:  This is a private setter function that sets the Card objects suit
              value to the value that is passed in. It will throw an invalid
              argument exception if the value passed in is an illegal suit.

Parameter:    rcSuit - the value, which is of type string that represents the
                       suit of the card. Must be a valid/legal suit

Returned:     None (void)
*******************************************************************************/
void Card::setSuit (const std::string& rcSuit) {
  bool bIsValidSuit = false;
  for (const auto& suit : SUITS) {
    if (suit == rcSuit) {
      bIsValidSuit = true;
    }
  }

  if (!bIsValidSuit) {
    throw std::invalid_argument ("Card Exception: Invalid suit");
  }
  else {
    mcSuit = rcSuit;
  }

}
/*******************************************************************************
Function:     setDenomination

Description:  This is a private setter function that sets the Card objects
              denomination value to the value that is passed in. if an invalid
              denomination value is passed in, the function will throw an
              invalid argument exception.

Parameter:    rcDenomination - the value, which is of type string, that
                               represents the denomination value of the Card
                               object. Must be a valid denomination

Returned:     None (void)
*******************************************************************************/
void Card::setDenomination (const std::string& rcDenomination) {
  bool bisValid = false;
  for (const auto& denomination : DENOMINATION_VALUES) {
    if (rcDenomination == denomination.first) {
      bisValid = true;
    }
  }

  if (!bisValid) {
    throw std::invalid_argument ("Card Exception: Invalid denomination");
  }

  mcDenomination = rcDenomination;
}

/*******************************************************************************
Function:     Card

Description:  Initialiazes a Card object with the specified suit and
              denomination. The first argument is the suit, and the second is
              the denomination. Both the suit and denomination is validated
              using setSuit and setDenomination.

Parameter:    rcSuit         - A string representing the suit of the Card.
              rcDenomination - A string representing the denomination of the
                               Card.

Returned:     None
*******************************************************************************/
Card::Card (const std::string& rcSuit, const std::string& rcDenomination) {
  setSuit (rcSuit);
  setDenomination (rcDenomination);
}

/*******************************************************************************
Function:     Card (copy constructor)

Description:  Initializes a Card object with the contents of another Card
              object, which would the the suit and denomination. Also uses
              setSuit and setDenomination to validate the contents of the copy
              object.

Parameter:    rcCard - a constant reference to a Card object that will be used
                       to set the current card objects suit and denomination

Returned:     None
*******************************************************************************/
Card::Card (const Card& rcCard) {
  setSuit (rcCard.mcSuit);
  setDenomination (rcCard.mcDenomination);
}

/*******************************************************************************
Function:     ~Card (destructor)

Description:  Does nothing

Parameter:    None

Returned:     None
*******************************************************************************/
Card::~Card () {

}

/*******************************************************************************
Function:    getSuit

Description: Returns the suit of the Card object.

Parameter:   None

Returned:    A string representing the Card suit
*******************************************************************************/
std::string Card::getSuit ()const {
  return mcSuit;
}

/*******************************************************************************
Function:    getDenomination

Description: Returns the denomination of the Card object, but not the actual
             numerical value

Parameter:   None

Returned:    A string representing the Card denomination
*******************************************************************************/
std::string Card::getDenomination () const {
  return mcDenomination;
}

/*******************************************************************************
Function:    getDenominationValue

Description: Returns the actual denomination value of the Card object

Parameter:   None

Returned:    A size_t representing the Card denomination value
*******************************************************************************/
size_t Card::getDenominationValue ()const {
  size_t denominationValue;
  for (const auto& value : DENOMINATION_VALUES) {
    if (mcDenomination == value.first) {
      denominationValue = value.second;
    }
  }
  return denominationValue;
}

/*******************************************************************************
Function:    getCard

Description: Returns the copy of the current Card object. Marked with a const so
             that the member variables aren't modifiable.

Parameter:   None

Returned:    A copy of the current Card object
*******************************************************************************/
Card Card::getCard () const {
  return *this;
}

/*******************************************************************************
Function:    operator==

Description: Returns true if the current Card object is identical to the Card
             object that is being passed in/checked

Parameter:   rcCard - a constant reference to a Card object being used to
                      check if its equal to the current Card object

Returned:    A bool, true if both objects are identical, false otherwise.
*******************************************************************************/
bool Card::operator==(const Card& rcCard) const {
  return (getSuit () == rcCard.getSuit () &&
    getDenomination () == rcCard.getDenomination ());
}

/*******************************************************************************
Function:    operator<<

Description: Write a Card object to an output stream in the form of the
             denomination followed by the suit, such as AH

Parameter:  rcOutStream - represent an output stream to which the Card will be
                          written to
            rcCard      - the Card object that is going to be written to an
                          output stream

Returned:   A reference to the output stream
*******************************************************************************/
std::ostream& operator<<(std::ostream& rcOutStream, const Card& rcCard) {
  rcOutStream << rcCard.getDenomination () << rcCard.getSuit ();
  return rcOutStream;
}
//******************************************************************************
// File name:   InBetweenHand.cpp
// Author:      Gio Adaya
// Date:        4/7/2025
// Class:       CS250
// Assignment:  05 CardGamePart B
// Purpose:     InBetweenHand is the subclass. It inherits the base class Hand.
//              The main purpose of InBetweenHand is to override the addcard 
//              function, which is a virtual function in the Hand class. We are 
//              also tasked to implement a getDistance function, which will 
//              tell us how many cards are between the two cards dealt.
// Hours:       3.5
//******************************************************************************
#include <iostream>
#include "../include/Deck.h"
#include "../include/Card.h"
#include "../include/Hand.h"
#include "../include/InBetweenHand.h"
#include <exception>

const int MAX_CARDS = 2;

/*******************************************************************************
Function:    InBetweenHand

Description:  Does nothing, but implicitly calls the default constructor of the
              base class (Hand)

Parameter:    None

Returned:     None
*******************************************************************************/
InBetweenHand::InBetweenHand () {

}

/*******************************************************************************
Function:     InBetweenHand copy constructor

Description:  Uses the copy constructor of the base class (Hand)

Parameter:    rcHand - a constant reference to the InBetweenHand object to copy

Returned:     None
*******************************************************************************/
InBetweenHand::InBetweenHand (const InBetweenHand& rcHand) : Hand (rcHand) {

}

/*******************************************************************************
Function:     ~InBetweenHand

Description:  Does nothing

Parameter:    None

Returned:     None
*******************************************************************************/
InBetweenHand::~InBetweenHand () {

}

/*******************************************************************************
Function:     addCard

Description:  Adds a card to the Hand in ascending order based on denomination
              value. If two cards have the same value, the new Card is added
              after the existing Card. Throws exception if theres already 2
              Cards

Parameter:    rcCard - a constant reference to the Card which will be added to
                       the hand

Returned:     Returns the current object (InBetweenHand)
*******************************************************************************/
Hand InBetweenHand::addCard (const Card& rcCard) {
  size_t index = 0;
  if (this->size () >= MAX_CARDS) {
    throw std::runtime_error
    ("InBetweenHand Exception: Hand cannot have more than 2 cards");
  }

  while (index < this->size () && this->getCard (index).getDenominationValue ()
    <= rcCard.getDenominationValue ()) {
    ++index;
  }

  Hand::addCard (rcCard, index);
  return *this;
}

/*******************************************************************************
Function:     getDistance

Description:  Calculates the number of cards between the first and second cards
              in the hand. Throws runtime_error exception if theres not exactly
              2 cards

Parameter:    None

Returned:     A size_t representing the number of cards between the two cards in
              the hand
*******************************************************************************/
size_t InBetweenHand::getDistance () const {
  size_t distance;
  size_t denominationValue1 = 0;
  size_t denominationValue2 = 0;
  size_t higherValue, lowerValue;

  if (this->size () != MAX_CARDS) {
    throw std::runtime_error
    ("InBetweenHand Exception: Hand must have exactly 2 cards");
  }

  denominationValue1 = this->getCard (0).getDenominationValue ();
  denominationValue2 = this->getCard (1).getDenominationValue ();

  if (denominationValue1 == denominationValue2) {
    distance = 0;
  }
  else {

    if (denominationValue1 > denominationValue2) {
      higherValue = denominationValue1;
      lowerValue = denominationValue2;
    }
    else {
      higherValue = denominationValue2;
      lowerValue = denominationValue1;
    }

    distance = higherValue - lowerValue;
  }
  return distance;
}
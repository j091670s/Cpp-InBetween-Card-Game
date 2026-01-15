//******************************************************************************
// File name:   Hand.cpp
// Author:      Gio Adaya
// Date:        4/7/2025
// Class:       CS250
// Assignment:  05 CardGamePart B
// Purpose:     Implement the base class Hand. Hand will soon be inherited by
//              InBetweenHand, therefore implementing Hand carefully is crucial.
//              We are tasked to implement virtual functions such as addCard, as
//              well as getCard, removeCard, size, clear, the constructors, and
//              the insertion << operator.
// Hours:       2.5
//******************************************************************************
#include <iostream>
#include "../include/Deck.h"
#include "../include/Card.h"
#include "../include/Hand.h"
#include <exception>
#include <string>

/*******************************************************************************
Function:     Hand

Description:  Does nothing

Parameter:    None

Returned:     None
*******************************************************************************/
Hand::Hand () {

}

/*******************************************************************************
Function:     Hand copy constructor

Description:  Sets rcHand mcCards to the current Hand object mcCards

Parameter:    None

Returned:     None
*******************************************************************************/
Hand::Hand (const Hand& rcHand) {
  mcCards = rcHand.mcCards;
}

/*******************************************************************************
Function:     ~Hand

Description:  Does nothing

Parameter:    None

Returned:     None
*******************************************************************************/
Hand::~Hand () {

}

/*******************************************************************************
Function:     virtual addCard

Description:  Adds a Card to the end of the Hand. Marked as virtual, which means
              it can be overwritten in derived classes.

Parameter:    rcCard - a constant reference to the Card object being added to
                       the end of the Hand

Returned:     Return the current Hand object
*******************************************************************************/
Hand Hand::addCard (const Card& rcCard) {
  mcCards.push_back (rcCard);
  return *this;
}

/*******************************************************************************
Function:     addCard

Description:  Adds a Card at a specific index in the Hand. The index must be in
              valid range [0,size], otherwise it will throw an out_of_range
              exception

Parameter:    rcCard -  a constant reference to the Card object being added to
                        the Hand
              index  - the position at which the Card will be added to

Returned:     Returns the current Hand object
*******************************************************************************/
Hand Hand::addCard (const Card& rcCard, size_t index) {
  if (index > mcCards.size ()) {
    throw std::out_of_range ("Hand Exception: Invalid hand index");
  }

  mcCards.insert (mcCards.begin () + index, rcCard);
  return *this;
}

/*******************************************************************************
Function:     removeCard

Description:  This function removes a Card from a Hand at a specific index. If
              the index is an invalid index, the function will throw an
              out_of_range exception

Parameter:    index - the position of the Card which will be removed from Hand

Returned:     Returns the removed Card object
*******************************************************************************/
Card Hand::removeCard (size_t index) {
  if (index >= mcCards.size ()) {
    throw std::out_of_range ("Hand Exception: Invalid hand index");
  }

  Card cRemovedCard = mcCards[index];
  mcCards.erase (mcCards.begin () + index);
  return cRemovedCard;
}

/*******************************************************************************
Function:     size

Description:  Returns the size of the private member mcCards

Parameter:    None

Returned:     The size of the mcCards private member (size_t)
*******************************************************************************/
size_t Hand::size () const {
  return mcCards.size ();
}

/*******************************************************************************
Function:     getCard

Description:  Returns the Card object in the Hand at the specified index

Parameter:    index - the position of the Card we are getting

Returned:     Returns the Card object at the specified index
*******************************************************************************/
Card Hand::getCard (size_t index) const {
  if (index >= this->size ()) {
    throw std::out_of_range ("Hand Exception: Invalid hand index");
  }
  return mcCards[index];
}

/*******************************************************************************
Function:     clear

Description:  Clears the Hand of its Card objects

Parameter:    None

Returned:     None (void)
*******************************************************************************/
void Hand::clear () {
  mcCards.clear ();
}

/*******************************************************************************
Function:     operator<<

Description:  Overloads the insertion operator to write the Hand to an output
              stream in the form of the Cards being denomination suit. Each Card
              from the Hand is seperated by a white space, minus the last Card.

Parameter:    rcOut  - The output stream we are writing to
              rcHand - The Hand object to be written

Returned:     A reference to the output stream, which is rcOut
*******************************************************************************/
std::ostream& operator<<(std::ostream& rcOut, const Hand& rcHand) {
  for (size_t i = 0; i < rcHand.size (); ++i) {
    rcOut << rcHand.mcCards[i];
    if (i < rcHand.size () - 1) {
      rcOut << " ";
    }
  }
  return rcOut;
}
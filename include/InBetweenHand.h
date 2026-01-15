//******************************************************************************
// File name:  Card.h
// Author:     CS, Pacific University
// Date:       
// Class:      CS250
// Assignment: Card Games
// Purpose:    Interface for class InBetweenHand. A InBetweenHand is a 
//             collection of cards. An InBetweenHand is a hand of cards that is
//             ordered by denomination. The lowest denomination is first and the
//             highest denomination is last. The class will have a method to
//             add a card to the hand. The card will be added in order with the
//             lowest denomination first.
//******************************************************************************
#pragma once

#include <iostream>
#include <vector>
#include "Hand.h"

class InBetweenHand : public Hand {
public:
  InBetweenHand ();
  InBetweenHand (const InBetweenHand& rcHand);
  virtual ~InBetweenHand ();
  virtual Hand addCard (const Card& rcCard);
  size_t getDistance () const;
};
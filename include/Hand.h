//******************************************************************************
// File name:  Hand.h
// Author:     CS, Pacific University
// Date:       
// Class:      CS250
// Assignment: Card Games
// Purpose:    Interface for class Hand. A Hand is a collection of cards.
//******************************************************************************
#pragma once

#include "Card.h"
#include <iostream>
#include <vector>

class Hand {
public:
  Hand ();
  Hand (const Hand& rcHand);
  virtual ~Hand ();
  virtual Hand addCard (const Card& rcCard);
  Hand addCard (const Card& rcCard, size_t index);
  Card removeCard (size_t index);
  size_t size () const;
  Card getCard (size_t index) const;
  void clear ();

  friend std::ostream& operator<< (std::ostream& rcOut, const Hand& rcHand);

private:
  std::vector<Card> mcCards;
};
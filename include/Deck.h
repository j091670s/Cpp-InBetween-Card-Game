//******************************************************************************
// File name:  Deck.h
// Author:     CS, Pacific University
// Date:       
// Class:      CS250
// Assignment: Card Games
// Purpose:    Interface for class Deck. A Deck is a collection of cards.
//******************************************************************************
#pragma once

#include <ostream>
#include <vector>
#include "../include/Deck.h"
#include "../include/Card.h"

class Deck {
public:
  Deck ();
  Deck (const Deck& rcDeck);
  virtual ~Deck ();
  void addCard (const Card& rcCard);
  Card dealCard ();
  size_t size () const;
  void shuffle ();
  void clear ();
  // void write (std::ostream& rcOut) const;
  friend std::ostream& operator<< (std::ostream& rcOutStream,
    const Deck& rcDeck);

private:
  std::vector<Card> mcCards;
};
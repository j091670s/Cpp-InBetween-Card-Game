//******************************************************************************
// File name:  Card.h
// Author:     CS, Pacific University
// Date:       
// Class:      CS250
// Assignment: Card Games
// Purpose:    Interface for class Card. A Card has a suit and a denomination.
//             Cards will be represented in the static const map
//             DENOMINATION_VALUES. The map will be used to convert the
//             denomination to a value. The value will be used to compare
//             cards. The class will also have a static const vector of
//             SUITS. The vector will be used to represent the four suits
//             of cards.
//******************************************************************************
#pragma once

#include <string>
#include <ostream>
#include <vector>
#include <map>

class Card {
public:
  Card (const std::string& rcSuit, const std::string& rcDenomination);
  Card (const Card& rcCard);
  virtual ~Card ();

  std::string getSuit () const;
  std::string getDenomination () const;
  size_t getDenominationValue () const;
  Card getCard () const;

  bool operator== (const Card& rcCard) const;

  friend std::ostream& operator<< (std::ostream& rcOutStream,
    const Card& rcCard);

  static const std::map<std::string, int> DENOMINATION_VALUES;
  static const std::vector<std::string> SUITS;

private:
  std::string mcSuit;
  std::string mcDenomination;

  void setSuit (const std::string& rcSuit);
  void setDenomination (const std::string& rcDenomination);
};
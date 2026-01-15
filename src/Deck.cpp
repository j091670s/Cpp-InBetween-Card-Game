//******************************************************************************
// File name:   Deck.cpp
// Author:      Gio Adaya
// Date:        4/7/2025
// Class:       CS250
// Assignment:  05 CardGamePart B
// Purpose:     Implement the Deck class, which has-a Card. The main objective
//              of the Deck class is to create an unshuffled and shuffled Deck,
//              add a card to the deck, deal a card from the deck, clear the
//              deck, and output the Decks to an output stream.
// Hours:       3.0
//******************************************************************************
#include <iostream>
#include "../include/Deck.h"
#include "../include/Card.h"
#include <exception>
#include <cstdlib> 


/*******************************************************************************
Function:     Deck

Description:  Creates an unshuffled Deck of Cards, which is created looping
              through the suits and denomination values of the map.

Parameter:    None

Returned:     None
*******************************************************************************/
Deck::Deck () {
  for (const auto& suit : Card::SUITS) {
    for (const auto& denomination : Card::DENOMINATION_VALUES) {
      Card cCard (suit, denomination.first);
      mcCards.push_back (cCard);
    }
  }
}

/*******************************************************************************
Function:     Deck copy constructor

Description:  Takes a Deck object and sets the current objects members to the
              object being passed in

Parameter:    rcDeck - A constant reference to an object that the current
                       objects members are being set to

Returned:     None
*******************************************************************************/
Deck::Deck (const Deck& rcDeck) {
  mcCards = rcDeck.mcCards;
}

/*******************************************************************************
Function:     ~Deck

Description:  Destructor

Parameter:    None

Returned:     None
*******************************************************************************/
Deck::~Deck () {

}

/*******************************************************************************
Function:     addCard

Description:  Adds a Card object to the end of the Deck

Parameter:    rcCard - A constant reference to the Card object that will be
                       added to the end of the Deck

Returned:    None (void)
*******************************************************************************/
void Deck::addCard (const Card& rcCard) {
  mcCards.push_back (rcCard);
}

/*******************************************************************************
Function:     dealCard

Description:  Deals a card from the end of the Deck

Parameter:    None

Returned:     Returns a Card object
*******************************************************************************/
Card Deck::dealCard () {
  if (mcCards.empty ()) {
    throw std::out_of_range ("Deck Exception: No cards in deck");
  }
  Card cDealtCard = mcCards.back ();
  mcCards.pop_back ();
  return cDealtCard;

}
/*******************************************************************************
Function:     size

Description:  Returns the size of the Deck, specifically the vector size which
              is of type Card

Parameter:    None

Returned:     A size_t variable which holds the size of the Deck
*******************************************************************************/
size_t Deck::size () const {
  return mcCards.size ();
}

/*******************************************************************************
Function:     shuffle

Description:  Shuffles the Deck of Cards using a specific algorithm.

Parameter:    None

Returned:     None (void)
*******************************************************************************/
void Deck::shuffle () {
  size_t cardIndex = mcCards.size () - 1;

  while (cardIndex > 0) {
    size_t randomIndex = rand () % cardIndex;

    Card cTempCard = mcCards[cardIndex];
    mcCards[cardIndex] = mcCards[randomIndex];
    mcCards[randomIndex] = cTempCard;

    --cardIndex;

  }
}
/*******************************************************************************
Function:     clear

Description:  Removes all Cards fromm the Deck, leaving Deck empty.

Parameter:    None

Returned:     None (void)
*******************************************************************************/
void Deck::clear () {
  mcCards.clear ();
}
/*******************************************************************************
Function:     operator<<

Description:  A friend function of operator<< to write the Deck to an output
              stream. Each Card object in the Deck is to be written in the form
              of denomination suit, such as AH. Each Card object is seperated by
              a single space, except for the last Card.

Parameter:    rcOutStream - The output stream that we are writing to
              rcDeck      - The Deck object that will be written

Returned:     A reference to the output stream
*******************************************************************************/
std::ostream& operator << (std::ostream& rcOutStream, const Deck& rcDeck) {

  for (size_t i = 0; i < rcDeck.size (); ++i) {
    rcOutStream << rcDeck.mcCards[i];
    if (i < rcDeck.size () - 1) {
      rcOutStream << " ";
    }
  }
  return rcOutStream;
}
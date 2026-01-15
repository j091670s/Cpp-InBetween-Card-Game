//******************************************************************************
// File name:   InBetweenGamePlay.cpp
// Author:      Gio Adaya
// Date:        4/18/2025
// Class:       CS250
// Assignment:  05 CardGamePart C
// Purpose:     The purpose is to implement the InBetweenGamePlay class, which
//              is essentially the central game management system. Here, we 
//              make sure that all game rules are implemented correctly as well
//              as the game mechanics (betting, winning chips, losing, etc).This 
//              class pretty much encapsulates all the logic for how the game 
//              play should go. Additionally, another purpose was for us to
//              find and determine what private variable and methods we should 
//              include to our class in order for certain functions, such as 
//              playRound from becoming too long and complex. Therefore, this
//              InBetweenGamePlay class ensures we break down this game to as 
//              little pieces as possible.
// Hours:       11.5
//******************************************************************************
#include <iostream>
#include "../include/Bank.h"
#include "../include/Deck.h"
#include "../include/InBetweenPlayer.h"
#include "../include/InBetweenHand.h"
#include "../include/HumanInBetweenPlayer.h"
#include "../include/AIConservativeInBetweenPlayer.h"
#include "../include/InBetweenGamePlay.h"
#include <exception>
#include <string>

const int SAME_CARDS = 0;
const int CONSECUTIVE_CARDS = 1;
const int INBETWEEN_HAND_SIZE = 2;
const int NO_CHIPS = 0;
const int EMPTY_POT = 0;
const int FIRST_CARD = 0;
const int SECOND_CARD = 1;


/*******************************************************************************
Function:     InBetweenGamePlay constructor

Description:  Initializes the game with a specified riskLevel, sets the pot to 0
              and shuffles the deck of Cards

Parameter:    rcRiskLevel - The risk level to be used for the game
                            (LOW, MEDIUM, HIGH).

Returned:     None
*******************************************************************************/
InBetweenGamePlay::InBetweenGamePlay (const RiskLevel& rcRiskLevel)
  : mcPot (0), mcRiskLevel (rcRiskLevel) {
  mcDeck.shuffle ();
}

/*******************************************************************************
Function:     InBetweenGamePlay destructor

Description:  Cleans up dynamically allocated memory for players stored in the
              mcInBetweenPlayers pointer vector

Parameter:    None

Returned:     None
*******************************************************************************/
InBetweenGamePlay::~InBetweenGamePlay () {
  for (auto player : mcInBetweenPlayers) {
    delete player;
  }
  mcInBetweenPlayers.clear ();
}

/*******************************************************************************
Function:     addPlayer

Description:  Adds a new player to the game. The player is dynamically allocated
              and passed in as a pointer to the function. The player is stored
              in the mcInBetweenPlayers vector

Parameter:    pcInBetweenPlayer - A pointer to an InBetweenPlayer object, which
                                  could be a Human or AI player

Returned:     None (void)
*******************************************************************************/
void InBetweenGamePlay::addPlayer (InBetweenPlayer* pcInBetweenPlayer) {
  mcInBetweenPlayers.push_back (pcInBetweenPlayer);
}

/*******************************************************************************
Function:     printBanks

Description:  Prints all the banks of the Players in the game at the end of a
              round.

Parameter:    None

Returned:     None (void)
*******************************************************************************/
void InBetweenGamePlay::printBanks () const {
  for (auto player : mcInBetweenPlayers) {
    std::cout << player->getName () << "'s Bank: $"
      << player->getBank ().getBalance () << std::endl;
  }
}

/*******************************************************************************
Function:     addAntesToPot

Description:  Collects chips from each player and adds them to the pot. The
              amount of chips is determined by the risk level of the game

Parameter:    None

Returned:     None (void)
*******************************************************************************/
void InBetweenGamePlay::addAntesToPot () {
  auto anteAmount = mcRiskLevel;

  for (auto player = mcInBetweenPlayers.begin ();
    player != mcInBetweenPlayers.end ();) {
    InBetweenPlayer* pcPlayer = *player;
    pcPlayer->subtractFromBank (anteAmount);
    mcPot.add (anteAmount);

    if (pcPlayer->getBank ().getBalance () <= NO_CHIPS) {
      player = mcInBetweenPlayers.erase (player);
    }
    else {
      player++;
    }
  }
}

/*******************************************************************************
Function:     dealCards

Description:  Ensures that each player is dealt two cards by clearing their
              hand before dealing. Then, one card is dealt to each player, and
              then a second card is dealt to each player again.

Parameter:    None

Returned:     None (void)
*******************************************************************************/
void InBetweenGamePlay::dealCards () {

  for (auto player : mcInBetweenPlayers) {
    player->clearInBetweenHand ();
  }

  for (size_t i = 0; i < INBETWEEN_HAND_SIZE; ++i) {
    for (auto player : mcInBetweenPlayers) {
      Card cCard = mcDeck.dealCard ();
      player->addToInBetweenHand (cCard);
    }
  }
}

/*******************************************************************************
Function:     isInBetween

Description:  Determines if the third card falls in between two cards in value.
              Cards are determined by their denomination value

Parameter:    rcCard1         - A constant reference to the first card
              rcCard2         - A constant reference to the second card
              rcInBetweenCard - A constant reference to the third card to check

Returned:     A boolean that returns true if the third card fell in between the
              two cards, otherwise returns false.
*******************************************************************************/
bool InBetweenGamePlay::isInBetween (const Card& rcCard1,
  const Card& rcCard2, const Card& rcInBetweenCard) const {

  int cardValue1 = rcCard1.getDenominationValue ();
  int cardValue2 = rcCard2.getDenominationValue ();
  int inBetweenValue = rcInBetweenCard.getDenominationValue ();

  int lowestCardValue = cardValue1;
  int highestCardValue = cardValue2;

  if (cardValue1 > cardValue2) {
    lowestCardValue = cardValue2;
    highestCardValue = cardValue1;
  }

  return (lowestCardValue < inBetweenValue && inBetweenValue
    < highestCardValue);
}

/*******************************************************************************
Function:     playRound

Description:  Executes one round of the game. One round is when each player gets
              a turn, or if the pot size is empty before everyone can get their
              turn.

Parameter:    None

Returned:     None (void)
*******************************************************************************/
void InBetweenGamePlay::playRound () {
  bool bIsPotEmpty = false;
  for (auto player = mcInBetweenPlayers.begin (); player
    != mcInBetweenPlayers.end ();) {

    InBetweenPlayer* pcPlayer = *player;

    if (mcPot.getBalance () > EMPTY_POT) {
      processPlayerTurn (pcPlayer);
      bIsPotEmpty = false;
    }
    else {
      if (!bIsPotEmpty) {
        std::cout << "Pot is empty" << std::endl;
        bIsPotEmpty = true;
      }
    }

    if (isPlayerOutOfChips (pcPlayer)) {
      player = mcInBetweenPlayers.erase (player);
    }
    else {
      player++;
    }
  }

  displayFinalPotSize ();
}


/*******************************************************************************
Function:     playAgain

Description:  Prompts the user if they want to play again by asking them to
              enter a capital P for Play, or Q for Quit. Validates so that
              the user only enter a P or Q.

Parameter:    None

Returned:     A boolean that returns true if the user wants to play again, false
              otherwise
*******************************************************************************/
bool InBetweenGamePlay::playAgain () const {
  char choice;
  bool bPlayAgain = false;
  bool bisValidChoice = false;

  do {
    std::cout << "P)lay game" << std::endl;
    std::cout << "Q)uit" << std::endl << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;


    if (choice == InBetweenGamePlay::GAME_PLAY) {
      bPlayAgain = true;
      bisValidChoice = true;
    }
    else if (choice == InBetweenGamePlay::QUIT_GAME) {
      bPlayAgain = false;
      bisValidChoice = true;
    }
    else {
      std::cout << "Illegal choice, enter either a P or a Q" << std::endl;

    }
  } while (!bisValidChoice);

  return bPlayAgain;
}

/*******************************************************************************
Function:     writeRoundHeading

Description:  Outputs the info at the start of the players turn, as well as the
              pot size, player name, bank balance, and cards. This is a private
              member function.

Parameter:    pcPlayer - A constant pointer to the player whose turn it is

Returned:     None (void)
*******************************************************************************/
void InBetweenGamePlay::writeRoundHeading (const InBetweenPlayer* pcPlayer)
const {
  std::cout << "Pot Size: $" << mcPot.getBalance () << std::endl << std::endl;

  std::cout << pcPlayer->getName () << "'s Turn" << std::endl;
  std::cout << pcPlayer->getName () << "'s Bank: "
    << pcPlayer->getBank ().getBalance () << std::endl;
  std::cout << "Cards: " << pcPlayer->getInBetweenHand () << std::endl;
}

/*******************************************************************************
Function:     displayBankBalance

Description:  Outputs the updated bank balances of the players after either
              winning or losing chips. This is different from printBanks because
              this function only prints a singular player bank balance when it
              is called. This function also takes in a InBetween player pointer.

Parameter:    pcPlayer - A constant pointer to the player whose turn it is to
                         output bank balance

Returned:     None (void)
*******************************************************************************/
void InBetweenGamePlay::displayBankBalance (const InBetweenPlayer* pcPlayer) {
  std::cout << pcPlayer->getName () << "'s Bank: "
    << pcPlayer->getBank ().getBalance () << std::endl << std::endl;
}

/*******************************************************************************
Function:     checkSameOrConsecutiveCards

Description:  Checks if the players two cards are the same or consecutive. If
              the cards are the same, the player wins two chips from the pot. If
              theyre consecutive, the player loses 1 chip from the pot. This is
              a private member method

Parameter:    pcPlayer - A pointer to the player whose cards are being checked.

Returned:     A boolean that returns true if cards are the same or consecutive,
              false otherwise
*******************************************************************************/
bool InBetweenGamePlay::isSameOrConsecutiveCards
(InBetweenPlayer* pcPlayer) {

  bool bIsSameOrConsecutive = false;
  int winAmount = 2;
  int loseAmount = 1;

  int cardDistance = pcPlayer->getInBetweenHand ().getDistance ();

  if (cardDistance == SAME_CARDS) {

    if (mcPot.getBalance () < winAmount) {
      winAmount = mcPot.getBalance ();
    }

    std::cout << pcPlayer->getName () << " wins!" << std::endl;
    pcPlayer->addToBank (winAmount);
    mcPot.subtract (winAmount);
    displayBankBalance (pcPlayer);
    bIsSameOrConsecutive = true;

  }
  else if (cardDistance == CONSECUTIVE_CARDS) {

    std::cout << pcPlayer->getName () << " loses." << std::endl;
    pcPlayer->subtractFromBank (loseAmount);
    mcPot.add (loseAmount);
    displayBankBalance (pcPlayer);
    bIsSameOrConsecutive = true;

  }
  return bIsSameOrConsecutive;
}

/*******************************************************************************
Function:     processPlayerTurn

Description:  Processes a single turn. Checks hand size, displays turn info
              by calling writeRoundHeading, checks same/consecutive cards
              by calling isSameOrConsecutiveCards, and processes betting if
              needed. This method is a private member

Parameter:    pcPlayer - A pointer to the player whose turn is being processed.

Returned:     None (void)
*******************************************************************************/
void InBetweenGamePlay::processPlayerTurn (InBetweenPlayer* pcPlayer) {
  bool bIsSameOrConsecutive;

  if (pcPlayer->getInBetweenHand ().size () != INBETWEEN_HAND_SIZE) {
    std::cout << "Invalid hand size \n";
  }
  else {
    writeRoundHeading (pcPlayer);
    bIsSameOrConsecutive = isSameOrConsecutiveCards (pcPlayer);
    if (!bIsSameOrConsecutive) {
      proccessBetAndDrawing (pcPlayer);
    }
  }
}

/*******************************************************************************
Function:     processBetAndDrawing

Description:  Handles the betting process for a player. Asks for player bet,
              draws third card, determines if the player won/loss their bet,
              and updates the bank and pot balances when needed. This method is
              a private method

Parameter:    pcPlayer - A pointer to the player thats betting

Returned:     None (void)
*******************************************************************************/
void InBetweenGamePlay::proccessBetAndDrawing (InBetweenPlayer*
  pcPlayer) {

  try {
    int playerBet = pcPlayer->getBet (mcPot.getBalance ());

    InBetweenHand firstCard = pcPlayer->getInBetweenHand ();
    Card cThirdCard = mcDeck.dealCard ();
    std::cout << "InBetween Card: " << cThirdCard << std::endl;

    const InBetweenHand cPlayerHand = pcPlayer->getInBetweenHand ();
    const Card cFirstCard = cPlayerHand.getCard (FIRST_CARD);
    const Card cSecondCard = cPlayerHand.getCard (SECOND_CARD);

    if (isInBetween (cFirstCard, cSecondCard, cThirdCard)) {
      std::cout << pcPlayer->getName () << " wins!" << std::endl;

      pcPlayer->addToBank (playerBet);
      mcPot.subtract (playerBet);
    }
    else {
      std::cout << pcPlayer->getName () << " loses." << std::endl;
      pcPlayer->subtractFromBank (playerBet);
      mcPot.add (playerBet);
    }

    displayBankBalance (pcPlayer);

  }
  catch (std::runtime_error& rcException) {
    std::cout << "Invalid bet amount. You lose your turn and 1 chip"
      << std::endl;
    pcPlayer->subtractFromBank (1);
    displayBankBalance (pcPlayer);
    mcPot.add (1);
  }
}

/*******************************************************************************
Function:     isPlayerOutOfChips

Description:  Checks if a player has ran out of chips and should therefore be
              removed from the game. Displays a message that they've been
              removed for clarity. This method is a private member method

Parameter:    pcPlayer - A pointer to the player to check

Returned:     A boolean that returns true if the player has no chips left, false
              otherwise.
*******************************************************************************/
bool InBetweenGamePlay::isPlayerOutOfChips (InBetweenPlayer* pcPlayer) {
  bool bIsOutOfChips = false;
  if (pcPlayer->getBank ().getBalance () <= NO_CHIPS) {
    std::cout << pcPlayer->getName () << " ran out of chips, kicked out. \n";
    bIsOutOfChips = true;
  }
  return bIsOutOfChips;
}

/*******************************************************************************
Function:     displayFinalPotSize

Description:  Displays the last pot size when the round is over. This is a
              a private member function

Parameter:    None

Returned:     None (void)
*******************************************************************************/
void InBetweenGamePlay::displayFinalPotSize () const {
  if (!mcInBetweenPlayers.empty ()) {
    std::cout << "Pot Size: $" << mcPot.getBalance () << std::endl << std::endl;
  }
}
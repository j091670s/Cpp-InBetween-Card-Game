//******************************************************************************
// File name:  InBetweenGamePlay.h
// Author:     CS, Pacific University
// Date:       
// Class:      CS250
// Assignment: Card Games
// Purpose:    Interface for class InBetweenGamePlay.
//******************************************************************************
#pragma once

#include <vector>
#include "InBetweenPlayer.h"
#include "Bank.h"
#include "Card.h"
#include "Deck.h"

class InBetweenGamePlay {
public:
  enum PlayerType { AI_PLAYER = 'A', HUMAN_PLAYER = 'H' };
  enum GamePlayChoice { GAME_PLAY = 'P', QUIT_GAME = 'Q' };
  enum RiskLevel { LOW = 1, MEDIUM = 2, HIGH = 3 };

  InBetweenGamePlay (const RiskLevel& rcRiskLevel);
  ~InBetweenGamePlay ();
  void addPlayer (InBetweenPlayer* pcInBetweenPlayer);
  void printBanks () const;
  void addAntesToPot ();
  void dealCards ();
  bool isInBetween (const Card& rcCard1,
    const Card& rcCard2, const Card& rcInBetweenCard) const;
  void playRound ();
  bool playAgain () const;

private:
  std::vector<InBetweenPlayer*> mcInBetweenPlayers;
  Bank mcPot;
  Deck mcDeck;
  RiskLevel mcRiskLevel;

  void writeRoundHeading (const InBetweenPlayer* pcPlayer) const;
  void displayBankBalance(const InBetweenPlayer *pcPlayer);
  bool isSameOrConsecutiveCards (InBetweenPlayer* pcPlayer);
  void processPlayerTurn(InBetweenPlayer *pcPlayer);
  void proccessBetAndDrawing (InBetweenPlayer* pcPlayer);
  bool isPlayerOutOfChips(InBetweenPlayer* pcPlayer);
  void displayFinalPotSize() const;
};
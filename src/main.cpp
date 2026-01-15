//******************************************************************************
// File name:   main.cpp
// Author:      Gio Adaya
// Date:        4/18/2025
// Class:       CS250
// Assignment:  05 CardGamePart c
// Purpose:     The purpose of the main file is to finally put together our
//              pieces of code to create the in between card game. Here we are
//              in charge of making sure the game flows correctly, as well as
//              to set the game risk level and the seed value for the random
//              number generator that shuffles the Deck of Cards.
// Hours:       3.5
//******************************************************************************

#include <iostream>
#include "../include/Deck.h"
#include "../include/Card.h"
#include "../include/Hand.h"
#include "../include/InBetweenHand.h"
#include "../include/InBetweenGamePlay.h"
#include "../include/AIConservativeInBetweenPlayer.h"
#include "../include/HumanInBetweenPlayer.h"
#include "../include/InBetweenPlayer.h"
#include <cstdlib>

const char DONE = 'D';

char getPlayerChoice ();
void playGame (InBetweenGamePlay& rcGame);
void addPlayerFromMenu (InBetweenGamePlay& rcGame);
void outputFinalStats (InBetweenGamePlay& rcGame);


int main () {
  srand (3);

  std::cout << "Welcome to InBetween!" << std::endl << std::endl;
  std::cout << "*** Adding players ***" << std::endl << std::endl;

  InBetweenGamePlay cGame (InBetweenGamePlay::LOW);

  addPlayerFromMenu (cGame);

  bool bPlayGame = cGame.playAgain ();

  if (bPlayGame) {
    playGame (cGame);
  }

  outputFinalStats (cGame);

  return EXIT_SUCCESS;
}

/*******************************************************************************
Function:     getPlayerChoice

Description:  Prompts the user to enter a choice from adding an AI conservative
              player, a human player, and if they are done adding players. The
              only valid choices are A, H, or D, they must be caps otherwise
              they are prompted to try again.

Parameter:    None

Returned:     A char representing the players choice.
*******************************************************************************/
char getPlayerChoice () {
  char choice;

  do {
    std::cout << "A)I player add" << std::endl;
    std::cout << "H)uman player add" << std::endl;
    std::cout << "D)one adding players" << std::endl << std::endl;

    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cout << std::endl;

    if (choice != InBetweenGamePlay::AI_PLAYER
      && choice != InBetweenGamePlay::HUMAN_PLAYER && choice != DONE) {
      std::cout << "Please enter a legal choice (capital A, H, or D)"
        << std::endl;
    }

  } while (choice != InBetweenGamePlay::AI_PLAYER
    && choice != InBetweenGamePlay::HUMAN_PLAYER && choice != DONE);

  return choice;
}

/*******************************************************************************
Function:     playGame

Description:  Manages the main game loop. The game ends when a player does not
              want to play again. This function calls addAntesToPot, dealCards,
              playRound, and playAgain.

Parameter:    rcGame - A reference to the InBetweenGamePlay object that handles
                       the logic and the game state.

Returned:     None (void)
*******************************************************************************/
void playGame (InBetweenGamePlay& rcGame) {
  bool bPlayAgain = true;
  int roundCounter = 1;
  while (bPlayAgain) {

    std::cout << std::endl << "ROUND #" << roundCounter << std::endl
      << std::endl;

    rcGame.addAntesToPot ();

    rcGame.dealCards ();

    rcGame.playRound ();

    bPlayAgain = rcGame.playAgain ();
    roundCounter++;
  }
}

/*******************************************************************************
Function:     addPlayerFromMenu

Description:  Handles adding players to the game. This function calls
              getPlayerChoice to determine what kind of player to add or if the
              selection is done.

Parameter:    rcGame - A reference to the InBetweenGamePlay object to which
                       players will be added to.

Returned:     None (void)
*******************************************************************************/
void addPlayerFromMenu (InBetweenGamePlay& rcGame) {
  char playerChoice;
  int aiBank;
  int humanBank;
  std::string humanName;
  InBetweenPlayer* pcPlayer = nullptr;

  do {
    playerChoice = getPlayerChoice ();

    if (playerChoice == InBetweenGamePlay::AI_PLAYER) {

      std::cout << "*** Adding Conservative AI Player ***" << std::endl
        << std::endl;

      pcPlayer = new AIConservativeInBetweenPlayer ();
      std::cout << "Enter name: ";
      std::cout << pcPlayer->getName ();
      std::cout << std::endl;
      std::cout << "Enter starting bank: $";
      std::cin >> aiBank;
      std::cout << std::endl;
      pcPlayer->addToBank (aiBank);
      rcGame.addPlayer (pcPlayer);

    }
    else if (playerChoice == InBetweenGamePlay::HUMAN_PLAYER) {
      std::cout << "*** Adding Human Player ***" << std::endl << std::endl;
      std::cout << "Enter name: ";
      std::cin >> humanName;
      std::cout << "Enter starting bank: $";
      std::cin >> humanBank;
      std::cout << std::endl;
      pcPlayer = new HumanInBetweenPlayer (humanName, humanBank,
        InBetweenHand ());
      rcGame.addPlayer (pcPlayer);
    }

  } while (playerChoice != DONE);

}


/*******************************************************************************
Function:     outputFinalStats

Description:  Displays the final bank values of the players. This function calls
              printBanks, a public method from InBetweenGamePlay. The final
              stats are outputted when a player decides to quit and not play
              another round

Parameter:    rcGame - A reference to the InBetweenGamePlay object containing
                       the players whose stats will be displayed

Returned:     None (void)
*******************************************************************************/
void outputFinalStats (InBetweenGamePlay& rcGame) {
  std::cout << std::endl << std::endl << "*** Final Bank Values: ***"
    << std::endl << std::endl;
  rcGame.printBanks ();
}

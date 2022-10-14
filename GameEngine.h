//
// Created by Aihua on 2020-08-03.
//

#ifndef BLACKJACKCARDGAME_GAMEENGINE_H
#define BLACKJACKCARDGAME_GAMEENGINE_H

#include "Player.h"

class GameEngine {
public:
    GameEngine() = default;

    // provides players with instructions for Blackjack
    static void gameInstructions();

    // creates a shuffled deck of playing cards for the game
    static vectorOfCards createShuffledDeckOfCards();

    // If the player's points tally EXCEEDS 21 AND he/she has collected
    // some Aces, some of those Aces can be devalued to have a worth of
    // 1 to lower the player's points
    static void devalueCollectedAces(Player& player);

    // displays input instructions for player on console
    static void displayHitOrStandInstructions();

    // checks whether the player's point tally exceeded the
    // maximum limit of 21
    static bool didPointExceedLimit(const int points);

    // checks to make sure that neither players have more than 21 points.
    // If that was the case, the other member automatically wins. Otherwise,
    // compares the points tally between player and dealer and decides whether
    // player wins, loses, or ties the dealer
    static void determineWinner(vectorOfCards& deck, Player& dealer, const int playerPts);

    // Displays the player picking cards on the console
    static void playerPickUpCardMessage();

    // Displays the dealer picking cards on the console
    static void dealerPickUpCardMessage();

    // the game logic behind Blackjack.
    static void BlackJackGameLogic();

    // offers player the chance to either play Blackjack again, or
    // end the game.
    static void playAgainOrNot();

    // The actual game of Blackjack. Enjoy!!
    static void playBlackJack();

    static int getMaxPointsForAce() {
        return maxPointsForAce;
    }

    static int getMinScoreForDealer() {
        return minScoreForDealer;
    }

    static int getMaxPoints() {
        return maxPoints;
    }

    static int getNumCardsGivenToPlayer() {
        return numCardsGivenToPlayer;
    }

private:
    inline static int maxPoints{21};
    inline static int minScoreForDealer{17};
    inline static int maxPointsForAce{11};
    inline static int aceDevalueAmount{10};
    inline static int initialNumCardsGivenToPlayer{2};
    inline static int numCardsGivenToPlayer{1};
};

#endif //BLACKJACKCARDGAME_GAMEENGINE_H

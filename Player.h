//
// Created by Aihua on 2020-07-21.
//

#ifndef BLACKJACKCARDGAME_PLAYER_H
#define BLACKJACKCARDGAME_PLAYER_H

#include "PlayingCard.h"

using cardRank = PlayingCard::cardRank;
using cardSuit = PlayingCard::cardSuit;
using vectorOfCards = std::vector<PlayingCard>;

class Player {
public:
    Player() = default;

    friend class GameEngine;

    int getPoints() {
        return points;
    }

    // returns the value of a given playing card
    static int getCardValue(const PlayingCard& card, Player& player);

    // gives player 'n' playing cards. The player's list of cards
    // and points tally are updated. Playing card deck gets reduced.
    static void giveOutPlayingCards(vectorOfCards& deck, Player& player,
                                    int numCardsToGet);

    // allows player to either repeatedly take playing cards (increasing their
    // points and card amount) or stand and allows the dealer to play its turn
    static void obtainPlayerHits(vectorOfCards& deck, Player& player);

    // allows dealer to repeatedly take playing cards (increasing their
    // points and card amount) until they accumulate at least 17 points
    static void obtainDealerHits(vectorOfCards& deck, Player& dealer);

private:
    int points{};
    int numAcesCollected{};
    vectorOfCards cards;
};

#endif //BLACKJACKCARDGAME_PLAYER_H
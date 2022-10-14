//
// Created by Aihua on 2020-07-21.
//

#ifndef BLACKJACKCARDGAME_PLAYINGCARD_H
#define BLACKJACKCARDGAME_PLAYINGCARD_H

#include <iostream>
#include <vector>
#include <algorithm>

class PlayingCard {
public:
    static const int numCardsInDeck{52};

    enum class cardRank {
        two,
        three,
        four,
        five,
        six,
        seven,
        eight,
        nine,
        ten,
        Jack,
        Queen,
        King,
        Ace,
        NumRanks,
    };

    enum class cardSuit {
        clubs,
        diamonds,
        hearts,
        spades,
        NumSuits,
    };

    using vectorOfCards = std::vector<PlayingCard>;

    PlayingCard() = default;

    PlayingCard(const cardRank& rank, const cardSuit& suit)
               : rank{rank}, suit{suit} {}

    cardRank getRankValue() const {
        return rank;
    }

    // prints a playing card's value in a two-character code
    static void printCard(const PlayingCard& card);

    // translates the rank of a playing card into a one character code
    char getCardRankSymbol() const;

    // translates the suit of a playing card into a one character code
    char getCardSuitSymbol() const;

    // generates a vector representing a deck of 52 playing cards
    static vectorOfCards createDeckOfCards();

    // prints out the entire deck of playing cards,
    // displaying each card using a two-character code
    static void printDeckOfCards(const vectorOfCards& deck);

    // shuffles the vector of playing cards so that
    // the cards are in random order
    static void shuffleDeckOfCards(vectorOfCards& deck);

private:
    cardRank rank{};
    cardSuit suit{};
};

#endif //BLACKJACKCARDGAME_PLAYINGCARD_H

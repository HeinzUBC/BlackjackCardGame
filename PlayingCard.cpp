//
// Created by Aihua on 2020-07-30.
//

#include "PlayingCard.h"
#include "RandomNumberSimulation.h"

using vectorOfCards = std::vector<PlayingCard>;

// prints a playing card's value in a two-character code
void PlayingCard::printCard(const PlayingCard& card) {
    std::cout << card.getCardRankSymbol()
              << card.getCardSuitSymbol();
}

// translates the rank of a playing card into a one character code
char PlayingCard::getCardRankSymbol() const {
    switch (rank) {
        case cardRank::Ace:
            return 'A';
        case cardRank::Jack:
            return 'J';
        case cardRank::King:
            return 'K';
        case cardRank::Queen:
            return 'Q';
        case cardRank::two:
            return '2';
        case cardRank::three:
            return '3';
        case cardRank::four:
            return '4';
        case cardRank::five:
            return '5';
        case cardRank::six:
            return '6';
        case cardRank::seven:
            return '7';
        case cardRank::eight:
            return '8';
        case cardRank::nine:
            return '9';
        case cardRank::ten:
            return 'T';
        default:
            return '?';
    }
}

// translates the suit of a playing card into a one character code
char PlayingCard::getCardSuitSymbol() const {
    switch (suit) {
        case cardSuit::clubs:
            return 'C';
        case cardSuit::diamonds:
            return 'D';
        case cardSuit::hearts:
            return 'H';
        case cardSuit::spades:
            return 'S';
        default:
            return '?';
    }
}

// generates a vector representing a deck of 52 playing cards
vectorOfCards PlayingCard::createDeckOfCards() {
    vectorOfCards cards(PlayingCard::numCardsInDeck);

    int numSuits{static_cast<int>(cardSuit::NumSuits)};
    int numRanks{static_cast<int>(cardRank::NumRanks)};
    cardSuit suit{};
    cardRank rank{};
    auto itr{cards.begin()};

    for (int i = 0; i < numSuits; ++i) {
        suit = static_cast<cardSuit>(i);
        for (int j = 0; j < numRanks; ++j) {
            rank = static_cast<cardRank>(j);
            itr->rank = rank;
            itr->suit = suit;
            ++itr;
        }
    }
    return cards;
}

// prints out the entire deck of playing cards,
// displaying each card using a two-character code
void PlayingCard::printDeckOfCards(const vectorOfCards& deck) {
    int numCommas{};
    for (const PlayingCard& card : deck) {
        printCard(card);
        if (numCommas < (numCardsInDeck - 1)) {
            std::cout << ", ";
        }
        ++numCommas;
    }
    std::cout << "\n\n";
}

// shuffles the vector of playing cards so that
// the cards are in random order
void PlayingCard::shuffleDeckOfCards(vectorOfCards& deck) {
    std::shuffle(deck.begin(), deck.end(), randomNumberGenerator::mersenne);
}

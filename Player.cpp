//
// Created by Aihua on 2020-07-21.
//

#include "Player.h"
#include "GameEngine.h"
#include <limits>

// returns the value of a given playing card
int Player::getCardValue(const PlayingCard& card, Player& player) {
    switch (card.getRankValue()) {
        case cardRank::two:
            return 2;
        case cardRank::three:
            return 3;
        case cardRank::four:
            return 4;
        case cardRank::five:
            return 5;
        case cardRank::six:
            return 6;
        case cardRank::seven:
            return 7;
        case cardRank::eight:
            return 8;
        case cardRank::nine:
            return 9;
        case cardRank::ten:
        case cardRank::Jack:
        case cardRank::Queen:
        case cardRank::King:
            return 10;
        case cardRank::Ace:
            ++player.numAcesCollected;
            return GameEngine::getMaxPointsForAce();
        default:
            std::cout << "Invalid rank detected in card\n\n";
            return -1;
    }
}

// gives player 'n' playing cards. The player's list of cards
// and points tally are updated. Playing card deck gets reduced.
void Player::giveOutPlayingCards(vectorOfCards& deck, Player& player,
                                 int numCardsToGet) {
    auto itr = deck.begin();
    int counter{};
    int endVal{numCardsToGet};

    while (counter < endVal) {
        PlayingCard::printCard(*itr);
        if (counter < (endVal - 1)) {
            std::cout << ", ";
        }
        player.cards.push_back(*itr);
        player.points = player.points + Player::getCardValue(*itr, player);
        itr = deck.erase(itr);
        ++counter;
    }
    // 'this' is the current player
    GameEngine::devalueCollectedAces(player);
    std::cout << "\n\n";
}

// allows player to either repeatedly take playing cards (increasing their
// points and card amount) or stand and allows the dealer to play its turn
void Player::obtainPlayerHits(vectorOfCards& deck, Player& player) {
    char input{};
    while (player.points < GameEngine::getMaxPoints()) {
        std::cout << "You currently have " << player.points << " points\n";
        std::cout << "and possess the following cards: ";

        PlayingCard::printDeckOfCards(player.cards);
        GameEngine::displayHitOrStandInstructions();

        std::cout << "Your input: ";
        std::cin >> input;
        std::cout << '\n';

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        if (input == 'h') {
            GameEngine::playerPickUpCardMessage();
            Player::giveOutPlayingCards(deck, player, GameEngine::getNumCardsGivenToPlayer());
        } else if (input == 's') {
            break;
        } else {
            std::cout << "Invalid input entered. Please try again.\n\n";
        }
    }
}

// allows dealer to repeatedly take playing cards (increasing their
// points and card amount) until they accumulate at least 17 points
void Player::obtainDealerHits(vectorOfCards& deck, Player& dealer) {
    std::cout << "The dealer currently has " << dealer.points << " points.\n";
    std::cout << "Furthermore, the dealer currently has these cards: ";
    PlayingCard::printDeckOfCards(dealer.cards);
    while (dealer.points < GameEngine::getMinScoreForDealer()) {
        GameEngine::dealerPickUpCardMessage();
        Player::giveOutPlayingCards(deck, dealer,
                                  GameEngine::getNumCardsGivenToPlayer());
    }
}
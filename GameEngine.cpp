//
// Created by Aihua on 2020-08-03.
//

#include "GameEngine.h"

// provides players with instructions for Blackjack
void GameEngine::gameInstructions() {
    std::cout << "Hello!! Welcome to playing Blackjack.\n\n";
    std::cout << "The rules of this game are as follows: \n\n";
    std::cout << "1) The dealer gets one card to start\n"
                 "2) The player gets two cards to start\n"
                 "3) The player goes first\n"
                 "4) The player can repeatedly “hit” or “stand”\n"
                 "     * If the player “stands”, their turn is over,\n"
                 "       and their score is calculated based on the \n"
                 "       cards they have been dealt\n"
                 "     * If the player “hits”, they get another card\n"
                 "       and the value of that card is added to their\n"
                 "       total score\n"
                 "5) The dealer goes after the player\n"
                 "6) The dealer repeatedly draws until they reach\n "
                 "  a score of 17 or more, at which point they end their turn\n"
                 "7) If the player GOES OVER a score of 21,\n"
                 "   they bust and lose immediately\n"
                 "8) If the dealer GOES OVER a score of 21, \n"
                 "   they bust and the player wins immediately\n"
                 "9) Otherwise, the winner will be determined based on\n"
                 "   which person accumulated the most points\n"
                 "10) If both the player and dealer have equal number of points,\n"
                 "    it will be a draw\n"
                 "11) An ace normally counts as a 1 or an 11 (whichever is better for the total score)\n\n";
}

// creates a shuffled deck of playing cards for the game
vectorOfCards GameEngine::createShuffledDeckOfCards() {
    vectorOfCards cardDeck{PlayingCard::createDeckOfCards()};
    PlayingCard::shuffleDeckOfCards(cardDeck);
    return cardDeck;
}

// If the player's points tally EXCEEDS 21 AND he/she has collected
// some Aces, some of those Aces can be devalued to have a worth of
// 1 to lower the player's points
void GameEngine::devalueCollectedAces(Player& player) {
    if ((player.points > maxPoints) && (player.numAcesCollected > 0)) {
        int numAceDevalued{};
        int pointsOriginal{player.points};
        while ((player.points > maxPoints) &&
               (player.numAcesCollected > 0)) {
            player.points = player.points - aceDevalueAmount;
            --player.numAcesCollected;
            ++numAceDevalued;
        }
        std::cout << "\n\nSince the current score of " << pointsOriginal
                  << " exceeded " << maxPoints << ", "
                  << numAceDevalued << " Aces were devalued to have value 1.\n"
                  << "removing " << (numAceDevalued * aceDevalueAmount)
                  << " points in the process.";
    }
}

// displays input instructions for player on console
void GameEngine::displayHitOrStandInstructions() {
    std::cout << "If you want to get another card (perform a hit),\n";
    std::cout << "enter 'h'. If you do not want to pick up more\n";
    std::cout << "cards (perform a stand and end your turn) enter\n";
    std::cout << "'s'\n\n";
}

// checks whether the player's point tally exceeded the
// maximum limit of 21
bool GameEngine::didPointExceedLimit(const int points) {
    return (points > maxPoints);
}

// checks to make sure that neither players have more than 21 points.
// If that was the case, the other member automatically wins. Otherwise,
// compare the points tally between player and dealer and decides whether
// player wins, loses, or ties the dealer
void GameEngine::determineWinner(vectorOfCards& deck, Player& dealer, const int playerPts) {

    if (GameEngine::didPointExceedLimit(playerPts)) {
        std::cout << "Unlucky buddy ... your points tally of "
                  << playerPts << " exceeded the points limit of "
                  << maxPoints << ".\n\n";
    } else {

        if (playerPts == maxPoints) {
            std::cout << "YAY!!! You achieved a points tally of "
                      << maxPoints << ". You win!!!\n\n";
            return;
        }
        Player::obtainDealerHits(deck, dealer);

        if (didPointExceedLimit(dealer.points)) {
            std::cout << "YAY!!! The dealer's points tally of "
                      << dealer.points << " exceeded the points limit of "
                      << maxPoints << ". You win!!!\n\n";
        } else {
            if (playerPts > dealer.points) {
                std::cout << "YAY!!! Your points tally of "
                          << playerPts << " exceeded the points total of "
                          << "dealer,\nwhich was " << dealer.points
                          << ". You win!!!\n\n";
            } else if (playerPts == dealer.points) {
                std::cout << "Damn ... I do not know what to say. We have a tie\n"
                          << "here ladies and gentlemen!! Both you and the dealer\n"
                          << "obtained a points total of " << playerPts
                          << "!!\n\n";
            } else {
                std::cout << "Unlucky buddy ... your points tally of "
                          << playerPts << " was less than the points total of "
                          << "the dealer,\nwhich was " << dealer.points << ".\n\n";
            }
        }
    }
}

// Displays the player picking cards on the console
void GameEngine::playerPickUpCardMessage() {
    std::cout << "You pick up: ";
}

// Displays the dealer picking cards on the console
void GameEngine::dealerPickUpCardMessage() {
    std::cout << "Dealer picks up: ";
}

// the game logic behind Blackjack.
void GameEngine::BlackJackGameLogic() {
    Player newPlayer{};
    Player dealer{};

    vectorOfCards deck{GameEngine::createShuffledDeckOfCards()};

    GameEngine::playerPickUpCardMessage();
    Player::giveOutPlayingCards(deck, newPlayer, initialNumCardsGivenToPlayer);

    GameEngine::dealerPickUpCardMessage();
    Player::giveOutPlayingCards(deck, dealer, numCardsGivenToPlayer);

    Player::obtainPlayerHits(deck, newPlayer);
    GameEngine::determineWinner(deck, dealer, newPlayer.getPoints());
}

// offers player the chance to either play Blackjack again, or
// end the game.
void GameEngine::playAgainOrNot() {
    std::cout << "It was very fun playing this game with you!!\n\n"
              << "If you would like to play again, press 'y'.\n"
              << "If you want to end the game, enter 'n'.\n\n";
    char input{};
    while (true) {
        std::cout << "You input is: ";
        std::cin >> input;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        if (input == 'y') {
            std::cout << "\n";
            BlackJackGameLogic();
            playAgainOrNot();
            break;
        } else if (input == 'n') {
            break;
        }
        std::cout << "Invalid input. Please try again.\n\n";
    }
}

// The actual game of Blackjack. Enjoy!!
void GameEngine::playBlackJack() {
    GameEngine::gameInstructions();
    GameEngine::BlackJackGameLogic();
    GameEngine::playAgainOrNot();
}